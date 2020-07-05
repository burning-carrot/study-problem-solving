#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int f(int& m, int& n, vector<int>& rocks) {
  int prev = 0;
  int cnt = 0;
  for (int i = 1; i < rocks.size(); ++i) {
    int diff = rocks[i] - rocks[prev];
    if (diff < m) {
      cnt++;
    } else
      prev = i;
  }

  return cnt > n;
}

int solution(int distance, vector<int> rocks, int n) {
  int answer = 0;

  rocks.push_back(0);
  rocks.push_back(distance);
  sort(rocks.begin(), rocks.end());

  int l = 0, r = distance;

  while (l <= r) {
    int m = (l + r) / 2;
    if (f(m, n, rocks)) {
      r = m - 1;
    } else {
      l = m + 1;
      answer = m;
    }
  }

  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int distance = 25;
  vector<int> rocks = {2, 14, 11, 21, 17};
  int n = 2;
  cout << solution(distance, rocks, n) << "\n";

  return 0;
}