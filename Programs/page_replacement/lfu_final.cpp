#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> requests;
  // page, freq
  map<int, int> freq;
  // page, age
  map<int, int> age;
  // page
  vector<int> cache;
  int cycle_count = 0;
  int n, t;
  int faults = 0, cache_hits = 0;
  cout << "Enter the number of requests: " ;
  cin >> n;
  cout << "Enter the requests: " << endl;
  for (int i = 0; i < n; ++i){
    cin >> t;
    requests.push_back(t);
  }

  int max_frames;
  cout << "Enter the number of cache frames: ";
  cin >> max_frames;

  int min_freq;
  vector<int> tempv;

  age.insert(make_pair(1, 1));
  age.insert(make_pair(2, 1));
  transform(age.begin(), age.end(), age.begin(), [](pair<int, int> &x){return make_pair(x.first, x.second+1);});
  cout << age[1] << endl << age[2];
  //
  // for(int r: requests){
  //   if (cache.size() < max_frames){
  //     freq[r]++;
  //     cache.push_back(r);
  //     transform(age.begin(), age.end(), [](int x): {return x.second++})
  //   }
  // }

  return 0;
}
