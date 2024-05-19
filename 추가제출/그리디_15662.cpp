#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;
vector<string> wheel;
vector<pair<int,int>> stack;
vector<int> visited;

//회전을 체크하는 함수
void check_rotation(int curr_n, int curr_dir){
    //왼쪽 바퀴 체크 (전 바퀴와 현재 바퀴)
    if (curr_n - 1 >= 0 && visited[curr_n-1] == 0){
        //전 바퀴와 현재 바퀴의 맞닿아 있는 면이 다르다면
        if (wheel[curr_n][6] != wheel[curr_n - 1][2]){
            //직전 바퀴가 반대로 회전해야함을 저장
            stack.push_back(make_pair(curr_n - 1, curr_dir * -1));
            //직전 바퀴 이미 작동했음을 표시
            visited[curr_n - 1] = 1;
            //직전 바퀴를 반대로 돌림
            check_rotation(curr_n - 1, curr_dir * -1);
        }
    }

    //오른쪽 바퀴 체크 (현재 바퀴와 다음 바퀴)
    if (curr_n + 1 < wheel.size() && visited[curr_n + 1] == 0){
        //맞닿아 있는 면이 다르다면 회전
        if (wheel[curr_n][2] != wheel[curr_n +1][6]){
            //다음 바퀴가 반대로 돌아야함을 저장
            stack.push_back(make_pair(curr_n + 1, curr_dir * -1));
            //다음 바퀴가 이미 작동했음을 표시
            visited[curr_n + 1] = 1;
            //다음 바퀴를 반대로 돌림
            check_rotation(curr_n + 1, curr_dir * -1);
        }
    }
}

int main(){

    int t, k;

    cin >> t;//톱니바퀴 개수
    //톱니바퀴 상태 입력
    for(int i = 0; i < t; i++){
        string num;
        //n극은 0, s극은 1
        cin >> num;
        //벡터에 스트링 저장
        wheel.push_back(num);
    }
    
    cin >> k; //회전 횟수
    //회전 방법 입력
    for (int i = 0; i < k; i++){
        //회전시킨 톱니바퀴 번호, 방향 입력
        //시계방향: 1, 반시계방향: -1
        int n, dir;
        cin >> n >> dir;
        
        //stack 초기화
        stack.clear();
        //회전 바퀴 번호(wheel idx가 0부터 시작하므로 1 빼기)와 방향 저장
        stack.push_back(make_pair(n - 1, dir));
        //t개만큼 0 초기화
        visited.assign(t, 0);
        //방문 등록
        visited[n-1] = 1;
        //회전 여부를 체크하는 함수 시행
        check_rotation(n-1, dir);

        while(!stack.empty()){
            //stack의 마지막 순서를 따로 저장
            pair<int, int> top = stack.back();
            //stack에서 삭제
            stack.pop_back();
            //돌려야 할 톱니바퀴 번호 지정
            int tmp_n = top.first;
            //회전 방향
            int tmp_dir = top.second;
            //1이라면 시계방향 돌리기
            if (tmp_dir == 1){
                //12시 바로 직전 글자가 12시 방향으로 오고, 나머지를 추출해서 뒤로 배치
                wheel[tmp_n] = wheel[tmp_n].back() + wheel[tmp_n].substr(0, 7);
            }
            //-1이라면 반시계방향으로 돌리기
            else {
                wheel[tmp_n] = wheel[tmp_n].substr(1) + wheel[tmp_n][0];
            }
        }
    }

    //12시 방향이 S극인 톱니바퀴 개수 체크
    int cnt = 0;
    //모든 톱니바퀴 검사
    for(int i = 0; i<t; ++i){
        //12시 방향은 인덱스가 0이므로 [0]이 S극인지 체크
        if (wheel[i][0] == '1'){
            cnt++;
        }
    }
    //출력
    cout << cnt;

    return 0;
}