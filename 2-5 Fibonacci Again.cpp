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

	// Looking for '0, 1' sequence occuring when Fibbonacci
	// numbers % n operation is performed.
	while (flag != 1)
	{
		temp = a[1];
		a[1] = ((a[1] + a[0]) % n);
		a[0] = temp;

		if (a[0] == 0 && a[1] == 1)
		{
			++flag;
		}
		++count;
	}
	flag = 0;
	cycle = count - 2;

	// Fibonacci modulous for m
	m = (m % cycle);

	a[0] = 0;
	a[1] = 1;
	for (int64_t i = 2; i <= m; i++)
	{
		temp = a[1];
		a[1] = ((a[1] + a[0]) % n);
		a[0] = temp;
	}
	cout << a[1];
}