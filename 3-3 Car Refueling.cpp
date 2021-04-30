#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int64_t d, tank, n;
    cin >> d >> tank >> n;

    if (n != 0)
    {
        vector<int64_t> v(n + 1);
        int64_t i;
        int64_t count = 0;
        bool flag = true;
        int64_t current = 0;
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        v[i] = d;
        i = 0;
        while (i <= n)
        {
            while ((current + tank >= v[i]) && (i < n))
            {
                ++i;
            }
            if (current == v[i - 1] && current + tank < v[i])
            {
                flag = false;
                cout << -1;
                break;
            }
            else if ((i == n) && (current + tank >= v[i]))
            {
                cout << count;
                break;
            }
            else
            {
                current = v[i - 1];
                ++count;
            }
        }
    }
    else if (d == tank)
    {
        cout << 0;
    }
    else
    {
        cout << -1;
    }
}