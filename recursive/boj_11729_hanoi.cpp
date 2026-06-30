// https://www.acmicpc.net/problem/11729

#include <bits/stdc++.h>
using namespace std;

// func(a, b, n) : n개의 원판을 a번 장대에서 b번 장대로 옮기는 함수
void
func(int a, int b, int n) {
    // Base condition: 원판이 1개면 바로 옮기면 끝
    if(n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }

    /*** k+1 문제 == k개 옮기기 + 1개 옴기기 + k개 옮기기 ***/
    /* k개 옯기기 -> 귀납가정 */

    // 1. 가장 큰 원판 위에 있는 n-1개를 보조 장대로 옮김
    // 귀납 가정: "N=k 일대는 잘 동작한다" 라고 가정했으니, 정상 동작
    func(a, 6-a-b, n-1);

    // 2. 가장 큰 원판 1개를 목적지로 옮김
    // 1에서 작은 원판들을 치워놨으니, 가장 큰 원판 옮기기 가능
    cout << a << ' ' << b << '\n';

    // 3. 보조 장대에 있던 n-1개를 목적지로 옮김
    // N=k 일때 이므로, 귀납 가정에 의해 정상 동작
    func(6-a-b, b, n-1);
}

int
main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int k;
    cin >> k;

    // 총 이동 횟수 = 2^k - 1
    cout << (1 << k) - 1 << '\n';

    // 1번 장대 -> 3번 장대로 k개 원판 이동
    func(1, 3, k);
}