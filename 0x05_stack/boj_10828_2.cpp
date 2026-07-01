#include <bits/stdc++.h>
using namespace std;

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    stack<int> S;
    int N;
    cin >> N;

    while (N--) {
        string op;
        cin >> op;

        if (op == "push") {
            int X;
            cin >> X;
            S.push(X);
        }
        if (op == "pop") {
            if (S.empty()) cout << -1 << '\n';
            else {
                cout << S.top() << '\n';
                S.pop();
            }
        }
        if (op == "top") {
            if (S.empty()) cout << -1 << '\n';
            else cout << S.top() << '\n';
        }
        if (op == "size") {
            cout << S.size() << '\n';
        }
        if (op == "empty") {
            if (S.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }


    }

}