#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int ans = 0;
    int len1 = 0, len2 = 0;
    int cur1 = -1, cur2 = 10;
    for(int i = 0; i < N; i++) {
        int t;
        cin >> t;
        if(cur1 <= t) {
            len1++;
            cur1 = t;
        }
        else {
            ans = max(ans, len1);
            len1 = 1;
            cur1 = t;
        }
        if(t <= cur2) {
            len2++;
            cur2 = t;
        }
        else {
            ans = max(ans, len2);
            len2 = 1;
            cur2 = t;
        }
    }
    ans = max(ans, max(len1, len2));
    cout << ans;
    return 0;
}