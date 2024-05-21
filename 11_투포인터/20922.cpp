#include <iostream>
#include <vector>

using namespace std;
int n, k;
int arr[200001];

//투포인터 구현
int findMaxLen(){
    //정답 저장
    int result = 0;
    //투포인터 설정
    int start = 0;
    int end = 0;
    //개수 체크용 배열
    int check[100001];
	
    //최대 n까지 반복
	while (end < n) {
        //k개 미만이라면 계속 뒤로 증가
		if (check[arr[end]] != k) {
			check[arr[end]]++;
			end++;
		}
        //k개라면 수열에서 뺀 다음 start 증가하며 하나씩 앞당기기
		else {
			check[arr[start]]--;
			start++;
		}
		result = max(result, end-start);
	}

    return result;
}

int main(){
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