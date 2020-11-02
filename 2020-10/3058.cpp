#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
int T;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    int sum = 0;
    int minn = 9999999;
    while(T--) {
        int n;
        
        sum = 0;
        minn = 111;
        for(int i = 0; i < 7; i++) {
            cin >> n;
            if(n % 2 == 0) {
            sum += n;
            minn = min(minn, n);
            }
        }
        
        cout << sum << " " << minn << "\n";
    }
    return 0;
}