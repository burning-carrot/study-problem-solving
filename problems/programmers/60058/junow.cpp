#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool isBalanced(string& p) {
  int cnt = 0;
  for (auto& _p : p) {
    if (_p == '(')
      cnt++;
    else
      cnt--;
  }
  return cnt == 0;
}

bool isRight(string& p) {
  stack<char> s;
  for (auto& _p : p) {
    if (_p == '(') {
      s.push(_p);
    } else {
      if (s.size() == 0) return false;
      s.pop();
    }
  }
  return s.size() == 0;
}

string flip(string& s) {
  int size = s.size();
  string ret = s.substr(1, size - 2);
  for (int i = 0; i < ret.size(); i++) {
    if (ret[i] == '(')
      ret[i] = ')';
    else
      ret[i] = '(';
  }

  return ret;
}
string convert(string& w) {
  if (w.size() == 0) return "";
  int open = 0, close = 0, idx = 0, size = w.size();
  for (int i = 0; i < size; i++) {
    if (w[i] == '(')
      open++;
    else
      close++;
    idx++;
    if (open == close) break;
  }

  string u = w.substr(0, idx);
  string v = w.substr(idx);

  string t = "";
  string ret = "";
  if (isRight(u)) {
    ret += u;
    ret += convert(v);
  } else {
    ret += "(";
    ret += convert(v);
    ret += ")";

    ret += flip(u);
  }
  return ret;
}
string solution(string p) {
  string answer = "";

  return convert(p);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string p1 = "(()())()";
  string p2 = ")(";
  string p3 = "()))((()";
  cout << solution(p1) << endl;
  cout << solution(p2) << endl;
  cout << solution(p3) << endl;
  return 0;
}