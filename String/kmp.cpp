#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define MOD 1000000007
#define ull unsigned long long int
#define ll long long int
#define pii pair<int, int>
#define pb push_back
#define MAX int(10e3)

const int INF = 0x3f3f3f3f;
using namespace std;

/*
	ENCONTRAR OCORRENCIAS DE SUB NA STRING STR
	N=SIZE-SRT, M=SIZE-SUB
	
	O(n+m)

*/

string str, sub;
int n, m, b[MAX];

void kmpPreprocess() {
   int i=0, j=-1;
   b[0]=-1;
   while(i<m) {
      while(j>=0 && sub[i]!=sub[j])
         j=b[j];
      i++;
      j++;
      b[i]=j;
   }
}

void kmpSearch() {
   int i=0, j=0;
   while(i<n) {
      while(j>=0 && str[i]!=sub[j])
         j=b[j];
      i++;
      j++;
      if(j==m) {
         cout << sub << " found on index " << i-j << "\n";
         j=b[j];
      }
   }
}

int main() {

   IO

   getline(cin, str);
   getline(cin, sub);

   n=str.size(), m=sub.size();

   kmpPreprocess();
   kmpSearch();

   return 0;
}
