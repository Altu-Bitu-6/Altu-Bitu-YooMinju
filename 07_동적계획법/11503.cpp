//탑다운
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[1001], dp[1001];

int main(){
    
    //입력
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //증가하는 부분수열 계산하기
    int max_dp;
    int cnt = 1;
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        
        for(int j = 0; j < i; j++){
            if (arr[j] < arr[i]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        
    }
    
    int result= *max_element(dp,dp+n+1);
    cout << result;
   
}

/* 실패 코드
if (arr[i-1]<arr[i]){
    //현재 dp의 최댓값을 찾은 뒤 +1
    max_dp= *max_element(dp,dp+i-1);
    dp[i] = max_dp + 1;
    cnt++;
}
증가하는 수열이 아님, 수열 반영 불가
*/
