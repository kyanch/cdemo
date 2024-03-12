#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
  *returnSize = 2;
  int* result = malloc(sizeof(int) * 2);
  if (numsSize == 0) {
    result[0] = result[1] = -1;
    return result;
  }
  result[0] = 0, result[1] = numsSize - 1;
  int mid;
  while (result[0] <= result[1]) {
    mid = result[0] + (result[1] - result[0]) / 2;
    if (nums[mid] == target) {
      goto found;
    } else if (nums[mid] < target) {
      result[0] = mid + 1;
    } else {
      result[1] = mid - 1;
    }
  }
  result[0] = result[1] = -1;
  return result;
found:
  result[0] = result[1] = mid;
  while (result[0] > 0 && nums[result[0] - 1] == target) result[0]--;
  while (result[1] < numsSize - 1 && nums[result[1] + 1] == target) result[1]++;
  return result;
}
int main() {
  int x[] = {5, 7, 7, 8, 8, 10};
  int* res;
  int len;
  res = searchRange(x, 6, 6, &len);

  printf("%d,%d", res[0], res[1]);
  free(res);
}