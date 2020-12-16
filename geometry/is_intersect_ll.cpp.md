---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.cpp
    title: geometry/base.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_parallel.cpp
    title: geometry/is_parallel.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.cpp
    title: geometry/line.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.cpp
    title: geometry/point.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/distance_ll.cpp
    title: geometry/distance_ll.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/base.cpp\"\n\nnamespace geometry {\n  using Real\
    \ = double;\n  const Real EPS = 1e-8;\n  const Real PI = acos(static_cast< Real\
    \ >(-1));\n\n  enum {\n    OUT, ON, IN\n  };\n\n  inline int sign(const Real &r)\
    \ {\n    return r <= -EPS ? -1 : r >= EPS ? 1 : 0;\n  }\n\n  inline bool equals(const\
    \ Real &a, const Real &b) {\n    return sign(a - b) == 0;\n  }\n}\n#line 3 \"\
    geometry/point.cpp\"\n\nnamespace geometry {\n  using Point = complex< Real >;\n\
    \n  istream &operator>>(istream &is, Point &p) {\n    Real a, b;\n    is >> a\
    \ >> b;\n    p = Point(a, b);\n    return is;\n  }\n\n  ostream &operator<<(ostream\
    \ &os, const Point &p) {\n    return os << real(p) << \" \" << imag(p);\n  }\n\
    \n  Point operator*(const Point &p, const Real &d) {\n    return Point(real(p)\
    \ * d, imag(p) * d);\n  }\n\n  // rotate point p counterclockwise by theta rad\n\
    \  Point rotate(Real theta, const Point &p) {\n    return Point(cos(theta) * real(p)\
    \ - sin(theta) * imag(p), sin(theta) * real(p) + cos(theta) * imag(p));\n  }\n\
    \n  Real cross(const Point &a, const Point &b) {\n    return real(a) * imag(b)\
    \ - imag(a) * real(b);\n  }\n\n  Real dot(const Point &a, const Point &b) {\n\
    \    return real(a) * real(b) + imag(a) * imag(b);\n  }\n\n  bool compare_x(const\
    \ Point &a, const Point &b) {\n    return equals(real(a), real(b)) ? imag(a) <\
    \ imag(b) : real(a) < real(b);\n  }\n\n  bool compare_y(const Point &a, const\
    \ Point &b) {\n    return equals(imag(a), imag(b)) ? real(a) < real(b) : imag(a)\
    \ < imag(b);\n  }\n\n  using Points = vector< Point >;\n}\n#line 3 \"geometry/line.cpp\"\
    \n\nnamespace geometry {\n  struct Line {\n    Point a, b;\n\n    Line() = default;\n\
    \n    Line(const Point &a, const Point &b) : a(a), b(b) {}\n\n    Line(const Real\
    \ &A, const Real &B, const Real &C) { // Ax+By=C\n      if(equals(A, 0)) {\n \
    \       assert(!equals(B, 0));\n        a = Point(0, C / B);\n        b = Point(1,\
    \ C / B);\n      } else if(equals(B, 0)) {\n        a = Point(C / A, 0);\n   \
    \     b = Point(C / A, 1);\n      } else {\n        a = Point(0, C / B);\n   \
    \     b = Point(C / A, 0);\n      }\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, Line &l) {\n      return os << l.a << \" to \" << l.b;\n    }\n\n    friend\
    \ istream &operator>>(istream &is, Line &l) {\n      return is >> l.a >> l.b;\n\
    \    }\n  };\n\n  using Lines = vector< Line >;\n}\n#line 3 \"geometry/is_parallel.cpp\"\
    \n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    \  bool is_parallel(const Line &a, const Line &b) {\n    return equals(cross(a.b\
    \ - a.a, b.b - b.a), 0.0);\n  }\n}\n#line 3 \"geometry/is_intersect_ll.cpp\"\n\
    \nnamespace geometry {\n  bool is_intersect_ll(const Line &l, const Line &m) {\n\
    \    Real A = cross(l.b - l.a, m.b - m.a);\n    Real B = cross(l.b - l.a, l.b\
    \ - m.a);\n    if(equals(abs(A), 0) && equals(abs(B), 0)) return true;\n    return\
    \ !is_parallel(l, m);\n  }\n}\n"
  code: "#include \"line.cpp\"\n#include \"is_parallel.cpp\"\n\nnamespace geometry\
    \ {\n  bool is_intersect_ll(const Line &l, const Line &m) {\n    Real A = cross(l.b\
    \ - l.a, m.b - m.a);\n    Real B = cross(l.b - l.a, l.b - m.a);\n    if(equals(abs(A),\
    \ 0) && equals(abs(B), 0)) return true;\n    return !is_parallel(l, m);\n  }\n\
    }\n"
  dependsOn:
  - geometry/line.cpp
  - geometry/point.cpp
  - geometry/base.cpp
  - geometry/is_parallel.cpp
  isVerificationFile: false
  path: geometry/is_intersect_ll.cpp
  requiredBy:
  - geometry/distance_ll.cpp
  timestamp: '2020-12-01 17:38:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/is_intersect_ll.cpp
layout: document
redirect_from:
- /library/geometry/is_intersect_ll.cpp
- /library/geometry/is_intersect_ll.cpp.html
title: geometry/is_intersect_ll.cpp
---