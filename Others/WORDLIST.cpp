/* Created by Ishaan Shah on 01-12-2017.
 * Problem Name: WORDLIST
 * Problem Link: http://opc.iarcs.org.in/index.php/problems/WORDLIST
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    set<string > words;

    scanf("%i\n", &n);
    while(n--)
    {
        string input, word;
        getline(cin, input);

        for(auto &character: input)
        {
            if(isalpha(character))
            {
                character = char(tolower(character));
            }
            else
            {
                character = ' ';
            }
        }

        stringstream ss(input);
        while(ss >> word)
        {
            words.insert(word);
        }
    }

    cout << words.size() << endl;
    for(auto &word: words)
    {
        cout << word << endl;
    }
}