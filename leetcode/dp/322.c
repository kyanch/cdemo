#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *c, len;
int mem[10000] = {0};
int dp(int a) {
  if (a == 0) return 0;
  if (a < 0) return -1;
  if (mem[a] != 0) {
    return mem[a];
  }
  int res = INT_MAX;
  for (int i = 0; i < len; i++) {
    int sub_problem = dp(a - c[i]);
    if (sub_problem == -1) continue;
    int tmp = sub_problem + 1;
    res = res < tmp ? res : tmp;
  }
  res = res == INT_MAX ? -1 : res;
  mem[a] = res;
  return res;
}
int dp_loop(int *coins, int coinsSize, int amount) {
  int memo[10001] = {0};
  for (int i = 0; i < 10001; i++) memo[i] = INT_MAX;
  memo[0] = 0;
  for (int j = 0; j < coinsSize; j++) {
    for (int i = coins[j]; i <= amount; i ++) {
      if (memo[i - coins[j]] == INT_MAX) continue;
      memo[i] = fmin(memo[i], memo[i - coins[j]] + 1);
    }
  }
  return memo[amount] == INT_MAX ? -1 : memo[amount];
}
int coinChange(int *coins, int coinsSize, int amount) {
  c = coins, len = coinsSize;
  int res = dp(amount);
  return res;
}
int main() {
  int coins[] = {2};
  int res = coinChange(coins, 1, 3);
  int coinss[] = {1,2,5};
  res = dp_loop(coinss, 3, 11);
  printf("%d", res);
}