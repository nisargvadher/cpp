#include <iostream>

using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
	if (b == 0)
	{
		return ((int64_t)a);
	}

	return ((int64_t)gcd(b, a % b));
}
int main()
{
	int64_t a, b;
	cin >> a >> b;
	int64_t lcm = ((a * b) / gcd(a, b));
	cout << lcm;
}