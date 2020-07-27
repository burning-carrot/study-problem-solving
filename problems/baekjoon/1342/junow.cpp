#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

string s;
int ans, cnt[26];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  int size = s.size();
  do {
    bool flag = true;
    for (int i = 0; i < size - 1; i++) {
      if (s[i] == s[i + 1]) {
        flag = false;
        break;
      }
    }
    if (flag) ans++;
  } while (next_permutation(s.begin(), s.end()));

  cout << ans << endl;

  return 0;
}
