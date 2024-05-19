#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//양방향 참조가 가능한 deque - 뱀
//게임이 끝나는 시간(초) 구하기
//방향 전환 정보 저장 - try 1: pair -> 참조 어려움 / try 2: 배열에 인덱스로 참조할 수 있도록 저장

//보드판
int board[101][101];
int now_here[101][101];
//뱀 방향 전환 정보 저장
char control[10001];

//방향 인덱스
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

/* 게임 플레이하는 함수
    반복하면서 시간 증가
    반복문 탈출조건 (벽 터치, 자기자신 터치)
 */
int playGame(int N){
    //뱀의 위치를 위한 deque
    //(행, 열) 정보를 저장
    deque<pair<int, int>> snake;

    //뱀의 처음 위치
    snake.push_back({1,1});
    now_here[1][1] = 1;
    //처음 시간과 위치
    int sec = 0; int dir = 0;

    while(true){
        sec++;

        int next_x = snake.back().first + dx[dir];
        int next_y = snake.back().second + dy[dir];

        //탈출 조건 (벽 부딪히기)
        if (next_x < 1 || next_x > N || next_y < 1 || next_y > N) {
            break;
        }

        //방향 변경 조건
        if (control[sec] == 'D'){
            dir = (dir + 1) % 4;
        }
        if (control[sec] == 'L'){
            dir = ((dir - 1) + 4) % 4;
        }

        //사과 체크
        if (board[next_x][next_y] == 1){
            board[next_x][next_y] == 0;
        } else {
            //꼬리 없애기
            now_here[snake.front().first][snake.front().second] = 0;
            snake.pop_front();
        }

        //이동 후의 위치에 원래 몸통이 있었다면 break
        if (now_here[next_x][next_y] == 1){
            break;
        } else {
            now_here[next_x][next_y] == 1;
        }
    }

    return sec;
}

int main(){

    int N, K, x, y, L, X;
    char C;

    //보드판 사이즈
    cin >> N;
    //사과의 개수
    cin >> K;

    //사과 위치 입력
    for(int i = 0; i < K; i++){
        cin >> x >> y;
        board[x][y] = 1;
    }

    //뱀의 방향 변환 횟수
    cin >> L;
    for (int i = 0; i < L; i++){
        cin >> X >> C;
        direction.push_back(make_pair(X, C));
    }
    
    
    cout << playGame(N);

    return 0;
}
