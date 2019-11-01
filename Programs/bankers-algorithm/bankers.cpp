#include<iostream>
using namespace std;

const int P = 5;
const int R = 4;

void caclNeed(int need[P][R], int maxm[P][R],
  int allocation[P][R])
  {

    for (int i = 0 ; i < P ; i++)
      for (int j = 0 ; j < R ; j++)
        need[i][j] = maxm[i][j] - allocation[i][j];
  }

  bool safety(int processes[], int available[], int maxm[][R],
    int allocation[][R])
    {
      int need[P][R];
      caclNeed(need, maxm, allocation);
      bool finish[P] = {0};
      int sequence[P];
      int work[R];

      for (int i = 0; i < R ; i++)
        work[i] = available[i];

      int finished = 0;
      while (finished < P)
      {
        bool found = false;
        for (int p = 0; p < P; p++)
        {
          if (finish[p] == 0)
          {
            int j;
            for (j = 0; j < R; j++)
              if (need[p][j] > work[j])
                break;
            if (j == R)
            {
              for (int k = 0 ; k < R ; k++)
                work[k] += allocation[p][k];
              sequence[finished++] = p;
              finish[p] = 1;
              found = true;
            }
          }
        }


        if (found == false)
        {
          cout << "System is not in safe state";
          return false;
        }
      }

      cout << "Safe sequence: ";
      for (int i = 0; i < P ; i++)
        cout << sequence[i] << " ";

      return true;
    }

    int main()
    {
      int processes[] = {0, 1, 2, 3, 4};
      // int available[] = {3, 14, 12, 12};
      // int maxm[][R] = {{0, 0, 1, 2},
      //                  {1, 7, 5, 0},
      //                  {2, 3, 5, 6},
      //                  {0, 6, 5, 2},
      //                  {0, 6, 5, 6}};
      // int allocation[][R] = {{0, 0, 1, 2},
      //                        {1, 0, 0, 0},
      //                        {1, 3, 5, 4},
      //                        {0, 6, 3, 2},
      //                        {0, 0, 1, 4}};

      int allocation[P][R], maxm[P][R], available[R];

      cout << "Enter the total resources vector: " << endl;
      for (int i = 0; i < R; ++i)
        cin >> available[i];



      cout << "Enter the max matrix: " << endl;
      for (int i = 0; i < P; ++i)
      for (int j = 0; j < R; ++j)
      cin >> maxm[i][j];

      cout << "Enter the allocation matrix: " << endl;
      for (int i = 0; i < P; ++i)
      for (int j = 0; j < R; ++j)
      cin >> allocation[i][j];


      for (auto i: allocation){
        for (int j = 0; j < R; ++j)
          available[j] -= i[j];
      }

      safety(processes, available, maxm, allocation);
      cout << endl;
      return 0;
    }


    // 0 0 1 2
    // 1 7 5 0
    // 2 3 5 6
    // 0 6 5 2
    // 0 6 5 6

    // 0 0 1 2
    // 1 0 0 0
    // 1 3 5 4
    // 0 6 3 2
    // 0 0 1 4

7 5 3
3 2 0
9 0 2
2 2 2
4 3 3
0 1 0
3 0 2
3 0 2
2 1 1
0 0 2
