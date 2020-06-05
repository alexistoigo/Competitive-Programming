#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.in", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define MAX int(1e5)+4

const int INF = 0x3f3f3f3f;
using namespace std;

/*
*  https://www.geeksforgeeks.org/find-the-count-of-distinct-numbers-in-a-range/
*	CONTA QUANTOS VALORES DIFERENTES A EM UM INTERVALO L-R COM UPDATE EM POINT
*/

ll seg[4*MAX];
vector<int>arr;

void build(int l, int r, int node) {
   if(l==r) {
      seg[node]=(1LL << arr[l]);
      return;
   }
   int mid=(l+r)/2;
   build(l, mid, 2*node);
   build(mid+1, r, 2*node+1);

   seg[node]=(seg[2*node] | seg[2*node+1]);
}

ll query(int start, int end, int l, int r, int node) {
   if(end<l || start>r)
      return 0;
   if(start>=l && end<=r)
      return seg[node];

   int mid=(start+end)/2;
   ll leftChild=query(start, mid, l, r, 2*node);
   ll rightChild=query(mid+1, end, l, r, 2*node+1);

   return (leftChild | rightChild);
}

void update(int l, int r, int index, int value, int node) {
   if(r==l) {
      arr[index]=value;
      seg[node]=(1LL<<value);
      return;
   }

   int mid=(l+r)/2;
   if(index>mid)
      update(mid+1, r, index, value, 2*node+1);
   else
      update(l, mid, index, value, 2*node);

   seg[node]=(seg[2*node] | seg[2*node+1]);
}

int main() {

   IO

   int n, q, m;

   cin >> n >> q >> m;

   arr.resize(n);
   for(int &i:arr)
      cin >> i;

   build(0, n-1, 1);
   int op, a, b;

   for(int i=0; i<q; i++) {
      cin >> op >> a >> b;
      if(op==1) {
         ll mask=query(0, n-1, a-1, b-1, 1);
         int cont=0;
         for(int i=63; i>=0; i--)
            if(mask & (1LL<<i))
               cont++;
         cout << cont << "\n";
      } else {
         update(0, n-1, a-1, b, 1);
      }
   }

   return 0;
}
