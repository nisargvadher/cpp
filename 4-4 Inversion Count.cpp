#include <iostream>
#include <vector>

using namespace std;

int64_t seperate(vector<int64_t>&, int64_t, int64_t, vector<int64_t>);
int64_t merge(vector<int64_t>&, int64_t, int64_t, int64_t, vector<int64_t>);

int64_t setup(vector<int64_t> &a, int64_t left, int64_t right, int64_t n)
{
  vector<int64_t> temp(n);
  return seperate(a, left, right, temp);
};

int64_t seperate(vector<int64_t> &a, int64_t left, int64_t right, vector<int64_t> temp)
{
  int64_t mid = (left + right) / 2;
  int64_t inv_count = 0;
  if (right > left)
  {
    inv_count += seperate(a, left, mid, temp);
    inv_count += seperate(a, mid + 1, right, temp);
    inv_count += merge(a, left, mid + 1, right, temp);
  }
  return inv_count;
};

int64_t merge(vector<int64_t> &a, int64_t left, int64_t mid, int64_t right, vector<int64_t> temp)
{

  int64_t l = left;
  int64_t k = left;
  int64_t m = mid;
  int64_t inv_count = 0;
  while ((l <= (mid - 1)) && (m <= right))
  {
    if (a[l] <= a[m])
    {
      temp[k++] = a[l++];
    }
    else
    {
      temp[k++] = a[m++];

      inv_count = inv_count + (mid - l);
    }
  }

  while (l <= mid - 1)
  {
    temp[k++] = a[l++];
  }

  while (m <= right)
  {
    temp[k++] = a[m++];
  }

  for (l = left; l <= right; l++)
  {
    a[l] = temp[l];
  }

  return inv_count;
};

int main()
{
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);

  for (int64_t i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int64_t count = setup(a, 0, n - 1, n);

  // for (int64_t i = 0; i < n; i++)
  // {
  //   cout << a[i] << ' ';

  // }

  cout << count;
}