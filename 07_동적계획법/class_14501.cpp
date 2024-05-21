
#include <iostream>
#include <vector>

using namespace std;

void dpBottomUp(vector<int>& dp, vector<pair<int, int> > li, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + li[i].first; j <= n; j++) { //n+1 퇴사이기 때문에 n일까지 반복해야..
            if (dp[j] < dp[i] + li[i].second) { //만약에 기존 값보다 크다면 새로 dp[j] 값 갱신
                dp[j] = dp[i] + li[i].second;
            }
        }
    }
}

void dpTopDown(vector<int>& dp, vector<pair<int, int> > li, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (i + li[i].first > n) {// i일에 상담하는 것이 n을 넘기면 상담을 할 수 없음
            dp[i] = dp[i + 1];
        }
        else {// 상담을 하는 것과 하지 않는 것 중 큰 값을 선택
            dp[i] = max(dp[i + 1], li[i].second + dp[i + li[i].first]);
        }
    }
}

int main() {
    int n;
    int duration, cost;
    cin >> n;

    vector<pair<int, int> > li; //상담 기간과 금액
    vector<int> dp(n + 1, 0); //0으로 초기화

    for (int i = 0; i<n;i++) {
        cin >> duration >> cost;
        li.push_back(make_pair(duration,cost));
    }
    //입력 끝

    // dpTopDown(dp, li, n);
    // cout << dp[0] << "\n";

    dpBottomUp(dp, li, n);
    cout << dp[n] << "\n";
    return 0;
}
