//평행우주
//최소 속도를 계산하는 조건
    //첫번째 수는 무조건 더하기 - 초기값
    //두번째부터는 비교하고 더하기
        //이전 수보다 큰 경우
            //배수인가?
    //-> 처음부터 접근한다면 이후 지구에 돌아오는 값을 계산 불가
    //마지막부터 접근(역순)
        //현재 속도가 res가 크다면 그 속도로 바꾸기
        //작다면 -> res // 현재 + 1 * 현재 (양의 정수 배로도 갈 수 있음)

#include <iostream>
#include <vector>

using namespace std;

int calcMin(int arr[]){
    //초기값 설정
    int res = arr[0];

    //배열 내에서 반복하며 res 값 계산
    for (int i = 1; i < sizeof(arr) ; i++){
        //현재 속도가 크다면 대체
        if (arr[i] > res){
            res = arr[i];
        }
        //현재 속도가 작거나 같다면 배수 계산해서 res 업데이트
        else {
            res = (res / arr[i] + 1) * res;
        }
    }

    return res;
}




int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int n, curr_speed, res;
    int min_speed[] = {};
    cin >> n;

    //역순으로 배열 생성
    while (n--){
        cin >> min_speed[n]; 
    }

    //필요한 최소 속도 계산
    res = calcMin(min_speed);

    //출력
    cout << res;
}