#include <bits/stdc++.h>
using namespace std;

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    deque<int> D;
    int N;
    cin >> N;

    while (N--) {
        string op;
        cin >> op;

        if (op == "push_front") {
            int X;
            cin >> X;
            D.push_front(X);
        }
        if (op == "push_back") {
            int X;
            cin >> X;
            D.push_back(X);
        }
        if (op == "pop_front") {
            if (D.empty()) cout << -1 << '\n';
            else {
                cout << D.front() << '\n';
                D.pop_front();
            }
        }
        if (op == "pop_back") {
            if (D.empty()) cout << -1 << '\n';
            else {
                cout << D.back() << '\n';
                D.pop_back();
            }
        }
        if (op == "size")
            cout << D.size() << '\n';
        if (op == "empty") {
            if (D.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        if (op == "front") {
            if (D.empty()) cout << -1 << '\n';
            else cout << D.front() << '\n';
        }
        if (op == "back") {
            if (D.empty()) cout << -1 << '\n';
            else cout << D.back() << '\n';
        }
    }

    return 0;
}