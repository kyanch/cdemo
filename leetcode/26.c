int removeDuplicates(int* nums, int numsSize) {
  int fast = 1, slow = 1;
  int val = nums[0];
  while (fast < numsSize) {
    if (val != nums[fast]) {
      val = nums[fast];
      nums[slow] = val;
      slow++;
    }
    fast++;
  }
  return slow;
}