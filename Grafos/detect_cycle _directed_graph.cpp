#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define MOD 1000000007
#define ull unsigned long long int
#define ll  long long int
#define pii pair<int, int>
#define pb push_back
#define MAX int(10e4+3)

const int INF = 0x3f3f3f3f;
using namespace std;

vector<int> adj[MAX];
bool visited[MAX], recStack[MAX], resp;

bool dfs(int u) {
   if(!visited[u]) {
      visited[u]=true;
      recStack[u]=true;
      for(int i:adj[u]) {
         if(!visited[i] && dfs(i))
            return true;
         else if(recStack[i])
            return true;
      }
   }
   recStack[u]=false;
   return false;
}

int main() {

   IO

   int t, n, m, a, b;

   cin >> t;
   while(t--) {
      cin >> n >> m;
      resp=false;
      for(int i=0; i<m; i++) {
         cin >> a >> b;
         adj[a].pb(b);
      }
      memset(visited, false, sizeof visited);
      memset(recStack, false, sizeof recStack);

      for(int i=1; i<=n; i++) {
         if(dfs(i)) {
            resp=true;
            break;
         }
      }

      cout << (resp ? "SIM\n" : "NAO\n");

      for(int i=0; i<=n; i++)
         adj[i].clear();
   }

   return 0;
}
