#include <bits/stdc++.h>

#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.in", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define MAX (999999999LL)+4

const int INF = 0x3f3f3f3f;
using namespace std;

/*
*	RETORNA QUANTOS BITS '1' HA NO INTERVALO 1-N
*
*/

ull countSetBits(ull n) {
    n++;
    ull powerOf2 = 2;
    ull cnt = n / 2;
    while (powerOf2 <= n) {
        ull totalPairs = n / powerOf2;
        cnt += (totalPairs / 2) * powerOf2;
        cnt += (totalPairs & 1) ? (n % powerOf2) : 0;
        powerOf2 <<= 1;
    }
    return cnt;
}

int main() {

    IO

    ull n, m;

    while (cin >> n >> m) {
        cout << countSetBits(m) - countSetBits(n - 1) << '\n';
    }

    return 0;
}
