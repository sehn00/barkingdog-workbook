#include <bits/stdc++.h>
using namespace std;

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N, cnt=0;

    cin >> N;
    while (N--) {
        string s;
        cin >> s;

        stack<char> stk;

        for (int i=0; i<s.size(); i++) {
            if (stk.empty()) stk.push(s[i]);
            else {
                if (stk.top() != s[i]) stk.push(s[i]);
                else stk.pop();     // top==s[i] 같으면 pop()
            }
        }
        if (stk.empty()) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}
