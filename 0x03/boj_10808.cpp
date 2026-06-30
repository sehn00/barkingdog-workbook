#include <bits/stdc++.h>
using namespace std;

int num[27];

int
main()
{
    string S;
    cin >> S;

    for (int i=0; i < S.size(); i++) {
        num[S[i]-'a']++;

        cout << "---> i: " << i
            << " | 문자: " << S[i]
            << " | num[" << S[i]-'a' << "] 값: " << num[S[i]-'a'] << '\n';
    }

    for (int i=0; i<26; i++)
        cout << num[i] << " ";
    cout << '\n';

    return 0;
}