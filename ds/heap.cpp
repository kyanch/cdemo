#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// 大根堆
class MaxHeap {
  vector<int> data;

 public:
  void push(int val) {
    data.push_back(val);
    // 从最后一个节点向父节点排序
    for (int i = data.size() - 1; i > 0;) {
      int parent = (i - 1) / 2;
      if (data[parent] < data[i]) {
        int tmp = data[parent];
        data[parent] = data[i];
        data[i] = tmp;
      }
    }
  }
  // 弹出最大节点，即首元素
  int pop() {
    int the_biggest = data.front();
    // 实际操作是将尾元素替换为首元素，再使堆有序
    data.front() = data.back();
    data.pop_back();

    for (int target = 0; target < data.size();) {
      int bigger, bigger_idx;

      int left = target * 2 + 1;
      int right = target * 2 + 2;
      if (left >= data.size()) {
        // 无左节点，target为叶子节点
        break;
      } else if (right >= data.size()) {
        // 无右节点，子节点中的最大为左节点
        bigger = data[left], bigger_idx = left;
      } else if (data[right] > data[left]) {
        bigger = data[right], bigger_idx = right;
      } else {
        bigger = data[left], bigger_idx = left;
      }

      if (bigger > data[target]) {
        data[bigger_idx] = data[target];
        data[target] = bigger;
        target = bigger;
      } else {
        break;
      }
    }

    return the_biggest;
  }
};

int main() {}