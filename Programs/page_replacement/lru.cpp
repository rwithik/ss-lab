#include<bits/stdc++.h>

using namespace std;

void print_cache(vector<int> q){
  for(auto i: q){
    cout << i << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  vector<int> requests;
  int cycle_count = 0;
  map<int, int>  access_times;
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

  vector<int> cache;

  for (int i = 0; i < max_frames; ++i){
    cache.push_back(requests[i]);
    faults++;
    access_times[requests[i]] = cycle_count;
    cycle_count++;
    print_cache(cache);
  }

  int min_access_time = access_times[requests[0]];
  int lrp = requests[0];

  for (int i = max_frames; i < n; ++i) {
    int r = requests[i];
    if (find(cache.begin(), cache.end(), r) == cache.end()) {
      faults++;
      cerr << "fault!" << endl;

      for(auto j = access_times.begin(); j != access_times.end(); ++j){
        if (j -> second < min_access_time){
          min_access_time = j -> second;
          lrp = j -> first;
          cerr << "lrp: " << lrp << endl;
        }
      }

      vector<int>::iterator it = find(cache.begin(), cache.end(), lrp);
      cache.erase(it);
      cache.insert(it, r);
      access_times.erase(lrp);
    }
    else{
      cache_hits++;
    }
    access_times[r] = cycle_count;
    min_access_time = access_times[r];
    lrp = r;
    print_cache(cache);
    cycle_count++;
  }

  cout << cache_hits << " cache hits." << endl;
  cout << faults << " page faults." << endl;

  return 0;
}
