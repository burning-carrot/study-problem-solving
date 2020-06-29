#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[11];
int limit;

void dfs(int n, int sum) {
  if (sum > 10) {
    return;
  }
  if (n == limit) {
    dp[sum] += 1;
    return;
  }

  dfs(n + 1, sum + 1);
  dfs(n + 1, sum + 2);
  dfs(n + 1, sum + 3);
}

void init() {
  for (int i = 1; i <= 10; i++) {
    limit = i;
    dfs(0, 0);
  }
}

void solution() {
  int N;
  cin >> N;

  cout << dp[N] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  init();
  for (int t = 0; t < T; t++) {
    solution();
  }
  // solution();

  return 0;
}