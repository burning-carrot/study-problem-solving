#include <bits/stdc++.h>

using namespace std;

int n;
int board[20][20];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  int ans = 0x7f7f7f7f;
  for (int i = 0; i < ((1 << n) - 1); i++) {
    if (__builtin_popcount(i) != (n / 2)) continue;
    // cout << bitset<8>(i) << "\n";

    vector<int> s, l;

    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        s.push_back(j);
      } else {
        l.push_back(j);
      }
    }
    int s1 = 0, s2 = 0;
    for (int j = 0; j < n / 2; j++) {
      for (int k = 0; k < n / 2; k++) {
        s1 += board[s[j]][s[k]];
        s2 += board[l[j]][l[k]];
      }
    }

    ans = min(ans, abs(s1 - s2));
  }

  cout << ans << "\n";

  return 0;
}