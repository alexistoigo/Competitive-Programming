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

/*
   CHECAR SE O GRAFO DIRIGIDO É FORTEMENTE CONEXO (DE QUALQUER VERTICE
                                             POSSO IR A QUAL QUER OUTO)

   CRIAR 2 LISTAS ADJ, UMA PARA O GRAFO NORMAL E OUTRA PARA O GRAFO REVERSO
   E RODAR UMA DFS A PARTIR DE QUALQUER VERTICE PARA AMBOS OS GRAFOS E
   VERIFICANDO SE ALGUM VERTICE NÃO FOI VISITADO, CASO CONTRARIO O GRAFO
   É FORTEMENTE CONEXO.
*/

vector<int> adj[MAX], adj_reverse[MAX];
bool visited[MAX];
int n, a, b;

void dfs(int u, vector<int> aux[]) {
   visited[u]=true;
   for(int v:aux[u])
      if(!visited[v])
         dfs(v, aux);
}

bool check() {
   for(int i=1; i<=n; i++)
      if(!visited[i])
         return false;
   return true;
}

int main() {

   IO

   cin >> n;

   for(int i=0; i<n; i++) {
      cin >> a >> b;
      adj[a].pb(b);
      adj_reverse[b].pb(a);
   }

   dfs(1, adj);

   if(!check()) {
      cout << "N\n";
   } else {
      memset(visited, false, sizeof visited);
      dfs(1, adj_reverse);
      if(!check())
         cout << "N\n";
      else
         cout << "S\n";
   }

   return 0;
}
