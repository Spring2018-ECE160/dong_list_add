#include <iostream>
#include <list>
#include <stack>

int main() {
  // Assume positive integers.
  std::list<int> a = {1, 2, 3, 4};
  std::list<int> b = {5, 5, 6};

  std::stack<int> astack;
  std::stack<int> bstack;

  // Put numbers into stacks.
  for (int ad : a) {
    astack.push(ad);
  }

  for (int bd : b) {
    bstack.push(bd);
  }

  // Add.
  long long res = 0;
  long long power = 1;
  while (true) {
    bool aempty = astack.empty();
    bool bempty = bstack.empty();
    int ad = aempty ? 0 : astack.top();
    int bd = bempty ? 0 : bstack.top();
    res += power * (ad + bd);
    power *= 10;

    if (!aempty)
      astack.pop();
    if (!bempty)
      bstack.pop();
    if (aempty && bempty)
      break;
  }

  std::cout << res << std::endl;
  return 0;
}
