#include <vector>
using namespace std;

class NumArray {
  vector<int> psum;

 public:
  NumArray(vector<int>& nums) {
    psum.resize(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++) {
      psum[i + 1] = psum[i]+nums[i];
    }
  }

  int sumRange(int left, int right) { return psum[right + 1] - psum[left]; }
};