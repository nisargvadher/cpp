#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool compare(string &a, string &b)
{
    return ((a + b) > (b + a));
};

int main()
{
    string result, temp;
    result = "";
    int64_t size;
    cin >> size;
    vector<string> original(size);

    for (int64_t i = 0; i < size; i++)
    {
        cin >> temp;
        original[i] = temp;
    }

    sort(original.begin(), original.end(), compare);

    vector<string>::iterator i = original.begin();

    while (original.size() > 0)
    {
        result = result + (*i);
        original.erase(i);
    }
    cout << result;
}