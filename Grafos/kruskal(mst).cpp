#pragma GCC optimize("O2")

#include <bits/stdc++.h>

#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define MAX int(1e3+10)
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

int n, m, pai[MAX], peso[MAX];
int cnt;

int find(int x) {
    while (pai[x] != x) x = pai[x];
    return x;
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (peso[x] > peso[y]) swap(x, y);
    pai[x] = y;
    peso[y] += peso[x];
    peso[x] = peso[y];
}

int main() {

    IO
#ifndef ONLINE_JUDGE
    FIN
    //FOUT
#endif

#define f first
#define s second

    while (cin >> n >> m) {
        vector<pair<int, pii>> mst(m);
        for (auto &i:mst) cin >> i.s.f >> i.s.s >> i.f;

        sort(mst.begin(), mst.end());
        memset(peso, 0, sizeof peso);
        iota(pai, pai + n + 1, 0);

        int sum = 0;
        for (int i = 0; i < m; i++) {
            if (find(mst[i].s.f) != find(mst[i].s.s)) {
                sum += mst[i].f;
                merge(mst[i].s.f, mst[i].s.s);
            }
        }
        cout << "Instancia " << ++cnt << "\n";
        cout << sum << "\n\n";
    }

    return 0;
}
