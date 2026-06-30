// https://www.acmicpc.net/problem/14503

#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
// 북 동 남 서

int n, m;
int x, y, d;
int board[52][52];

int
RotateLeft(int d)
{
    return (d + 3) % 4;
}

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    cin >> x >> y >> d;

    int cnt = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            cin >> board[i][j];
    }

    while (1) {
        if (board[x][y] == 0) {
            board[x][y] = -1;
            cnt++;
            continue;
        }
        bool moved = false;

        for (int dir=0; dir<4; dir++) {
            d = RotateLeft(d);

            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (board[nx][ny] == 0) {
                x = nx;
                y = ny;
                moved = true;
            }
            break;
        }
        continue;

        if 
    
    }
}