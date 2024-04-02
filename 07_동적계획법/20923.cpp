//n - 카드개수, m - 게임 횟수
//함수
    //1: checkBell - 종을 칠 때의 인덱스 전달 -> 도도가 카드를 전부 가질 때 or 수연이가 카드를 전부 가질때로 나누어 카드 추가 및 삭제
    //2: checkWin - m번의 횟수가 끝나고 승자를 가리는 함수

#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;
int n,m,d,s; //입력변수
string result;
deque<int> dodo(n);
deque<int> suyeon(n);
deque<int> dodo_ground;
deque<int> suyeon_ground;

//카드 내려놓기
void putCard(bool turn){
    if (turn) {
        dodo_ground.push_back(dodo.back());
        dodo.pop_back();
    } else {
        suyeon_ground.push_back(suyeon.back());
        suyeon.pop_back();
    }
}

//수연이가 종을 쳤을 경우의 카드 이동
void suyeonBell(){
    //카드 가져가기
    //suyeon.insert(suyeon.end(), dodo.begin(), dodo.begin()+idx+1);
    //suyeon.insert(suyeon.end(), suyeon.begin(), suyeon.begin()+idx+1);

    //카드 삭제
    //dodo.erase(dodo.begin(), dodo.begin()+idx+1);
    //suyeon.erase(suyeon.begin(), suyeon.begin()+idx+1);
    
    while(dodo_ground.size() > 0){
        suyeon.push_front(dodo_ground.front());
        dodo_ground.pop_front();
    }
    while(suyeon_ground.size() > 0){
        suyeon.push_front(suyeon_ground.front());
        suyeon_ground.pop_front();
    }
}

//도도가 종을 쳤을 경우의 카드 이동
void dodoBell(){
    while(suyeon_ground.size() > 0){
        dodo.push_front(suyeon_ground.front());
        suyeon_ground.pop_front();
    }
    while(dodo_ground.size() > 0){
        dodo.push_front(dodo_ground.front());
        dodo_ground.pop_front();
    }
}

//승자 확인
string checkWin(){
    string str;

    if (dodo.size() > suyeon.size()){
        str = "do";
    }
    if (dodo.size() < suyeon.size()){
        str = "su";
    }
    if (dodo.size() == suyeon.size()){
        str = "dosu";
    }

    return str;
}

int main(){
    cin >> n >> m;
    
    
    //덱 생성
    for (int i = 0; i < n; i++){
        cin >> d >> s;
        dodo.push_back(d);
        suyeon.push_back(s);
    }

    //게임
    int cnt = 0;
    //dodo -> true / suyeon -> false
    bool turn = true;
    
    while (cnt <= m){
        cnt++;
        
        //카드 내려놓기
        putCard(turn);
        
        //빈 덱인지 확인
        if (dodo.empty()){
            result = "su";
            break;
        } else if (suyeon.empty()){
            result = "do";
            break;
        }

        //종 치는 경우 검사
        //수연이가 종을 치는 경우
        if (dodo_ground.size() && suyeon_ground.size() && dodo_ground.back()+suyeon_ground.back() == 5){
            suyeonBell();
        }
        //도도가 종을 치는 경우
        else if ((dodo_ground.size() && dodo_ground.back() == 5 )||(suyeon_ground.size() && suyeon_ground.back() == 5)){
            dodoBell();
        }
        
        //상대의 턴으로 변경
        turn = !turn;
    }
    

    if (cnt == m+1){
        result = checkWin();
    }
    //출력
    cout << result;
    
    return 0;
}