#include <iostream>
#include <algorithm>
#include <deque>
#include <utility>

using namespace std;
//n: 강의의 수, m: 블루레이 개수, t: 각 강의 시간 
int n, m, t;

//강의 시간을 담기위한 덱
deque<int> lecture;


/*
mid 값인 블루레이 크기에 맞게 강의 시간을 채워넣고, 블루레이 개수와 최대 블루레이 크기를 계산하는 함수
*/
pair<int,int> demoBlueray(int mid){
    int blueray = 0; int max_size = 0; int cnt = 0;
    //시뮬레이션 위한 덱 카피
    deque copy(lecture);
    
    while(copy.size()){
        //블루레이 크기 검사
        if (blueray + copy.front() <= mid) {
            //앞에서부터 더하기 (강의 순서 중요)
            blueray += copy.front();
            copy.pop_front(); 
        }
        //만약 블루레이 크기 초과라면 새로운 블루레이에 담기 
        else {
            //최대값갱신
            if (max_size < blueray){
                max_size = blueray;
            }
            
            //블루레이 개수 추가하고 초기화
            cnt += 1;
            blueray = 0;
            
            //해당 강의 추가
            blueray += copy.front();
            copy.pop_front();
        }
    }
    //마지막 블루레이 개수에 추가
    cnt += 1;    
    //최대값갱신
    if (max_size < blueray){
        max_size = blueray;
    }

    return make_pair(cnt, max_size);
}
/*
블루레이 크기를 조절해가며 적절한 크기 찾는 이분탐색 함수
    - 포인터 초기값: 가장 큰 강의시간 ~ total(총 강의시간)
*/
int binarySearch(int total, int max_lecture){
    int left = max_lecture; int right = total;
    int mid, result;

    while (left <= right){
        mid = (left+right)/2;  

        //mid값에 맞춰 블루레이 시뮬레이션
        //first: cnt, second: max_size
        pair<int, int> p = demoBlueray(mid);
        
        //cnt가 m개 초과라면 사이즈 키워야 함
        if (p.first > m){
            left = mid + 1;
        } 
        //m보다 같거나 작은 개수로 채워졌다면 더 작은 사이즈로 가능 (m개 이전에 다 채워졌으므로)
        else {
            //max_size가 mid보다 작거나 같다면 result 저장하고 크기 줄이기
            if (p.second <= mid) {
                result = p.second;
                right = mid - 1;
            }
            //하지만 max_size가 현재 mid 값보다 크다면 mid 값 증가해야 함 (mid값으로는 부족하므로)
            if (p.second > mid){
                left = mid + 1;
            }
        }
    }
    return result;
}

int main(){

    cin >> n >> m;
    
    int max_lecture = 0;
    int totalTime = 0;
    for (int i = 0; i < n; i++){
        cin >> t;
        totalTime += t;
        
        if (max_lecture < t){
            max_lecture = t;
        }
        lecture.push_back(t);
    }

    //이분탐색
    int blueraySize = binarySearch(totalTime, max_lecture);

    //출력
    cout << blueraySize;

    return 0;
}