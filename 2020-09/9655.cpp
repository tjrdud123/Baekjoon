#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N;
int isWin[1001];
bool game(int N) {
	if (isWin[N] != -1) return isWin[N];
	if (game(N - 1) == 1 && game(N - 3) == 1) return isWin[N] = 0;
	else return isWin[N] = 1;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(isWin, -1, sizeof(isWin));
	cin >> N;
	isWin[0] = 0;
	isWin[1] = 1;
	isWin[2] = 0;
	isWin[3] = 1;
	
	if (game(N)) cout << "SK";
	else cout << "CY";
	return 0;
}