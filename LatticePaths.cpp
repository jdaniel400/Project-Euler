#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int findPaths (int **paths, int rows, int cols) {

  return paths[rows][cols]; // no need for recursion
}

int **build_paths_matrix ()
{
    //build 2D array to store number of paths for each lattice dimensions
  int **paths = new int* [500];
  for (int i = 0; i < 500; i++)
      paths[i] = new int [500];
  for (int i = 0; i < 500; i++) {
      paths[i][0] = 1; //intialize the top and left borders to 1's
      paths[0][i] = 1;
  }
  paths[0][1] = 1; //start off the smallest two sizes
  paths[1][0] = 1;

  for (int i = 1; i < 500; i++)
    for (int j = 1; j < 500; j++)
      paths[i][j] = (paths[i-1][j] + paths[i][j-1]) % 1000000007; //dynamic programming solution
  return paths;
}

int main() {
    int d, m, n;
    int **paths = build_paths_matrix ();
    cin >> d; //get number of trials
    for (int i = 0; i < d; i++) {
      cin >> n; //number of rows
      cin >> m; //number of columns
      cout << findPaths (paths, n, m) << endl; //return answer
    }

    return 0;
}

