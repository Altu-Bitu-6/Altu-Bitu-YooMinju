#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//기타의 시리얼 번호대로 정렬
/*
    1. 길이가 짧은 번호 먼저
    2. 같다면 자리수의 합이 작은 것 먼저
    3. 자리수의 합이 같다면 사전 순 비교 (숫자 < 알파벳)
*/
//입력: 기타의 개수 n -> 시리얼번호 (중복 X)
//중복 없음 - 맵인가?
//출력: 정렬 결과


// 비교함수
int cmp(string g1, string g2) {
    int g1size = g1.size();
    int g2size = g2.size();
    int g1sum = 0;
    int g2sum = 0;

    //길이가 다르면 짧은 것부터
	if (g1size != g2size)
        return g1size < g2size;

    //길이가 같다면 합이 작은 것부터
	for(int i = 0; i < g1size; i++){
        if(g1[i] >= '0' && g1[i] <= '9'){
            g1sum += int(g1[i]) - 48;
        }
        if(g2[i] >= '0' && g2[i] <= '9'){
            g2sum += int(g2[i]) - 48;
        }
    }
    if (g1sum != g2sum) {
        return g1sum < g2sum;
    }

    //마지막으로 사전 순 비교
    return g1 < g2;
}



/*
* 시리얼 넘버 입력받기
* 정렬 방법을 비교 함수에 추가
*/

int main()
{
	int n;
	string serial[50];
	
    // 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
        cin >> serial[i];
    }

	// 정렬
	sort(serial, serial + n, cmp);
	
    // 출력
	for (int i = 0; i < n; i++) {
		cout << serial[i] << '\n';
	}
	return 0;
}

