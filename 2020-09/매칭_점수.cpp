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
typedef struct webPage {
	string content;
	int basicPoint;
	vector<string> links;
	double linkPoint = 0;
	double matchingPoint = 0;
} webPage;
vector<int> getPI(string N) {
	int m = N.size();
	vector<int> ret(m, 0);

	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			matched++;
			ret[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - ret[matched - 1];
				matched = ret[matched - 1];
			}
		}
	}
	return ret;
}
vector<int> kmp(string H, string N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPI(N);

	int begin = 0, matched = 0;
	while (begin <= n - m) {
		if (matched < m && H[begin + matched] == N[matched]) {
			matched++;
			if (matched == m) ret.push_back(begin);
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
vector<string> words;
void getWords(string word, int idx) {
	if (idx == word.size()) {
		words.push_back(word);
		return;
	}
	char ch = word[idx];
	getWords(word, idx + 1);
	if (65 <= ch && ch <= 90) word[idx] += 32;
	else if (97 <= ch && ch <= 122) word[idx] -= 32;
	getWords(word, idx + 1);
}
int solution(string word, vector<string> pages) {
	int answer = 0;
	int nPages = pages.size();
	vector<webPage> infos(nPages);

	getWords(word, 0);

	for (int i = 0; i < nPages; i++) {
		string page = pages[i];
		for (int j = 0; j < words.size(); j++) {
			vector<int> v = kmp(page, words[j]);
			for (int k = 0; k < v.size(); k++) {
				char ch1 = page[v[k] - 1];
				char ch2 = page[v[k] + word.size()];
				if (!isupper(ch1) && !islower(ch1) && !isupper(ch2) && !islower(ch2)) {
					infos[i].basicPoint++;
				}
			}
		}
		vector<int> v = kmp(page, "<meta property=\"og:url\"");
		int idx = v[0];
		idx += 33;
		while (page[idx] != '\"') infos[i].content += page[idx++];
		v = kmp(page, "<a href=\"");
		for (int j = 0; j < v.size(); j++) {
			string link = "";
			int idx = v[j] + 9;
			while (page[idx] != '\"') link += page[idx++];
			infos[i].links.push_back(link);
		}
	}

	for (int i = 0; i < nPages; i++) {
		for (int j = 0; j < nPages; j++) {
			if (i == j) continue;
			for (int k = 0; k < infos[j].links.size(); k++) {
				string link = infos[j].links[k];
				if (infos[i].content == link) {
					infos[i].linkPoint += ((double)infos[j].basicPoint / (double)infos[j].links.size());
					break;
				}
			}
		}
	}
	for (int i = 0; i < nPages; i++) {
		infos[i].matchingPoint += (double)infos[i].basicPoint + infos[i].linkPoint;
	}
	double max = -1.0;
	for (int i = 0; i < nPages; i++) {
		if (max < infos[i].matchingPoint) {
			answer = i;
			max = infos[i].matchingPoint;
		}
	}
	return answer;
}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	return 0;
}
