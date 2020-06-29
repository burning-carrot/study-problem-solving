#include <bits/stdc++.h>

using namespace std;

int T, N, ans;

void dfs(int n) {
  if (n == 0) {
    ans++;
    return;
  }

  for (int i = 1; i <= 3; i++) {
    if (n - i >= 0) {
      dfs(n - i);
    }
  }
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N;
    ans = 0;
    dfs(N);
    cout << ans << "\n";
  }
  return 0;
}
