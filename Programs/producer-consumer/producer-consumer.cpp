#include<bits/stdc++.h>
using namespace std;

vector<int> buffer;
int mutex = 0;
int full = 0;
int empty = 0;
int size;

void produce(){
  if(full == size){
    cout << "Buffer is full!" << endl;
  }
  else{
    buffer.push_back(1);
    full++;
    empty--;
    cout << "Producer produced item " << full << endl;
  }
}

void consume(){
  if(full == 0){
    cout << "Buffer is empty!" << endl;
  }
  else{
    cout << "Producer consumed item " << full << endl;
    buffer.erase(buffer.end() - 1);
    full--;
    empty++;
  }
}

int main() {
  cout << "Enter the size of the buffer: ";
  cin >> size;
  cout << "Enter 1 to produce to  buffer, 2 to consume from buffer." << endl;
  int choice;
  while (1){
    cout << "Enter choice: ";
    cin >> choice;
    if (choice == 1){
      produce();
    }
    else if (choice == 2){
      consume();
    }
  }
  return 0;
}
