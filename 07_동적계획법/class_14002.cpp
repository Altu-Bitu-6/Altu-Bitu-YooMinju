//동적계획법 - 이전범위의 값을 저장함으로써 효율적으로 값을 얻는 것
//문제를 봤을 때 동적계획법을 써야겠다고 판별하는 것이 중요함 - 바로 알아채진 못함

//피보나치 수열
    //재귀를 활용해야하나? -> n이 커지면 시간초과, 같은 함수를 여러번 호출하는 것
    //DP - 배열에 값을 저장해두고, 다음 숫자에서 값이 있는지 검색해서 활용하는 것
        //top-down(재귀) vs bottom-up(빠름)
        //점화식!


//dp[i]에 인덱스 i번째 값을 꼭 넣는다
//i 이전 값을 탐색, j 가 i보다 작을 때 +1해준 값을 비교해서 max값으로 갱신
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,max_num,max_idx,len;
int a[1001],dp[1001]; //입력받을 수열, 부분수열
vector<int> arr;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        len = 0;

        // for(int j = 0; j < i; j++) {
        //     if(a[i] > a[j]) {
        //         len = max(dp[j], len);
        //     }
        // }
        // dp[i] = len + 1;
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        if(max_num < dp[i]) {
            max_num = dp[i];
            max_idx = i;
        }
    }

    for(int i = max_idx;i >= 0;i--) {
        if(max_num == dp[i]) {
            arr.push_back(a[i]);
            max_num--;
        }
    }

    int size = arr.size();
    cout << size << "\n";

    for(int i = 0; i < size; i++) {
		cout << arr.back() << " ";
        arr.pop_back();
    }

    return 0;
}