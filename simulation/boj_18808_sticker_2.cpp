// https://www.acmicpc.net/problem/18808

#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int board[42][42];
int sticker[12][12];

int n, m, k;
int r, c;

void
Rotate()
{
    int tmp[12][12] = {};
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) tmp[i][j] = sticker[i][j];
    }
    for (int i=0; i<c; i++) {
        for (int j=0; j<r; j++) sticker[i][j] = tmp[r-1-j][i];
    }
    swap(r,c);
}

bool
Pastable(int x, int y)
{
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (board[x+i][y+j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (sticker[i][j] == 1) board[x+i][y+j] = 1;
        }
    }
    return true;
}

int
main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) cin >> sticker[i][j];
        }

        for (int rot=0; rot<4; rot++) {

            bool is_paste = false;
            for (int x=0; x<=n-r; x++) {
                if (is_paste) break;
                for (int y=0; y<=m-c; y++) {
                    if (Pastable(x,y)) {
                        is_paste = true;
                        break;
                    }
                }
            }
            if (is_paste) break;

            Rotate();
        }
    }

    // 개수세기
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt += board[i][j];

    cout << cnt << '\n';
    return 0;
}