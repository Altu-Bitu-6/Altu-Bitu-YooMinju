#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

// bfs: 시간초과가 걸릴 수도 있음
// 다익스트라 알고리즘: 하나의 정점에서 다른 모든 정점으로 가는 최단 경로 (다만 음의 간선 불가)
// 오고 가는데 걸리는 시간 : 다익스트라 알고리즘 2번 적용해서 합치기

typedef pair<int, int> ci;
const int INF = 2e5;

int dist[1002];
vector<ci> graph[1002];
int result;

void dijkstra(int start, int v){
    //dist 초기화
    memset(dist, INF, sizeof(dist));
    //우선순위큐 : 중간 정점까지의 최단시간
    priority_queue<ci, vector<ci>, greater<ci>> pq;

    //시작 정점 초기화
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()){
        int weight = pq.top().first; //현재 정점까지의 경로값
        int node = pq.top().second; //현재 정점
        pq.pop();

        //마을에 도착하면 break
        if(node == v){
            result = dist[node];
            break;
        }

        //다음 정점들
        for (int i = 0; i < graph[node].size(); i++){
            int next_node = graph[node][i].first; //연결된 다음 정점
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]){
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});       
            }
        }
    }
}
int main(){
    //N: 학생 수, M: 도로 개수, X:파티 마을
    //start, end, t: 도로의 시작점, 끝점, 소요시간
    int N, M, X, start, end, t;
    cin >> N >> M >> X;

    //그래프 입력
    for(int i = 0; i < M; i++){
        cin >> start >> end >> t;
        graph[start].push_back({end, t});
    }

    //연산 및 처리
    int answer = 0;
    for(int i = 1; i <= N; i++){
        dijkstra(i, X); //가는 길 최단 시간
        int a1 = result;
        dijkstra(X, i); //오는 길 최단 시간
        int a2 = result;

        //오고 가는 시간 체크 (최대값 구해야 함)
        if (answer < a1+a2){
            answer = a1 + a2;
        }
    }
    
    cout << answer << '\n';
    return 0;
}