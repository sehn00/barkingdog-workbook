#include <bits/stdc++.h>
using namespace std;

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    queue<int> Q;
    int N;
    cin >> N;

    while (N--) {
        string op;
        cin >> op;

        if (op == "push") {
            int X;
            cin >> X;
            Q.push(X);
        }
        if (op == "pop") {
            if (Q.empty()) cout << -1 << '\n';
            else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        if (op == "size")
            cout << Q.size() << '\n';
        if (op == "empty") {
            if (Q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        if (op == "front") {
            if (Q.empty()) cout << -1 << '\n';
            else cout << Q.front() << '\n';
        }
        if (op == "back") {
            if (Q.empty()) cout << -1 << '\n';
            else cout << Q.back() << '\n';
        }
    }

    return 0;
}