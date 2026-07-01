#include <bits/stdc++.h>
using namespace std;

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M, cnt=0;
    cin >> N >> M;
    
    deque<int> D;
    for (int i=1; i<=N; i++) D.push_back(i);


    while (M--) {
        int target;
        cin >> target;

        // 현재 덱에서 target의 위치 찾기
        int pos = find(D.begin(), D.end(), target) - D.begin();
        
        // 왼쪽으로 도는게 더 빠른 경우
        if (pos <= D.size()/2) {
            while (D.front() != target) {
                D.push_back(D.front());
                D.pop_front();
                cnt++;
            }
        }
        // 오른쪽으로 도는게 더 빠른 경우
        else {
            while (D.front() != target) {
                D.push_front(D.back());
                D.pop_back();
                cnt++;
            }
        }

        // 목표 원소 제거 (1번 연산)
        D.pop_front();
    }

    cout << cnt << '\n';

    return 0;
}