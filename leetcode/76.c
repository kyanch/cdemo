#include <stdio.h>

#define HASH_LEN ('z'-'A'+1)

char* minWindow(char* s, char* t) {
  // 字符串hash表
  int need[HASH_LEN];
  int need_len;
  int window[HASH_LEN];
  // 结果判断
  int valid;
  // 最小结果
  int start = 0, length = 1e6;
  int left = 0, right = 0;

  // 初始化hash
  for (start = 0; start < HASH_LEN; start++)
    need[start] = 0, window[start] = 0;
  // 初始化t_count
  for (start = 0; t[start] != '\0'; start++) {
    need[t[start] - 'A']++;
  }
  need_len = 0;
  for (int i = 0; i < HASH_LEN; i++) {
    if (need[i] != 0) {
      need_len++;
    }
  }
  valid = 0;

  // 开始求解
  while (s[right] != '\0') {
    // 求单个可行解
    int idx = s[right] - 'A';
    if (need[idx] != 0) {
      window[idx]++;
      if (window[idx] == need[idx]) {
        valid++;
      }
    }
    right++;

    // 判断是否满足条件
    while (valid == need_len) {
      // 更新最优解，不然无法确定最后一次满足条件时的情况
      if (length > right - left) {
        start = left, length = right - left;
      }
      // 优化单个解
      idx = s[left] - 'A';
      left++;
      if (need[idx] != 0) {
        if (window[idx] == need[idx]) {
          valid--;
        }
        window[idx]--;
      }
    }
  }

  if (length == 1e6) {
    s[0] = '\0';
    return s;
  } else {
    s[start + length] = '\0';
    return s + start;
  }
}

int main() {
  char* x = minWindow("aa", "aa");
  printf("%s", x);
}