//탑다운 방식
//마지막 계단을 밟는 경우 - 2가지
    //1. 2칸 전의 계단을 밟고 마지막 계단을 밟는 경우
    //2. 1칸 전의 계단을 밟고, 3칸 전의 계단을 밟는 경우

//0, 1, 2 까지는 따로 계산


#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

//변수 미리 선언
int stair[301];
int dp[301];

void maxScore(int n){
    
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[3]+stair[1], stair[3]+stair[2]);
    
    //4부터는 식이 성립 가능
    for(int i = 4; i <= n; i++){
        dp[i] = max(stair[i]+dp[i-2], stair[i]+stair[i-1]+dp[i-3]);
    }

}


int main(){
    //계단 입력
    int n, s;    
    cin >>  n;
    
    //1번째 계단부터 시작이므로 idx 0은 비워놓기
    for(int i = 1; i <= n; i++){
        cin >> stair[i];
    }
    
    //계단 점수 계산
    maxScore(n);
    
    //출력
    cout << dp[n];

    return 0;
}