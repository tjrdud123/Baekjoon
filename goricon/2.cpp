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
    vector<pair<int, int>> cnt;
    bool cmp(pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    int main(void) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin >> N;
        cnt.resize(N + 1);
        for(int i = 0; i <= N; i++) cnt[i] = make_pair(i, 0);
        for(int i = 0; i < N; i++) {
            int t;
            cin >> t;
            cnt[t].second++;
        }
        sort(cnt.begin(), cnt.end(), cmp);
        
        if(cnt[N].first == 0) {
            if(cnt[N - 1].second == cnt[N - 2].second) {
                cout << "skipped";
            }
            else {
                cout << cnt[N - 1].first;
            }
        }
        else {
            if(cnt[N].second == cnt[N - 1].second) {
                cout << "skipped";
            }
            else {
                cout << cnt[N].first;
            }
        }
        return 0;
    }