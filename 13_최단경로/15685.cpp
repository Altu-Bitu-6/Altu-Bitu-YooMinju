#include <iostream>
#include <vector>
#include <deque>

using namespace std;
//좌표 저장용 자료형 (j, i)
typedef pair<int, int> ii;
//좌표 저장용 보드판
vector<vector<int>> board(101, vector<int>(101, 0));


//드래곤 커브 개수 계산하는 함수
//네 칸이 모두 1이면 드래곤 커브
int calcDragonCurve(){
    //정답 담을 변수
    int ans = 0;
    //보드판 순회
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            //2*2 모두 1이면
            if (board[i][j] == 1 && board[i][j+1] == 1
                && board[i+1][j+1] == 1 && board[i+1][j] == 1){
                    //개수 추가
                    ans++;
                }
        }
    }

    return ans;
}

//드래곤 커브 그리는 함수
void dragonCurve(deque<ii> &dq, int g){
    //세대만큼 반복하며 드래곤 커브 그리기
    for (int i = 0; i < g; i++){
        //덱의 끝 좌표 기준으로 시계방향으로 회전된 좌표 계산
        
        //덱의 끝 좌표
        int ei = dq.back().first; int ej = dq.back().second;
        
        //맨 끝 이전의 좌표부터 처음까지 반복
        //시계방향 회전을 완료한 좌표 추가
        // j 증가 -> i 감소, j 감소 -> i 증가 => j에 따라 i는 반비례 (차이 빼기)
        // i 증가 -> j 증가, i 감소 -> j 감소 => i에 따라 j는 비례 (차이 더하기)

        for (int j = dq.size()-2; j >= 0; j--){
            //회전 대상이 되는 curr 좌표
            int ci = dq[j].first; int cj = dq[j].second;
            //회전 완료한 finish 좌표
            int fi = ei - (ej-cj); int fj = ej + (ei-ci);
            //회전 완료 좌표를 덱에 추가하기
            dq.push_back(make_pair(fi, fj));
        }
    }

    //덱의 좌표들을 보드판에 표기
    for (int i = 0; i < dq.size(); i++){
        board[dq[i].first][dq[i].second] = 1;
    }
}


int main(){
    //입력
    int N, x, y, d, g;
    //방향 정보: 우, 상, 좌, 하
    int di[4] = {0, -1, 0, 1};
    int dj[4] = {1, 0, -1, 0};
    //드래곤 커브 개수
    cin >> N;
    //드래곤 커브 정보 입력 및 연산
    for (int i = 0; i < N; i++){
        //시작좌표, 방향, 세대 정보 입력
        cin >> x >> y >> d >> g;
        //드래곤 커브의 좌표 저장할 벡터 초기화
        deque<ii> lst_coord;
        //시작 좌표 추가
        lst_coord.push_back(make_pair(y, x));
        //방향에 따라 0세대 좌표 추가
        lst_coord.push_back(make_pair(y + di[d], x + dj[d]));
        //세대 수만큼 드래곤 커브 그리는 함수
        dragonCurve(lst_coord, g);
    }

    //드래곤 커브 개수 구하고 출력
    cout << calcDragonCurve();

}