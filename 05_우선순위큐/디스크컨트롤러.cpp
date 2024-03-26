//디스크 컨트롤러가 순서를 재배열함
    //작업 소요시간 기준으로 작은 순서대로
    //cmp 재정의

//try 1 :
    //1) sort 다시 해준 뒤, 2)sum을 계산하고, 3)평균을 계산
//try 2 :
    //현재 시간 고려 + 현재 작업이 끝난 후에 요청된 작업들도 고려,,
    //우선순위 큐?
    //여전히 우선순위 큐가 어떻게 작업시간대로 정렬을 하는건진 모르겠음 -> 사용 불가

    //작업이 끝난 시간보다 요청 시간이 이르다면 먼저 처리를 해줘야함 -> 정렬 순서와 상관없이 우선적으로

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//정렬 조건 재정의
bool cmp(vector<int> &v1, vector<int> &v2){
    //소요시간이 작은 순으로
    return v1[1] < v2[1];
}


int solution(vector<vector<int>> jobs) {    
    int time = 0;
    int start = 0;
    //마지막에 구하면 0이 되므로 미리 구해놓기
    int size = jobs.size();
    
    //정렬
    sort(jobs.begin(), jobs.end(), cmp);
    
    
    while(!jobs.empty()){
        for(int i=0; i<jobs.size(); i++){

            //요청시간이 현재 시점보다 이르거나 같다면 먼저 계산
            if(jobs[i][0] <= start) {
                start += jobs[i][1];
                time += start - jobs[i][0];
                
                //삭제
                jobs.erase(jobs.begin() + i);
                break;
            }
            //전부 아니라면 (아무것도 실행될 게 없음 -> i가 마지막이라면)
            if(i == jobs.size()-1) {
                start++;
            }
        }
    }
    
    int answer = time / size;
    return answer;
}