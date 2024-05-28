#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;

//deque - 뱀
//게임이 끝나는 시간(초) 구하기
//방향 전환 정보 저장 - try 1: pair -> 참조 어려움 / try 2: 배열에 인덱스로 참조할 수 있도록 저장

//사과: 1, 뱀: 2
const int EMPTY = 0;
const int APPLE = 1;
const int SNAKE = 2;

/* 게임 플레이하는 함수
    반복하면서 시간 증가
    반복문 탈출조건 (벽 터치, 자기자신 터치)
 */
int playGame(int N, vector<vector<int>> &board, map<int, char> &cmd){

    //방향 인덱스
    int dx[4] = {0, -1, 0, 1}; //오, 하, 왼, 상
    int dy[4] = {1, 0, -1, 0};

    //뱀의 위치를 위한 deque
    //(행, 열) 정보를 저장
    deque<ci> snake;
    //뱀의 처음 위치를 벡터에 삽입 후, 보드판 변경
    snake.push_front({1,1});
    board[1][1] = SNAKE;

    //처음 시간과 위치
    int sec = 0; int dir = 0;

    while(true){
        //방향 변경 조건
        // 왼쪽 회전
        if (cmd[sec] == 'L'){
            dir = (dir + 1) % 4;
        }
        // 오른쪽 회전
        if (cmd[sec] == 'D'){
            dir = (dir + 3) % 4;
        }

        //시간 증가
        sec++;
        
        //다음 뱀의 머리 위치 칸(x,y) - 방향 배열 이용
        int next_x = snake.front().first + dx[dir];
        int next_y = snake.front().second + dy[dir];
        
        //반복문 탈출 조건
        //벽에 부딪히거나, 자기 자신의 몸에 부딪힐 때
        if (next_x < 1 || next_x > N || next_y < 1 || next_y > N || board[next_x][next_y] == SNAKE) {
            break;
        }

        //이동 - 다음칸에 머리를 위치시킴
        snake.push_front({next_x, next_y});
        //** 사과가 없을 때를 체크
        if (board[next_x][next_y] != APPLE){
            //꼬리를 다음칸에 위치시켜야 함
            //꼬리 위치 변수로 선언
            ci tail = snake.back();
            //board에서 삭제 - 0 삽입
            board[tail.first][tail.second] = EMPTY;
            //snake에서 꼬리 삭제
            snake.pop_back();
        }
        //board 값 변경 (** 사과 유무와 관련X)
        board[next_x][next_y] = SNAKE;
    }

    return sec;
}

int main(){

    int N, K, x, y, L, X;
    char C;

    //보드판 사이즈
    cin >> N;
    //보드판 생성
    vector<vector<int>> board(N+1, vector<int>(N+1, EMPTY));
    //사과의 개수
    cin >> K;
    //사과 위치 입력
    for(int i = 0; i < K; i++){
        cin >> x >> y;
        //보드판에 1로 표시
        board[x][y] = APPLE;
    }

    //뱀의 방향 변환 횟수
    cin >> L;
    map<int, char> cmd;
    while (L--) {
        cin >> X >> C; // 뱀의 방향 변환 정보
        cmd[X] = C;
    }
    
    //연산 및 출력
    cout << playGame(N, board, cmd);

    return 0;
}
