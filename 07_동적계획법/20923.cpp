//n - 카드개수, m - 게임 횟수
//함수
    //1: checkBell - 종을 칠 때의 인덱스 전달 -> 도도가 카드를 전부 가질 때 or 수연이가 카드를 전부 가질때로 나누어 카드 추가 및 삭제
    //2: checkWin - m번의 횟수가 끝나고 승자를 가리는 함수

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,d,s; //입력변수
vector<int> dodo, suyeon; //도도와 수연이의 카드 (전역변수로 선언)

//수연이가 종을 쳤을 경우의 카드 이동
void suyeonBell(int idx){
    //카드 가져가기
    suyeon.insert(suyeon.end(), dodo.begin(), dodo.begin()+idx+1);
    suyeon.insert(suyeon.end(), suyeon.begin(), suyeon.begin()+idx+1);

    //카드 삭제
    dodo.erase(dodo.begin(), dodo.begin()+idx+1);
    suyeon.erase(suyeon.begin(), suyeon.begin()+idx+1);
}

//도도가 종을 쳤을 경우의 카드 이동
void dodoBell(int idx){
    //카드 가져가기
    dodo.insert(dodo.end(), suyeon.begin(), suyeon.begin()+idx+1);
    dodo.insert(dodo.end(), dodo.begin(), dodo.begin()+idx+1);

    //카드 삭제
    dodo.erase(dodo.begin(), dodo.begin()+idx+1);
    suyeon.erase(suyeon.begin(), suyeon.begin()+idx+1);
}

//승자 확인
string checkWin(){
    
    string s;

    if (dodo.size() > suyeon.size()){
        s = "do";
    }
    if (dodo.size() < suyeon.size()){
        s = "su";
    }
    if (dodo.size() == suyeon.size()){
        s = "dosu";
    }

    return s;
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
    for (int j = 0; j < m; j++) {
        //빈 벡터인지 확인
        if (dodo.empty()){
            cout << 'su';
        } else if (suyeon.empty()){
            cout << 'do';
        }
        //모두 카드가 있다면 게임 시작
        else {
            //수연이가 종을 치는 경우
            if ((dodo[j]+suyeon[j]) == 5){
                suyeonBell(j);
            }
            //도도가 종을 치는 경우
            else if (dodo[j] == 5 || suyeon[j] == 5){
                dodoBell(j);
            }
        }
    }

    //게임이 끝난 뒤
    string result = checkWin();
    //출력
    cout << result;
}