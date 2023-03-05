#include<iostream>
#include<vector>
using namespace std;

template<class T>
Container
{
    // ...
};

template<class T, class<typename> 


template <typename T, 

template <
typename ELEM, 
typename ALLOC = std::allocator<ELEM>
 > class CONT = std::deque
 
 >   //deque的基本型有2个模板参数 
class Stack { 
  private: 
    CONT<T> elems;         // OK！
    //… 
}; 

template<class T>
 class A { // primary template
      int x;
};
template<class T>
 class A<T*> { // partial specialization
       long x;
};

template
<template<class U> class V> 

class C {

        V<int> y;
        V<int*> z;
};
C<A> c; // V<int> within C<A> uses the primary template, so c.y.x has type int
        // V<int*> within C<A> uses the partial specialization, so c.z.x has type long
template<class T> class A { /* ... */ };
template<class T, class U = T> class B { /* ... */ };
template <class ... Types> class C { /* ... */ };

template<template<class> class P> class X { /* ... */ };

template<template<class ...> class Q> class Y { /* ... */ };

X<A> xa; // OK
X<B> xb; // ill-formed: default arguments for the parameters of a template argument are ignored
X<C> xc; // ill-formed: a template parameter pack does not match a template parameter
Y<A> ya; // OK
Y<B> yb; // OK
Y<C> yc; // OK  


template <class T> struct eval;
template <template <class, class...> class TT, class T1, class... Rest>
struct eval<TT<T1, Rest...>> { };

template <class T1> struct A;
template <class T1, class T2> struct B;
template <int N> struct C;
template <class T1, int N> struct D;
template <class T1, class T2, int N = 17> struct E;
eval<A<int>> eA; // OK: matches partial specialization of eval