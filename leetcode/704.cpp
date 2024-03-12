#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int b = 0, e = nums.size() - 1;
    while (b >= e) {
      int mid = b + (e - b) / 2;
      if (nums[mid] > target)
        e = mid - 1;
      else if (nums[mid] < target)
        b = mid + 1;
      else
        return mid;
    }
    return -1;
  }
};