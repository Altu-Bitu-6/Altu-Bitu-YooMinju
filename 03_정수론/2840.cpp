#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<char> wheel(n, '?');
    int idx = 0;

    for(int i = 0; i < k; i++) {
        int s;
        char c;

        cin >> s >> c;

        s %= n;

        for (int i = 0; i < s; i++) {

        }
        if(idx - s < 0)
            idx = (idx - s) + n;
        else
            idx -= s;

        //if 인덱스에 다른 알파벳
        if (wheel[idx] != '?' && wheel[idx] != c) {
            cout << "!\n";
            return 0;
        }
        else {
            wheel[idx] = c;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++) {
            if(wheel[i] = '?' && wheel[i]== wheel[j]){
                cout << "!\n";
                return 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << wheel[(i + idx) % n];
    }

    cout << "\n";
    return 0;

}