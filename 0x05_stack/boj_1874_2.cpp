#include <bits/stdc++.h>
using namespace std;

int
main()
{
    stack<int> S;
    vector<char> Ans;

    int cur = 1;

    int N;
    cin >> N;

    while (N--) {
        int target;
        cin >> target;

        while (cur <= target) {
            S.push(cur);
            Ans.push_back('+');
            cur++;
        }

        if (S.top() == target) {
            S.pop();
            Ans.push_back('-');
        }
        else {
            cout << "NO" << '\n';
            return 0;
        }
    }

    for (auto c : Ans)
            cout << c << '\n';

    return 0;
}