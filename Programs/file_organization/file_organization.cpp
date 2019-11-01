#include <bits/stdc++.h>
using namespace std;

#include "single-level.h"
#include "two-level.h"
#include "hierarchial.h"

int main(int argc, char const *argv[]) {

    int choice;

    cout << "1. Single Level Directory" << endl;
    cout << "2. Two Level Directory" << endl;
    cout << "3. Hierarchial Directory" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice){
      case 1: single();
      break;
      case 2: two();
      break;
      case 3: hierarchial();
      break;
      default: cout << "Invalid choice" << endl;
      break;
    }

    return 0;
  }
