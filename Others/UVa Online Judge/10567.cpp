/* Created by Ishaan Shah on 25-07-2018.
* Problem Name: Helping Fill Bates
* Problem Link: https://uva.onlinejudge.org/external/105/10567.pdf
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<char, int> pp;

const int MIN = numeric_limits<int>::min();

bool cmp(const pp &l,const pp &r) {
    return l.first < r.first;
}


int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int q;
	string temp;
	cin >> temp;
	pp s[temp.length()];
	for (int i = 0; i < temp.length(); i++) {
		s[i].first = temp[i];
		s[i].second = i;		
	}
	scanf("%d", &q);
	string ss[q];
	for (int i = 0; i < q; i += 1) cin >> ss[i];
	sort(s, s+temp.length());
	
	for (string qry: ss) {
		vector<int> aux;
		bool match = true;
		for (char c: qry) {
			int idx	= lower_bound(s, s+temp.length(), pp(c, MIN), cmp) - s;
			while (lower_bound(aux.begin(), aux.end(), s[idx].second) != aux.end()) {
				idx++;
				if (c != s[idx].first) {
					match = false;
					break;
				}
			}
			if (!match) {
				printf("Not matched\n");
				break;
			}
			aux.push_back(s[idx].second);
		}
		if (match) {
			printf("Matched %d %d\n", aux[0], *(aux.end()-1));
		}
	}
}
