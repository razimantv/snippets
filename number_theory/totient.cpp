#include <iostream>

const int NMAX = 1000000;
int aprime[NMAX], totient[NMAX];

int main() {
  for (int i = 2; i * i < NMAX; ++i) {
    if (aprime[i]) continue;
    totient[i] = i - 1;
    for (int j = i * i; j < NMAX; j += i) aprime[j] = i;
  }

  totient[1] = 1;
  long long phitot = 1;
  for (int i = 2; i < NMAX; ++i) {
    if (!aprime[i]) totient[i] = i - 1;
    else if ((i / aprime[i]) % aprime[i])
      totient[i] = totient[i / aprime[i]] * (aprime[i] - 1);
    else
      totient[i] = totient[i / aprime[i]] * aprime[i];
    phitot += totient[i];
  }
  std::cout << phitot << std::endl;
  return 0;
}
