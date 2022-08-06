  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  //-----------------------------------------------------------------
  int mid = left + (right - left) / 2;

  int leftMajority = get_majority_element_divConq(a, left, mid);
  int rightMajority = get_majority_element_divConq(a, mid+1, right);

  std::cout << "leftMajority" << leftMajority << "\n";
  std::cout << "rightMajority" << rightMajority << "\n";

  // otherwise, count each element and return the "winner".
  int leftCount = count_occurence(a, left, right, leftMajority);
  int rightCount = count_occurence(a, left, right, rightMajority);
  
  std::cout << "leftCount" << leftCount << "\n";
  std::cout << "rightCount" << rightCount << "\n";

  // if the two halves agree on the majority element, return it. 
  if((leftCount > rightCount) && (leftCount > (a.size()/2))) return leftMajority;
  if((rightCount > leftCount) && (rightCount > (a.size()/2))) return rightMajority;
  //-----------------------------------------------------------------
  return -1;