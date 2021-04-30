#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int64_t, int64_t> &a, const pair<int64_t, int64_t> &b)
{
    return a.second < b.second;
};

int main()
{
    int n, x, y;
    cin >> n;
    vector<pair<int64_t, int64_t>> v;
    vector<int64_t> result;
    for (int64_t i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    while (v.size() != 0)
    {
        vector<pair<int64_t, int64_t>>::iterator itr = min_element(v.begin(), v.end(), compare);
        int64_t min_val = (*itr).second;
        result.push_back(min_val);
        v.erase(itr);
        itr = v.begin();
        while (itr < v.end())
        {
            if (min_val >= (*itr).first)
            {
                v.erase(itr);
            }
            else
            {
                ++itr;
            }
        }
    }
    cout << result.size() << endl;
    for (int64_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}