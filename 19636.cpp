//입력 1: before_w(체중), before_in, meta(일일섭취량, 기초대사량), t(기초대사량 변화 역치)
//입력 2: day, diet_in(일일 에너지 섭취량), diet_act(일일 활동 대사량)

//BEFORE_A = 0
//diff = diet_in - (meta + diet_act)

//체중 1: before_w + (diff) * (day)
       //if < 0 : "Danger Diet"
//체중 2: change_meta
    // if |diff| > t -> meta += diff/2 -> if meta < 0 = "Danger Diet"

    //yoyo_diff = before_in - (meta + BEFORE_A) > 0 -> yoyo

//출력 1: 일일 기초대사량 변화 X - static_w, static_l / if 사망 예상 - "Danger Diet"
//출력 2: 일일 기초대사량 변화 고려 - change_w, change_l, yoyo(요요 여부) / if 사망 예상 - "Danger Diet"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main(){
    
    //변수 선언
    int w0, before_in, t, day, diet_in, diet_act;
    int BEFORE_ACT = 0;
    
    //입력
    cin >> w0 >> before_in >> t;
    cin >> day >> diet_in >> diet_act;

    //1: 기초대사량 고려 X
    int meta = before_in;
    int w1 = w0;
    w1 += (diet_in - (meta + diet_act)) * day;
    
    if (w1 <= 0)
        cout << "Danger Diet\n";
    else
        cout << w1 << " " << before_in << "\n";

    //2: 기초대사량 고려 O
    int w2 = w0;
    //기초대사량 고려
    int change_meta = before_in;
    while (day--) {
        w2 += diet_in - (change_meta + diet_act);
        if (abs(diet_in - (change_meta + diet_act)) > t) {
            change_meta += floor((float)(diet_in - (change_meta + diet_act)) / 2);
        }
    }
    if (w2 <= 0 || change_meta <= 0)
        cout << "Danger Diet\n";
    
    //요요 계산
    else {
        cout << w2 << " " << change_meta << " ";
        if (before_in - (change_meta + BEFORE_ACT) > 0)
            cout << "YOYO";
        else
            cout << "NO";
    }
}