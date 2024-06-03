#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//matrix 타입과 사이즈 선언
typedef vector<vector<int>> matrix;
const int SIZE = 20;

//방향을 검사하는 벡터 - x좌표와 y좌표로 나눔
//맨 왼쪽 위 돌이 기준이므로 오른쪽/아래쪽 방향만 따지면 됨
const vector<int> dx = {-1, 0, 1, 1};
const vector<int> dy = {1, 1, 1, 0};

//범위와 돌의 종류가 유효한지 확인하는 함수
bool isValid(matrix &board, int x, int y, int color){
    //조건을 검사하는 함수
    //보드판 벗어나지 않는지, 색깔 동일한지
    return (x>0 && x<SIZE && y>0 && y<SIZE && board[x][y] == color);
}


bool checkWin(matrix &board, int x, int y){
    //기준 색
    int color = board[x][y];
    //4방향 검사
    for (int dir = 0; dir < 4; dir++){
        int cnt = 1;
        //탐색하려는 좌표의 직전 좌표
        int px = x - dx[dir];
        int py = y - dy[dir];
        //탐색 좌표의 다음 좌표
        int nx = x + dx[dir];
        int ny = y + dy[dir];


        //같은 방향에서 직전 돌이 같은 색이었다면 패스 -> 6개 이상 놓이는 걸 방지
        if (isValid(board, px, py, color)) {
            continue;
        }

        //같은 돌 5개가 있는지 검사 - 돌이 유효하고(같은 색깔이고) 6개가 되기 전까지 검사
        while (isValid(board, nx, ny, color) && cnt < 6){
            //좌표를 더하면서 같은 방향으로 검사 이어나감
            nx += dx[dir];
            ny += dy[dir];
            cnt++;
        }

        //5개 연속으로 놓였다면 오목 성공
        if(cnt == 5){
            return true;
        }  
    }

    //그 이외의 경우는 모두 실패
    return false; 
}
int main(){

    //보드판 정의
    matrix board(SIZE, vector<int>(SIZE, 0));

    //1번부터 시작하는 바둑판 입력
    for(int i = 1; i < SIZE; i++){
        for (int j = 1; j <SIZE; j++){
            cin >> board[i][j];
        }
    }
    //연산 및 출력
    for(int y = 1; y < SIZE; y++){
        for (int x = 1; x < SIZE; x++){
            //빈칸이면 패스하고
            if (board[x][y] == 0){
                continue;
            }
            //해당 좌표부터 연속적으로 5알이 놓였다면 정답
            if (checkWin(board, x, y)){
                cout << board[x][y] << '\n' << x << ' '<< y;
                //오목 결과를 출력하는 것이 목적이므로 
                //출력했다면 바로 리턴 후 종료
                return 0;
            }
        }
    }

    //결과 알 수 없다면 0 출력 후 리턴
    cout << "0";
    
    return 0;
}