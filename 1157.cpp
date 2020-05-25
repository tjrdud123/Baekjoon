#include <math.h>
#include <stdio.h>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <utility>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a')
			str[i] -= 32;
		cnt[(int)str[i] - 'A']++;
	}
	
	int maxV = 0;
	int maxI = 0;
	int a = 0;
	for (int i = 0; i < 26; i++) {
		if (maxV < cnt[i]) {
			maxV = cnt[i];
			maxI = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (maxV == cnt[i])
			a++;
	}
	if (a == 1) {
		cout << (char)(maxI + 'A') << endl;
	}
	else 
		cout << "?";
	return 0;
}