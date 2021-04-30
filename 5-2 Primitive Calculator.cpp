#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int64_t m;
    bool x, y;
    x = y = false;
    cin >> m;
    vector<int64_t> v(m + 1);
    vector<int64_t> result;
    v[0] = 0;

    for (int64_t i = 1; i <= m; i++)
    {
        x = (i % 2 == 0) ? true : false;
        y = (i % 3 == 0) ? true : false;

        if (y == false && x == false)
        {
            v[i] = v[i - 1] + 1;
        }

        else if (y == true && x == true)
        {
            v[i] = min((v[i / 3] + 1), (v[i / 2] + 1));
        }

        else if (x == true && (y == false) && (i - 1) % 3 == 0)
        {
            v[i] = min((v[i - 1] + 1), (v[i / 2] + 1));
        }

        else if (x == false && y == true)
        {
            v[i] = v[i / 3] + 1;
        }
        else
        {
            v[i] = v[i / 2] + 1;
        }
    }

    cout << (v[m] -1) << "\n";

    int64_t i = m;

    while (i >= 1)
    {
        result.push_back(i);

        x = (i % 2 == 0) ? true : false;
        y = (i % 3 == 0) ? true : false;

        if ((v[i] - 1) == v[i - 1])
        {
            --i;
        }

        else if (((v[i] - 1) == v[i / 2]) && (y == false))
        {
            i = i / 2;
        }

        else if (x == true && y == true && (v[i] - 1) == v[i / 3])
        {
            i = i / 3;
        }

        else if (x == false && y == true)
        {
            i = i / 3;
        }
    }

    for (auto j = result.rbegin(); j < result.rend(); j++)
    {
        cout << (*j) << ' ';
    }
}
