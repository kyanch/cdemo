int removeElement(int* nums, int numsSize, int val) {
  int head = 0, tail = numsSize;
  while (head < tail) {
    if (nums[head] == val) {
      nums[head] = nums[tail - 1];
      tail--;
    } else {
      head++;
    }
  }
  return tail;
}