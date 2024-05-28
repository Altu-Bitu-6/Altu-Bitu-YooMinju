#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;

//최대 길이 탐색 함수
//low = 1, high = max_snack
//중앙값의 길이로 모두에게 나눠줄 수 없다면 줄이고, 있다면 늘리기
int binarySearch(vector<int> &snack){
    int left, right, mid, total;
    left = 1;
    right = snack[m-1]; //맨 끝 값이 최대 과자 길이

    while (left <= right){
        mid = (left+right)/2;
        total = 0;
        for(int i = 0; i < m; i++){
            total += snack[i] / mid;
        } //현재 중앙값 길이로 나눴을 때 조카보다 부족하게 나눠줄 수 있다면 최대값을 작게 조정
        if (total < n){
            right = mid - 1;
        } //같거나 넘친다면 최소값을 크게 조정
        else {
            left = mid + 1;
        }
    }
    
    //마지막에 부족하게 나눠주는 상황으로끝났을 경우 - mid - 1
    if (total < n){
        mid -= 1;
    }
    //중앙 길이 값이 최대 길이
    return mid;
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    //n - 조카 수, m - 과자 수
    cin >> n >> m;
    vector<int> snack(m);

    for(int i = 0; i < m; i++){
        cin >> snack[i];
    } //과자 길이 입력 끝

    //정렬
    sort(snack.begin(), snack.end());
    
    //최대길이 탐색
    int maxLength = binarySearch(snack);

    cout << maxLength;

    return 0;
}