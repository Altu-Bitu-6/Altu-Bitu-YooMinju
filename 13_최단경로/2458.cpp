#include <vector>
#include <iostream>
#include <queue>

using namespace std;

const int INF = 1e7;

int isPossibleRank(int n, vector<vector<int>> &graph){
    //연결된 정점 개수가 N-1이라면 자신의 위치 정확히 파악 가능
    int ans, cnt;
    ans = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for (int j = 1; j <= n; j++){
            if (graph[i][j] != INF || graph[j][i] != INF){
                cnt += 1;
            }
        }
        if (cnt == n-1){
            ans += 1;
        }
    }
    return ans;
}

void floyd(int n, vector<vector<int>> &graph){
    //중간 정점
    for (int k = 1; k <= n; k++){
        //출발 정점
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                //k를 거쳐 i에서 j로 갈 때의 비용
                int cost = graph[i][k] + graph[k][j];

                //최소값 판별
                graph[i][j] = min(graph[i][j], cost);

            }
        }
    }
}

int main(){
    int N, M, a, b;
    //N: 학생 수, M: 키 비교 횟수
    cin >> N >> M;

    //키 비교 그래프 초기화
    vector<vector<int>> graph(N+1, vector<int>(N+1, INF));
    //키 비교 결과 입력
    while (M--){
        cin >> a >> b;
        graph[a][b] = 1;
    }

    //연산
    //플로이드워셜 알고리즘
    floyd(N, graph);
    
    //출력
    //자신의 키 등수를 알 수 있는 학생 수 출력
    cout << isPossibleRank(N, graph);
}