#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "../../template/template.cpp"

#include "../../math/number-theory/enumerate-prime.cpp"

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  auto d = enumerate_prime(N);
  vector< int > ans;
  for(int i = B; i < d.size(); i += A) {
    ans.emplace_back(d[i]);
  }
  cout << d.size() << " " << ans.size() << "\n";
  cout << ans << "\n";
}
