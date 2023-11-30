#include <iostream>
#include <string>

#include <benchmark/benchmark.h>
using namespace std;
/**
    斐波那契数列Fibonacci
    一对小兔子两月具有繁殖能力，每月生一对
    经过月数：0 1 2 3 4 5 6  7 ...
    兔子对数：0 1 1 2 3 5 8 13 ...
*/

// 传统递归实现normal recursion
static unsigned long fib_normal_rec(unsigned long n) {
  if (n <= 2)
    return 1;
  else
    return fib_normal_rec(n - 1) + fib_normal_rec(n - 2);
}

// // 尾递归实现Rail recusion
static unsigned long fib_rail_rec(unsigned long n, unsigned long first = 1,
                                  unsigned long second = 1) {
  if (n == 1)
    return first;
  return fib_rail_rec(n - 1, second, second + first);
}

// // 循环实现
static unsigned long fib_no_rec(unsigned long n) {
  if (n <= 2)
    return 1;
  unsigned int x = 1, y = 1, y_tmp = 0;
  for (unsigned int i = 0; i < n - 2; i++) {
    y_tmp = y;
    y = x + y;
    x = y_tmp;
  }
  return y;
}
// static void BM_fib_normal_rec(benchmark::State& state){
//     fib_normal_rec(state.range(0));
// }
// BENCHMARK(BM_fib_normal_rec)->Arg(8)->Arg(14)->Arg(20)->Arg(30)->Arg(40);
// static void BM_fib_tail_rec(benchmark::State &state) {
//   fib_rail_rec((unsigned long)state.range(0));
//   state.SetBytesProcessed(int64_t(state.iterations()) *
//                           int64_t(state.range(0)));
// }
// BENCHMARK(BM_fib_tail_rec)->Range(10, 50);
static void BM_fib_loop(benchmark::State &state) {
  int64_t n = state.range();
  if (n <= 2)
    return ;
  unsigned int x = 1, y = 1, y_tmp = 0;
  for (unsigned int i = 0; i < n - 2; i++) {
    y_tmp = y;
    y = x + y;
    x = y_tmp;
  }
}
BENCHMARK(BM_fib_loop)->Arg(200);

static void BM_StringCopy(benchmark::State &state) {
  std::string str(state.range(0), '-');
  for (auto _ : state) {
    std::string copy(str);
    benchmark::DoNotOptimize(copy);
  }
}
BENCHMARK(BM_StringCopy)->RangeMultiplier(2)->Range(10, 50)->Arg(500);

BENCHMARK_MAIN();