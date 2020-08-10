#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

struct INFO {
  int plays;
  int id;
};

struct compare {
  bool operator()(const INFO& a, const INFO& b) {
    if (a.plays < b.plays) return 1;
    if (a.plays > b.plays) return 0;
    if (a.id < b.id) return 0;
    if (a.id > b.id) return 1;
    return 1;
  }
};
vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;
  map<string, priority_queue<INFO, vector<INFO>, compare>> genreTotal;  // 장르 : {횟수, id}
  priority_queue<pair<int, string>> topPlays;                           // 횟수, 장르
  map<string, int> playsByGenre;                                        // 장르, 횟수
  int size = genres.size();

  for (int i = 0; i < size; i++) {
    if (playsByGenre.find(genres[i]) == playsByGenre.end()) {
      playsByGenre[genres[i]] = 0;
    }
    if (genreTotal.find(genres[i]) == genreTotal.end()) {
      priority_queue<INFO, vector<INFO>, compare> _pq;
      _pq.push({plays[i], i});
      genreTotal[genres[i]] = _pq;
    } else {
      genreTotal[genres[i]].push({plays[i], i});
    }
    playsByGenre[genres[i]] += plays[i];
  }

  for (auto& v : playsByGenre) {
    topPlays.push({v.second, v.first});
  }

  while (!topPlays.empty()) {
    string topPlayedGenre = topPlays.top().second;  // 플레이횟수순 장르들
    topPlays.pop();
    for (int j = 0; j < 2; j++) {
      if (genreTotal[topPlayedGenre].size() == 0) break;
      INFO topInGenre = genreTotal[topPlayedGenre].top();
      genreTotal[topPlayedGenre].pop();
      answer.push_back(topInGenre.id);
    }
  }

  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<string> genres = {"classic", "pop", "classic", "classic"};
  vector<int> plays = {500, 600, 150, 800};
  auto ans = solution(genres, plays);
  for (auto& v : ans) {
    cout << v << " ";
  }
  cout << endl;

  return 0;
}