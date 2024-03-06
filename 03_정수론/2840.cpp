#include <iostream>
//k개의 입력을 관리하기 위함: 벡터
#include <vector>

using namespace std;

//중복 체크 배열 필요
    //없으면 ok
    //있는데 같은 글자면 ok, 다른 글자면 만들기 불가능 -> !
//바퀴
    //시계방향 회전: 인덱스가 감소하는 것처럼 보임 ???? (-방향)
    //-> 인덱스 음수가 될 수도 있어 X
    // + 방향으로 하고 인덱스 증가하도록, 출력할 때는 반대방향으로 출력
        //s가 더해짐 -> idx = (idx+s)%n


//쌍으로 입력받을 시엔 pair 자료형
//자료형을 쉽게 선언하기 위한 작업(typedef)
typedef pair<int, char> ic;
//알파벳의 개수 26개를 상수로 만들기
const int ALPHA = 26;

//바퀴 문자열 출력하기
string printWheel(int n, int idx, vector<char>& wheel){
    //string 변수 생성
    string ans = "";

    //마지막에 가리킨 인덱스부터 감소하며 반복하게끔
    for(int i = idx + n ; i > idx; i--){
        //거꾸로 출력
        ans += wheel[i % n];
    }
    //결과값 반환
    return ans;
}

//바퀴 문자열을 만드는 함수
string makeWheel(int n, int k, vector<ic>& record){
    //바퀴의 문자를 담을 벡터 생성 및 초기화 (결정 못한 문자열은 ?이므로)
    vector<char> wheel(n, '?');

    //중복 여부 체크하는 문자열 생성 및 초기화 (false)
    vector<bool> is_available(ALPHA, false);

    //바퀴 회전 후 위치를 뜻하는 인덱스 변수
    int idx = 0;
    //k번 반복
    for (int i = 0; i < k; i++){
        //화살표가 돌아가는 횟수
        int s = record[i].first;
        //가리키는 글자
        char c = record[i].second;
        //회전 후의 인덱스: 인덱스가 0~(n-1)까지의 범위를 유지할 수 있도록 만들기
        idx = (idx + s) % n;

        //해당 칸에 이미 같은 글자가 있는 경우
        if (wheel[idx] == c) {
            //바로 패스하도록 continue - else if 대체!
            continue;
        }
        //다른 글자로 채워진 경우 | 이미 사용된 알파벳으로 채워진 경우
        //초기값인지 검사
        if (wheel[idx] != '?' || is_available[c-'A']) { //문자끼리 연산하면 아스키코드 변환 -> 벡터 배열을 26칸으로 효율적으로 사용하기 위해
            //! string으로 반환
            return "!";
        }

        //중복 검사 이후 채워주기
        wheel[idx] = c;
        //사용 여부 체크하기
        is_available[c - 'A'] = true;
    }
    //바퀴 문자열을 만들고 반환 -> 최종 출력은 main에서
    return printWheel(n, idx, wheel);

}
int main() {
    //입출력 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //칸 수와 횟수 변수 선언
    int n, k;
    //입력 받기
    cin >> n >> k;

    //벡터 선언
    vector<ic> record(k);
    //k번 반복하며 pair 자료형 입력받기
    for (int i = 0; i < k; i++){
        //pair 자료형 입력 받기 (e.g. '.first')
        cin >> record[i].first >> record[i].second;
    }

    //연산 및 출력을 담당하는 makeWheel 함수 사용하여 최종 출력
    cout << makeWheel(n, k, record);

    
}