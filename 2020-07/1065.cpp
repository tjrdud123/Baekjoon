#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N, K;
int ans = 0;
vector<bool> possible(26, 0);
vector<string> words;
void f(int idx, int toPick) {
	if (toPick == 0) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			string str = words[i];
			bool flag = 1;
			for (int j = 4; j < str.size() - 4; j++) {
				if (!possible[str[j] - 'a'])
					flag = 0;
			}
			if (flag)
				cnt++;
		}
		ans = max(ans, cnt);
	}
	for (int i = idx; i < 26; i++) {
		if (!possible[i]) {
			possible[i] = true;
			f(i + 1, toPick - 1);
			possible[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		words.push_back(str);
	}
	if (K < 5) {
		cout << 0;
		return 0;
	}
	possible['a' - 'a'] = possible['n' - 'a'] = possible['t' - 'a'] = possible['c' - 'a'] = possible['i' - 'a'] = true;
	f(0, K - 5);
	cout << ans;
	return 0;
}