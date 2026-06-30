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
            int num;
            cin >> num;
            S.push(num);
        }
        if (op == "pop") {
            if (S.empty()) cout << "-1\n";
            // else S.pop();  -> 파이썬이 아니다.. c++의 pop()은 삭제만 함
            else {
                cout << S.top() << '\n';
                S.pop();
            }
            
        }
        if (op == "size") {
            cout << S.size() << '\n';
        }
        if (op == "empty") {
            if (S.empty()) cout << "1\n";
            else cout << "0\n";
        }
        if (op == "top") {
            if (S.empty()) cout << "-1" << '\n';
            else cout << S.top() << '\n';
        }
    }

    return 0;
}