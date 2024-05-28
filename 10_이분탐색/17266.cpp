#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;

//길이 다 밝혀졌는지 판별하는 함수
bool isBright(int light[], int mid){
    
    int tmpLower, tmpUpper;
    int darkStart = 0;
    
    for(int i = 0; i < m; i++){
        tmpLower = light[i] - mid;
        tmpUpper = light[i] + mid;
        
        //어두운 부분보다 밝히는 부분이 더 앞서있다면 false
        if (darkStart < tmpLower){
            return false;
        } else {
            darkStart = tmpUpper;
        }    
    }
    
    //어두운 부분이 도로보다 뒤에 있다면 전부 밝혀진 것 - true
    if (darkStart >= n) {
        return true;
    } 
    
    return false;
    
}


//height를 조절해가며 최소 높이 찾기
int minHeightSearch(int light[]){
    //최소, 최대 높이 포인터
    int left = 0; int right = n;
    int mid, result;

    //left가 right보다 커질때까지 반복
    while (left <= right){
        //중앙값으로 가로등 높이 설정
        mid = (left+right)/2;
        
        //전부 밝혀졌을 경우 - isBright 함수로 체크
        if (isBright(light, mid)){
            //mid값을 정답에 저장
            result = mid;
            //가로등 높이 축소
            right = mid - 1;
        }
        //어두운 부분이 있는 경우 가로등 높이 증가
        else {
            left = mid + 1;
        }
        
    }
    
    return result;

}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    //굴다리 길이 입력
    cin >> n;

    //가로등 위치 배열 입력
    cin >> m;
    int light[m];
    for (int i = 0; i < m; i++){
        cin >> light[i];
    }

    //연산 - 이분탐색으로 최소 가로등 높이 도출
    int min_height = minHeightSearch(light);

    //출력
    cout << min_height;

    return 0;
}