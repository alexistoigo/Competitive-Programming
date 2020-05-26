#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define ull unsigned long long int
#define ll long long int
#define pii pair<int, int>
#define pb push_back
#define MAX int(10e3)

const int INF = 0x3f3f3f3f;
using namespace std;

/*
   MAX 1000 CHAR
   O (N^2 LOG(N)

*/

string t;
int sa[1000], i, n;

bool cmp(int a, int b) {
   return strcmp(t.c_str()+a, t.c_str()+b)<0;
}

int main() {

   IO

   cin >> t;

   n=t.size();

   for(int i=0; i<n; i++) {
      sa[i]=i;
   }

   sort(sa, sa+n, cmp);

   for(int i=0; i<n; i++) {
      cout << sa[i] << " " << t.c_str()+sa[i] << "\n";
   }
   return 0;
}
