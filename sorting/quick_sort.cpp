#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> &vec, int left, int right)
{
  int pivot = right;
  int ind = left - 1;
  for (int i = left; i < right; i++)
  {
    if (vec[i] < vec[pivot])
    {
      ind++;
      swap(vec[i], vec[ind]);
    }
  }
  swap(vec[ind + 1], vec[pivot]);
  return ind + 1;
}

void quickSort(vector<int> &vec, int left, int right)
{
  if (left >= right)
    return;
  int ind = findPivot(vec, left, right);
  quickSort(vec, left, ind - 1);
  quickSort(vec, ind + 1, right);
}

int main()
{
  vector<int> vec = {4, 5, 3, 1, 2};
  for (auto &it : vec)
    cout << it << " ";
  quickSort(vec, 0, vec.size() - 1);
  cout<<endl;
  for (auto &it : vec)
    cout << it << " ";
  return 0;
}