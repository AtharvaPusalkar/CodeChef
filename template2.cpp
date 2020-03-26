// A optimized school method based C++ program to check
// if a number is prime
#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n)
{
	// Corner cases
	if (n <= 1) return false;
	if (n <= 3) return true;

	// This is checked so that we can skip
	// middle five numbers in below loop
	if (n%2 == 0 || n%3 == 0) return false;

	for (long long i=5; i*i<=n; i=i+6)
		if (n%i == 0 || n%(i+2) == 0)
		return false;

	return true;
}


// Driver Program to test above function
int main()
{
	int N = 100000;
	pair<int,int> up[N];
	for(int i =1;i<=N;i++) {
        up[i] = {i,i};
	}
	cout << (sizeof(up)/1024)*2 << endl;
	return 0;
}
