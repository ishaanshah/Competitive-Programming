/* Created by Ishaan Shah on 28-11-2017.
 * Problem Name: CHEFGP
 * Problem Link: https://www.codechef.com/OCT17/problems/CHEFGP
*/


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, x, y;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        cin >> x >> y;
        vector<char> answer;
        int a = 0;
        int b = 0;
        for(const char &i: s)
        {
            if(a == x && i == 'a')
            {
                answer.push_back('*');
                answer.push_back('a');
                a = 0;
                b = 0;
            }
            else if(b == y && i == 'b')
            {
                answer.push_back('*');
                answer.push_back('b');
                a = 0;
                b = 0;
            }
            else if(i == 'a')
            {
                answer.push_back('a');
                a++;
                b = 0;
            }
            else if(i == 'b')
            {
                answer.push_back('b');
                b++;
                a = 0;
            }
        }
        for(auto elem: answer)
        {
            cout << elem;
        }
        cout << endl;
    }
}
