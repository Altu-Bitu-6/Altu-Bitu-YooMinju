#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    queue<int> circle;
    
    //원에 차례대로 입력
    for (int i = 1; i <= n; i++){
        circle.push(i);
    }
    
    cout << "<";

    
    //size가 1이 되기 전까지 반복
    while (circle.size() > 1) {
        //k-1번째 까지 앞 자리 숫자를 뒤로 밀고, k번째 숫자 제거
        for (int i = 1; i < k; i++) {
            circle.push(circle.front());
            circle.pop();
        }
        cout << circle.front() << ", ";
        circle.pop();
    }

    cout << circle.front() << ">";

    return 0;

}