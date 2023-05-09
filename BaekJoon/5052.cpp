#include <iostream>
#include <vector>

using namespace std;

class NumberFlatter
{
public:
  bool flag;
  NumberFlatter *children[10];
  NumberFlatter()
  {
    flag = false;
    for (int i = 0; i < 10; i++)
    {
      children[i] = nullptr;
    }
  }
};

bool isConsistentList(vector<string> &phoneNumbers)
{
  struct NumberFlatter *head = new NumberFlatter();
  struct NumberFlatter *cursor;
  for (string phoneNumber : phoneNumbers)
  {
    cursor = head;
    for (int i = 0; i < phoneNumber.length(); i++)
    {
      int number = phoneNumber[i] - '0';
      if (cursor->flag)
      {
        return false;
      }
      if (cursor->children[number] == nullptr)
      {
        cursor->children[number] = new NumberFlatter();
      }
      cursor = cursor->children[number];
    }
    cursor->flag = true;
  }
  return true;
}

int main()
{
  freopen("input.txt", "r", stdin);
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
    cout << (isConsistentList(phoneNumbers) ? "YES\n" : "NO\n");
  }
}