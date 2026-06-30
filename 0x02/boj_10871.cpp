#include <bits/stdc++.h>

using namespace std;

int N, X, A;

int
main()
{
    cin >> N >> X;
    for (int i=0; i<N; i++) {
        cin >> A;
        if (A < X) cout << A << " ";
    }
    return 0;
}