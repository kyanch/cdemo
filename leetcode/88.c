void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int i = m - 1, j = n - 1;
  int tail = nums1Size - 1;
  while (i >= 0 && j >= 0) {
    if (nums1[i] > nums2[j]) {
      nums1[tail] = nums1[i];
      i--, tail--;
    } else {
      nums1[tail] = nums2[j];
      j--, tail--;
    }
  }
  while (j >= 0) {
    nums1[tail] = nums2[j];
    j--, tail--;
  }
}