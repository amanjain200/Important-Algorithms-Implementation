#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int> &vec, int left, int mid, int right){
  int vecInd = left;
  int leftInd = left, rightInd = mid+1;
  vector<int> temp;
  while(leftInd<=mid && rightInd<=right){
    if(vec[leftInd]<=vec[rightInd]){
      temp.push_back(vec[leftInd++]);
    }else{
      temp.push_back(vec[rightInd++]);
    }
  }

  while(leftInd <= mid){
    temp.push_back(vec[leftInd++]);
  }

  while(rightInd <= right){
    temp.push_back(vec[rightInd++]);
  }

  for(int i=0; i<temp.size(); i++){
    vec[vecInd++] = temp[i];
  }

}

void mergeSort(vector<int> &vec, int left, int right){
  if(left==right) return;
  int mid = (right+left)/2;
  mergeSort(vec, left, mid);
  mergeSort(vec, mid+1, right);
  merge(vec, left, mid, right);
}

int main(){
  vector<int> vec = {4,2,1,5,3};
  for(int i=0; i<vec.size(); i++){
    cout<<vec[i]<<" ";
  }
  cout<<endl;
  mergeSort(vec, 0, vec.size()-1);
  for(int i=0; i<vec.size(); i++){
    cout<<vec[i]<<" ";
  }
  return 0;
}