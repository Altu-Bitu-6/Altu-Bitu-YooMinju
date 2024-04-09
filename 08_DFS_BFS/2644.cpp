//촌수 계산 - 무방향 그래프
//자식들 먼저 계산하는 것이 편리하므로 bfs

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b, x, y;
vector<vector<int>> family;
vector<int> visited;


void bfs(int idx){
    queue<int> q;
    q.push(idx);
    visited[idx] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        //촌 수 계산이므로 계속 1씩 더해가야함
        for (int i = 1; i <= n; i++){
            if(family[curr][i] == 1 && visited[i] == 0){
                visited[i] = visited[curr] + 1;
                q.push(i);
            }
        }
    }
}

int main(){
    cin >> n;
    cin >> a >> b;
    cin >> m;
    
    family.assign(n+1, vector<int> (n+1, 0));
    visited.assign(n+1, 0);
    
    while(m--){
        cin >> x >> y;
        family[x][y] = 1;
        family[y][x] = 1;
    }//입력 끝

    //a 기준으로 촌 수 업데이트
    bfs(a);
    
    //촌 수 구하기
    if (visited[b] == 0) {
       cout << -1;
    }
    else {
        //나를 1촌으로 했기 때문에 1 빼기
        cout << visited[b] - 1;
    }
    return 0;
}