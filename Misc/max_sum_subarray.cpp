#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define MAX int(55)

const int INF = 0x3f3f3f3f;
using namespace std;

/*
	RETORNA A SOMA MAXIMA DE UM SUBCONJUNTO DO ARRAY

*/

int n;
vector<int>arr;

int maxSum() {
   int max_so_far=INT_MIN, max_ending=0, start, end, s;
   start=end=s=0;
   for(int i=0; i<n; i++) {
      max_ending+=arr[i];
      if(max_so_far<max_ending) {
         max_so_far=max_ending;
         start=s;
         end=i;
      }
      if(max_ending<0) {
         max_ending=0;
         s=i+1;
      }
   }
   return max_so_far;
}

int main() {

   IO

   cin >> n;

   arr.resize(n);
   for(int &i:arr)
      cin >> i;

   cout << maxSum() << "\n";

   return 0;
}
