#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define MOD 1000000007
#define ull unsigned long long int
#define ll  long long int
#define pii pair<int, int>
#define pb push_back
#define MAX int(227)

const int INF = 0x3f3f3f3f;
using namespace std;

/*
	COM MATRIZ DE ADJ
	MENOR CAMINHO COM ALGORITMO DE DIJKSTRA MOSTRANDO O CAMINHO.
*/

int graph[MAX][MAX], dist[MAX], parent[MAX];
bool sptSet[MAX];
int n, m, dest;
vector<int>resp;

int minDistance() {
   int min=INT_MAX, min_index;
   for(int i=1; i<=n; i++)
      if(!sptSet[i] && dist[i]<=min)
         min=dist[i], min_index=i;
   return min_index;
}

void path(int j) {
   if(parent[j]==-1)
      return;
   path(parent[j]);
   resp.pb(j);
}

void dijkstra(int src) {
   dist[src]=0;

   for(int cont=0; cont<n; cont++) {
      int u=minDistance();
      sptSet[u]=true;

      for(int v=1; v<=n; v++) {
         if(!sptSet[v] && graph[u][v] && dist[u]+graph[u][v]<dist[v]) {
            parent[v]=u;
            dist[v]=dist[u]+graph[u][v];
         }
      }
   }
   path(dest);
}


int main() {

   IO

   while(cin >> n >> m, n, m) {
      int a, b, c;
      memset(graph, 0, sizeof graph);
      resp.clear();
      for(int i=0; i<m; i++) {
         cin >> a >> b >> c;
         graph[a][b]=c;
         graph[b][a]=c;
      }

      cin >> dest;

      for(int i=1; i<=n; i++) {
         parent[i]=-1;
         dist[i]=INF;
         sptSet[i]=false;
      }

      dijkstra(1);
      reverse(resp.begin(), resp.end());

      if(dist[dest]>120) {
         cout << "It will be " << dist[dest]-120 << " minutes late. Travel time - "
              << dist[dest] << " - best way - ";
         for(int i:resp)
            cout << i << " ";
         cout << "1\n";
      } else {
         cout << "Will not be late. Travel time - " << dist[dest] << " - best way - ";
         for(int i:resp)
            cout << i << " ";
         cout << "1\n";
      }
   }


   return 0;
}
