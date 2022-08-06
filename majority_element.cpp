#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int count_occurence(vector<int> &a, int left, int right, int num ) {
    int count = 0;
    for (int i = left; i <= right; i++) {
        if (a[i] == num) {
            count++;
        }
    }
    return count;
}

int get_majority_element_divConq(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  //-----------------------------------------------------------------
  int mid = left + (right - left) / 2;

  int leftMajority = get_majority_element_divConq(a, left, mid);
  int rightMajority = get_majority_element_divConq(a, mid+1, right);

  // if the two halves agree on the majority element, return it.
  if (leftMajority == rightMajority) {
      return leftMajority;
  }

  // otherwise, count each element and return the "winner".
  int leftCount = count_occurence(a, left, right, leftMajority);
  int rightCount = count_occurence(a, left, right, rightMajority);

  if(leftCount > rightCount){
    return leftMajority;
  }else{
    return rightMajority;
  }
  //-----------------------------------------------------------------
  return -1;
}

int get_majority_element_sort(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  //------------------------------------------------
  std::sort(a.begin(), a.end());
  int mid = left + (right - left) / 2;
  int majElement = a[mid];
  int count = 0;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] == majElement)
      count++;
  }
  if (count > a.size() / 2)
  {
    return 1;
  }
  //------------------------------------------------
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  //std::cout << (get_majority_element_sort(a, 0, a.size()) != -1) << '\n';
  std::cout << (get_majority_element_divConq(a, 0, a.size()) != -1) << '\n';
}
