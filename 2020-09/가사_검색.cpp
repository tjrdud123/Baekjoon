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
struct TrieNode {
	TrieNode* children[ALPHABETS];
	vector<TrieNode*> v;
	int cnt;
	bool isTerminal;
	TrieNode() : isTerminal(false), cnt(0) {
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
			cnt++;
			children[next]->insert(key + 1);
		}
	}
	TrieNode* find(const char* key) {
		if (*key == 0) return this;
		int next = toNumber(*key);
		if (children[next] == NULL) return NULL;
		return children[next]->find(key + 1);
	}
	int count(const char* key) {
		if (*key == 0) {
			return cnt;
		}
		int next = toNumber(*key);
		if (children[next] != NULL) return children[next]->count(key + 1);
		return 0;
	}
};
vector<int> solution(vector<string> words, vector<string> queries) {
	int N = words.size();
	vector<string> reverseWords = words;
	for (int i = 0; i < N; i++) reverse(reverseWords[i].begin(), reverseWords[i].end());

	vector<const char*> cwords, rcwords;
	cwords.resize(N);
	rcwords.resize(N);

	int cntArr[10001];
	memset(cntArr, 0, sizeof(cntArr));
	for (int i = 0; i < N; i++) {
		cntArr[words[i].size()]++;
		cwords[i] = words[i].c_str();
		rcwords[i] = reverseWords[i].c_str();
	}

	TrieNode * root1[10001];
	TrieNode * root2[10001];
	for (int i = 0; i < 10001; i++) {
		root1[i] = new TrieNode();
		root2[i] = new TrieNode();
	}
	for (int i = 0; i < N; i++) {
		int size = words[i].size();
		root1[size]->insert(cwords[i]);
	}

	for (int i = 0; i < N; i++) {
		int size = reverseWords[i].size();
		root2[size]->insert(rcwords[i]);
	}

	vector<int> ans;

	for (int i = 0; i < queries.size(); i++) {
		int size = queries[i].size();
		int t;
		TrieNode* node;
		if (queries[i][0] == '?' && queries[i][size - 1] == '?') {
			ans.push_back(cntArr[size]);
			continue;
		}
		if (queries[i][0] == '?') {
			reverse(queries[i].begin(), queries[i].end());
			int idx = queries[i].find('?');
			queries[i] = queries[i].substr(0, idx);
			const char* query = queries[i].c_str();
			t = root2[size]->count(query);
		}
		else {

			int idx = queries[i].find('?');
			queries[i] = queries[i].substr(0, idx);
			const char* query = queries[i].c_str();
			t = root1[size]->count(query);

		}
		ans.push_back(t);
	}
	return ans;
}
