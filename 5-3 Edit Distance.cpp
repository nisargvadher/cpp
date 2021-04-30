#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2;
    int64_t diff;
    getline(cin, s1);
    getline(cin, s2);

    int64_t l1 = s1.length();
    int64_t l2 = s2.length();

    int64_t arr[l2 + 1][l1 + 1];

    for (int64_t i = 0; i <= l2; i++)
    {
        arr[i][0] = i;
    }

    for (int64_t i = 0; i <= l1; i++)
    {
        arr[0][i] = i;
    }

    for (int64_t i = 1; i <= l2; i++)
    {
        for (int64_t j = 1; j <= l1; j++)
        {
            diff = (s2[i - 1] == s1[j - 1]) ? 0 : 1;

            arr[i][j] = min({arr[i][j - 1] + 1, arr[i - 1][j] + 1, arr[i - 1][j - 1] + diff});
        }
    }

    cout << arr[l2][l1];
}