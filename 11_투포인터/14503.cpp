#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, r, c, d;
int arr[52][52];
int check[52][52];

//방향 정의 {북, 동, 남, 서}
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

//현재 위치에서 청소하고 - 모두 막히면 1)벽이 아니면 후진 2) 벽이면 종료
//청소 - 4방향 탐색 - 빈곳이면 새로운 방향
int clean(){
    int cnt = 0;

    while(true){
        //현재 위치 청소
        if (check[r][c]==false){
            check[r][c] = true;
            cnt += 1;
        }
        
        //4방향 탐색하면서 청소 안한 곳 청소하기
        bool blank = true;
        for(int i = 0; i < 4; i++){
            d = (d+3) % 4;
            int cx = r + dx[d];
            int cy = c + dy[d];
            //빈공간 있을 경우 청소 (check 판 조건 추가)
            if (arr[cx][cy] == 0 && check[cx][cy] == false){
                    r += dx[d]; c += dy[d];
                    blank = false;
                    break;
                }
            } 
            if (blank){
                int b = (d+2) % 4;
                //벽 만났을 경우
                if (arr[r+dx[b]][c+dy[b]] == 1){
                    break;
                }
                //갱신
                r += dx[b]; c += dy[b];
            }
            
    }

    return cnt;
}

int main(){
    //입력
    //방 크기 (n*m)
    cin >> n >> m;
    //좌표(r,c), 방향(d)
    cin >> r >> c >> d;

    //방 입력
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    cout << clean();

    return 0;
}