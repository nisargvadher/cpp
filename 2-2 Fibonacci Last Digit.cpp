#include <iostream>
#include <vector>

using namespace std;

int64_t fibonacci(vector<int64_t> &a, int64_t &n)
{
	int64_t i, temp;
	for (i = 2; i <= n; i++)
	{
		temp = a[1];
		a[1] = a[1] + a[0];
		a[0] = temp;
	}

	return (a[1] % 10);
}

int main()
{
	int64_t n;
	int64_t cycle = 60;
	cin >> n;
	n = n % 60;
	vector<int64_t> a(2);
	a[0] = 0;
	a[1] = 1;
	if (n == 0 || n == 1)
	{
		cout << a[n];
	}
	else
	{
		
		int64_t result = fibonacci(a, n);
		cout << result;
	}
}