//n - 카드개수, m - 게임 횟수
//함수
    //1: checkBell - 종을 칠 때의 인덱스 전달 -> 도도가 카드를 전부 가질 때 or 수연이가 카드를 전부 가질때로 나누어 카드 추가 및 삭제
    //2: checkWin - m번의 횟수가 끝나고 승자를 가리는 함수

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

//도도와 수연이의 덱을 하나로 묶어주는 카드 벡터 선언
typedef vector<deque<int>> cards; //도도 - 0 / 수연 - 1
//많이 사용하는 값을 상수로 선언
const int DO = 0, SU = 1;

//승리 판단하기
string judge(cards& deck){

    //사이즈 비교를 위한 변수 생성
    int do_deck = deck[DO].size();
    int su_deck = deck[SU].size();
    //도도의 덱 개수가 더 많으면 do
    if (do_deck > su_deck){
        return "do";
    }
    //수연의 덱 개수가 많으면 su
    else if(su_deck > do_deck){
        return "su";
    }
    //같다면 비긴 것이므로 dosu
    return "dosu";
}
//그라운드에서 덱으로 카드 이동하는 함수
void groundToDeck(deque<int>& deck, deque<int>& ground){
    //그라운드가 빌 때까지
    while (!ground.empty()){
        //그라운드의 뒤에서 덱 뒤로 이동(뒤집어서 옮기므로) -> 이후 그라운드에서 제거
        deck.push_back(ground.back());
        ground.pop_back();
    }
}
//종을 쳤을 때
void ringTheBell(int player, cards& deck, cards& ground){
    //플레이어가 아닌 사람의 그라운드를 플레이어 덱으로 이동
    groundToDeck(deck[player],ground[!player]);
    //플레이어의 그라운드를 플레이어 덱으로 이동
    groundToDeck(deck[player], ground[player]);
}

//종을 칠 수 있는지 검사
int whoCanRingTheBell(cards& deck, cards& ground){
    //도도가 종을 칠 떄
    //도도의 그라운드가 비어있지 않고 카드 5 낼 때
    if (ground[DO].size() && ground[DO].front() == 5) {
        return DO;
    }
    //수연의 그라운드가 비어있지 않고 카드 5 낼 때
    if (ground[SU].size() && ground[SU].front() == 5) {
        return DO;
    }

    //수연이가 종을 칠 때
    //두 그라운드가 모두 비어있지 않고 두 카드 숫자의 합이 5일 때
    if (!ground[DO].empty() && !ground[SU].empty() && ground[DO].front() + ground[SU].front() == 5){
        return SU;
    }

    //위의 경우 모두 아니라면 -1 반환하여 패스
    return -1;
    
}

//게임 진행 함수
string game(int m, cards& deck, cards& ground){
    
    //도도부터 게임 시작
    bool turn = DO;
    //m회의 턴 진행
    while(m--){
        //1. 카드 그라운드에 한 장 놓기
        ground[turn].push_front(deck[turn].front());
        //그라운드로 이동했으므로 덱에서는 삭제 (***놓친 부분)
        deck[turn].pop_front();

        //카드덱이 빈 경우 게임 중단
        if (deck[turn].empty()){
            break;
        }

        //2. 누가 종을 칠 수 있는지 검사 (0: 도도, 1: 수연, -1: 종치기 불가)
        int bell = whoCanRingTheBell(deck, ground);
        //3. 종을 친 경우 모두의 그라운드의 카드를 종 친 사람의 덱으로 옮기기
        if (bell != -1){
            ringTheBell(bell, deck, ground);
        }
        
        //4. 턴 교체
        turn = !turn;
    }
    
    //승자 및 출력결과 체크
    string result = judge(deck);
    return result;
}


int main(){
    
    //변수 선언
    int n, m, card1, card2;
    //카드 덱과 그라운드 선언
    cards deck(2), ground(2);
    
    //입력받기
    cin >> n >> m;
    
    //덱 생성
    for (int i = 0; i < n; i++){
        cin >> card1 >> card2;
        //앞쪽부터 카드 배열
        deck[DO].push_front(card1);
        deck[SU].push_front(card2);
    }
    
    //게임 진행
    string winner = game(m, deck, ground);
    
    //출력
    cout << winner;
    
    return 0;
}