/* Created by Ishaan Shah on 01-12-2017.
 * Problem Name: GIT01
 * Problem Link: https://www.codechef.com/DEC17/problems/GIT01
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        vector<string >cherries;
        for(int i = 0; i < m; i++) {
            string input;
            cin >> input;
            cherries.push_back(input);
        }

        char temp = 'G';
        int score_1 = 0;
        for(auto &row: cherries) {
            for(auto &cherry: row) {
                if(temp == 'G' && cherry == 'R') {
                    score_1 += 5;
                }
                else if(temp == 'R' && cherry == 'G') {
                    score_1 += 3;
                }

                if(temp == 'G') {
                    temp = 'R';
                }
                else {
                    temp = 'G';
                }
            }
            if(n%2 == 0) {
                if(temp == 'G') {
                    temp = 'R';
                }
                else {
                    temp = 'G';
                }
            }
        }

        temp = 'R';
        int score_2 = 0;
        for(auto &row: cherries) {
            for(auto &cherry: row) {
                if(temp == 'G' && cherry == 'R') {
                    score_2 += 5;
                }
                else if(temp == 'R' && cherry == 'G') {
                    score_2 += 3;
                }

                if(temp == 'G') {
                    temp = 'R';
                }
                else {
                    temp = 'G';
                }
            }
            if(n%2 == 0) {
                if(temp == 'G') {
                    temp = 'R';
                }
                else {
                    temp = 'G';
                }
            }
        }

        cout << min(score_1, score_2) << endl;
    }
}
