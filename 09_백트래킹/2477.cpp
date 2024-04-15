//try 1: 가로 벡터, 세로 벡터를 구분해서 최대 변길이를 구해서 큰 사각형을 구하기 -> 작은 사각형 구할 수 없음
//try 2: 전체를 한번에 받으면서 최대 가로/세로를 구하기 -> 이후 최대 길이의 인덱스를 활용해서 앞뒤 인덱스의 길이의 차이가 곧 작은 사각형의 변 길이라는 점 활용

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> length;
pair<int, int> max_x = make_pair(0, 0); 
pair<int, int> max_y = make_pair(0, 0);
int area, ans;

int calcArea(){
    
    int bigSq, smallSq;
    int small_x, small_y;
    //큰 사각형 넓이 = 가장 긴 가로 * 가장 긴 세로
    bigSq = max_x.second * max_y.second;

    //작은 사각형 가로 = max_y의 인덱스 양 옆의 차이
    if (max_y.first != 0){
        small_x = abs(length[(max_y.first+1)%6] - length[(max_y.first-1)%6]);
    } else { //인덱스가 0일 경우 음수가 나오므로 따로 분류
        small_x = abs(length[1] - length[5]);
    }
    
    //작은 사각형 세로 = max_x의 인덱스 양 옆의 차이
    if (max_x.first != 0){
        small_y = abs(length[(max_x.first+1)%6] - length[(max_x.first-1)%6]);
    } else {
        small_y = abs(length[1] - length[5]);
    }
    
    smallSq = small_x * small_y;

    //육각형의 넓이 = 큰 사각형 - 작은 사각형
    return bigSq - smallSq;
}

void findMax(int i, int d, int l){
    //가로 길이 중 최대 길이 구하기 -> 순서와 길이를 페어형에 저장
    if (d == 1 || d == 2){
        if (l > max_x.second){
            max_x.first = i;
            max_x.second = l;
        }
    }
    //세로 길이 중 최대 길이 구하기
    else if (d == 3 || d == 4){
        if (l > max_y.second){
            max_y.first = i;
            max_y.second = l; 
        }
    }
}

int main(){
    int k, d, l;
    
    //참외 개수 입력받기
    cin >> k;

    //각변 길이 입력 받기
    for(int i = 0; i < 6; i++){
        cin >> d >> l;
        //최대길이 찾기
        findMax(i, d, l);
        
        //길이저장
        length.push_back(l);
        
    }

    //넓이 구하기
    area = calcArea();
    
    //참외 개수 구하기
    ans = k * area;

    //출력
    cout << ans;
    
    return 0;
}