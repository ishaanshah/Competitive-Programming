/* Created by Ishaan Shah on 07-12-2017.
 * Problem Name: CHEFEXQ
 * Problem Link: https://www.codechef.com/problems/CHEFEXQ
*/

#include <bits/stdc++.h>

using namespace std;

int query_2(int k,int end);
void create_blocks();
void update(int index, int new_value);

int n, q;
int blocks[320];
int block_arr[320][320];
unsigned long block_size;
int arr[100005];
map<int, int> value[320];

int main() {
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int> >queries;
    for(int i = 0; i < q; i++) {
        vector<int>inp(3);
        cin >> inp[0] >> inp[1] >> inp[2];
        queries.push_back(inp);
    }
    create_blocks();

    for(auto &query: queries) {
        if(query[0] == 1) {
            update(query[1]-1, query[2]);
        }
        else {
            int ans = query_2(query[2], query[1]);
            cout << ans << '\n';
        }
    }
}

int query_2(int k,int end)
{
    int ans = 0;
    if(end >= block_size) {
        ans = value[0][k];
    } else {
        for(int i = 0; i < block_size; i++) {
            if(k == block_arr[0][i]) {
                ans++;
            }
        }
    }

    int x = 0;
    for(int i = 1; i < end/block_size; i++) {
        x ^= blocks[i-1];

    }
}

void create_blocks() {
    block_size = unsigned long(ceil(sqrt(n)));
    int x = 0;
    for(int i = 0; i < n; i++) {
        x ^= arr[i];
        blocks[i/block_size] = x;
        block_arr[i/block_size][i % block_size] = x;
        if(value[i/block_size].count(x)) {
            value[i/block_size][x]++;
        } else {
            value[i/block_size][x] = 1;
        }
    }
}

void update(int index, int new_value) {
    for (auto i = index % block_size; i < block_size; i++) {
        int x;
        int old_value = arr[i];
        blocks[index / block_size] ^= new_value ^ old_value;
        x = block_arr[index / block_size][i];
        value[index / block_size][x]--;
        x ^= new_value ^ old_value;
        if (value[index / block_size].count(x)) {
            value[index / block_size][x]++;
        } else {
            value[index / block_size][x] = 1;
        }
        arr[index] = new_value;
    }
}