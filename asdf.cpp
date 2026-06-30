#include <bits/stdc++.h>
using namespace std;

int board1[21][21]; // 원본 보드
int board2[21][21]; // 시뮬레이션용 보드
int n;

void rotate() { // board2를 시계 방향으로 90도 회전
    int tmp[21][21];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board2[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board2[i][j] = tmp[n - 1 - j][i];
}

void tilt(int dir) {
    // dir번 회전해서 해당 방향 이동을 "왼쪽 이동"으로 통일
    while (dir--) rotate();

    for (int i = 0; i < n; i++) {
        int tilted[21] = {}; // i번째 줄을 왼쪽으로 민 결과
        int idx = 0;         // 현재 채워 넣을 위치

        for (int j = 0; j < n; j++) {
            if (board2[i][j] == 0) continue; // 빈칸은 무시

            if (tilted[idx] == 0) {
                // 현재 위치가 비어 있으면 그냥 넣기
                tilted[idx] = board2[i][j];
            }
            else if (tilted[idx] == board2[i][j]) {
                // 같은 수면 합치고, 다음 칸으로 이동
                tilted[idx++] *= 2;
            }
            else {
                // 다른 수면 다음 칸에 넣기
                tilted[++idx] = board2[i][j];
            }
        }

        // 계산 결과를 다시 board2에 반영
        for (int j = 0; j < n; j++) board2[i][j] = tilted[j];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board1[i][j];

    int mx = 0;

    // 5번 이동, 매번 4방향 -> 4^5 = 1024가지 전부 탐색
    for (int tmp = 0; tmp < 1024; tmp++) {
        // 원본 보드를 작업용 보드에 복사
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board2[i][j] = board1[i][j];

        int brute = tmp;
        for (int i = 0; i < 5; i++) {
            int dir = brute % 4; // 현재 이동 방향
            brute /= 4;
            tilt(dir);
        }

        // 이번 경우의 최댓값 갱신
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mx = max(mx, board2[i][j]);
    }

    cout << mx;
}