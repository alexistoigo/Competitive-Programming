#include <bits/stdc++.h>

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);

#define MOD 1000000007
#define ull unsigned long long int
#define ll  long long int
#define MAX 305

using namespace std;

/*
RECEBE UM INT(n) E UM DIGITO(d) E RETORNA QUANTAS VEZES O DIGITO APARECE
DE 0 ATÉ N
*/

ll getOccurence(ll n, ll d) {
    
    ll result = 0, pot = 1, rem = 0;
    
    while (n) {
        int x = n%10;
        n /= 10;

        if (x > d)
            result += (n+1)*pot;
        else
            result += n*pot;
        if (x == d)
            result += rem+1;

        if (d == 0)
            result -= pot;

        rem += pot * x;
        pot *= 10;
    }
    return result;
}


int main() {

    IO

    ll n, m, i;

    while(cin >> n >> m, n, m) {

        for(i=0; i<9; i++) {
            cout << getOccurence(m, i)-getOccurence(n-1, i) << " ";
        }

        cout << getOccurence(m, 9)-getOccurence(n-1, 9) << "\n";

    }

    return 0;
}