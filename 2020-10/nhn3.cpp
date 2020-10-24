#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string conv(string str) {
  bool flag = true;
  for(int i = 0; i < str.size(); i++) {
    if(str[i] == '(' || str[i] == ')') {
      flag = false;
      break;
    }
  }
  if(flag) return str;

  string ret;
  int left, right;
  for(left = 0; ; left++) if(str[left] == '(') break;
  for(right = str.size() - 1; ; right--) if(str[right] == ')') break;

  ret = str.substr(0, left - 1);
  char suf = str[left - 1];
  string inStr = conv(str.substr(left + 1, right - left - 1));
  if('1' <= suf && suf <= '9') {
    // 숫자
    for(int j = 0; j < suf - '0'; j++) ret += inStr;
  }
  else {
    // 문자
    for(int j = 0; j < inStr.size(); j++) {
      ret += suf;
      ret += inStr[j];
    }
  }
  
  ret += str.substr(right + 1);
  return ret;
}
void solution(int numOfOrder, string *orderArr) {
  for(int i = 0; i < numOfOrder; i++) {
    string order = orderArr[i];
    for(int i = 0; i < order.size(); i++) {
      if('1' <= order[i] && order[i] <= '9') {
        if(order[i + 1] != '(' && order[i + 1] != ')') {
          int n = order[i] - '0';
          char ch = order[i + 1];
          order.erase(i, 1);
          order.insert(i, n - 1, ch);
        }
      }
    }

    // conv
    cout << conv(order) << "\n";
  }
}

struct input_data {
  int numOfOrder;
  string *orderArr;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfOrder;

  inputData.orderArr = new string[inputData.numOfOrder];
  for (int i = 0; i < inputData.numOfOrder; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.orderArr[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfOrder, inputData.orderArr);
  return 0;
}