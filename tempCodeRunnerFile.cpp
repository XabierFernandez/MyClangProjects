#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int countOccurrence(vector<int> &a, int left, int right, int majority ){
  int count = 0;
  for(int i = 0; i <= right; i++){
    if(a[i] == majority ) count++;
  }

  return count;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int mid = ((right- left)/2) + left;

  int leftMajority = get_majority_element(a, left, mid);
  int rightMajority = get_majority_element(a, mid + 1, right);

  if(leftMajority == rightMajority)return leftMajority;

  int leftCount = countOccurrence(a, left, right, leftMajority);
  int rightCount = countOccurrence(a, left, right, rightMajority);

  if(leftCount > rightCount){
    return leftMajority;
  }else{
    return rightMajority;
  }

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
