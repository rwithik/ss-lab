#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>

// available[i] = k => k instances of resource i are available
// max[i, j] = k => max allowed number of instances of resource j for process i is k
// allocation[i, j] = k => k instances of resource j is currently allocated to process i
// need[i, j] = max[i, j] - allocation[i, j]


bool safety(vi available, vii max, vii allocation, int p, int r){
  int finished = 0;
  vii need;

  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < r; ++j) {
      need[i][j] = max[i][j] - allocation[i][j];
    }
  }

  vi work;
  copy(available.begin(), available.end(), work.begin());

  vector<bool> finish(p, false);
  int i = 0;
  while (finished < p){
    bool found = false;

    for (int i = 0; i < p; ++i) {
      if (!finish[i]) {
        int j;
        for (j = 0; j < r; j++)
        if (need[p][j] > work[j])
        break;

        if (j == r)
        {
          for (int k = 0 ; k < r ; k++)
          work[k] += allocation[i][k];
          finish[i] = true;
          found = true;
        }
      }
    }
    if (found == false)
    {
      return false;
    }
  }
  return true;
}

int main(int argc, char const *argv[]) {
  int r = 3, p = 5;
  vi processes = {0, 1, 2, 3, 4};

  vi avail = {3, 3, 2};

  vii maxm = {{7, 5, 3},
                   {3, 2, 2},
                   {9, 0, 2},
                   {2, 2, 2},
                   {4, 3, 3}};

  vii allot = {{0, 1, 0},
                    {2, 0, 0},
                    {3, 0, 2},
                    {2, 1, 1},
                    {0, 0, 2}};

  cout << safety(avail, maxm, allot, p, r);
  return 0;
}
