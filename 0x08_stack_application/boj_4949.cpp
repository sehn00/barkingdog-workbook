#include <bits/stdc++.h>
using namespace std;

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    while (1) {
        bool isValid = true;
        string s;
        getline(cin, s);
        
        if (s == ".") break;

        stack<char> stk;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(' || s[i]=='[') stk.push(s[i]);
            else if (s[i] == ')') {
                if (!stk.empty() && stk.top() == '(')
                    stk.pop();
                else {
                    isValid = false;
                    break;
                }
            }
            else if (s[i] == ']') {
                if (!stk.empty() && stk.top() == '[')
                    stk.pop();
                else {
                    isValid = false;
                    break;
                }
            }
        }
        if (isValid && stk.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}