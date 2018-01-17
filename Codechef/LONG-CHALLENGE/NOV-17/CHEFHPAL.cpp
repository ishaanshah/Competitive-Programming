/* Created by Ishaan Shah on 27-11-2017.
 * Problem Name: CHEFHPAL
 * Problem Link: https://www.codechef.com/NOV17/problems/CHEFHPAL
*/

#include <iostream>

using namespace std;

int main()
{
    int t, n, a;
    cin >> t;
    while(t--)
    {
        cin >> n >> a;
        if(a > 2)
        {
            cout << "1" << " ";
            for(int i = 0; i < n; i++)
            {
                cout << "abc"[i % 3];
            }

            cout << endl;
        }
        else if(a == 1)
        {
            cout << n << " ";
            while(n--)
            {
                cout << "a";
            }

            cout << endl;
        }
        else
        {
            if(n <= 8)
            {
                switch(n)
                {
                    case 1: cout << "1" << "a"; break;
                    case 2: cout << "1 " << "ab"; break;
                    case 3 : cout << "2 " << "aab"; break;
                    case 4 : cout << "2 " << "aabb"; break;
                    case 5 : cout << "3 " << "aaaba"; break;
                    case 6 : cout << "3 " << "aaabab"; break;
                    case 7 : cout << "3 " << "aaababb"; break;
                    case 8 : cout << "3 " << "aaababbb"; break;
                    default: break;
                }
                cout << endl;
            }
            else
            {
                char arr[] = {'a', 'a', 'b', 'b', 'a', 'b'};
                cout << "4" << " ";
                for(int i = 0; i < n; i++)
                {
                    cout << arr[i % 6];
                }

                cout << endl;
            }
        }
    }
}
