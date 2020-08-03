#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int answer = 0;

bool check(string& selected, vector<string>& data) {
  for (auto& s : data) {
    char from = s[0];
    char to = s[2];
    char op = s[3];
    int num = s[4] - '0';

    int idx1 = selected.find(from);
    int idx2 = selected.find(to);
    int diff = abs(idx2 - idx1) - 1;

    if (op == '=') {
      if (diff != num) {
        return false;
      }
    } else if (op == '<') {
      if (diff >= num) {
        return false;
      }
    } else {
      if (diff <= num) {
        return false;
      }
    }
  }
  return true;
}

int solution(int n, vector<string> data) {
  int answer = 0;
  string selected = "ACFJMNRT";
  do {
    if (check(selected, data)) {
      answer++;
    }
  } while (next_permutation(selected.begin(), selected.end()));
  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 2;
  vector<string> data1 = {"N~F=0", "R~T>2"};
  vector<string> data2 = {"M~C<2", "C~M>1"};

  cout << solution(n, data1) << endl;

  return 0;
}