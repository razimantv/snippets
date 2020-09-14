#include <iostream>

const int NMAX = 1000000;
char notprime[NMAX+1];

int main() {
  for (int i = 2; i * i < NMAX; ++i) {
    if(notprime[i]) continue;
    for (int j = i * i; j < NMAX; j += i) {
      notprime[j] = 1;
    }
  }
  int cnt = 0;
  for (int i = 2; i < NMAX; ++i) {
    if (!notprime[i]) ++cnt;
  }
  std::cout << cnt << std::endl;
  return 0;
}
