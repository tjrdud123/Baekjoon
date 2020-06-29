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
int N;
bool pos[1000];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 1000; i++)
		pos[i] = true;
	for (int i = 100; i < 1000; i++) {
		string target = to_string(i);
		if (target[0] == '0' || target[1] == '0' || target[2] == '0')
			pos[i] = false;
		if (target[0] == target[1] || target[1] == target[2] || target[0] == target[2])
			pos[i] = false;
	}
	for (int i = 0; i < N; i++) {
		string str;
		int S, B;
		cin >> str >> S >> B;

		for (int i = 100; i < 1000; i++) {
			string target = to_string(i);
			int s = 0;
			int b = 0;
			if (pos[i] == false)
				continue;
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					
					if (x == y && target[x] == str[y])
						s++;
					else if (x != y && target[x] == str[y])
						b++;
				}
			}
			if (S != s || B != b)
				pos[i] = false;
		}
	}
	int ans = 0;
	for (int i = 100; i < 1000; i++) {
		if (pos[i])
			ans++;
	}
	cout << ans;
	return 0;
}