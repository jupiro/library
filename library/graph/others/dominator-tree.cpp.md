---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: graph/others/dominator-tree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e557c7f962c39680942b9dada22cabec">graph/others</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/others/dominator-tree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-30 23:02:43+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/verify/aoj-0294.test.cpp.html">test/verify/aoj-0294.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template< typename G >
struct DominatorTree {

  struct UnionFind {
    const vector< int > &semi;
    vector< int > par, m;

    UnionFind(const vector< int > &semi) : semi(semi), par(semi.size()), m(semi.size()) {
      iota(begin(par), end(par), 0);
      iota(begin(m), end(m), 0);
    }

    int find(int v) {
      if(par[v] == v) return v;
      int r = find(par[v]);
      if(semi[m[v]] > semi[m[par[v]]]) m[v] = m[par[v]];
      return par[v] = r;
    }

    int eval(int v) {
      find(v);
      return m[v];
    }

    void link(int p, int c) {
      par[c] = p;
    }
  };

  const G &g;
  vector< vector< int > > rg;
  vector< int > ord, par;
  vector< int > idom, semi;
  UnionFind uf;

  DominatorTree(G &g) : g(g), rg(g.size()), par(g.size()), idom(g.size(), -1), semi(g.size(), -1), uf(semi) {
    ord.reserve(g.size());
  }


  void dfs(int idx) {
    semi[idx] = (int) ord.size();
    ord.emplace_back(idx);
    for(auto &to : g[idx]) {
      if(~semi[to]) continue;
      dfs(to);
      par[to] = idx;
    }
  }

  void build(int root) {
    const int N = (int) g.size();
    dfs(root);
    for(int i = 0; i < N; i++) {
      for(auto &to : g[i]) {
        if(~semi[i]) rg[to].emplace_back(i);
      }
    }

    vector< vector< int > > bucket(N);
    vector< int > U(N);
    for(int i = (int) ord.size() - 1; i >= 0; i--) {
      int x = ord[i];
      for(int v : rg[x]) {
        v = uf.eval(v);
        if(semi[x] > semi[v]) semi[x] = semi[v];
      }
      bucket[ord[semi[x]]].emplace_back(x);
      for(int v : bucket[par[x]]) U[v] = uf.eval(v);
      bucket[par[x]].clear();
      uf.link(par[x], x);
    }
    for(int i = 1; i < ord.size(); i++) {
      int x = ord[i], u = U[x];
      idom[x] = semi[x] == semi[u] ? semi[x] : idom[u];
    }
    for(int i = 1; i < ord.size(); i++) {
      int x = ord[i];
      idom[x] = ord[idom[x]];
    }
    idom[root] = root;
  }

  int operator[](const int &k) {
    return idom[k];
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/others/dominator-tree.cpp"
template< typename G >
struct DominatorTree {

  struct UnionFind {
    const vector< int > &semi;
    vector< int > par, m;

    UnionFind(const vector< int > &semi) : semi(semi), par(semi.size()), m(semi.size()) {
      iota(begin(par), end(par), 0);
      iota(begin(m), end(m), 0);
    }

    int find(int v) {
      if(par[v] == v) return v;
      int r = find(par[v]);
      if(semi[m[v]] > semi[m[par[v]]]) m[v] = m[par[v]];
      return par[v] = r;
    }

    int eval(int v) {
      find(v);
      return m[v];
    }

    void link(int p, int c) {
      par[c] = p;
    }
  };

  const G &g;
  vector< vector< int > > rg;
  vector< int > ord, par;
  vector< int > idom, semi;
  UnionFind uf;

  DominatorTree(G &g) : g(g), rg(g.size()), par(g.size()), idom(g.size(), -1), semi(g.size(), -1), uf(semi) {
    ord.reserve(g.size());
  }


  void dfs(int idx) {
    semi[idx] = (int) ord.size();
    ord.emplace_back(idx);
    for(auto &to : g[idx]) {
      if(~semi[to]) continue;
      dfs(to);
      par[to] = idx;
    }
  }

  void build(int root) {
    const int N = (int) g.size();
    dfs(root);
    for(int i = 0; i < N; i++) {
      for(auto &to : g[i]) {
        if(~semi[i]) rg[to].emplace_back(i);
      }
    }

    vector< vector< int > > bucket(N);
    vector< int > U(N);
    for(int i = (int) ord.size() - 1; i >= 0; i--) {
      int x = ord[i];
      for(int v : rg[x]) {
        v = uf.eval(v);
        if(semi[x] > semi[v]) semi[x] = semi[v];
      }
      bucket[ord[semi[x]]].emplace_back(x);
      for(int v : bucket[par[x]]) U[v] = uf.eval(v);
      bucket[par[x]].clear();
      uf.link(par[x], x);
    }
    for(int i = 1; i < ord.size(); i++) {
      int x = ord[i], u = U[x];
      idom[x] = semi[x] == semi[u] ? semi[x] : idom[u];
    }
    for(int i = 1; i < ord.size(); i++) {
      int x = ord[i];
      idom[x] = ord[idom[x]];
    }
    idom[root] = root;
  }

  int operator[](const int &k) {
    return idom[k];
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
