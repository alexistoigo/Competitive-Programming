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
*	CONTA QUANTOS ANAGRAMAS UMA STRING TEM
*
*/

const ll MOD = 1e9 + 7;
ll fact[10009];

void factorial() {
    fact[0] = 1;
    fact[1] = 1;
    int i;
    for (i = 2; i <= 10000; i++) {
        fact[i] = ((fact[i - 1] % MOD) * (i) % MOD) % MOD;
    }
}

ll binary_exp(ll x, ll n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x % MOD;
    } else {
        ll temp = binary_exp(x, n / 2);
        temp = (temp * temp) % MOD;

        if (n % 2 == 0) {
            return temp;
        } else {
            return ((x % MOD) * temp) % MOD;
        }
    }
}

int main() {

    IO

    string x;

    while (cin >> x) {
        unordered_map<char, int> mapa;

        for (int i = 0; i < x.size(); i++) {
            mapa[x[i]]++;
        }
        factorial();
        ll b = 1;
        ll a = x.size() % MOD;
        for (auto it = mapa.begin(); it != mapa.end(); it++) {
            if (it->second > 1) {
                b = ((b % MOD) * (fact[it->second] % MOD)) % MOD;
            }
        }
        cout << fact[a] * binary_exp(b, MOD - 2) % MOD << "\n";
    }

    return 0;
}
