#include<bits/stdc++.h>

using namespace std;

int seek(int n, int head, vector<int> q, bool print=true){
  std::vector<int> left, right;
  for (auto i: q){
    if (i > head)
      right.push_back(i);
    else
      left.push_back(i);
  }

  sort(left.begin(), left.end());
  sort(right.begin(), right.end());

  int current;
  int total_seek = 0;

  for(int i: right){
    if (print)
      cout << "Move from " << head << " to " << i 
			  << " with seek " << abs(i - head) << endl;
    total_seek += abs(i - head);
    head = i;
  }
  for(int i: left){
    if (print)
      cout << "Move from " << head << " to " << i 
			  << " with seek " << abs(i - head) << endl;
    total_seek += abs(i - head);
    head = i;
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
