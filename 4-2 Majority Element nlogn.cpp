#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int64_t n;
    int64_t count = 1;
    cin >> n;
    if (n == 1)
    {
        int64_t temp;
        cin >> temp;
        cout << 1;
    }
    else
    {
        vector<int64_t> v(n);
        for (int64_t i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        for (int64_t i = 1; i < n; i++)
        {
            if (v[i - 1] == v[i])
            {
                count++;
                if (count > floor(n / 2))
                {
                    cout << 1;
                    break;
                }
            }
            else
            {
                count = 1;
            }
            
        }
        if (count <= (n / 2))
        {
            cout << 0;
        }
        
        
    }
}