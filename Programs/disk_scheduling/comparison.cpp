#include <bits/stdc++.h>

using namespace std;

namespace fcfs{
  #include "fcfs.cpp"
}
namespace scan{
  #include "scan.cpp"
}
namespace cscan{
  #include "cscan.cpp"
}
namespace look{
  #include "look.cpp"
}
namespace clook{
  #include "clook.cpp"
}
namespace sstf{
  #include "sstf.cpp"
}

int min(int a, int b){
  return (a < b) ? a : b;
}

int main(int argc, char const *argv[]) {
  vector<int> q;
  int head, pos, max;
  int n;

  cout << "Enter the size of Queue: ";
  cin >> n;
  cout << "Enter the initial head position: ";
  cin >> head;
  cout << "Enter the number of cylinders: ";
  cin >> max;
  cout << "Enter the Queue: ";

  for (int i = 0; i < n; ++i){
    cin >> pos;
    q.push_back(pos);
  }

  int fcfs_seek_time = fcfs::seek(n, head, q, false);
  int scan_seek_time = scan::seek(n, head, q, false);
  int cscan_seek_time = cscan::seek(n, head, q, max, false);
  int look_seek_time = look::seek(n, head, q, false);
  int clook_seek_time = clook::seek(n, head, q, false);
  int sstf_seek_time = sstf::seek(n, head, q, false);

  cout << "FCFS seek time  : " << fcfs_seek_time  << endl;
  cout << "SCAN seek time  : " << scan_seek_time  << endl;
  cout << "SCAN seek time  : " << cscan_seek_time << endl;
  cout << "LOOK seek time  : " << look_seek_time  << endl;
  cout << "CLOOK seek time : " << clook_seek_time << endl;
  cout << "SSTF seek time  : " << sstf_seek_time  << endl;
  cout << "\n\n";
  int smallest = min(min(min(min(min(fcfs_seek_time, scan_seek_time), cscan_seek_time), look_seek_time), clook_seek_time), sstf_seek_time);
  cerr << smallest << "<-" << endl;
  if(smallest == fcfs_seek_time){
    cout << "FCFS gives optimum seek time." << endl;
  }
  if(smallest == scan_seek_time){
    cout << "SCAN gives optimum seek time." << endl;
  }
  if(smallest == cscan_seek_time){
    cout << "CSCAN gives optimum seek time." << endl;
  }
  if(smallest == look_seek_time){
    cout << "LOOK gives optimum seek time." << endl;
  }
  if(smallest == clook_seek_time){
    cout << "CLOOK gives optimum seek time." << endl;
  }
  if(smallest == sstf_seek_time){
    cout << "SSTF gives optimum seek time." << endl;
  }

  return 0;
}
