/* Created by Ishaan Shah on 20-01-2019.
* Problem Name: Dreamoon and WiFi
* Problem Link: https://codeforces.com/problemset/problem/476/B
*/

#include <bits/stdc++.h>

using namespace std;

string sent, rec;
int finpos;

double search(int pos, int idx) {
	if (idx == sent.length()-1) {
		if (rec[idx] == '+'){
			pos++;
			if (pos == finpos) return 1;
			else return 0;
		} else if (rec[idx] == '-') {
			pos--;
			if (pos == finpos) return 1;
			else return 0;
		} else {
			pos++;
			if (pos == finpos) return 0.5;
			pos -= 2;
			if (pos == finpos) return 0.5;
			else return 0;
		}
	}
	if (rec[idx] == '?') return 0.5*(search(pos+1, idx+1)+search(pos-1, idx+1));
	if (rec[idx] == '+') return search(pos+1, idx+1);
	if (rec[idx] == '-') return search(pos-1, idx+1);
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	cin >> sent;
	cin >> rec;
	finpos = 0;
	for (int i = 0; i < sent.length(); i++) {
		if (sent[i] == '+') finpos++;
		else finpos--;
	}
	printf("%.9f", search(0, 0));
}
