#include <iostream>
#include <vector>

using namespace std;

static int64_t count = 0;

void seperate(vector<int64_t> &, int64_t, int64_t);
void merge(vector<int64_t> &, int64_t, int64_t, int64_t);

void seperate(vector<int64_t> &a, int64_t left, int64_t right)
{
  if (right > left)
  {
    int64_t mid = (left + right) / 2;

    seperate(a, left, mid);
    seperate(a, mid + 1, right);
    merge(a, left, mid + 1, right);
  }
  return;
};

void merge(vector<int64_t> &a, int64_t left, int64_t mid, int64_t right)
{
  vector<int64_t> temp(a.size());
  int64_t l = left;
  int64_t k = left;
  int64_t m = mid;
  while ((l <= mid - 1) && (m <= right))
  {
    if (a[l] <= a[m])
    {
      temp[k++] = a[l++];
    }
    else
    {
      temp[k++] = a[m++];
      count = count + (mid - l);
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

  seperate(a, 0, n - 1);
  cout << count;
}