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
vector<long long> numbers;
vector<char> opers;
long long comp(long long a, long long b, char op) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}
void subsol(char op) {
	for (int i = 0; i < opers.size(); i++) {
		if (opers[i] == op) {
			numbers[i] = comp(numbers[i], numbers[i + 1], op);
			numbers.erase(numbers.begin() + i + 1);
			opers.erase(opers.begin() + i);
			i--;
		}
	}
	
}
long long solution(string expression) {
	long long n = 0LL;
	for (int i = 0; i < expression.size(); i++) {
		char ch = expression[i];
		if ('0' <= ch && ch <= '9') {
			n *= 10;
			n += ch - '0';
		}
		else {
			numbers.push_back(n);
			n = 0LL;
			opers.push_back(ch);
		}
	}
	numbers.push_back(n);
	
	vector<long long> A = numbers;
	vector<char> B = opers;
	long long ans = 0;
	subsol('+'); subsol('-'); subsol('*');
	ans = max(ans, abs(numbers[0]));
	
	numbers = A; opers = B;
	
	subsol('+'); subsol('*'); subsol('-');
	ans = max(ans, abs(numbers[0]));
	numbers = A; opers = B;

	subsol('*'); subsol('-'); subsol('+');
	ans = max(ans, abs(numbers[0]));
	numbers = A; opers = B;

	subsol('*'); subsol('+'); subsol('-');
	ans = max(ans, abs(numbers[0]));
	numbers = A; opers = B;

	subsol('-'); subsol('*'); subsol('+');
	ans = max(ans, abs(numbers[0]));
	numbers = A; opers = B;

	subsol('-'); subsol('+'); subsol('*');
	ans = max(ans, abs(numbers[0]));
	numbers = A; opers = B;

	return ans;
}