#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define MOD 1000000007
#define ull unsigned long long int
#define ll  long long int
#define pii pair<int, int>
#define pb push_back
#define MAX int(5*10e5+2)

const int INF = 0x3f3f3f3f;
using namespace std;

ll fastExp(ll base, ll e) {
   if(e==0)
      return 1;
   ll resp=fastExp(base, e/2);
   resp*=resp;
   if(e%2==1)
      resp*=base;

   return resp;
}


int main() {

   IO

   int a, b;
   cin >> a >> b;

   cout << fastExp(a, b) << "\n";

   return 0;
}
