#include <math.h>
#include <stdio.h>
int lengthOfLongestSubstring(char* s) {
  int left = 0, right = 0;
  int res = 0;
  while (s[right] != '\0') {
    // expand window
    right++;
    // shrink window
    for (int i = left; i < right - 1; i++) {
      if (s[i] == s[right-1]) {
        // found repeat
        left = i + 1;
        break;
      }
    }
    res = fmax(res, right-left);
  }
  return res;
}
int main(){
  
    int x=lengthOfLongestSubstring("bbbb");
    printf("%d",x);
}