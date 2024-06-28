#include <iostream>
#include <vector>
using namespace std;

/*
approach
create the array lps i.e. longest common prefix and suffix same
aaabaaab
*/

int kmp(string str, string target)
{
  // compute the lps array
  vector<int> lps(target.size(), 0);
  for (int i = 1; i < target.size(); i++)
  {
    int prev = lps[i - 1];
    if (target[i] == target[prev])
      lps[i] = lps[i - 1] + 1;
    else
    {
      for (int j = prev - 1; j >= 0; j--)
      {
        if (target[i] == target[j])
        {
          lps[i] = j + 1;
        }
      }
    }
  }

  for (auto it : lps)
    cout << it << " ";

  int j = 0;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == target[j])
    {
      j++;
    }
    else
    {
      if(j==0) continue;
      j = lps[j - 1];
      i--;
    }

    if (j == target.size())
      return i-target.size()+1;
  }

  return -1;
}

int main()
{
  string str = "ABABDABACDABABCABAB";
  string target = "asgd";
  int ans = kmp(str, target);
  cout << endl;
  cout << ans << endl;

  return 0;
}