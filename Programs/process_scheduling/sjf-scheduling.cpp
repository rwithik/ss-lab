#include<bits/stdc++.h>

using namespace std;

class Process{
public:
  static int count;
  static int cycle_count;
  int id;
  int at;
  int wt;
  int tat;
  int bt;

  Process(){
    id = count++;
  }

};

float average_wt(int n, vector<Process> v){
  float avg = 0;
  for (Process i: v){
    avg += i.wt;
  }
  avg /= n;
  return avg;
}

float average_tat(int n, vector<Process> v){
  float avg = 0;
  for (int i = 0; i < n; ++i){
    avg += v[i].tat;
  }
  avg /= n;
  return avg;
}

void print(int n, vector<Process> v){
  cout << "Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time" << endl;
  cout << "-------\t----------\t------------\t------------\t---------------" << endl;
  for(Process& i: v){
    cout << i.id << "\t\t\t" << i.bt << "\t\t\t" << i.at << "\t\t\t\t" << i.wt << "\t\t\t\t" << i.tat << endl;
  }
  cout << "Average Waiting Time: " << average_wt(n, v) << endl;
  cout << "Average Turnaround Time: " << average_tat(n, v) << endl;
  cout << endl;
}


bool sort_on_bt(Process a, Process b){
  return a.bt < b.bt;
}

int Process::count = 0;
int Process::cycle_count = 0;

int main(int argc, char const *argv[]) {


  int n;
  cout << "Enter the number of processes: ";
  cin >> n;
  vector<Process> process(n);
  for(int i = 0; i < n; ++i){
    cout << "Process " << i << ":" << endl;
    cout << "\tArrival Time: ";
    cin >> process[i].at;
    cout << "\tBurst Time: ";
    cin >> process[i].bt;
  }
  sort(process.begin(), process.end(), sort_on_bt);
  process[0].wt = 0;
  for(int i = 0; i < n; ++i){
    for (int i = 1; i < n ; i++ )
      if(process[i].at < Process::cycle_count){
        i--;
        swap(process[i], process[n-1]);
      }
      process[i].wt = process[i-1].bt + process[i-1].wt;
      process[i].tat = process[i].bt + process[i].wt;
}

  print(n, process);

  return 0;
}
