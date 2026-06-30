// https://www.acmicpc.net/problem/18808

#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
int r, c;
int board[42][42];
int sticker[12][12];

void 
Rotate()
{
    int tmp[12][12] = {};
  
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            tmp[i][j] = sticker[i][j];

    for(int i=0; i<c; i++)
        for(int j=0; j<r; j++)
            sticker[i][j] = tmp[r-1-j][i];

    swap(r, c);
}

bool
Pastable(int x, int y)
{
    // (1) 붙일 수 있는지?
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (board[x+i][y+j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }
    
    // (2) 붙일 수 있으면, board 채워넣기
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (sticker[i][j] == 1)
                board[x+i][y+j] = 1;
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
        
        // 4가지 방향 돌리기
        for (int rot=0; rot<4; rot++) {
            // 지금 rotation으로 들어갈 수 있는지 확인하기
            // 근데 맞으면 그만 돌려도되니까,
            // flag 하나 두고 들어갈 수 있으면 플래그 켜기
            bool is_paste = false;

            // 스티커블록 좌상단 기준점(x,y)을 이동시키기면서 확인하기
            for (int x=0; x<=n-r; x++) {
                if (is_paste) break;
                for (int y=0; y<=m-c; y++) {
                    if (Pastable(x, y)) {
                        is_paste = true;
                        break;
                    }
                }
            }

            // 붙였으면 다음 스티커로 넘어감
            if (is_paste) break;

            // 못 붙였으면 회전해서 다시 시도
            Rotate();
        }
    }
    // board 총 칸 수 세기
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt += board[i][j];

    cout << cnt << '\n';
    return 0;
}