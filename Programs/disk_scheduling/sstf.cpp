#include<bits/stdc++.h>

using namespace std;

int seek(int n, int head, vector<int> q, bool print=true){
  int current;
  int total_seek = 0;

  std::vector<int> left, right;
  for (auto i: q){
    if (i > head)
      right.push_back(i);
    else
      left.push_back(i);
  }

  sort(left.begin(), left.end(), greater<int>());
  sort(right.begin(), right.end());

  int i = 0, l = 0, r = 0;

  while (l < left.size() && r < right.size()){
    if (abs(head - left[l]) < abs(head - right[r])){
      if (print)
        cout << "Move from " << head << " to " << left[l] << " with seek " << abs(left[l] - head) << endl;
      total_seek += abs(left[l] - head);
      head = left[l++];
    }
    else {
      if (print)
        cout << "Move from " << head << " to " << right[r] << " with seek " << abs(right[r] - head) << endl;
      total_seek += abs(right[r] - head);
      head = right[r++];
    }
  }

  while (l < left.size()){
    if (print)
      cout << "Move from " << head << " to " << left[l] << " with seek " << abs(left[l] - head) << endl;
    total_seek += abs(left[l] - head);
    head = left[l++];
  }
  while (r < right.size()){
    if (print)
      cout << "Move from " << head << " to " << right[r] << " with seek " << abs(right[r] - head) << endl;
    total_seek += abs(right[r] - head);
    head = right[r++];
  }


  return total_seek;
}


int main(int argc, char const *argv[]) {
  vector<int> q;
  int head, pos;
  int n;

  cout << "Enter the size of Queue: ";
  cin >> n;
  cout << "Enter the initial head position: ";
  cin >> head;
  cout << "Enter the Queue: ";

  for (int i = 0; i < n; ++i){
    cin >> pos;
    q.push_back(pos);
  }

  int total_seek = seek(n, head, q);
  cout << "\nTotal seek time is " << total_seek << endl;
  cout << "Average seek time is " << total_seek / float(n) << endl;
  return 0;
}
