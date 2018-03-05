/* Created by Ishaan Shah on 05-03-2018.
 * Implementation of Heaps and its functions.
*/

#include <bits/stdc++.h>

using namespace std;

class Node{
    public:

    int value;
    int lch;
    int rch;
    int parent;

    Node() {
        value = 0;
        lch = -1;
        rch = -1;
        parent = -1;
    }

    Node(int v, int l, int r, int p) {
        value = v;
        lch = l;
        rch = r;
        parent = p;
    }
};

class Heap{
    public:

    int size;
    Node *ptn;
    int max;
    
    Heap(int s,int m) {
        size = s;
        max = m;
        ptn = new Node[size];
    }

    int get_max();
    int remove_key(int key);
    void heapify(int i);
    void make_heap(int input[]);
    void increase_key(int key, int value);
    void decrease_key(int key, int value);
    void insert(int value);
};

int Heap::get_max() {
    return ptn[0].value;
}

int Heap::remove_key(int key) {
    if(size < 1) {
        return -1;
    }
    int result = ptn[key].value;
    ptn[key].value = ptn[size-1].value;
    size--;
    heapify(key);
    return result;
}

void Heap::heapify(int i) {
    int l = ptn[i].lch;
    int r = ptn[i].rch;
    int largest;
    if(l < size and ptn[l].value > ptn[i].value) {
        largest = l;
    } else {
        largest = i;
    }

    if(r < size and ptn[r].value > ptn[largest].value) {
        largest = r;
    }

    if(largest != i) {
        swap(ptn[i].value, ptn[largest].value);
        heapify(largest);
    }
}

void Heap::make_heap(int input[]) {
    switch (size){
        case 1:
            ptn[0] = Node(input[0], -1, -1, -1);
            break;
        case 2:
            ptn[0] = Node(input[0], 1, -1, -1);
            break;
        default:
            ptn[0] = Node(input[0], 1, 2, -1);
            break;
    }

    for(int i = 1; i < size; i++) {
        ptn[i].value = input[i];
        ptn[i].parent = (i-1)/2;
        if(i*2 + 1 < size){
            ptn[i].lch = i*2 + 1;
        } else {
            ptn[i].lch = -1;
        }

        if(i*2 + 2 < size) {
            ptn[i].rch = i*2 + 2;
        } else {
            ptn[i].rch = -1;
        }  
    }

    for(int i = size/2; i >= 0; i--) {
        heapify(i);
    }
}

void Heap::increase_key(int key, int new_value) {
    ptn[key].value = new_value;
    if(ptn[key].parent != -1) {
        if(ptn[ptn[key].parent].value < ptn[key].value) {
            swap(ptn[ptn[key].parent].value, ptn[key].value);
            increase_key(ptn[key].parent, new_value);
        }
    }
}

void Heap::decrease_key(int key, int new_value) {
    ptn[key].value = new_value;
    heapify(key);
}

void Heap::insert(int value) {
    if(size + 1 <= max) {
        size++;
        ptn[size-1].value = value;
        increase_key(size-1, value);
    }
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int n;
    cin >> n;

    int input[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    Heap hp(n, n);
    hp.make_heap(input);
    for(int i = 0; i < n; i++) {
        cout << hp.ptn[i].value << ' ' << hp.ptn[i].lch << ' ' << hp.ptn[i].rch << ' ' << hp.ptn[i].parent << endl; 
    }
}