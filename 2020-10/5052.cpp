#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
int T, N;
int toNumber(char ch) {
    return ch - '0';
}
typedef struct Node {
    bool isTerminal;
    Node* children[10];
    Node() : isTerminal(false) {
        memset(children, 0, sizeof(children));
    }
    void insert(string key) {
        if(key == "") isTerminal = true;
        else {
            int next = toNumber(key[0]);
            if(children[next] == NULL) children[next] = new Node();
            children[next]->insert(key.substr(1));
        }
    }
    Node* find(string key) {
        if(key == "") return this;
        int next = toNumber(key[0]);
        if(children[next] == NULL) return NULL;
        return children[next]->find(key.substr(1));
    }
} Node;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while(T--) {
        Node *root = new Node();
        vector<string> v;
        cin >> N;
        for(int i = 0; i < N; i++) {
            string str;
            cin >> str;
            v.push_back(str);
            root->insert(str);
        }
        bool flag = true;
        for(int i = 0; i < N; i++) {
            Node* node = root->find(v[i]);
            for(int j = 0; j < 10; j++) {
                if(node->children[j] != NULL) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}