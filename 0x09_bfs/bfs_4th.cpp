#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// 남동북서

int board[502][502];
int vis[502][502];

int n = 7, m = 10;
// n = 행의 수, m = 열의 수

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    queue<pair<int,int>> Q;
    Q.push({0,0});
    vis[0][0] = 1;

    while (!Q.empty()) {
        pair<int,int> cur = Q.front();
        Q.pop();

        for (int dir=0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.X + dy[dir];

            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (vis[nx][ny] != 0 || board[nx][ny] != 1) continue;

            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
}