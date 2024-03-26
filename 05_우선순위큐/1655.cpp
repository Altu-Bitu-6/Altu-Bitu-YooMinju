//가운데를 말해요
//try 1: 큰 수 작은수를 비교해서 small,big으로 만들기 -> 비교할 방법 없음
//작은 수를 저장하는 small
//큰 수를 저장하는 big

//if small.size()-big.size() == 0 -> small 에 push
//                           == 1 -> big에 push
//실패!

//try 2: 숫자간의 크기 비교는 하지 않고 개수로 비교할 것
    //그냥 개수가 1개 차이나면 max에 넣고 -> 균일하게 맞춰줌
//저장된 위치가 맞는지 확인하는 것 
    //-> 각 힙의 top끼리 비교한 다음 max_heap.top()이 항상 min_heap.top()보다 작게 유지

#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    //힙 2개 생성
    priority_queue<int, vector<int>, greater<int> >min_heap; //최소 힙
    priority_queue<int> max_heap; //최대 힙

    //횟수 입력
    int n, i, middle;
    cin >> n;
    
    //처리 및 출력
    while (n--) {
        cin >> i;
        
        //max_heap 사이즈가 항상 1씩 커야함 -> 작거나 같으면 max로 push
        if (max_heap.size() <= min_heap.size()){
            max_heap.push(i);
        } else {
            min_heap.push(i);
        }
        
        //중간값 디폴트: max_heap.top()
        //2번째 이후: min_heap.size() > 0 -> top끼리 비교 필요 
        //항상 max_heap.top()이 min_heap.top()보다 더 작게 유지되어야 함
        if (min_heap.size() > 0) {
            if (max_heap.top() >= min_heap.top()){
                int tmp1 = max_heap.top();
                int tmp2 = min_heap.top();
                max_heap.push(tmp2);
                min_heap.push(tmp1);
                max_heap.pop();
                min_heap.pop();
            } 
        } 
        
        middle = max_heap.top();
        
        cout << middle << '\n';
    }
}