#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

ll dp[2001];

long long solution(int n) {
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i < n + 1; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
  }

  return dp[n];
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << solution(2000) << endl;
  return 0;
}