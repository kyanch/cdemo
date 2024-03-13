int maxProfit(int* prices, int pricesSize) {
  // 最大利润
  int max_profit = 0;
  // 前i天的最小买价
  int min = prices[0];
  for (int i = 1; i < pricesSize; i++) {
    // 第i天卖出会获得的利润
    int profit = prices[i] - min;
    max_profit = max_profit > profit ? max_profit : profit;
    min = min < prices[i] ? min : prices[i];
  }
  return max_profit;
}
