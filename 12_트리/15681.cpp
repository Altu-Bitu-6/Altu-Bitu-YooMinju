#include <iostream>
#include <vector>

using namespace std;

//서브트리의 정점의 수 구하기 -> dp (중복되는 부분 문제?)
// 밑에서부터 dfs 구한 뒤 위로 올라감
int dp[100001];
bool visited[100001];
vector<int> tree[100001];
bool isleaf;

//완전탐색으로 자식노드부터 순회하는 함수
void dfs(int parent, int curr){
    visited[curr] = 1;
    for (int i = 0; i < tree[curr].size(); i++){
        //*** 현재 노드의 자식노드를 next로 지정
        int next = tree[curr][i];
        //이미 계산했으면 패스
        if (visited[next]){
            continue;
        }
        //자식노드 탐색
        dfs(curr, next);
    }
    //루트노드가 아니라면 노드 더하기
    if(parent != -1){
        dp[parent] += dp[curr];
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //dp 배열 1로 초기화(자기자신 포함해야하므로
    fill_n(dp, 100001, 1);

    //정점의 수 n, 루트의 번호 r, 퀴리의 수 q
    int n, r, q;
    cin >> n >> r >> q;

    //u, v : 트리의 양 끝점
    int u, v;
    //트리에 저장
    for (int i = 0; i < n-1; i++){
        cin >> u >> v;
        //*** 양방향으로 저장
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    //처리
    //루트노드를 -1로 시작
    dfs(-1, r);

    //각 쿼리 별 연산 및 결과 출력
    for(int i = 0; i < q; i++){
        int qu;
        cin >> qu;
        cout << dp[qu] << '\n';
    }


    return 0;
}
