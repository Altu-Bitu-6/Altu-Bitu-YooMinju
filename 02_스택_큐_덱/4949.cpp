//.이 들어오면 입력을 멈추는 반복문
//(나 [가 들어오면 push
//)가 들어올 때: (가 있고 비어있지 않으면 ( pop / else: false
//]가 들어올 떄: [가 있고 비어있지 않으면 [ pop / else: false

#include <iostream>
#include <stack>
#include <string>

using namespace std;

//짝이 맞으면 stack에서 사라지게 하는 함수
//result 값으로 판별해야 하므로 리턴 필요
bool matchPop(string str, stack<char>& test, bool result){
    for (int i = 0; i < str.length(); i++){
            if (str[i] == '(' || str[i] == '[')
                test.push(str[i]);
            //대괄호 주의
            if (str[i] == ')') {
                if (!test.empty() && test.top() == '(') {
                    test.pop();
                } else {
                    result = false;
                    break;
                }
            }

            else if (str[i] == ']') {
                if(!test.empty() && test.top() == '[') {
                    test.pop();
                } else {
                    result = false;
                    break;
                }
            }
        } 
    
    return result;

}
int main(){
    while (true){

        string str;
        stack<char> test;
        bool result = true;
        
        getline(cin, str);

        if(str == ".") {
            break;
        }
        //result 값 받아오기
        result = matchPop(str, test, result);
        
    //스택이 비어있고 result가 참이면 성공
    if(test.empty() && result) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}
    return 0; 
}