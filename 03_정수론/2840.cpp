#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;

    cin >> n >> k;
    vector<char> wheel(n, '?');

    int idx;

    for(int i = 0; i < k; i++){
        int s, c;
        cin >> s >> c;
        if (i == 0) {
            wheel[0] = c;
            idx = 0;
            continue;
        }

        idx = (s+idx);
    }
}