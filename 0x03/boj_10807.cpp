#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, x, cnt=0;
    cin >> N;
    int arr[N] = {};

    for (int i=0; i<N; i++)
        cin >> arr[i];
    cin >> x;

    for (int i=0; i<N; i++) {
        if (arr[i] == x) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}