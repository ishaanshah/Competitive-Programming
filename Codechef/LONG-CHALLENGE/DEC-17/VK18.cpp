/* Created by Ishaan Shah on 05-12-2017.
 * Problem Name: VK18
 * Problem Link: https://www.codechef.com/DEC17/problems/VK18
*/

#include <bits/stdc++.h>

using namespace std;

int diamonds(int n);

void calculate(long long init, int i);

vector<long long> func;
vector<long long> results;

int main() {
    int t, n;
    cin >> t;
    vector<int> inputs;
    while (t--) {
        cin >> n;
        inputs.push_back(n);
    }
    int temp = *max_element(inputs.begin(), inputs.end());
    results.resize(temp+1);
    func.resize(temp+1);

    for (int i = 1; i <= temp; i++) {
        calculate(results[i - 1], i);
    }
    for(auto &elem: inputs)
    {
        cout << results[elem] << endl;
    }
}

int diamonds(int n)
{
    string str = to_string(n);
    int sum_1 = 0;
    int sum_2 = 0;
    for(auto &elem: str)
    {
        if(int(elem-'0') % 2 == 0)
        {
            sum_1 += elem - '0';
        }
        else
        {
            sum_2 += elem - '0';
        }
    }
    return abs(sum_1 - sum_2);
}

void calculate(long long init, int i)
{
    int temp = diamonds(2*i);
    func[i] = func[i-1] - diamonds(i-1 + 1) + diamonds(2*i - 1) + temp;
    results[i] = init + 2*func[i] - temp;
}