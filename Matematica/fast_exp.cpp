#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

#define MOD 1000000007
#define ull unsigned long long int
#define ll  long long int

using namespace std;

/*
EXPONENCIAÇÃO RÁPIDA:
OPERAÇÕES O(log(n))
MEMORIA O(1)
*/

ll fastExp(ll base, ll e) {
   ll resp=1;

   while(e>0) {
      if(e%2==1)
         resp=(resp*base)%MOD;
      base=(base*base)%MOD;
      e/=2;
   }

   return resp;
}

int main() {

   IO

   int a, b;
   cin >> a >> b;

   cout << fastExp(a, b) << "\n";

   return 0;
}
