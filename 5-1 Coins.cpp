#include <iostream>

using namespace std;

int main()
{
    int64_t m, result, temp;
    cin >> m;

    if (m <= 4)
    {
        if (m == 2)
        {
            cout << 2;
        }

        else
        {
            cout << 1;
        }
    }

    else
    {
        result = (m / 4);
        temp = (result * 4);
        if (m - temp != 0)
        {
            cout << ++result;
        }
        else
        {
            cout << result;
        }
    }
}