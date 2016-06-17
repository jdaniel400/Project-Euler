#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long getEvenFibSum (long n) {
	long fib_1 = 0;
	long fib_2 = 2;

	long sum = 0;

	while (fib_2 < n) {
		if (fib_2 % 2 == 0) {
			sum += fib_2;
		}

		long tmp = fib_2;
		fib_2 = 4*fib_2 + fib_1;
		fib_1 = tmp;
	}
	return sum;
}

int main() {
	long d;
	cin >> d; //get number of entries from input
	for (long i = 0; i < d; i++) {
		long n;
		cin >> n; //get current fibonacci max num from input
		cout << getEvenFibSum (n) << endl; //call method to compute problem
	}
    return 0;
}

