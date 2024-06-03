#include <iostream>
#include <algorithm>

using namespace std;
int n, k;

/*이 부분을 main과 findMaxLen 안에 넣었을 때는 OutofBound 에러가 발생했는데, 전역변수로 바꾸니 해결되었습니다..! 왜 그런건가요?
*/
int arr[200001];
int check[100001];


//투포인터 구현
int findMaxLen(){
    //정답 저장
    int result = 0;
    //투포인터 설정
    int start = 0;
    int end = 0;
	
    //end가 끝까지 탐색할 때까지
	while (end < n) {
        //k개 미만이라면 계속 뒤로 증가
		if (check[arr[end]] < k) {
			check[arr[end]]++;
			end++;
		}
        //마지막 수가 k개라면 수열에서 하나씩 뺀 다음 start 증가하며 하나씩 앞당기기
		else {
			check[arr[start]]--;
			start++;
		}
		result = max(result, end-start);
	}

    return result;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    
    //입력
    cin >> n >> k;
    //수열 입력받기
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //최장 연속 부분 수열 길이 출력하기
    cout << findMaxLen();

    return 0;
}