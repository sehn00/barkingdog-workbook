#include <bits/stdc++.h>
using namespace std;

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    queue<int> Q;
    int N;
    cin >> N;

    for (int i=1; i<=N; i++)
        Q.push(i);
    // 1,2,3,4 있는 경우면
    // pop해야할게 1 --> 1이 front
    // 그럼 1부터 push하는게 맞네 ㅇㅇ push는 back에 하잖아
    
    while (Q.size()>1) {
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }

    cout << Q.front() << '\n';

    return 0;
}