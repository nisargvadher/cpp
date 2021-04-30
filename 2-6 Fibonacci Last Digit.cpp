#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int64_t m, temp, cycle;

	int64_t count = 2;
	int flag = 0;
	vector<int64_t> a(2);
	a[0] = 0;
	a[1] = 1;
	cin >> m;

	// Cycle for Fibonacci number modulo 10 is 60.
	cycle = 60;

	// Fibonacci modulous for m.
	//Here sum of F(n) = F(n+2) -1 so we will change m to first find F(n+2).
	m = (m + 2) % cycle;

	a[0] = 0;
	a[1] = 1;
	for (int64_t i = 2; i <= m; i++)
	{
		temp = a[1];
		a[1] = ((a[1] + a[0]) % 10);
		a[0] = temp;
	}
	//Now we will subtract 1 to obtain last digit of sum. Modulo is used to prevent
	// '-1' negative remainder scenario.
	int64_t result = (a[1] - 1) % 10;
	if (result < 0)
	{
		result = result + 10;
	}
	cout << result;
}