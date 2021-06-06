#include <iostream>

auto ContinuousAdd = [](int initial, int addBy) {
  int total = initial;
  return [total, addBy]() mutable {
    total += addBy;
    return total;
  };
};

int main() {
  auto c_add = ContinuousAdd(10, 2);

  std::cout << c_add() << std::endl;
  std::cout << c_add() << std::endl;
  std::cout << c_add() << std::endl;
  return 0;
}
