void swap(int* a, int* b) {
  int t = *a;
  *a = *b, *b = t;
}
void reverse(int* nums, int start, int end) {
  while (start < end) {
    swap(nums + start, nums + end);
    start += 1, end -= 1;
  }
}

void rotate(int* nums, int numsSize, int k) {
  // 旋转法
  k %= numsSize;
  reverse(nums, 0, numsSize - k - 1);
  reverse(nums, numsSize - k, numsSize - 1);
  reverse(nums, 0, numsSize - 1);
}

int main() { return 0; }