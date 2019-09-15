#include<bits/stdc++.h>

using namespace std;

int cycle_count = 0;

class Process{
public:
  static int count;
  int id;
  int at;
  int wt;
  int tat;
  int bt;
  int rem;
  bool done;

  Process(){
    done = false;
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
  for(Process i: v){
    cout << i.id << "\t\t\t" << i.bt << "\t\t\t" << i.at << "\t\t\t\t" << i.wt << "\t\t\t\t" << i.tat << endl;
  }
  cout << "Average Waiting Time: " << average_wt(n, v) << endl;
  cout << "Average Turnaround Time: " << average_tat(n, v) << endl;
  cout << endl;
}

bool sort_on_at(Process a, Process b){
  return a.at < b.at;
}


void compute(vector<Process> &v, int q){
  int n = v.size();
  int done_count = 0;
  while(done_count != n){
  for(Process& i: v){
    if(!i.done){
      if (i.rem > q){
        cycle_count += q;
        i.rem -= q;
      }
      else{
        cycle_count += i.rem;
        i.wt = cycle_count - i.bt - i.at;
        i.rem = 0;
        i.done = true;
        done_count ++;
      }
    }
    i.tat = i.wt + i.bt;
  }
}
}


int Process::count = 0;

int main(int argc, char const *argv[]) {


  int n, q;
  cout << "Enter the number of processes: ";
  cin >> n;
  vector<Process> process(n);
  for(int i = 0; i < n; ++i){
    cout << "Process " << i << ":" << endl;
    cout << "\tArrival Time: ";
    cin >> process[i].at;
    cout << "\tBurst Time: ";
    cin >> process[i].bt;
    process[i].rem = process[i].bt;
  }

  cout << "Enter the time quantum: ";
  cin >> q;

  sort(process.begin(), process.end(), sort_on_at);
  compute(process, q);

  print(n, process);

  return 0;
}
