//.이 들어오면 입력을 멈추는 반복문
//(나 [가 들어오면 push
//)가 들어올 때: (가 있고 비어있지 않으면 ( pop / else: false
//]가 들어올 떄: [가 있고 비어있지 않으면 [ pop / else: false

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    while (true){

        string str;
        stack<char> test;
        bool result = true;
        
        getline(cin, str);

        if(str.length() == 1 && str[0] == '.') {
            break;
        }

        for (int i = 0; i < str.length(); i++){
            if (str[i] == '(' || str[i] == '[')
                test.push(str[i]);

            if (str[i] == ')') {
                if(!test.empty() && test.top() == '(')
                    test.pop();
                else
                    result = false;
                    break;
            }

            if (str[i] == ']') {
                if(!test.empty() && test.top() == '[')
                    test.pop();
                else
                    result = false;
                    break;
            }
        } 

    //스택이 비어있고 result가 참이면 성공
    if(test.empty() && result) {
        cout << "yes";
    } else {
        cout << "no";
    }
}
return 0; 
}