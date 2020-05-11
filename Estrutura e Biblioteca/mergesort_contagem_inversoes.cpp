#include <bits/stdc++.h>

//#include <stdio.h>
//#include <math.h>
//#include <string.h>
//#include <stdbool.h>
//#include <stdlib.h>

#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define MOD 1000000007
#define ull unsigned long long int
#define ll  long long int
#define pii pair<int, int>
#define pb push_back
#define MAX 1001

const int INF = 0x3f3f3f3f;
using namespace std;

int merge_sort(vector<int> &vet) {
   int inv=0;

   if(vet.size()==1)
      return 0;

   vector<int> u1, u2;

   for(int i=0; i<vet.size()/2; i++)
      u1.pb(vet[i]);
   for(int i=vet.size()/2; i<vet.size(); i++)
      u2.pb(vet[i]);

   inv+=merge_sort(u1);
   inv+=merge_sort(u2);

   u1.pb(INF);
   u2.pb(INF);

   int ini1=0, ini2=0;

   for(int i=0; i<vet.size(); i++) {
      if(u1[ini1]<=u2[ini2]) {
         vet[i]=u1[ini1];
         ini1++;
      } else {
         vet[i]=u2[ini2];
         ini2++;

         inv+=u1.size()-ini1-1;
      }
   }

   return inv;
}



int main() {

   int n, i, x;
   cin >> n;
   vector<int> vet;

   while(n--) {
      cin >> x;
      vet.pb(x);
   }

   cout << merge_sort(vet) << "\n";


   return 0;
}