#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareNumbers(vector<string> &phoneNumbers, int numberCount)
{
  for (int i = 0; i < numberCount; i++)
  {
    for (int j = i + 1; j < numberCount; j++)
    {
      bool inconsistent = true;
      for (int k = 0; k < phoneNumbers[i].length(); k++)
      {
        if (phoneNumbers[i][k] != phoneNumbers[j][k])
        {
          inconsistent = false;
          break;
        }
      }
      if (inconsistent)
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int testCase;
  cin >> testCase;
  while (testCase--)
  {
    int numberCount;
    cin >> numberCount;
    vector<string> phoneNumbers(numberCount);
    for (int i = 0; i < numberCount; i++)
    {
      cin >> phoneNumbers[i];
    }
    sort(phoneNumbers.begin(), phoneNumbers.end());
    cout << (compareNumbers(phoneNumbers, numberCount) ? "YES\n" : "NO\n");
  }
}