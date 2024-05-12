#include <iostream>
#include <vector>

using namespace std;
int n, k;
int arr[200001];

//투포인터 구현
int findMaxLen(int arr[]){
    //정답 저장
    int result = 0;
    //투포인터 설정
    int start = 0;
    int end = 0;
    //개수 체크용 배열
    int check[100001];

    int start = 0;
	int end = 0;
	
	while (start < n) {
		if (check[arr[start]] != k) {
			check[arr[start]]++;
			start++;
		}
		else {
			check[arr[end]]--;
			end++;
		}
		result = max(result, start - end);
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
    cout << findMaxLen(arr);

    return 0;
}