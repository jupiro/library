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


# :heavy_check_mark: graph/mst/boruvka.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#51f95ed2fd9ed3be34f576d38fbd25a2">graph/mst</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/mst/boruvka.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-30 23:02:43+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/verify/aoj-grl-2-a-3.test.cpp.html">test/verify/aoj-grl-2-a-3.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template< typename T, typename F >
T boruvka(int N, F f) {
  vector< int > rev(N), belong(N);
  UnionFind uf(N);
  T ret = T();
  while(uf.size(0) != N) {
    int ptr = 0;
    for(int i = 0; i < N; i++) {
      if(uf.find(i) == i) {
        belong[i] = ptr++;
        rev[belong[i]] = i;
      }
    }
    for(int i = 0; i < N; i++) {
      belong[i] = belong[uf.find(i)];
    }
    auto v = f(ptr, belong);
    bool update = false;
    for(int i = 0; i < ptr; i++) {
      if(~v[i].second && uf.unite(rev[i], rev[v[i].second])) {
        ret += v[i].first;
        update = true;
      }
    }
    if(!update) return -1; // notice!!
  }
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/mst/boruvka.cpp"
template< typename T, typename F >
T boruvka(int N, F f) {
  vector< int > rev(N), belong(N);
  UnionFind uf(N);
  T ret = T();
  while(uf.size(0) != N) {
    int ptr = 0;
    for(int i = 0; i < N; i++) {
      if(uf.find(i) == i) {
        belong[i] = ptr++;
        rev[belong[i]] = i;
      }
    }
    for(int i = 0; i < N; i++) {
      belong[i] = belong[uf.find(i)];
    }
    auto v = f(ptr, belong);
    bool update = false;
    for(int i = 0; i < ptr; i++) {
      if(~v[i].second && uf.unite(rev[i], rev[v[i].second])) {
        ret += v[i].first;
        update = true;
      }
    }
    if(!update) return -1; // notice!!
  }
  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
