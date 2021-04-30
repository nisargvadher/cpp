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
	cin >> m >> n;

	// As we want to subtract the sum before the input fibonacci number.
	m = --m;

	// Cycle for Fibonacci number modulo 10 is 60.
	cycle = 60;

	// Fibonacci modulous for m.
	//Here sum of F(n) = F(n+2) -1 so we will change m to first find F(n+2).
	m = (m + 2) % cycle;
	n = (n + 2) % cycle;

	a[0] = 0;
	a[1] = 1;
	for (int64_t i = 2; i <= m; i++)
	{
		temp = a[1];
		a[1] = ((a[1] + a[0]) % 10);
		a[0] = temp;
	}
	int64_t x = a[1] - 1;

	a[0] = 0;
	a[1] = 1;
	for (int64_t i = 2; i <= n; i++)
	{
		temp = a[1];
		a[1] = ((a[1] + a[0]) % 10);
		a[0] = temp;
	}

	int64_t y = a[1] - 1;
	// Modulo is used to prevent
	// negative remainder scenario.
	int64_t result =  (y - x) % 10 ;
	if (result < 0)
	{
		result = result + 10;
	}
	cout << result;
}