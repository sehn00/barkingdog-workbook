#include <bits/stdc++.h>
using namespace std;

int sum;

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    stack<int> S;

    int K;
    cin >> K;
    while (K--) {
        int num;
        cin >> num;
        
        if (num == 0) {
            if (S.empty()) continue;
            else S.pop();
        }
        else S.push(num);
    }

    stack<int> tmp = S;     // S를 복사해올 tmp 스택 생성
    while (!tmp.empty()) {
        sum += tmp.top();
        tmp.pop();
    }
    cout << sum << '\n';

    return 0;
}