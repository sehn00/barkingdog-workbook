// https://www.acmicpc.net/problem/15683

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[10][10];

int N, M;
int ans = 987654321;
vector<pair<int,int>> cctv;

void
check(int x, int y, int dir)
{
    dir %= 4;

    while (1) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;

        if (nx<0 || nx>=N || ny<0 || ny>=M) return;
        if (board[x][y] == 6) return;
        if (board[x][y] != 0) continue;
        board[x][y] = -1;
    }
    
}

void
dfs(int idx)    // 방향 정하기
{
    // Base condition
    if (idx == cctv.size()) {
        // 사각지대 개수 세기
        int cnt = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (board[i][j] == 0) cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }

    int x = cctv[idx].X;
    int y = cctv[idx].Y;

    for (int dir=0; dir<4; dir++) {

        // tmp에 복사해놓기
        int tmp[10][10];
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++)
                tmp[i][j] = board[i][j];
        }

        if (board[x][y] == 1)
            check(x, y, dir);
        else if (board[x][y] == 2) {
            check(x, y, dir);
            check(x, y, dir+2);
        }
        else if (board[x][y] == 3) {
            check(x, y, dir);
            check(x, y, dir+1);
        }
        else if (board[x][y] == 4) {
            check(x, y, dir);
            check(x, y, dir+1);
            check(x, y, dir+2);
        }
        else if (board[x][y] == 5) {
            check(x, y, dir);
            check(x, y, dir+1);
            check(x, y, dir+2);
            check(x, y, dir+3);
        }

        dfs(idx + 1);

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++)
                board[i][j] = tmp[i][j];
        }
    }
}

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6)
                cctv.push_back({i,j});
        }
    }

    dfs(0);
    cout << ans << '\n';
    return 0;
}   