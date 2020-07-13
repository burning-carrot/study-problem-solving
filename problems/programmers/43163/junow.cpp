#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int getDiff(string str1, string str2) {
  int ret = 0;
  for (int i = 0, len = str1.size(); i < len; i++) {
    if (str1[i] != str2[i]) ret++;
  }
  return ret;
}
int solution(string begin, string target, vector<string> words) {
  int answer = 0;
  queue<string> q;
  vector<bool> visit(begin.size());
  q.push(begin);

  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      auto cur = q.front();
      q.pop();

      if (cur == target) return answer;
      for (int i = 0, len = words.size(); i < len; i++) {
        if (visit[i]) continue;
        int diff = getDiff(words[i], cur);

        if (diff == 1) {
          visit[i] = true;
          q.push(words[i]);
        }
      }
    }
    answer++;
  }

  return 0;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string begin1 = "hit";
  string target1 = "cog";
  vector<string> words1 = {"hot", "dot", "dog", "lot", "log", "cog"};

  string begin2 = "hit";
  string target2 = "cog";
  vector<string> words2 = {"hot", "dot", "dog", "lot", "log"};
  cout << solution(begin2, target2, words2) << "\n";

  return 0;
}