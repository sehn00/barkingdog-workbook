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

/*************************************************************

    < 손코딩 방식 >
    1. Top-Down 스케치
    - main() 함수의 뼈대 잡기
    - 구체적인 로직은 작성 x
    - "나중에 만들 함수의 이름만 호출"하면서 전체 시나리오 구상하기

    2. 인터페이스 정의
    - 방금 스케치한 함수들이 작동하려면
    - "어떤 파라미터"를 넘겨야 하고, "어떤 리턴값"을 뱉어야 하는지
    - 함수의 프로토타입만 적어놓기

    3. Bottom-up 구현
    - 각각의 작은 함수들 내부의 로직 채우기

    --------

[Main Logic]

1. 입력 받기 (N, M, K)
2. K번 반복 (스티커 하나씩 처리):
    입력 받기 (r, c, paper)
    
    bool is_paste = false; // 이번 스티커 붙였는지 체크
    
    3. 4방향 시도 (rot = 0, 1, 2, 3):
        // 노트북의 어디에 붙일 수 있을지 탐색
        // 주의: 스티커가 노트북을 벗어나면 안 되니까 범위 제한!
        for x: 0 부터 (N - r) 까지:
            if is_paste == true: break (이미 붙였으면 y루프 컷)
            
            for y: 0 부터 (M - c) 까지:
                if pastable(x, y) == true:
                    is_paste = true;
                    break; // 찾아서 붙였으니 y루프 탈출
        
        // 4. 방향 하나에 대해 탐색이 끝난 후
        if is_paste == true:
            break; // 현재 스티커 다음으로 넘어감 (방향 루프 탈출)
        else:
            rotate(); // 못 붙였으니 90도 회전하고 다시 탐색!

5. 모든 스티커 반복 종료 후
   note 배열 쫙 돌면서 1인 칸(cnt) 개수 세서 출력.

// ***********************************************************

[pastable(x, y) Logic]

// x, y는 노트북에서 스티커의 왼쪽 위(0, 0)가 위치할 기준 좌표.

// 1단계: 충돌 검사
for i: 0 부터 r-1 까지
    for j: 0 부터 c-1 까지
        // 노트북의 (x+i, y+j) 위치를 확인.
        // 만약 노트북에도 이미 스티커가 붙어있고(1) AND 
        // 현재 붙이려는 스티커의 해당 칸도 색칠되어 있다면(1):
        if (note[x+i][y+j] == 1) AND (paper[i][j] == 1):
            return false; // 단 한 칸이라도 겹치면 즉시 실패 반환!

// 2단계: 스티커 붙이기
for i: 0 부터 r-1 까지
    for j: 0 부터 c-1 까지
        // 스티커 배열에서 색칠된 부분(1)만 노트북에 옮겨 적는다.
        if paper[i][j] == 1:
            note[x+i][y+j] = 1;

return true; // 성공적으로 붙였음을 main 함수에 알림!

*************************************************************/