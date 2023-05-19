#include <iostream>
#include <list>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  list<int> sequenceA;
  list<int> sequenceB;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;

    list<int>::iterator cursorA = sequenceA.begin();
    list<int>::iterator cursorB = sequenceB.begin();

    while (true)
    {
      if (cursorA == sequenceA.end() || *cursorA > a)
      {
        sequenceA.insert(cursorA, a);
        break;
      }
      cursorA++;
    }
    while (true)
    {
      if (cursorB == sequenceB.end() || *cursorB > b)
      {
        sequenceB.insert(cursorB, b);
        break;
      }
      cursorB++;
    }

    cursorA = sequenceA.begin();
    cursorB = --sequenceB.end();
    int answer = 0;
    while (cursorA != sequenceA.end())
    {
      answer = max(*cursorA + *cursorB, answer);
      cursorA++;
      cursorB--;
    }
    cout << answer << '\n';
  }

  return 0;
}