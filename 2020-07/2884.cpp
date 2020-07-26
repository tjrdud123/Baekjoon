#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int h, m;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> h >> m;
	for (int i = 0; i < 45; i++) {
		m--;
		if (m < 0) {
			h--;
			if (h < 0)
				h = 23;
			m = 59;
		}
	}
	cout << h << " " << m;
	return 0;
}