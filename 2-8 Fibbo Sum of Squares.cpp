#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int64_t m, n, temp, cycle;

	int64_t count = 2;
	int flag = 0;
	vector<int64_t> a(2);
	a[0] = 0;
	a[1] = 1;
	cin >> m;

	// As we want to subtract the sum before the input fibonacci number.
	n = m + 1;

	// Cycle for Fibonacci number modulo 10 is 60.
	cycle = 60;

	// Fibonacci modulous for m.
	//Here sum of F(n) = F(n+2) -1 so we will change m to first find F(n+2).
	m = m % cycle;
	n = n % cycle;

	a[0] = 0;
	a[1] = 1;
	if (m == 0 || m == 1)
	{
		m = a[m];
	}
	else
	{
		for (int64_t i = 2; i <= m; i++)
		{
			temp = a[1];
			a[1] = ((a[1] + a[0]) % 10);
			a[0] = temp;
		}
		m = a[1];
	}

	a[0] = 0;
	a[1] = 1;
	if (n == 0 || n == 1)
	{
		n = a[n];
	}
	else
	{
		for (int64_t i = 2; i <= n; i++)
		{
			temp = a[1];
			a[1] = ((a[1] + a[0]) % 10);
			a[0] = temp;
		}
		n = a[1];
	}
	// Modulo is used to prevent
	// negative remainder scenario.
	cout << (m * n) % 10;
}