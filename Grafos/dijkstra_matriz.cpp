#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define MOD 1000000007
#define ull unsigned long long int
#define ll  long long int
#define pii pair<int, int>
#define pb push_back
#define MAX int(502)

const int INF = 0x3f3f3f3f;
using namespace std;

const int di[]= {-1, 0, 0, 1};
const int dj[]= {0, -1, 1, 0};

int graph[MAX][MAX], dist[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
pii inicio, dest;

void dijkstra(int x, int y) {
   dist[x][y]=0;

   queue<pii> fila;
   fila.push({x, y});

   while(!fila.empty()) {
      pii act=fila.front();
      fila.pop();
      for(int k=0; k<4; k++) {
         pii to= {act.first+di[k], act.second+dj[k]};
         if(dist[to.first][to.second]> dist[act.first][act.second]+ graph[to.first][to.second]) {
            dist[to.first][to.second]=dist[act.first][act.second]+ graph[to.first][to.second];
            fila.push({to.first, to.second});
         }
      }
   }
}


int main() {

   IO

   cin >> n >> m;
   char c;

   memset(dist, INF, sizeof dist);
   memset(graph, INF, sizeof graph);

   for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
         cin >> c;
         if(c=='.')
            graph[i][j]=0;
         else if(c=='H') {
            inicio= {i, j};
            graph[i][j]=0;
         } else if(c=='E') {
            dest= {i, j};
            graph[i][j]=0;
         } else if(c=='#') {
            visited[i][j]=true;
         } else
            graph[i][j]=c-'0';
      }
   }

   dijkstra(inicio.first, inicio.second);


   dist[dest.first][dest.second]==INF ? cout << "ARTSKJID\n" : cout << dist[dest.first][dest.second] << "\n";

   return 0;
}
