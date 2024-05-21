//연산자를 반복없이 순열로 뽑는 것?
//+: 0, -: 1, *: 2, /: 3
// 0, 1, 2, 3으로 구성된 숫자들을 n-1개 뽑아서 수열로 만드는 것
//try 1: 재귀함수 호출 전에 미리 숫자들을 연산해서 축적하기 -> 초기화 및 이전 정보 중 일부를 저장이 불가하다는 문제 발생
//try 2: 수열 만들기처럼 연산자의 수열을 미리 어레이에 저장한 뒤 연산을 한번에

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[11];
bool is_used[11];
int formula[11];
vector<int> oper;
vector<int> result;
pair<int, int> resMinMax;
int n;
int res;

//formula array 순서 대로 계산하는 함수
int calcFormula(){
    
    for (int i = 0; i < n-1; i++){
        if (formula[i] == 0) {
            res += num[i+1];
        } 
        else if (formula[i] == 1) {
            res -= num[i+1];
        }
        else if (formula[i] == 2) {
            res *= num[i+1];
        }
        else {
            res /= num[i+1];
        }
    }
    
    return res;
}

void backtrack(int idx){
    if (idx == n-1){
        //formula 순서대로 계산
        int answer = calcFormula();
        result.push_back(answer);
        
        //초기화
        res = num[0];
        return;
    }
    
    for (int i = 0; i < n-1; i++){
        if (is_used[i]){
            continue;
        }
        
        is_used[i] = true;
        //연산자의 경우의 수 구하기
        formula[idx] = oper[i];
        backtrack(idx+1);
        is_used[i] = false;
    }
}

//연산자를 숫자로 변환하여 어레이에 삽입
void putOper(int add, int minus, int multi, int divide){
    if(add > 0){
        while(add--){
            oper.push_back(0);   
        }
    }
    if(minus > 0){
        while(minus--){
            oper.push_back(1);   
        }
    }
    if(multi > 0){
        while(multi--){
            oper.push_back(2);   
        }
    }
    if(divide > 0){
        while(divide--){
            oper.push_back(3);   
        }
    }
}


int main(){
    int k, o;

    cin >> n;
    for (int i = 0; i < n; i++) {
        //숫자 입력
        cin >> num[i];
    } 

    //연산자 입력 (숫자(0~3)로 변환)
    int add, minus, multi, divide;
    cin >> add >> minus >> multi >> divide;
    putOper(add, minus, multi, divide);
    //입력 끝

    //각 결과 계산 후 결과를 벡터에 저장
    //연산 시작을 위해 첫번째 값으로 초기화
    res = num[0];
    
    backtrack(0);
    
    int max = *max_element(result.begin(), result.end());
    int min = *min_element(result.begin(), result.end());
    
    cout << max << "\n" << min;
    return 0;
}