#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int N, M;
vector<int> v(1000000);

ll f(int h) {
  ll ret = 0;
  for (int i = 0; i < N; i++) {
    if (v[i] > h) {
      ret += (v[i] - h);
    }
  }
  return ret;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int maxh;
  maxh = 0;

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> v[i];
    maxh = max(maxh, v[i]);
  }

  int l = 0;
  int r = maxh;
  int ans = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    ll t = f(m);
    if (t < M) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  cout << r << "\n";
  return 0;
}