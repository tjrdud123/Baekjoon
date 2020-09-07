#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <ctype.h>
using namespace std;
const int ALPHABETS = 26;
int toNumber(char ch) {
	return ch - 'a';
}
typedef struct TrieNode {
	TrieNode* children[ALPHABETS];
	bool isTerminal;
	TrieNode() : isTerminal(false) {
		memset(children, 0, sizeof(children));
	}
	~TrieNode() {
		for (int i = 0; i < ALPHABETS; i++) {
			if (children[i]) delete children[i];
		}
	}
	void insert(const char* key) {
		if (*key == 0) {
			isTerminal = true;
		}
		else {
			int next = toNumber(*key);
			if (children[next] == NULL) 
				children[next] = new TrieNode();
			children[next]->insert(key + 1);
		}
	}
	TrieNode* find(const char* key) {
		if (*key == 0) return this;
		int next = toNumber(*key);
		if (children[next] == NULL) return NULL;
		return children[next]->find(key + 1);
	}
};
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	return 0;
}