#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

long long solution(int n, vector<int> times) {
  long long answer = LLONG_MAX;
  int len = times.size();
  sort(times.begin(), times.end());
  ll l = 1, r = (ll)times[len - 1] * (ll)n;

  while (l <= r) {
    ll m = (l + r) / 2;
    ll sum = 0;
    for (int i = 0; i < len; i++) {
      sum += m / times[i];
    }
    if (n <= sum) {
      answer = min(answer, m);
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 6;
  vi times = {7, 10};

  cout << solution(n, times) << endl;

  return 0;
}