#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

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

  int low = 0, high = n - 1;
  long long answerLow = solutions[low];
  long long answerHigh = solutions[high];
  while (low < high)
  {
    if (abs(answerHigh + answerLow) > abs(solutions[low] + solutions[high]))
    {
      answerLow = solutions[low];
      answerHigh = solutions[high];
    }
    if (solutions[low] + solutions[high] > 0)
    {
      high--;
    }
    else
    {
      low++;
    }
  }
  cout << answerLow << ' ' << answerHigh;
  return 0;
}