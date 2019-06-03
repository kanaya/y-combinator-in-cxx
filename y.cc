#include <iostream>

auto Y = [](auto f) {
  return [=](auto... args) {
    return f(f, args...);
  };
};

int main() {
  auto f = Y([](auto f, int n) -> int {
      return n == 1 ? 1 : n + f(f, n-1);
    });

  std::cout << f(10) << std::endl;
  return 0;
}
