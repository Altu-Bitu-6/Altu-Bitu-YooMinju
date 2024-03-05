#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//배열 선언 - int로 선언했을 때 모호하다고 나옴
#define MAX 1000000

int arr[MAX] = {0};

void arrPrime() {

    for (int i = 2; i * i <= MAX; i++) {
        if (arr[i] == 0){
            for (int j = i * i; j <= MAX; j += i){
                arr[j] = 1;
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    arrPrime();
    
    while (1) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        bool chk = false;
        
        for(int a = 3; a<= n; a+=2){
           // int b = n - a;
            if(arr[a]==0 && arr[n-a]==0) {    //a가
                cout << n << " = " << a << " + " << n-a << "\n";
                chk = true;
                break;
            }
        }
        if(!chk){
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;

}