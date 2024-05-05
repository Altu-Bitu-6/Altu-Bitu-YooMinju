#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;
int n;
ll m;
ll t[100001];


int main(){

    cin >> n >> m;

    //소요시간 입력
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }

    //최소, 최대값 설정
    ll left = 1; ll right = 1e19;
    ll mid;
    ll result = 0;
    
    while (left <= right){
        mid = (left+right) / 2;
        
        //시간 안에 심사받는 사람 인원 계산
        ll cnt = 0;
        for (int i = 0; i < n; i++){
            cnt += mid / t[i];
        }
        
        //포인터 이동
        if (cnt >= m){
            //최소값 갱신
            if (result > mid || result == 0){
                result = mid;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }

    }
    cout << result;
        
}