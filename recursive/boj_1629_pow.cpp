// https://www.acmicpc.net/problem/1629

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll
POW(ll a, ll b, ll m) {
    // 1. 가장 작은 문제면 바로 답 반환 (base condition)
    if(b == 1) return a % m;

    // 2. 아니면 작은 문제 먼저 해결 (귀납가정: k일때 참)
    ll val = POW(a, b / 2, m);

    // 3. 그걸 이용해 현재 문제 계산 (2k & 2k+1 일때도 참)
    val = val * val % m;

    // 4. 짝수냐 홀수냐에 따라 최종 답 반환
    if(b % 2 == 0) return val;
    return val * a % m;
}

int
main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << POW(a, b, c);
}