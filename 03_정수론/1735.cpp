#include <iostream>

using namespace std;

//재귀로 최대공약수 구하기
int getGcdRecur(int x, int y) {
    if (y == 0) {
        return x;
    }
    return getGcdRecur(y, x%y);
}

int main() {
    //입력
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;

    //분수 합
    int e = a*d + c*b;
    int f = b*d;
    //약분
    int min = getGcdRecur(e, f);
    e /= min;
    f /= min;

    cout << e << ' '<< f <<'\n';

    return 0;
}