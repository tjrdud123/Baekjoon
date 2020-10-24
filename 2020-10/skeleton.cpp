#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<string> split(string str) {
    vector<string> ret;
    int start = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == ' ') {
            ret.push_back(str.substr(start, i - start));
            start = i + 1;
        }
    }
    ret.push_back(str.substr(start));
    return ret;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    string str;
    getline(cin, str);
    for(int i = 0; i < N; i++) {
        getline(cin, str);
        vector<string> t = split(str);
        cout << "god";
        for(int i = 1; i < t.size(); i++) {
            cout << t[i];
        }
        cout << "\n";
    }

    return 0;
}