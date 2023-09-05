#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int arr[], int size, int target) {
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (arr[mid] == target) {
      return mid;
    } else if (target < arr[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }
  return -1;
}

int findFirstOccurence(vector<int> vect, int target) {
  int s = 0;               // start
  int e = vect.size() - 1; // end
  int m = s + (e - s) / 2; // mid

  int ans_index = -1;
  while (s <= e) {
    if (target == vect[m]) {
      ans_index = m;
      e = m - 1;
    } else if (target < vect[m]) {
      e = m - 1;
    } else if (target > vect[m]) {
      s = m + 1;
    }
    m = s + (e - s) / 2;
  }
  return ans_index;
}

int findLastOccurence(vector<int> vect, int target) {
  int s = 0;               // start
  int e = vect.size() - 1; // end
  int m = s + (e - s) / 2; // mid

  int ans_index = -1;
  while (s <= e) {
    if (target == vect[m]) {
      ans_index = m;
      s = m + 1;
    } else if (target < vect[m]) {
      e = m - 1;
    } else if (target > vect[m]) {
      s = m + 1;
    }
    m = s + (e - s) / 2;
  }
  return ans_index;
}

int findTotalOccurence(vector<int> vect, int target) {
  // Combination of 1st & last Occurence
  // 1. find 1st Occurence
  int s = 0;               // start
  int e = vect.size() - 1; // end
  int m = s + (e - s) / 2; // mid

  int first_index = -1;
  while (s <= e) {
    if (target == vect[m]) {
      first_index = m;
      e = m - 1;
    } else if (target < vect[m]) {
      e = m - 1;
    } else if (target > vect[m]) {
      s = m + 1;
    }
    m = s + (e - s) / 2;
  }

  // 2. find Last Occurence
  s = 0;               // start
  e = vect.size() - 1; // end
  m = s + (e - s) / 2; // mid

  int last_index = -1;
  while (s <= e) {
    if (target == vect[m]) {
      last_index = m;
      s = m + 1;
    } else if (target < vect[m]) {
      e = m - 1;
    } else if (target > vect[m]) {
      s = m + 1;
    }
    m = s + (e - s) / 2;
  }

  int total_occurence;
  if (first_index == -1 || last_index == -1) {
    return first_index;
  } else {
    total_occurence = last_index - first_index + 1;
  }
  return total_occurence;
}

int findTotalOccurenceInOneLoop(vector<int> vect, int target) {
  // Combination of 1st & last Occurence- INCOMPLETED
  // 1. find 1st Occurence
  int s = 0;               // start
  int e = vect.size() - 1; // end
  int m = s + (e - s) / 2; // mid

  // 2. find Last Occurence
  int s2 = 0;               // start
  int e2 = vect.size() - 1; // end
  int m2 = s + (e - s) / 2; // mid

  // Finding 1st Occurence
  int first_index = -1;
  int last_index = -1;
  while (s <= e) {
    if (target == vect[m]) {
      first_index = m;
      e = m - 1;
    } else if (target < vect[m]) {
      e = m - 1;
    } else if (target > vect[m]) {
      s = m + 1;
    }
    // Finding Last Occurence
    else if (target == vect[m2]) {
      last_index = m2;
      s2 = m2 + 1;
    } else if (target < vect[m2]) {
      e2 = m2 - 1;
    } else if (target > vect[m2]) {
      s2 = m2 + 1;
    }

    m = s + (e - s) / 2;     // for 1st Index
    m2 = s2 + (e2 - s2) / 2; // for last Index
  }

  int total_occurence;
  if (first_index == -1 || last_index == -1) {
    return first_index;
  } else {
    total_occurence = last_index - first_index + 1;
  }
  return total_occurence;
}

int peakElementOfMountaing(vector<int> nums) {
  int start = 0;
  int end = nums.size() - 1;
  int mid = start + (end - start) / 2;

  while (start < end) {
    if (nums[mid] < nums[mid + 1]) {
      start = mid + 1;
    } else {
      end = mid;
    }
    mid = start + (end - start) / 2;
  }
  return start;
}

int main() {

  // Find peak element in a mountain Array
  vector<int> vect{3, 5, 3, 2, 0};

  int ans = peakElementOfMountaing(vect);
  cout << "Peak Element of Mountain is in Index: " << ans;

  // Find Total Occurence of target In Single Loop
  /*
  vector<int> vect{1,2,3,3,3,3,3,3,4,6};
  int target = 3;

  int total_occurence = findTotalOccurenceInOneLoop(vect, target);
  if(total_occurence == -1) {
    cout << "Target not Found";
  }
  else {
    cout << "Total Occurence: " << total_occurence;
  } */

  // Find Total Occurence of target
  /*
  vector<int> vect{1,2,3,3,3,3,3,3,4,6};
  int target = 4;

  int total_occurence = findTotalOccurence(vect, target);
  if(total_occurence == -1) {
    cout << "Target not Found";
  }
  else {
    cout << "Total Occurence: " << total_occurence;
  } */

  // Find Last Occurence of target
  /*
  vector<int> vect{1,2,3,3,3,3,3,3,6};
  int target = 4;

  int ans_index = findLastOccurence(vect, target);
  if(ans_index == -1) {
    cout << "Target not Found";
  }
  else {
    cout << "Target Found at Index: " << ans_index;
  } */

  // Find 1st Occurence of target
  /*
  vector<int> vect{1,2,3,3,3,3,3,5,6};
  int target = 4;

  int ans_index = findFirstOccurence(vect, target);
  if(ans_index == -1) {
    cout << "Target not Found";
  }
  else {
    cout << "Target Found at Index: " << ans_index;
  } */

  // Binary Search- Find Target
  /*
  int arr[] = {2,4,6,8,10,12,16};
  int size = 7;
  int target = 12;

  int ansIndex = binarySearch(arr, size, target);

  if(ansIndex == -1) {
    cout << "Target Not Found";
  }
  else {
    cout << "Target Found at Index: " << ansIndex;
  } */
  return 0;
}