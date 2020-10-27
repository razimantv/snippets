int modpow(int a, int b, int MOD) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = (ret * (long long)a) % MOD;
    a = (a * (long long)a) % MOD;
    b >>= 1;
  }
  return ret;
}

bool isresidue(int a, int p) { return modpow(a, (p - 1) / 2, p) == 1; }

int getnonresidue(int p) {
  for (int i = 2; i < p; ++i)
    if (!isresidue(i, p)) return i;
  return -1;
}

int TonelliShanks(int p, int n) {
  if (!isresidue(n, p)) return -1;
  int Q = p - 1, S = 0, z = getnonresidue(p);
  while (!(Q & 1)) Q >>= 1, ++S;
  long long c = modpow(z, Q, p), t = modpow(n, Q, p);
  int R = modpow(n, (Q + 1) >> 1, p);
  while (1) {
    if (t == 1) return R;

    int i = 0;
    long long tt = t;
    while (tt != 1) tt = (tt * tt) % p, ++i;
    for (int j = 1; j < S - i; ++j) c = (c * c) % p;
    S = i;
    R = (R * c) % p;
    c = (c * c) % p;
    t = (t * c) % p;
  }
}

