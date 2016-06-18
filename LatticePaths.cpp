#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int findPaths_helper (int * paths, int rows, int cols)
{
    int down_paths, right_paths;
    if (paths[rows-1][cols] != 0)
        right_paths = paths[rows-1][cols];
    else
        findPaths_helper (paths, rows - 1, cols);
    if (paths[rows][cols-1] != 0)
        down_paths = paths[rows][cols-1];
    else
        findPaths_helper (paths, rows, cols - 1);
    return down_paths + right_paths;

}
void findPaths (int rows, int cols) {
  int paths [500][500];
  paths[0][1] = 1;
  paths[1][0] = 1;
  findPaths_helper (paths, rows, cols);
}

int main() {
    int d, m, n;
    cin >> d;
    int sum;
   	for (int i = 0; i < d; i++) {
        sum = 0;
   		cin >> n;
   		cin >> m;
      cout << findPaths (n, m) << endl;
   	}

    return 0;
}
