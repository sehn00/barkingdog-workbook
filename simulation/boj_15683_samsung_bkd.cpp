#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

// 방향 벡터
// 문제 풀이에서는 방향을 0,1,2,3으로 두고
// 남, 동, 북, 서 순서로 사용한다.
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

// 원본 보드
// 입력 그대로 저장해두는 배열
int board1[10][10];

// 탐색용 보드
// 각 경우마다 감시된 칸을 표시해보는 배열
int board2[10][10];

// CCTV 좌표들을 저장할 벡터
vector<pair<int,int>> cctv;

// 범위를 벗어났는지 확인하는 함수
bool OOB(int a, int b){
    return a < 0 || a >= n || b < 0 || b >= m;
}

// (x, y) 위치의 CCTV가 dir 방향을 감시한다고 할 때,
// 그 방향으로 쭉 전진하면서 감시 가능한 빈칸(0)을 7로 바꾼다.
void upd(int x, int y, int dir){
    dir %= 4; // dir+1, dir+2 등을 쓰므로 혹시 4 이상이면 다시 0~3으로 맞춤

    while(1){
        x += dx[dir];
        y += dy[dir];

        // 범위를 벗어나거나 벽(6)을 만나면 더 이상 진행 불가
        if(OOB(x, y) || board2[x][y] == 6) return;

        // 빈칸이 아니면(다른 CCTV거나 이미 감시된 칸이면) 그냥 통과
        // CCTV는 벽이 아니므로 감시선이 지나갈 수 있다.
        if(board2[x][y] != 0) continue;

        // 빈칸이면 감시된 칸으로 표시
        board2[x][y] = 7;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // 최솟값 저장 변수
    // 처음에는 "빈칸의 총 개수"로 시작
    // 이후 더 작은 사각지대가 나오면 갱신
    int mn = 0;

    // 입력 받기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board1[i][j];

            // 1~5는 CCTV, 6은 벽, 0은 빈칸
            // CCTV이면 좌표를 따로 저장
            if(board1[i][j] != 0 && board1[i][j] != 6)
                cctv.push_back({i, j});

            // 빈칸 개수 세기
            if(board1[i][j] == 0) mn++;
        }
    }

    // CCTV가 k개라면, 각 CCTV는 방향을 4가지 중 하나로 잡을 수 있다고 보고
    // 총 4^k 가지 경우를 전부 탐색한다.
    //
    // 4^k = (2^2)^k = 2^(2k) = 1 << (2*k)
    for(int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++){

        // 매 경우마다 board2를 원본 board1으로 초기화
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                board2[i][j] = board1[i][j];

        // tmp를 4진수처럼 해석할 것이므로
        // 원본 tmp를 보존하기 위해 brute라는 복사본 사용
        int brute = tmp;

        // 각 CCTV에 대해 방향 결정
        for(int i = 0; i < cctv.size(); i++){
            // brute의 현재 4진수 한 자리 = 현재 CCTV의 방향
            int dir = brute % 4;
            brute /= 4;

            int x = cctv[i].X;
            int y = cctv[i].Y;

            // CCTV 종류에 따라 감시 방향이 다름

            if(board1[x][y] == 1){
                // 1번 CCTV: 한 방향만 감시
                upd(x, y, dir);
            }
            else if(board1[x][y] == 2){
                // 2번 CCTV: 서로 반대 방향 2개 감시
                // 예: 남+북, 동+서
                upd(x, y, dir);
                upd(x, y, dir + 2);
            }
            else if(board1[x][y] == 3){
                // 3번 CCTV: 직각 방향 2개 감시
                // 예: 남+동, 동+북, 북+서, 서+남
                upd(x, y, dir);
                upd(x, y, dir + 1);
            }
            else if(board1[x][y] == 4){
                // 4번 CCTV: 세 방향 감시
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            }
            else{
                // 5번 CCTV: 네 방향 모두 감시
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }

        // 현재 경우에서 사각지대(아직 0인 칸) 개수 세기
        int val = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                val += (board2[i][j] == 0);

        // 최솟값 갱신
        mn = min(mn, val);
    }

    cout << mn;
}