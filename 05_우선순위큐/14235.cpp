//산타 선물보따리 = 우선순위 큐
//1) 선물주기
    //input이 0이라면
        //empty -> -1
        //else -> top & pop
//2) 충전하기
    //input이 0이 아니라면
    //a를 입력받고 a번동안 반복해서 push

#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int n, input, a, present;
    cin >> n;
    priority_queue<int> santa;
    
    //처리
    while(n--){
        cin >> input;
        //선물주기
        if(input == 0){
            //줄 게 없다면 -1
            if (santa.empty()){
                cout << -1 << "\n";
            }
            //선물이 있다면 우선순위 큰 것부터
            else {
                cout << santa.top() << "\n";
                santa.pop();
            }
        } 
        //충전하기
        else {
            //여기서 다시 a 입력받을 필요 X -> 받을 시 메모리 초과
            while(input--){
                cin >> present;
                santa.push(present);
            }
        }
        
    }
    return 0;
}