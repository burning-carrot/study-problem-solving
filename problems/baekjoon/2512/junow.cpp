#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int N, M, a[10000], maxv;

ll getSum(int m) {
  ll ret = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] <= m) {
      ret += a[i];
    } else {
      ret += m;
    }
  }
  return ret;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    maxv = max(maxv, a[i]);
  }
  cin >> M;

  int l = 0;
  int r = maxv;
  while (l <= r) {
    int m = (l + r) / 2;
    ll sum = getSum(m);
    if (sum <= M) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  cout << r << "\n";
  return 0;
}