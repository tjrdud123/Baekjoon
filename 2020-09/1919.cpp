#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int cnt[26];
int main(void) {
	memset(cnt, 0, sizeof(cnt));
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		cnt[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.size(); i++) {
		cnt[s2[i] - 'a']--;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] != 0) ans += abs(cnt[i]);
	}
	cout << ans;
	return 0;
}