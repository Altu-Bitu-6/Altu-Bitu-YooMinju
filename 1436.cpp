//입력: n
//처리: 666으로 나눈다 -> 만약 나눠진다면 종말의 수 -> cnt가 n과 같아질 때 값 / 안 나눠진다면 값을 10으로 나누고 값이 0이 될 때까지 반복
//출력: n번째 종말의 수

#include <iostream>

using namespace std;

int checkDestroyNum(int n){
    //초기화
    int i = 0;
    int cnt = 0;

    //n과 cnt가 같아질 때의 i값이 답
    while (n != cnt){
        //하나하나 판별 = i 증가
        i++;
        int testNum = i;

        while (testNum != 0){
            //666으로 나누어떨어지는지(666이 포함되는지)
            if (testNum % 1000 == 666) {
                cnt++;
                break;
            }
            //10으로 나눠 일의 자리수 삭제
            else {
                testNum /= 10;
            }
        }    
    }

    return i;
}

int main(){
    //구해야 할 n번째 종말의 수
    int n;
    cin >> n;

    //n번째 종말의 수 찾아내는 함수
    int res = checkDestroyNum(n);

    //출력
    cout << res;
}