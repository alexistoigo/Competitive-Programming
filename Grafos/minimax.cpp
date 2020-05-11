/*
Maior distancia percorrida entre vertices no menor caminho.
Utilizado Floyd Warshall
*/


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
#define MAX 503

const int INF = 0x3f3f3f3f;
using namespace std;

int grafo[MAX][MAX];

int main() {

   IO

   memset(grafo, INF, sizeof grafo);

   int n, m, t;

   cin >> n >> m;

   for(int i=0; i<m; i++) {
      int a, b, p;
      cin >> a >> b >> p;
      grafo[a][b]=p;
      grafo[b][a]=p;
   }

   for(int k = 1; k <= n; k++)
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++)
            grafo[i][j] = min(grafo[i][j], max(grafo[i][k], grafo[k][j]));

   cin >> t;
   while(t--) {
      int a, b;
      cin >> a >> b;

      (a==b) ? cout << "0\n" : cout << grafo[a][b] << "\n";
   }

   return 0;
}
