#include <bits/stdc++.h>
using namespace std;

int M;
int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    list<char> L;
    string init;
    cin >> init;
    
    cin >> M;
    for (auto c : init)
        L.push_back(c);
    auto cursor = L.end();

    for (int i=0; i<M; i++) {
        char op;
        cin >> op;

        if (op == 'L') {
            if (cursor != L.begin()) cursor--;
        }
        else if (op == 'D') {
            if (cursor != L.end()) cursor++;
        }
        else if (op == 'B') {
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
        else if (op == 'P') {
            char x;
            cin >> x;
            L.insert(cursor, x);
        }
    }
    
    for (char c : L)
        cout << c;
    cout << '\n';
    
    return 0;
}