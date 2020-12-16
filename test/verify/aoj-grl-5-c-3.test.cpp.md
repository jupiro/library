---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.cpp
    title: graph/graph-template.cpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/rmq-lowest-common-ancestor.cpp
    title: "RMQ-Lowest-Common-Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: structure/others/sparse-table.cpp
    title: "Sparse-Table(\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB)"
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/verify/aoj-grl-5-c-3.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\n\n#line 1\
    \ \"template/template.cpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing int64 = long long;\nconst int mod = 1e9 + 7;\n\nconst int64 infll = (1LL\
    \ << 62) - 1;\nconst int inf = (1 << 30) - 1;\n\nstruct IoSetup {\n  IoSetup()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(10);\n    cerr << fixed << setprecision(10);\n  }\n} iosetup;\n\
    \n\ntemplate< typename T1, typename T2 >\nostream &operator<<(ostream &os, const\
    \ pair< T1, T2 >& p) {\n  os << p.first << \" \" << p.second;\n  return os;\n\
    }\n\ntemplate< typename T1, typename T2 >\nistream &operator>>(istream &is, pair<\
    \ T1, T2 > &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate< typename\
    \ T >\nostream &operator<<(ostream &os, const vector< T > &v) {\n  for(int i =\
    \ 0; i < (int) v.size(); i++) {\n    os << v[i] << (i + 1 != v.size() ? \" \"\
    \ : \"\");\n  }\n  return os;\n}\n\ntemplate< typename T >\nistream &operator>>(istream\
    \ &is, vector< T > &v) {\n  for(T &in : v) is >> in;\n  return is;\n}\n\ntemplate<\
    \ typename T1, typename T2 >\ninline bool chmax(T1 &a, T2 b) { return a < b &&\
    \ (a = b, true); }\n\ntemplate< typename T1, typename T2 >\ninline bool chmin(T1\
    \ &a, T2 b) { return a > b && (a = b, true); }\n\ntemplate< typename T = int64\
    \ >\nvector< T > make_v(size_t a) {\n  return vector< T >(a);\n}\n\ntemplate<\
    \ typename T, typename... Ts >\nauto make_v(size_t a, Ts... ts) {\n  return vector<\
    \ decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));\n}\n\ntemplate< typename\
    \ T, typename V >\ntypename enable_if< is_class< T >::value == 0 >::type fill_v(T\
    \ &t, const V &v) {\n  t = v;\n}\n\ntemplate< typename T, typename V >\ntypename\
    \ enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {\n  for(auto\
    \ &e : t) fill_v(e, v);\n}\n\ntemplate< typename F >\nstruct FixPoint : F {\n\
    \  FixPoint(F &&f) : F(forward< F >(f)) {}\n \n  template< typename... Args >\n\
    \  decltype(auto) operator()(Args &&... args) const {\n    return F::operator()(*this,\
    \ forward< Args >(args)...);\n  }\n};\n \ntemplate< typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 2 \"graph/graph-template.cpp\"\
    \n\ntemplate< typename T = int >\nstruct Edge {\n  int from, to;\n  T cost;\n\
    \  int idx;\n\n  Edge() = default;\n\n  Edge(int from, int to, T cost = 1, int\
    \ idx = -1) : from(from), to(to), cost(cost), idx(idx) {}\n\n  operator int()\
    \ const { return to; }\n};\n\ntemplate< typename T = int >\nstruct Graph {\n \
    \ vector< vector< Edge< T > > > g;\n  int es;\n\n  Graph() = default;\n\n  explicit\
    \ Graph(int n) : g(n), es(0) {}\n\n  size_t size() const {\n    return g.size();\n\
    \  }\n\n  void add_directed_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from,\
    \ to, cost, es++);\n  }\n\n  void add_edge(int from, int to, T cost = 1) {\n \
    \   g[from].emplace_back(from, to, cost, es);\n    g[to].emplace_back(to, from,\
    \ cost, es++);\n  }\n\n  void read(int M, int padding = -1, bool weighted = false,\
    \ bool directed = false) {\n    for(int i = 0; i < M; i++) {\n      int a, b;\n\
    \      cin >> a >> b;\n      a += padding;\n      b += padding;\n      T c = T(1);\n\
    \      if(weighted) cin >> c;\n      if(directed) add_directed_edge(a, b, c);\n\
    \      else add_edge(a, b, c);\n    }\n  }\n};\n\ntemplate< typename T = int >\n\
    using Edges = vector< Edge< T > >;\n#line 5 \"test/verify/aoj-grl-5-c-3.test.cpp\"\
    \n\n#line 1 \"structure/others/sparse-table.cpp\"\n/**\n * @brief Sparse-Table(\u30B9\
    \u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB)\n * @docs docs/sparse-table.md\n */\n\
    template< typename T, typename F >\nstruct SparseTable {\n  F f;\n  vector< vector<\
    \ T > > st;\n  vector< int > lookup;\n\n  SparseTable() = default;\n\n  explicit\
    \ SparseTable(const vector< T > &v, const F &f) : f(f) {\n    const int n = (int)\
    \ v.size();\n    const int b = 32 - __builtin_clz(n);\n    st.assign(b, vector<\
    \ T >(n));\n    for(int i = 0; i < v.size(); i++) {\n      st[0][i] = v[i];\n\
    \    }\n    for(int i = 1; i < b; i++) {\n      for(int j = 0; j + (1 << i) <=\
    \ n; j++) {\n        st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n\
    \      }\n    }\n    lookup.resize(v.size() + 1);\n    for(int i = 2; i < lookup.size();\
    \ i++) {\n      lookup[i] = lookup[i >> 1] + 1;\n    }\n  }\n\n  inline T fold(int\
    \ l, int r) const {\n    int b = lookup[r - l];\n    return f(st[b][l], st[b][r\
    \ - (1 << b)]);\n  }\n};\n\ntemplate< typename T, typename F >\nSparseTable< T,\
    \ F > get_sparse_table(const vector< T > &v, const F &f) {\n  return SparseTable<\
    \ T, F >(v, f);\n}\n#line 2 \"graph/tree/rmq-lowest-common-ancestor.cpp\"\n\n\
    /**\n * @brief RMQ-Lowest-Common-Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148\
    )\n * @docs docs/rmq-lowest-common-ancestor.md\n **/\ntemplate< typename T = int\
    \ >\nstruct RMQLowestCommonAncestor : Graph< T > {\npublic:\n  using Graph< T\
    \ >::Graph;\n  using Graph< T >::g;\n  using F = function< int(int, int) >;\n\n\
    \  void build(int root = 0) {\n    ord.reserve(g.size() * 2 - 1);\n    dep.reserve(g.size()\
    \ * 2 - 1);\n    in.resize(g.size());\n    dfs(root, -1, 0);\n    vector< int\
    \ > vs(g.size() * 2 - 1);\n    iota(begin(vs), end(vs), 0);\n    F f = [&](int\
    \ a, int b) { return dep[a] < dep[b] ? a : b; };\n    st = get_sparse_table(vs,\
    \ f);\n  }\n\n  int lca(int x, int y) const {\n    if(in[x] > in[y]) swap(x, y);\n\
    \    return x == y ? x : ord[st.fold(in[x], in[y])];\n  }\n\nprivate:\n  vector<\
    \ int > ord, dep, in;\n  SparseTable< int, F > st;\n\n  void dfs(int idx, int\
    \ par, int d) {\n    in[idx] = (int) ord.size();\n    ord.emplace_back(idx);\n\
    \    dep.emplace_back(d);\n    for(auto &to : g[idx]) {\n      if(to != par) {\n\
    \        dfs(to, idx, d + 1);\n        ord.emplace_back(idx);\n        dep.emplace_back(d);\n\
    \      }\n    }\n  }\n};\n#line 7 \"test/verify/aoj-grl-5-c-3.test.cpp\"\n\nint\
    \ main() {\n  int N, Q;\n  cin >> N;\n  RMQLowestCommonAncestor< int > lca(N);\n\
    \  for(int i = 0; i < N; i++) {\n    int k;\n    cin >> k;\n    for(int j = 0;\
    \ j < k; j++) {\n      int c;\n      cin >> c;\n      lca.add_edge(i, c);\n  \
    \  }\n  }\n  lca.build();\n  cin >> Q;\n  for(int i = 0; i < Q; i++) {\n    int\
    \ u, v;\n    cin >> u >> v;\n    cout << lca.lca(u, v) << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#include \"../../template/template.cpp\"\n#include \"../../graph/graph-template.cpp\"\
    \n\n#include \"../../graph/tree/rmq-lowest-common-ancestor.cpp\"\n\nint main()\
    \ {\n  int N, Q;\n  cin >> N;\n  RMQLowestCommonAncestor< int > lca(N);\n  for(int\
    \ i = 0; i < N; i++) {\n    int k;\n    cin >> k;\n    for(int j = 0; j < k; j++)\
    \ {\n      int c;\n      cin >> c;\n      lca.add_edge(i, c);\n    }\n  }\n  lca.build();\n\
    \  cin >> Q;\n  for(int i = 0; i < Q; i++) {\n    int u, v;\n    cin >> u >> v;\n\
    \    cout << lca.lca(u, v) << \"\\n\";\n  }\n}\n"
  dependsOn:
  - template/template.cpp
  - graph/graph-template.cpp
  - graph/tree/rmq-lowest-common-ancestor.cpp
  - structure/others/sparse-table.cpp
  isVerificationFile: true
  path: test/verify/aoj-grl-5-c-3.test.cpp
  requiredBy: []
  timestamp: '2020-11-11 23:28:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/aoj-grl-5-c-3.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-grl-5-c-3.test.cpp
- /verify/test/verify/aoj-grl-5-c-3.test.cpp.html
title: test/verify/aoj-grl-5-c-3.test.cpp
---