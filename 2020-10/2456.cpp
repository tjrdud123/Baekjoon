#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
typedef struct Elem {
    int idx;
    vector<int> count;
    int total;
} Elem;
bool cmp(Elem a, Elem b) {
    if(a.total == b.total) {
        if(a.count[3] != b.count[3]) return a.count[3] < b.count[3];
        if(a.count[2] != b.count[2]) return a.count[2] < b.count[2];
    }
    return a.total < b.total;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<Elem> A(3);
    for(int i = 0; i < 3; i++) {
        A[i].idx = i;
        A[i].count.assign(4, 0);
        A[i].total = 0;
    }
    cin >> N;
    for(int i = 0; i < N; i++) {
        vector<int> point(3);
        cin >> point[0] >> point[1] >> point[2];

        for(int j = 0; j < 3; j++) {
            A[j].total += point[j];
            A[j].count[point[j]]++;
        }
    }
    sort(A.begin(), A.end(), cmp);

    if(A[1].total == A[2].total) {
        if(A[1].count[2] == A[2].count[2]) {
            if(A[1].count[3] == A[2].count[3]) {
                cout << 0 << " " << A[2].total;
                return 0;
            }
        }
    }

    cout << A[2].idx + 1 << " " << A[2].total;


    return 0;
}