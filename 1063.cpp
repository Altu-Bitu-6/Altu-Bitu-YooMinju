#include <iostream>
#include <vector>

using namespace std;
//위치의 좌표값을 저장하는 타입 선언
typedef pair<char, char> pos;

//이동 함수 -> 4가지만 만들고 조합하면 8가지 이동 가능
pos move(string cmd, char x, char y){
    
    //명령어의 알파벳을 하나하나 비교하는 조건문
    for (char how: cmd){
        //R이 들어가면 x좌표 1 증가
        if (how == 'R'){
            x++;
        }
        //L이 들어가면 x좌표 1 감소
        else if (how == 'L'){
            x--;
        }
        //B가 들어가면 y좌표 1 감소
        else if (how == 'B'){
            y--;
        }
        //T이 들어가면 y좌표 1 증가
        else {
            y++;
        }
    }
    //결과값 리턴
    return make_pair(x,y);
}

//위치가 겹치는 지 확인하는 함수
bool isSame(pos k, pos s){
    //좌표가 동일하면 true 반환
    return (k.first == s.first && k.second == s.second);
}

//격자판 범위를 넘어서는지 확인하는 함수
bool checkRange(pos p){
    //x좌표가 A와 H 사이에 없거나 y좌표가 1과 8 사이에 없다면
    if (p.first < 'A' || p.first > 'H' || p.second < '1' || p.second > '8') {
        //벗어난 것이므로 false 리턴
        return false;
    }
    //통과했다면 격자판 내에 있는 것이므로 true 리턴
    return true;
}
int main(){

    pos k, s; //king과 stone 위치
    int n; //횟수
    string cmd; //명령어- 길이 가변이므로 str로 맡기

    //입력
    cin >> k.first >> k.second >> s.first >> s.second >> n;

    //처리
    while(n--){
        cin >> cmd;

        pos next_k, next_s; //예상 위치

        //king 예상 이동 좌표
        next_k = move(cmd, k.first, k.second);
        //stone 예상 이동 좌표 -> king과 겹칠 경우만 이동하게끔
        if (isSame(next_k, s)) {
            //겹치는 경우 똑같은 방향으로 이동
            next_s = move(cmd, s.first, s.second);
            
        } else {
            //안겹친다면 이동 안하고 유지
            next_s = s;
        }
        //체스판 범위 확인 후 이동
        if (checkRange(next_k) && checkRange(next_s)) {
            //격자판 내에 모두 있는 경우 실제값인 k, s에 이동한 위치 저장
            k = next_k;
            s = next_s;
        }
    }
    //출력
    cout << k.first << k.second << '\n' << s.first << s.second;

    return 0;
}