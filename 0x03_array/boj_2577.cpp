#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int arr[10];

int
main()
{
    cin >> A >> B >> C;
    int mul = A * B * C;    // int overflow 안나나? 10^9 인데
    
    while (1) {
        arr[mul%10]++;
        mul/=10;
        if (mul==0) break;
    }
    for (int i=0; i<10; i++)
        cout << arr[i] << '\n';
    return 0;
}
