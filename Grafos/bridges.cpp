#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define MOD 1000000007
#define ull unsigned long long int
#define ll  long long int
#define pii pair<int, int>
#define pb push_back
#define MAX int(52)

const int INF = 0x3f3f3f3f;
using namespace std;

int n, m, bridge, cont;
vector<int>adj[MAX];
int tempo[MAX], parent[MAX], low[MAX];
bool visited[MAX];

void dfs(int u) {
   visited[u]=true;
   tempo[u]=low[u]=++cont;
   for(int v:adj[u]) {
      if(!visited[v]) {
         parent[v]=u;
         dfs(v);
         low[u]=min(low[u], low[v]);
         if(low[v]>tempo[u]) {
            bridge++;
         }
      } else if(v!=parent[u]) {
         low[u]=min(low[u], tempo[v]);
      }
   }
}

int main() {

   IO

   int n, m, a, b;

   while(cin >> n >> m) {
      cont=0;
      bridge=0;
      memset(low, 0, sizeof low);
      memset(tempo, 0, sizeof tempo);
      memset(parent, -1, sizeof parent);
      memset(visited, false, sizeof visited);


      for(int i=0; i<m; i++) {
         cin >> a >> b;
         adj[a].pb(b);
         adj[b].pb(a);
      }


      for(int i=1; i<=n; i++) {
         if(!visited[i]) {
            dfs(i);
         }
      }

      cout << bridge << "\n";

      for(int i=0; i<=n; i++)
         adj[i].clear();

   }

   return 0;
}
