#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int D, K;
vector<pair<int, int>> AB;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> D >> K;
    AB.resize(D + 1);
    AB[1] = make_pair(1, 0);
    AB[2] = make_pair(0, 1);
    for(int i = 3; i <= D; i++) {
        int a = AB[i - 2].first + AB[i - 1].first;
        int b = AB[i - 2].second + AB[i - 1].second;
        AB[i] = make_pair(a, b);
    }
    int a = AB[D].first;
    int b = AB[D].second;
   
    for(int A = 1; ; A++) {
        for(int B = 1; ; B++) {
            int c = a * A + b * B;
            if(c == K) {
                cout << A << "\n" << B;
                return 0;
            }
            if(c > K) break;
        }
    }
    return 0;
}