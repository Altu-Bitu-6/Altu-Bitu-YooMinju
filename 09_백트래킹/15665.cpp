#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, m;
int ans[7];
set<int> num;

//정답을 프린트하는 함수
void printAns(){
    for(int i = 0; i < m; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    return;
}

//수열의 길이를 인자로 받아 재귀함수 실행
void backtrack(int length){
    
    //목표한 길이의 수열이 되었으면 출력
    if(length == m){
        printAns();
        return;
    }

    //set의 값에 접근한 뒤 재귀함수 호출
    for (auto it = num.begin(); it != num.end(); ++it){
        ans[length] = *it;
        backtrack(length+1);
    }
}

int main(){

    //조건과 수 입력받기
    cin >> n >> m;
    
    //중복없이 오름차순으로 정렬된 배열을 사용해야 하므로 set에 삽입
    int tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        num.insert(tmp);
    }
    
    /*
    cout << "잘 제거 되었나?\n";
    for (auto it = num.begin(); it != num.end(); it++) {
	    cout << *it << " ";
    }
    cout << "\n";
    */

    //백트래킹
    backtrack(0);

    return 0;
}