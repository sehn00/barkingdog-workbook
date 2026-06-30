#include <bits/stdc++.h>
using namespace std;

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    string init;

    cin >> N;
    while (N--) {
        list<char> L;
        auto cursor = L.end();

        string init;
        cin >> init;

        for (auto c : init) {
            if (c == '-') {
                if (cursor != L.begin()) {
                    cursor--;
                    cursor = L.erase(cursor);
                }
                continue;
            }
            if (c == '<') {
                if (cursor != L.begin())
                    cursor--;
                continue;
            }
            if (c == '>') {
                if (cursor != L.end())
                    cursor++;
                continue;
            }
            L.insert(cursor, c);
            // cursor++;   <- 이게 들어오면 안됐네;;;
        }

        for (auto c : L)
            cout << c;
        cout << '\n';

    }

    return 0;

}