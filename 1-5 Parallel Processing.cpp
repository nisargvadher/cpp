#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int64_t, int64_t> process;

struct Compare
{
    bool operator()(process &a, process &b)
    {
        if (a.second > b.second)
        {
            return true;
        }

        else if (a.second == b.second)
        {
            return (a.first > b.first);
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int64_t n, m;
    cin >> n >> m;

    typedef pair<int64_t, int64_t> process;
    vector<pair<int64_t, int64_t>> result(m);
    priority_queue<process, vector<process>, Compare> threads;
    result.clear();
    if (m > n)
    {
        vector<int64_t> pTimes(m);
        for (int64_t i = 0; i < m; i++)
        {
            cin >> pTimes[i];
        }

        for (int64_t i = 0; i < n; i++)
        {
            result.push_back(make_pair(i, 0));
        }

        for (int64_t i = 0; i < n; i++)
        {
            threads.push(make_pair(i, pTimes[i]));
        }

        for (int64_t i = n; i < m; i++)
        {
            process temp = threads.top();
            threads.pop();
            result.push_back(make_pair(temp.first, temp.second));
            threads.push(make_pair(temp.first, temp.second + pTimes[i]));
        }
    }

    else
    {
        for (int64_t i = 0; i < m; i++)
        {
            result.push_back(make_pair(i, 0));
        }
    }

    for (vector<process>::iterator i = result.begin(); i != result.end(); i++)
    {
        cout << (*i).first << " " << (*i).second << "\n";
    }
}