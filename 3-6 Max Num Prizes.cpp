#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int64_t n;
    int64_t l = 1;
    cin >> n;
    vector<int64_t> v;
    for (l; n > (2 * l); l++)
    {
        n = n - l;
        v.push_back(l);
    }
    if (n <= (2 * l))
    {
        if (n == l)
        {
            v.push_back(l);
        }
        else
        {
            v.push_back((l + (n - l)));
        }
    }

    cout << v.size() << endl;
    vector<int64_t>::iterator itr = v.begin();
    while (v.size() > 0)
    {
        cout << (*itr) << " ";
        v.erase(itr);
    }

}