#include <bits/stdc++.h>

#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define MAX int(1e2+10)
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

//inicialmente setado para movimentos do cavalo(chess) trocar para células adj
const int di[] = {2, 1, -1, -2, -2, -1, 1, 2}, dj[] = {1, 2, 2, 1, -1, -2, -2, -1};

//definir sempre onde tem 16 o tamanho dos nodos + 1
int n, m, k, limit, dist[MAX][MAX][16], dp[16][1 << 16];
bool visited[MAX][MAX];
deque<pii > points;
char grid[MAX][MAX];

bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#'; }

void bfs(int idx) {
    int cx = points[idx].first;
    int cy = points[idx].second;
    visited[cx][cy] = true;
    dist[cx][cy][idx] = 0;
    queue<pii > pq;
    pq.push({cx, cy});

    while (!pq.empty()) {
        pii aux = pq.front();
        pq.pop();
        for (int i = 0; i < 8; i++) {
            cx = aux.first + di[i];
            cy = aux.second + dj[i];
            if (!visited[cx][cy] && safe(cx, cy)) {
                visited[cx][cy] = true;
                dist[cx][cy][idx] = dist[aux.first][aux.second][idx] + 1;
                pq.push({cx, cy});
            }
        }
    }
}

int solve(int id, int mask) {
    if (mask == limit) return dist[points[0].first][points[0].second][id];
    if (dp[id][mask] != -1) return dp[id][mask];
    int ans = INF;
    for (int i = 0; i < k; i++) {
        if (!(mask & (1 << i))) {
            ans = min(ans, solve(i, mask | (1 << i)) +
                           dist[points[i].first][points[i].second][id]);
        }
    }
    return dp[id][mask] = ans;
}

int main() {

    IO
#ifndef ONLINE_JUDGE
    FIN
    //FOUT
#endif

    while (cin >> n >> m >> k, n) {
        k++;
        points.clear();
        memset(dp, -1, sizeof dp);
        memset(dist, INF, sizeof dist);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'C') points.push_front({i, j});
                else if (grid[i][j] == 'P') points.pb({i, j});
            }

        limit = (1 << k) - 1;
        for (int i = 0; i < k; i++) {
            memset(visited, false, sizeof visited);
            bfs(i);
        }
        cout << solve(0, 1) << "\n";
    }

    return 0;
}
/*
 * https://www.geeksforgeeks.org/bitmasking-dynamic-programming-set-2-tsp/
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1513
 */
