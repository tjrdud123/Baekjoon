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
vector<string> _board;
vector<pair<int, int> > find() {
	vector<pair<int, int> > ret;
	int m = _board.size(), n = _board[0].size();
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			char ch = _board[i][j];
			if (ch == ' ') continue;
			if (_board[i][j + 1] == ch && _board[i + 1][j] == ch && _board[i + 1][j + 1] == ch) {
				ret.push_back(make_pair(i, j));
				ret.push_back(make_pair(i, j + 1));
				ret.push_back(make_pair(i + 1, j));
				ret.push_back(make_pair(i + 1, j + 1));
			}
		}
	}
	return ret;
}
void fall() {
	int m = _board.size(), n = _board[0].size();
	for (int i = m - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (_board[i][j] != ' ') {
				int y;
				for (y = i + 1; y < m; y++) {
					if (_board[y][j] != ' ') break;
				}
				
					char temp = _board[y - 1][j];
					_board[y - 1][j] = _board[i][j];
					_board[i][j] = temp;
				
			}
		}
	}
}
int solution(int m, int n, vector<string> board) {
	int ans = 0;
	_board = board;
	while (true) {
		vector<pair<int, int> > v = find();
		if (v.empty()) break;
		for (int i = 0; i < v.size(); i++) {
			int y = v[i].first, x = v[i].second;
			if (_board[y][x] != ' ') ans++;
			_board[y][x] = ' ';
		}
	
		fall();
		
		
	}
	return ans;
}