//완전 탐색
//현재 위치에서 움직일 수 있으면 재귀함수 호출
//끝에 도달할 수 있으면 1, 아니면 0

#include <iostream>
#include <string.h>

using namespace std;

int board[101][101];
int check[101][101]; //끝에 도달할 수 있는지 1, 0 을 체크하는 배열
int n;

int dp(int x, int y) {
    if (x >= n || y >= n) {
        return 0;
    }

    if (x == n - 1 && y == n - 1) { //끝에 도달한 것!
        return 1;
    }
 
    if (check[x][y] != -1) {  //이미 체크판에서 체크해두었다면 바로 해당값 리턴
        return check[x][y];
    }
 
    check[x][y] = (dp(x + board[x][y], y) || dp(x, y + board[x][y])); //재귀함수를 호출하여 말을 이동하는 과정   //오른쪽으로 진행            //아래로 진행
  
    return check[x][y];
}

int main() {
    int c;
    cin >> c;

    for (int t = 1; t <= c; t++) {
		memset(board, -1, sizeof(board)); //보드 배열 초기화
        memset(check, -1, sizeof(check)); //체크 배열 초기화

        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        } // 보드 데이터 입력

        int result = dp(0, 0); // 0,0 시작점에서 시작하여 목적지에 도달할 수 있는지 확인
        if (result) {
            cout << "YES\n"; // 도달 가능
        }
        else {
            cout << "NO\n"; // 도달 불가
        }
    }

    return 0;
}