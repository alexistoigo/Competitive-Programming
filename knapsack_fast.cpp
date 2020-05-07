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


int n, valor[MAX], peso[MAX];
int teste=1;

int knapsack(int n, int W) {
   int dp[W+1];
   memset(dp, 0, sizeof(dp));
   for(int i=0; i < n; i++)
      for(int j=W; j>=peso[i]; j--)
         dp[j] = max(dp[j], valor[i] + dp[j-peso[i]]);

   return dp[W];
}

int main() {

   IO

   int w;

   while(cin >> w >> n, w, n) {
      for(int i=0; i<n; i++) {
         cin >> peso[i] >> valor[i];
      }

      cout << "Teste "  << teste++ << "\n";
      cout << knapsack(n, w) << "\n\n";

   }

   return 0;
}
