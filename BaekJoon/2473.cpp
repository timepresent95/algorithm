#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

long long absFn(long long input)
{
  return input < 0 ? -input : input;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> solutions(n);
  for (int i = 0; i < n; i++)
  {
    cin >> solutions[i];
  }
  sort(solutions.begin(), solutions.end());

  vector<pair<long long, pair<long long, long long>>> ph(n);
  long long minPh = 3000000001;
  vector<int> answer(3, -1);
  for (int i = 0; i < n; i++)
  {
    long long currentValue = solutions[i];
    int lo = (i == 0 ? 1 : 0);
    int hi = (i == n - 1 ? n - 2 : n - 1);
    ph[i] = {abs(currentValue + solutions[lo] + solutions[hi]), {lo, hi}};
    while (lo < hi)
    {
      long long sum = currentValue + solutions[lo] + solutions[hi];
      if (abs(sum) < ph[i].first)
      {
        ph[i] = {abs(sum), {lo, hi}};
      }
      if (sum == 0)
      {
        break;
      }
      else if (sum > 0)
      {
        hi = (hi - 1 == i ? hi - 2 : hi - 1);
      }
      else
      {
        lo = (lo + 1 == i ? lo + 2 : lo + 1);
      }
    }
    if (ph[i].first < minPh)
    {
      minPh = ph[i].first;
      answer[0] = solutions[i];
      answer[1] = solutions[ph[i].second.first];
      answer[2] = solutions[ph[i].second.second];
    }
  }
  sort(answer.begin(), answer.end());
  cout << answer[0] << ' ' << answer[1] << ' ' << answer[2];

  return 0;
}