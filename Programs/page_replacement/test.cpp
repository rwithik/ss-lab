#include<vector>
#include<iostream>

using namespace std;


int main(int argc, char const *argv[]) {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(7);
  v.push_back(6);
  v.push_back(4);
  v.push_back(2);
  v.push_back(3);
  vector<int>::iterator it = v.begin();
  v.erase(it);
  v.insert(it, 0);
  for (auto i: v){
    cout << i << " ";
  }
  return 0;
}
