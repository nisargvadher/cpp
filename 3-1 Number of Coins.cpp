#include <iostream>

using namespace std;

int main()
{

    int a[3] = {1, 5, 10};
    int m = 0;
    int64_t x;
    int i = 2;
    cin >> x;

    while (i >= 0 && x >= 0)
    {
        m = m + (x / a[i]);
        x = x % a[i];
        --i;
    }
    cout << m;
}