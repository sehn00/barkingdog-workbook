// https://www.acmicpc.net/problem/15683
// https://0m1n.tistory.com/115

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[8][8];                     // 사무실 상태
vector<pair<int, int>> cctv;       // CCTV 좌표 저장
int ans = 987654321;               // 사각지대 최소값

int dx[4] = {0, -1, 0, 1}; // 우, 상, 좌, 하
int dy[4] = {1, 0, -1, 0};

// (x, y)의 CCTV가 dir 방향을 감시하도록 표시
void check(int x, int y, int dir){
    dir %= 4;

    while(1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;

        // 범위를 벗어나거나 벽을 만나면 종료
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;
        if(arr[nx][ny] == 6) return;

        // CCTV나 이미 감시된 칸이면 지나감
        if(arr[nx][ny] != 0) continue;

        // 빈 칸이면 감시 표시
        arr[nx][ny] = -1;
    }
}

// idx번째 CCTV의 방향을 정하는 DFS
// (idx번째 cctv에 대해 가능한 방향 전부 시도하는 함수)
void dfs(int idx){
    
    // 종료 조건 -> 모든 CCTV 방향을 다 정했으면 사각지대 개수 계산
    if(idx == cctv.size()){
        int cnt = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(!arr[i][j]) cnt++;

        ans = min(ans, cnt);
        return;
    }

    int x = cctv[idx].first;
    int y = cctv[idx].second;
    int tmp[9][9];

    // 현재 idx의 CCTV를 4방향으로 돌려보며 전부 탐색
    for(int dir = 0; dir < 4; dir++){

        // 현재 상태 백업
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                tmp[i][j] = arr[i][j];

        // CCTV 종류에 따라 감시 방향 처리
        if(arr[x][y] == 1)
            check(x, y, dir);
        else if(arr[x][y] == 2){
            check(x, y, dir);
            check(x, y, dir + 2);
        }
        else if (arr[x][y] == 3){
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        else if (arr[x][y] == 4){
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2); 
        }
        else if (arr[x][y] == 5){
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        dfs(idx+1);

        // 다음 방향 경우를 위해 원상복구
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                arr[i][j] = tmp[i][j];
    }    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    // 입력 받으면서 CCTV 좌표 저장
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j] != 0 && arr[i][j] != 6)
                cctv.push_back({i, j});
        }
    }

    dfs(0);
    cout << ans << '\n';

    return 0;
}