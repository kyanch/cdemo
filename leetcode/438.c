#include <stdio.h>

#include "stdlib.h"

#define HASH_LEN ('z' - 'a' + 1)

int* findAnagrams(char* s, char* p, int* returnSize) {
  int hash[HASH_LEN];
  int window_hash[HASH_LEN];
  int hash_len = 0;
  int valid = 0;
  int* ans = (int*)malloc(30000 * sizeof(int));
  int left = 0, right = 0;

  *returnSize = 0;

  for (int i = 0; i < HASH_LEN; i++) {
    hash[i] = 0;
    window_hash[i] = 0;
  }
  for (int i = 0; p[i] != '\0'; i++) {
    hash[p[i] - 'a']++;
  }
  for (int i = 0; i < HASH_LEN; i++)
    if (hash[i] != 0) hash_len++;

  while (s[right] != '\0') {
    int idx = s[right] - 'a';
    if (hash[idx] != 0) {
      // 匹配到字符
      window_hash[idx]++;
      if (window_hash[idx] == hash[idx])
        valid++;
      else if (window_hash[idx] > hash[idx]) {
        // 满足缩窗条件，开始缩窗
        while (window_hash[idx] != hash[idx]) {
          int rm_idx = s[left] - 'a';
          // 要删除的字符满足了数量要求，这时删除的话，valid应该减1
          if (window_hash[rm_idx] == hash[rm_idx]) valid--;
          window_hash[rm_idx]--;
          left++;
        }
      }
      right++;
    } else {
      // 未匹配到字符，重新匹配
      left = right + 1;
      right++;
      valid = 0;
      for (int i = 0; i < HASH_LEN; i++) window_hash[i] = 0;
      continue;
    }

    if (valid == hash_len) {
      ans[(*returnSize)++] = left;
      idx = s[left] - 'a';
      if (hash[idx] != '\0') {
        window_hash[idx]--;
        valid--;
      }
      left++;
    }
  }
  return ans;
}

int main() {
  int len = 0;
  int* x = findAnagrams("abaacbabc", "abc", &len);
  for (int i = 0; i < len; i++) {
    printf("%d ", x[i]);
  }
}