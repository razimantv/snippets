#include <string>
#include <iostream>
#include <vector>

const long long P = 37, MOD = 1'000'000'007;
std::vector<long long> fwhash, ppow;

void buildfwhash(const std::string& s, int L) {
  fwhash = std::vector<long long>(L + 1, 0);
  ppow = std::vector<long long>(L + 1, 1);
  for (int i = 0; i < L; ++i) {
    fwhash[i + 1] = (fwhash[i] * P + (s[i] - 'a' + 1)) % MOD;
    ppow[i + 1] = (ppow[i] * P) % MOD;
  }
}

int hash(int i, int j) {
  int ret = fwhash[i + j] + MOD - (fwhash[i] * ppow[j]) % MOD;
  if (ret >= MOD) ret -= MOD;
  return ret;
}

int main() {
  std::string s = "abacabd";
  int L = s.size();
  buildfwhash(s, L);

  for (int i = 0; i < L; ++i) {
    for (int j = i+1; j < L; ++j) {
      for (int k = 1; k+j <= L; ++k) {
        if(hash(i, k) == hash(j, k))
          std::cout << "(" << i << "," << j << "," << k
                    << "): " << s.substr(i, k) << " == " << s.substr(j, k)
                    << "\n";
      }
    }
  }
  return 0;
}

