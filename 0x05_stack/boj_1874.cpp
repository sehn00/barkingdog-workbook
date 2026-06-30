#include <bits/stdc++.h>
using namespace std;

int
main()
{
    stack<int> S;
    int N;
    cin >> N;
    
    while (N--) {
        int tp;
        cin >> tp;

        if (S.top() == tp) S.pop();
        else if (S.top() > tp) {
            for (int i=1; i<=tp; i++) 
                S.push(i);
        }
        if (S.top() == )


    }
}