#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool sortpair(const pair<double, double> &a, const pair<double, double> &b)
{
    return ((a.first / a.second) > (b.first / b.second));
};

int main()
{
    double n;
    double W, temp;
    double V = 0;
    cin >> n;
    cin >> W;
    double x, y;
    vector<pair<double, double>> v(n);
    for (double i = 0; i < n; i++)
    {
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }

    sort(v.begin(), v.end(), sortpair);

    // for (double j = 0; j < n; j++)
    // {
    //     cout << v[j].first << " " << v[j].second << endl;
    // }

    for (double i = 0; (i < n && W >= 0); i++)
    {
        temp = min(W, v[i].second);
        W = W - temp;
        V = V + (temp * (v[i].first / v[i].second));
    }

    cout << fixed << setprecision(4) << V;
}