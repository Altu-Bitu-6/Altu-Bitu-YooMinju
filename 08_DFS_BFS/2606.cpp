//웜바이러스 걸리는 알고리즘 = 그래프 알고리즘
//탐색해야함 -> 연결된 자식들을 탐색하는 것이므로 bfs
//queue 사용하여 bfs 함수 만들기

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int n, m, a, b;
//바이러스 걸리는 컴퓨터의 수
int num_virus;
vector<vector<int>> computer;
vector<bool> visited;

//bfs 함수
int bfs(int idx){
    queue<int> q;
    num_virus = 0;
    q.push(idx);
    visited[idx] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int i = 1; i <= n; i++){
            if (computer[curr][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
                num_virus++;
            }
        }
    }

    return num_virus;
}

int main(){
    cin >> n;
    computer.assign(n+1, vector<int>(n+1, 0));
    visited.assign(n+1, false);
    cin >> m;

    for (int i = 0; i < m; i++){
        cin >> a >> b;
        computer[a][b] = 1;
        computer[b][a] = 1;
    } //입력 끝

    //1번 컴퓨터의 영향을 알아보는 것이므로
    cout << bfs(1);

    return 0;
}