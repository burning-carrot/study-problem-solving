#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int solution(string arr) {
  int answer = 0;
  int sticks = 0;
  int size = arr.size();
  for (int i = 0; i < size; i++) {
    if (arr[i] == '(') {
      if (arr[i + 1] == ')') continue;
      sticks++;
      answer++;
      continue;
    }
    if (arr[i - 1] == '(') {
      answer += sticks;
    } else {
      sticks--;
    }
  }
  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s = "()(((()())(())()))(())";

  cout << solution(s) << endl;

  return 0;
}