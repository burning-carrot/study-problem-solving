#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int N, C, a[200000];

int f(int m) {
  int ret = 1;
  int before = a[0];
  for (int i = 1; i < N; i++) {
    if (a[i] - before >= m) {
      before = a[i];
      ret++;
    }
  }

  return ret;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> C;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  sort(a, a + N);

  int l, r;
  l = 0;
  r = a[N - 1] - a[0];

  while (l <= r) {
    int m = (l + r) / 2;
    int t = f(m);

    if (t < C) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  cout << r << "\n";
  return 0;
}
