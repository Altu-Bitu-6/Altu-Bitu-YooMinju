//큰수: 문자열로 받기 - 자리수 맞추기(0)으로 - 각 자리수별로 더한 스택 만들기 - 스택끼리 더해 또다른 스택 만들기 - 올림 고려하여 계산

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

string addNum(string a, string b) {

    //자릿수 맞추기
    int numSize = max(a.length(), b.length());
    if (a.length() < numSize) {
        a = string(numSize - a.length(), '0') + a;
    }
    if(b.length() < numSize) {
        b = string(numSize - b.length(), '0') + b;
    }
        
    int carry = 0; //올림
    stack<int> result; //결과

    //자릿수끼리 더하고 올림수를 별도로 더하는 과정
    for (int i = numSize - 1; i >= 0; i--) {
        int sum_one = (a[i]-'0') + (b[i]-'0') + carry;
        carry = sum_one / 10;
        //스택에 추가할 때는 나머지만 추가
        result.push(sum_one % 10);
    }

    //올림값이 최종에 남았다면 마지막 값으로 스택 추가
    if (carry > 0){
        result.push(carry);
    }

    string result_string;
    int size = result.size();
    while(size--) {
        //int to string 변환
        result_string += to_string(result.top());
        result.pop(); 
    }
    
    return result_string;
}

int main() {
    string a, b;
    cin >> a >> b;

    string sum_a = addNum(a, b);
    cout << sum_a;
    
    return 0;
}