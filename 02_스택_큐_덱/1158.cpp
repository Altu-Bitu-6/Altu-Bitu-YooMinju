#include <iostream>
#include <queue>

using namespace std;

string deleteK(queue<int>& circle, int k){
    
    string ans = "";
    //size가 0이 되기 전까지 반복
    while (circle.size() > 0) {
        //k-1번째 까지 앞 자리 숫자를 뒤로 밀고, k번째 숫자 제거
        for (int i = 1; i < k; i++) {
            circle.push(circle.front());
            circle.pop();
        }
        ans += to_string(circle.front());
        //마지막이 아니라면 반점 추가
        if (circle.size() > 2){
            ans += ", ";
        }
        circle.pop();
    }

    return ans;
}
int main(){
    int n, k;
    cin >> n >> k;

    queue<int> circle;
    
    //원에 차례대로 입력
    for (int i = 1; i <= n; i++){
        circle.push(i);
    }
    
    cout << "<";

    //함수 사용
    string ans = deleteK(circle, k);

    cout << ans << ">";

    return 0;

}