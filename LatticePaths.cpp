#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void findPaths (int m, int n, int col, int row, int &sum) {
    if (col == n && row == m)
        sum++;
    if (col < n) 
        findPaths (m, n, col + 1, row, sum);
   
    if (row < m)
        findPaths (m, n, col, row + 1, sum);
}

int main() {
    int d, m, n;
    cin >> d;
    int sum;
   	for (int i = 0; i < d; i++) {
        sum = 0;
   		cin >> n;
   		cin >> m;
        findPaths (n, m, 0, 0, sum);
   		cout << sum << endl;
   	}

    return 0;
}
