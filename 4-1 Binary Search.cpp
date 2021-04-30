#include <iostream>
#include <vector>

using namespace std;

void searchelem(int64_t &x, vector<int64_t> a)
{
    int64_t start_index = 0;
    int64_t end_index = (a.size() - 1);
    int64_t mid;
    bool flag = false;
    while (flag != true)
    {
        if ((end_index - start_index) > 2)
        {
            mid = ((start_index + end_index) / 2);
            if (x > a[mid])
            {
                start_index = mid;
            }
            else if (x < a[mid])
            {
                end_index = mid;
            }
            else if (x == a[mid])
            {
                cout << mid << " ";
                flag = true;
            }
        }
        else
        {
            mid = ((start_index + end_index) / 2);
            if (a[mid] == x)
            {
                cout << mid << " ";
                flag = true;
            }
            else
            {
                if (a[end_index] == x)
                {
                    cout << end_index << " ";
                }
                else if (a[start_index] == x)
                {
                    cout << start_index << " ";
                }
                else
                {
                    cout << -1 << " ";
                }
                flag = true;
            }
        }
    }
}

int main()
{
    int64_t m, n;
    cin >> m;
    vector<int64_t> v(m);
    for (int64_t i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    cin >> n;
    vector<int64_t> s(n);
    
    for (int64_t i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    if (m > 2)
    {
        for (int64_t i = 0; i < n; i++)
        {
            searchelem(s[i], v);
        }
    }
    else
    {
        for (int64_t i = 0; i < n; i++)
        {
            if (s[i] == v[0])
            {
                cout << 0 << " ";
            }
            else if (s[i] == v[1])
            {
                cout << 1 <<" ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
    }
}