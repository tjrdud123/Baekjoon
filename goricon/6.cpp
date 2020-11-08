#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int N;
vector<int> A;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int t;
        cin >> t;
        A.push_back(t);
    }
    sort(A.begin(), A.end());
    int ans = 0;
    int left = 0;
    int right = N - 1;
    while(left <= right) {
        if(left == right) ans += A[left];
        else {
            ans += (A[right] * 2);
            
        }
        left++;
        right--;
    }
    cout << ans;
    return 0;
}