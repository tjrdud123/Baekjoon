#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int N, M;
int toNumber(char ch) {
    return ch - 'a';
}
typedef struct Node {
    Node* children[26];
    bool isTerminal;
    Node() {
        for(int i = 0; i < 26; i++) children[i] = NULL;
        isTerminal = false;
    }
    void insert(string& key, int idx) {
        if(idx == key.size()) isTerminal = true;
        else {
            int next = toNumber(key[idx]);
            if(children[next] == NULL) children[next] = new Node();
            children[next]->insert(key, idx + 1);
        }
    }
    Node* find(string& key, int idx) {
        if(idx == key.size()) return this;
        int next = toNumber(key[idx]);
        if(children[next] == NULL) return NULL;
        return children[next]->find(key, idx + 1);
    }
} Node;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    Node* root = new Node();
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        root->insert(str, 0);
    }
    int ans = 0;
    for(int i = 0; i < M; i++) {
        string str;
        cin >> str;
        Node* node = root->find(str, 0);
        if(node != NULL && node->isTerminal == true) ans++;
    }
    cout << ans;
    return 0;
}