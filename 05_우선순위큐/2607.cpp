//try #1: 알파벳과 개수를 pair로 저장 -> 비교할 방법 생각 안남
//try #2:
//단어의 알파벳 개수를 26칸 배열에 저장
//두 단어의 배열을 비교하기
//한글자 추가된 경우: 차이값 -1 1개
//한글자 제거된 경우: 차이값 1 1개
//다른 알파벳 추가된 경우: 차이값 -1 1개, 차이값 1 1개
    //이중 반복문을 돌리며 -1 차이가 나기 시작하는 경우 -1과 1 차이가 나는 경우 구분 -> 시간 초과날 듯 + 나머지 알파벳 전부 계산하기가 불가능
    //-> 반복문을 하나만 돌리고 차이가 나는 것을 벡터에 모두 저장
//비슷한 단어 체크
    //벡터 길이가 1 && ( 벡터 값 -1 || 벡터 값 1 ) -> 비슷한 단어
    //벡터 길이가 2 && 벡터값이 -1 && 벡터값이 1
 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//알파벳 개수를 체크하는 배열 만들기
vector<int> checkAlpha(string s){
    vector<int> alpha(26, 0);
    for (int i = 0; i < s.size(); i++){
        alpha[s[i]-'A'] += 1;
    }
    return alpha;
}

//두 단어를 비교하고 비슷한 단어임을 체크하는 함수
bool isSimilar(vector<int> X, vector<int> Y){
    vector<int> diff;
    for (int i = 0; i < 26; i++){
        //유의미한 차이값만 diff 벡터에 저장하려 했으나 같은 구성을 골라내지 못함
        //값이 다른 알파벳 모두 저장
        if (X[i] != Y[i]){
            diff.push_back(X[i]-Y[i]);
        }
    }
    
    //같은 구성일 경우
    if (diff.empty()){
        return true;
    }
    //알파벳을 한 개 제거 or 추가한 경우
    //비교조건 길면 틀렸다고 뜸.. abs 활용할 것
    if (diff.size() == 1 && abs(diff[0]) == 1) {
        return true;
    }
    //다른 알파벳을 한 개 추가한 경우
    if (diff.size() == 2 && abs(diff[0]) == 1 && diff[0]+diff[1] == 0){
        return true;
    }

    return false;  
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    //입력
    int n, cnt;
    string first, test;
    vector<int> vectorFirst;
    vector<int> vectorTest;
    cin >> n;

    //기준이 될 첫번째 단어 알파벳 체크
    cin >> first;
    vectorFirst = checkAlpha(first);
    
    //처리
    n--;
    for (int i = 0; i < n; i++){
        cin >> test;
        //알파벳 체크 후 비슷한 단어 체크
        vectorTest = checkAlpha(test);
        if (isSimilar(vectorFirst, vectorTest)){
            cnt++;
        }
    }

    //출력
    cout << cnt;
    
    return 0;
}