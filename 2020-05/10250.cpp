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
int T, H, W, N;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> H >> W >> N;
		int t = N % H;
		if (t == 0)
			t = H;
		t *= 100;
		t += N / H;
		if (N % H != 0)
			t++;
		cout << t << endl;
	}
	return 0;
}