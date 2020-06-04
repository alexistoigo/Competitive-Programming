#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.in", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define MAX (10003)*1LL

const int INF = 0x3f3f3f3f;
using namespace std;

/*

	ALGORITMO MOCHILA PODENDO REPETIR ITENS

*/

int unboundedKnapsack(int W, int n, int val[], int wt[]) {
   int dp[W+1];
   memset(dp, 0, sizeof dp);

   int ans = 0;

   for(int i=0; i<=W; i++)
      for(int j=0; j<n; j++)
         if(wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]]+val[j]);

   return dp[W];
}


int main() {

   IO

   int n, W;
   int instancia=1;

   while(cin >> n >> W, n && W) {

      int val[n];
      int wt[n];

      for(int i=0; i<n; i++) {
         cin >> wt[i] >> val[i];
      }

      int total=unboundedKnapsack(W, n, val, wt);

      cout << "Instancia " << instancia++ << "\n";
      cout << total << "\n\n";
   }

   return 0;
}

