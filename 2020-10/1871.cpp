#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;

        int w1 = 26 * 26 * (str[0] - 'A') + 26 * (str[1] - 'A') + str[2] - 'A';
        int w2 = stoi(str.substr(4, 4));

        if(abs(w1 - w2) <= 100) cout << "nice\n";
        else cout << "not nice\n";
    }
    return 0;
}