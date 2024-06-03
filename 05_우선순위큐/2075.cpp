//n개의 힙(min heap?) - 1번째 큰 수부터 n번째 큰 수까지 내림차순으로 정렬하도록
//만약 n개 이상으로 들어와야할 수가 있다면.. 제일 작은 숫자를 Pop하고 다시 추가 -> 큰 수대로 정렬될 수 있도록
#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int n, input;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> >min_heap;
    
    //처리
    for(int i = 0; i < n*n; i++){
        cin >> input;
        min_heap.push(input);
        if (min_heap.size() > n){
            min_heap.pop();
        }
    }
    
    //출력
    cout << min_heap.top();
    
    return 0;
}