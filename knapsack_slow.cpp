#include <bits/stdc++.h>

//#include <stdio.h>
//#include <math.h>
//#include <string.h>
//#include <stdbool.h>
//#include <stdlib.h>

#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define MOD 1000000007
#define ull unsigned long long int
#define ll  long long int
#define pii pair<int, int>
#define pb push_back
#define MAX 1001

const int INF = 0x3f3f3f3f;
using namespace std;


int n, valor[MAX], peso[MAX], tab[MAX][MAX];
int teste=1;

int knapsack(int obj, int w) {
   if(tab[obj][w]>=0)
      return tab[obj][w];

   if(obj==n || !w)
      return tab[obj][w]=0;

   int n_coloca=knapsack(obj+1, w);

   if(peso[obj]<=w) {
      int coloca=valor[obj]+knapsack(obj+1, w-peso[obj]);
      return tab[obj][w]=max(coloca, n_coloca);
   }
   return tab[obj][w]=n_coloca;
}

int main() {

   IO

   int w;

   while(cin >> w >> n, w, n) {

      memset(tab, -1, sizeof tab);
      for(int i=0; i<n; i++) {
         cin >> peso[i] >> valor[i];
      }

      cout << "Teste "  << teste++ << "\n";
      cout << knapsack(0, w) << "\n\n";

   }

   return 0;
}
