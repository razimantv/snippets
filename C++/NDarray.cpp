#include <array>
#include <iostream>
#include <ranges>
#include <experimental/iterator>

template<class T, size_t n1, size_t... ns>
struct NDarrayhelper {
  using subarray = typename NDarrayhelper<T, ns...>::type;
  using type = std::array<subarray, n1>;
};

template<class T, size_t n1>
struct NDarrayhelper<T, n1> {
  using type = std::array<T, n1>;
};

template<class T, size_t... ns>
using NDarray = typename NDarrayhelper<T, ns...>::type;

template <std::ranges::range range>
std::ostream& operator<<(std::ostream& out, range R) {
  out << "[";
  bool flag{};
  for(const auto& elem:R) {
    if(flag) out << ",";
    else flag = true;
    out << elem;
  }
  out << "]";
  return out;
}

int main() {
  NDarray<int, 3, 3, 2> ar;
  for(int val = 0; auto& ar1: ar) {
    for (auto &ar2 : ar1) {
      for(int & ar3: ar2) {
        ar3 = ++val;
      }
    }
  }

  std::cout << ar << "\n";
  return 0;
}

