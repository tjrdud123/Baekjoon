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
vector<vector<char>> A;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; i++) A[i].resize(N);
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < N; j++) {
            A[i][j] = str[j];
        }
    }
    bool flag = true;
    for(int i = 0; i < N; i++) {
        string str1, str2;
        for(int j = 0; j < N; j++) str1 += A[i][j];
        for(int j = 0; j < N; j++) {
            str2 += A[j][i];
        }
        if(str1 != str2) {
            flag = false;
            break;
        }
    }
    if(flag) cout << "YES";
    else cout << "NO";
    return 0;
}