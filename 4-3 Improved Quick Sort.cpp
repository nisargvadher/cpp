#include <iostream>
#include <vector>
#include <cstdlib>

using std::swap;
using std::vector;

int64_t partition2(vector<int64_t> &a, int64_t l, int64_t r)
{
  int64_t x = a[l];
  int64_t j = l;
  for (int64_t i = l + 1; i <= r; i++)
  {
    if (a[i] < x)
    {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

int64_t partition3(vector<int64_t> &a, int64_t l, int64_t r)
{
  int64_t x = a[l];
  int64_t j = l;
  for (int64_t i = l + 1; i <= r; i++)
  {
    if (a[i] == x)
    {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int64_t> &a, int64_t l, int64_t r)
{
  if (l >= r)
  {
    return;
  }

  int64_t k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int64_t m = partition2(a, l, r);
  int64_t j = partition3(a, m, r);
  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, j + 1, r);
}

int main()
{
  int64_t n;
  std::cin >> n;
  vector<int64_t> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }
}
