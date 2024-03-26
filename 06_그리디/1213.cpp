//팰린드롬이 가능한 경우 -> 홀수개의 알파벳이 딱 하나 -> 그 알파벳을 중간에 놓고 시작, 나머지 알파벳을 알파벳 순으로 맨 앞과 맨 뒤에 넣어주기
//불가능할 경우 - 쏘리 한수 출력

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

bool checkPalindrome(int alpha[]){
    int cnt = 0;
    //홀수가 2번 이상 나오면 sorry

    for (int i = 0; i < 26; i++){
        if (alpha[i]%2 != 0) {
            cnt++;
        }
    }
    bool ans = false;
    if (cnt > 1){
        ans = true;
    }
    return ans;
}

string makePalindrome(int alpha[]){
    string ans;

    //앞에서 중간까지 사전순으로
    for (int i = 0; i < 26; i++) {
        for(int j = 0; j < alpha[i]/2; j++){
                ans += i + 'A';
            }
        }
    for (int i = 0; i < 26; i++){
        if(alpha[i]%2) {
            ans += i + 'A';
        }
    }
    //끝에서부터 다시 사전순으로 놓기
    for (int i = 26; i > 0; i--){
        for (int j = 0; j < alpha[i-1]/2; j++){
            ans += i-1 + 'A';
        }
    }

    return ans;
}

int main() {
    //문자열 입력
    string s;
    cin >> s;

    //알파벳 배열에 개수 체크
    int alpha[26];
    for (int i = 0; i< s.size(); i++){
        alpha[s[i] - 'A']++;
    }

    //팰린드롬 만들기
    if (checkPalindrome(alpha)) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    string ans;
    ans = makePalindrome(alpha);
    cout << ans;
    
}