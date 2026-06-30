// https://www.acmicpc.net/problem/14503

#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
// is subaq..?

#define X first
#define Y second

using namespace std;

// 북 동 남 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int board[52][52];
int N, M;
int x, y, d;
int cnt = 0;

int
RotateLeft(int d)
{
    return (d + 3) % 4;
}

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int r, c, d;
    cin >> N >> M;    // 방크기 NxM
    cin >> x >> y >> d;    // 초기위치 (x,y), 방향 d
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            cin >> board[i][j];
    }
    
    int cnt = 0;
    while (1) {
        // 현재 칸 청소 안했으면, 청소
        if (board[x][y] == 0) {
            board[x][y] = -1;
            cnt++;
        }

        // 주변 4칸 둘러보고, 청소 안된 빈 칸 있으면 전진
        for (int dir=0; dir<4; dir++) {
            d = RotateLeft(d);
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (board[nx][ny] == 0) {
                x = nx;
                y = ny;
                break;
            }
        }
    }


    cout << cnt << '\n';
    
    return 0;
}
