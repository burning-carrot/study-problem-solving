#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
  if (a.size() < b.size()) return true;
  return false;
}
vector<int> solution(string s) {
  vector<int> answer;
  vector<string> strv;
  set<string> sset;
  string s2 = s.substr(1, s.size() - 2);
  int len = s2.size();
  int i = 0;
  while (i < len) {
    if (s2[i] == '{') {
      string t;
      while (s[i++] != '}') {
        t.push_back(s[i]);
      }
      strv.push_back(t.substr(1, t.size() - 2));
    }
  }

  sort(strv.begin(), strv.end(), cmp);

  for (auto a : strv) {
    istringstream ss(a);
    string sb;
    vector<string> a2;
    while (getline(ss, sb, ',')) {
      a2.push_back(sb);
    }

    for (auto b : a2) {
      if (sset.find(b) == sset.end()) {
        sset.insert(b);
        answer.push_back(stoi(b));
      }
    }
  }

  return answer;
}

int main(void) {
  string s1 = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
  string s2 = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
  string s3 = "{{20,111},{111}}";
  string s4 = "{{123}}";
  string s5 = "{{4,2,3},{3},{2,3,4,1},{2,3}}";

  vector<int> ans = solution(s5);
  for (int a : ans) {
    cout << a << " ";
  }
  return 0;
}