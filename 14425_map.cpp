#include <iostream>
#include <map>

using namespace std;

//n개의 문자열로 이루어진 집합 s
//m개의 문자열이 s에 포함되어 있는지 구하는 프로그램

//변수 설정 - map 사용
map<string, bool> train;
int n, m;
string str;
int result = 0;

int main(void)
{
    //개수 입력
    cin >> n >> m;

    //문자열 입력
    //문자열, Bool 형태
    for(int i = 0; i < n; i++) {
        cin >> str;
        train.insert(pair<string, bool>(str, true));
    }

    //테스트할 문자열을 맵으로 불러오기
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (train[str] == true)
            result++;
    }

    //개수 출력
    cout << result;
}