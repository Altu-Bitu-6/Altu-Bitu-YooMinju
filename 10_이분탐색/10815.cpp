#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int binarySearch(vector<int> &cards, int key, int n){
    //포인터 설정
    int left, right, mid;
    left = 0; right = n-1;

    //left가 right보다 클 때 반복 종료
    while (left <= right){
        //중앙포인터 계산
        mid = (left+right)/2;

        //찾고자 하는 값 key를 찾으면 1 반환
        if (cards[mid] == key){
            return 1;
        } //key가 더 크다면 왼쪽 포인터 이동 
        else if (cards[mid] < key){
            left = mid + 1;
        }
        else { //key가 작다면 오른쪽 포인터 이동
            right = mid - 1;
        }

    }

    //없는 경우 0 반환
    return 0;
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    
    int n, m, key;
    cin >> n;
    vector<int> cards(n);
    
    //카드 입력받기
    for(int i = 0; i < n; i++){
        cin >> cards[i];
    }
    //카드 정렬*** 중요!
    sort(cards.begin(), cards.end());

    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> key;
        cout << binarySearch(cards, key, n) << " ";
    }

    return 0;

}