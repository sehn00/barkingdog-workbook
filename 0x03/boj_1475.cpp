#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;

    if (N==0) cnt[0]++;

    while (N>0) {
        cnt[N%10]++;
        N/=10;
    }   // 이럼 N==0 일때는? 위에 if로 일단 처리해보자
    
    int tmp = (cnt[6] + cnt[9] + 1) / 2;
    cnt[6] = tmp;
    cnt[9] = 0;

    cout << *max_element(cnt, cnt+10) << '\n';

    return 0;    
}

/*
STL:
    max_element(시작 주소, 끝 주소)
    
    리턴값은 포인터! 쓸때는 *max_element() 로 사용
    =>
    int arr[10]; 으로 선언했으니, 쓸때는
    int mx = *max_element(arr, arr+10);
*/