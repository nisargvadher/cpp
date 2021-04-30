#include <iostream>
#include <numeric>

using namespace std;

bool subsetSum(int64_t S[], int64_t n, int64_t a, int64_t b, int64_t c)
{

    if (a == 0 && b == 0 && c == 0)
        return true;

    if (n < 0)
        return false;

    bool A = false;
    if (a - S[n] >= 0)
        A = subsetSum(S, n - 1, a - S[n], b, c);

    bool B = false;
    if (!A && (b - S[n] >= 0))
        B = subsetSum(S, n - 1, a, b - S[n], c);

    bool C = false;
    if ((!A && !B) && (c - S[n] >= 0))
        C = subsetSum(S, n - 1, a, b, c - S[n]);

    return A || B || C;
}

bool partition(int64_t S[], int64_t n)
{
    if (n < 3)
        return false;

    int64_t sum = std::accumulate(S, S + n, 0);

    return !(sum % 3) && subsetSum(S, n - 1, sum / 3, sum / 3, sum / 3);
}

int main()
{

    int64_t n;
    cin >> n;
    int64_t S[n];

    for (int64_t i = 0; i < n; i++)
    {
        cin >> S[i];
    }

    if (partition(S, n))
        std::cout << 1;
    else
        std::cout << 0;

    return 0;
}