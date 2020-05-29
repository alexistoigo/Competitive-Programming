#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define ull unsigned long long int
#define ll long long int
#define pii pair<int, int>
#define pb push_back
#define MAX int(5*1e5+6)

const int INF = 0x3f3f3f3f;
using namespace std;

///SEGTREE RANGE QUERY POINT UPDATE

int n, a[MAX], t[4*MAX];

int op(int a, int b) {
   return max(a, b);///operação segtree
}

void build(int v, int tl, int tr) {
   if(tl == tr) {
      t[v] = a[tl];
   } else {
      int tm = (tl + tr) / 2;
      build(v*2, tl, tm);
      build(v*2+1, tm+1, tr);
      t[v] = op(t[v*2], t[v*2+1]);
   }
}

int query(int v, int tl, int tr, int l, int r) {
   if(l > r)
      return 0;
   if(l == tl && r == tr) {
      return t[v];
   }
   int tm = (tl + tr) / 2;
   return op(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
   if(tl == tr) {
      t[v] = new_val;///onde faz a troca do valor, tmb pode ser feita a soma/etc
   } else {
      int tm = (tl + tr) / 2;
      if(pos <= tm)
         update(v*2, tl, tm, pos, new_val);
      else
         update(v*2+1, tm+1, tr, pos, new_val);
      t[v] = op(t[v*2], t[v*2+1]);
   }
}

int main() {

   //IO

   int k;

   cin >> n >> k;
   for(int i=0; i<n; i++)
      cin >> a[i];

   build(1, 0, n-1);

   while(k--) {
      int a, b, op;
      cin >> op;
      if(op==1) {
         cin >> a >> b;
         update(1, 0, n-1, a, b);
      } else {
         cin >> a >> b;
         cout << query(1, 0, n-1, a, b) << "\n";
      }
   }


   return 0;
}
