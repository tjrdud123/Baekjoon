#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string str, str2;
        cin >> str;
        for(int j = str.size() - 1; j >= 0; j--) str2 += str[j];
        int n = stoi(str) + stoi(str2);
        str = to_string(n);
        str2 = "";
        for(int j = str.size() - 1; j >= 0; j--) str2 += str[j];
        if(str == str2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}