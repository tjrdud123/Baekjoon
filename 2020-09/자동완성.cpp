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
	int n;
	TrieNode() : isTerminal(false), n(0) {
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
			if (children[next] == NULL) {
				children[next] = new TrieNode();
				
			}
			children[next]->insert(key + 1);
			children[next]->n++;
		}
	}
	TrieNode* find(const char* key) {
		if (*key == 0) return this;
		int next = toNumber(*key);
		if (children[next] == NULL) return NULL;
		return children[next]->find(key + 1);
	}
};
int solution(vector<string> words) {
	int N = words.size();
	TrieNode* root = new TrieNode();
	for (int i = 0; i < N; i++) {
		const char* word = words[i].c_str();
		root->insert(word);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		string word = words[i];
		for (int j = 1; j <= word.size(); j++) {
			string temp = word.substr(0, j);
			const char* w = temp.c_str();
			TrieNode* node = root->find(w);
			//cout << temp << " " << node->n << "\n";
			if (node != NULL && node->n == 1) {
				//cout << temp << "\n";
				ans += j;
				break;
			}
			if (j == word.size()) {
				ans += j;
				break;
			}
		}
	}
	return ans;
}