#include <iostream>
#include <vector>
#include <algorithm>

typedef vector<vector<int>> matrix;
const int SIZE = 20;
//방향을 검사하는 벡터 - x좌표와 y좌표로 나눔
const vector<int> dx = {-1, 0, 1, 1};
const vector<int> dy = {1, 1, 1, 0};

//범위와 돌의 종류가 유효한지 확인하는 함수
bool isValid(matrix &board, int x, int y, int color){
    //조건을 검사하는 함수
    //보드판 벗어나지 않는지
    return (x>0 && x<SIZE && y>0 && y<SIZE && board[x][y] == color);
}


bool checkWin(matrix &board, int x, int y){
    //기준 색
    int color = board[x][y];
    //4방향 검사
    for (int idx = 0; idx < 4; idx++){
        int cnt = 1;
        //탐색하려는 좌표의 반대방향
        int px = x - dx[idx];
        int py = y - dy[idx];
        //탐색 좌표의 다음 좌표
        int nx = x + dx[idx];
        int ny = y + dy[idx];

        //유효한 지 검사한 뒤 패스
        if (isValid(board, px, py, color)){
            continue;
        }

        //
        while (isValid(board, nx, ny, color) && cnt < 6){
            nx += dx[idx];
            ny += dy[idx];
            cnt++;
        }

        if(cnt == 5){
            return true;
        }

        return false;
    }
}
int main(){

    matrix board(SIZE, vector<int>(SIZE, 0));

    //1번부터 시작하는 바둑판 입력
    for(int i = 1; i <SIZE; i++){
        for (int j = 1; j <SIZE; j++){
            cin >> board[i][j];
        }
    }
    //연산 및 출력
    for(int i = 1; i <SIZE; i++){
        for (int j = 1; j <SIZE; j++){
            //빈칸이면 패스하고
            if (board[i][j] == 0){
                continue;
            }
            //해당 좌표부터 연속적으로 5알이 놓였다면 정답
            if (checkWin(board, i, j)){
                cout << board[i][j] << '\n' << i << ' '<< j;
            }
        }
    }

    //결과 미정이라면 0 출력
    return 0;
}