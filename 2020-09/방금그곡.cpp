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
typedef struct info {
	int idx;
	int start, end, length;
	string title, music;
} info;
bool cmp(info a, info b) {
	if (a.length == b.length) {
		return a.start < b.start;
	}
	else return a.length > b.length;
}
string solution(string m, vector<string> musicinfos) {

	int N = musicinfos.size();
	vector<info> infos(N);
	for (int i = 0; i < N; i++) {
		infos[i].idx = i;
		string str = musicinfos[i];
		int h = stoi(str.substr(0, 2));
		int ma = stoi(str.substr(3, 2));

		infos[i].start = h * 60 + ma;
		h = stoi(str.substr(6, 2));
		ma = stoi(str.substr(9, 2));

		infos[i].end = h * 60 + ma;
		infos[i].length = infos[i].end - infos[i].start + 1;

		int idx = str.find(',', 12);
		//cout << idx << "\n";
		infos[i].title = str.substr(12, idx - 12);

		string mel = str.substr(idx + 1, 3000);

		string mel2;
		for (int j = 0; j < mel.size(); j++) {
			if (mel[j] == '#') {
				mel2.back() += 32;
			}
			else mel2 += mel[j];
		}
		mel = mel2;
		int size = mel.size();

		int j;
		for (j = 0; infos[i].music.size() < infos[i].length; j++) {

			infos[i].music += mel[j % size];

		}
		cout << mel << "\n";
	}
	string m2;
	for (int i = 0; i < m.size(); i++) {
		if (m[i] == '#') {
			m2.back() += 32;
		}
		else m2 += m[i];
	}
	m = m2;
	sort(infos.begin(), infos.end(), cmp);
	for (int i = 0; i < N; i++) {
		string music = infos[i].music;
		if (music.find(m) != string::npos) {
			return infos[i].title;
		}

	}
	return "(None)";
}