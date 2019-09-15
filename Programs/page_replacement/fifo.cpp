#include<bits/stdc++.h>

using namespace std;

void print_cache(deque<int> q){
  for(auto i: q){
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> requests;
  int n, t;
  int faults = 0, cache_hits = 0;
  cout << "Enter the number if requests: " ;
  cin >> n;
  cout << "Enter the requests: " << endl;
  for (int i = 0; i < n; ++i){
    cin >> t;
    requests.push_back(t);
  }

  int max_frames;
  cout << "Enter the number of cache frames: ";
  cin >> max_frames;

  deque<int> cache;

  for (int i = 0; i < max_frames; ++i){
    cache.push_back(requests[i]);
    faults++;
    print_cache(cache);
  }

  for (int i = max_frames; i < n; ++i){
    int r = requests[i];
    if (find(cache.begin(), cache.end(), r) == cache.end()) {
      faults++;
      cache.pop_front();
      cache.push_back(r);
    }
    else
      cache_hits++;
    print_cache(cache);
  }
  cout << faults << " page faults." << endl;
  cout << cache_hits << " cache hits." << endl;
  return 0;
}

// 7 2 3 1 2 5 3 4 6 7 7 1 0 5 4 6 2 3 0 1
