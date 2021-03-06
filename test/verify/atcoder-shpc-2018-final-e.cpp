#define IGNORE

using int64 = long long;

int64 power[234567];
const int LIM = 1000000;
 
int main() {
  int N, M;
  string S[20];
 
  power[0] = 1;
  for(int i = 0; i < 234566; i++) power[i + 1] = 1LL * power[i] * 1000000 % mod;
 
  cin >> N >> M;
  for(int i = 0; i < M; i++) cin >> S[i];
  vector< vector< pair< int, int > > > dat(M, vector< pair< int, int > >(N));
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      dat[i][j].first = S[i][j] - 'a';
      dat[i][j].first++;
      dat[i][j].second = 1;
    }
  }
  using pi = pair< int, int >;
  auto F = [&](pi x, pi y) {
    return pi((1LL * y.first * power[x.second] + x.first % mod) % mod, x.second + y.second);
  };
  vector< RandomizedBinarySearchTree< pi > >
      beet(M, RandomizedBinarySearchTree< pi >(N, F, pi(0, 0)));
  vector< RandomizedBinarySearchTree< pi >::Node * > root;
  for(int i = 0; i < M; i++) root.push_back(beet[i].build(dat[i]));
  
  int Q;
  cin >> Q;
  while(Q--) {
    int T, A, B, C, D;
    cin >> T >> A >> B >> C >> D;
    --A, --B, --C;
    if(T == 1) {
      auto S = beet[A].split(root[A], D);
      auto T = beet[A].split(S.first, C);
      auto U = beet[B].split(root[B], D);
      auto V = beet[B].split(U.first, C);
      root[A] = beet[A].merge(T.first, beet[A].merge(V.second, S.second));
      root[B] = beet[B].merge(V.first, beet[B].merge(T.second, U.second));
    } else {
      auto S = beet[A].split(root[A], D);
      auto T = beet[A].split(S.first, C);
      printf("%d\n", beet[A].sum(T.second).first);
      root[A] = beet[A].merge(beet[A].merge(T.first, T.second), S.second);
    }
  }
}
