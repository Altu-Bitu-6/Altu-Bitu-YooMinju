//비트마스크
//공집합 배열을 n개만큼 만들고 추가하려함 -> 21개짜리 배열을 만들고 1, 0으로 표시 -> int 비트마스크로 처리
#include <iostream>
#include <string>

using namespace std;

int calc(string cmd, int x, int& S){
    //return값을 위한 선언 및 초기화
    int res = -1;

    if(cmd == "add"){
        //S와 or 연산
        S = S | (1<<x);
    }

    else if(cmd == "remove"){
        //입력숫자 반대와 and 연산
        S = S & ~(1<<x);
    }

    else if(cmd == "check"){
        //있으면 (and 연산)
        if(S & (1<<x)){
            res = 1;
        }
        else{
            res = 0;
        }
    }

    else if(cmd == "toggle"){
        //있으면 제거
        if (S & (1<<x)){
            S = S & ~(1<<x);
        }
        //없으면 추가
        else{
            S = S | (1<<x);
        }
    }

    else if(cmd == "all"){
        //전체선택 -> 이해 안됨
        S = (1<<21) - 1;    
    }

    else if(cmd == "empty"){
        //초기화
        S = 0;
    }

    return res;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string cmd = "";
    int M, x, res;
    int S = 0;

    cin >> M;

    while(M--){
        cin >> cmd;
        
        //기존: 한꺼번에 입력받음 but all과 empty의 경우 수가 없다 -> 조건 나눔
        if (cmd == "all" || cmd == "empty") {
            //txt로만 명령어가 구성된 경우
            x = 0;
        } else {
            //x 입력받기
            cin >> x;
        }
        
        res = calc(cmd, x, S);
        //음수가 아니라면 -> check 명령어 입력
        if (res >= 0){
            cout << res << "\n";
        }
    }

    return 0;
}