#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define ull unsigned long long int
#define ll long long int
#define pii pair<int, int>
#define pb push_back
#define MAX int(10e4+2)

const int INF = 0x3f3f3f3f;
using namespace std;

/*
   MAX 100000 CHAR->10e4
   O (N LOG(N))

*/

string t;
int sa[MAX], tempSa[MAX], n;
int ra[MAX], tempRa[MAX];
int c[MAX];

void countingSort(int k) {
   int i, sum, maxi=max(300, n);
   memset(c, 0, sizeof c);
   for(i=0; i<n; i++) {
      c[i+k<n ? ra[i+k]:0]++;
   }
   for(i=sum=0; i<maxi; i++) {
      int x=c[i];
      c[i]=sum;
      sum+=x;
   }
   for(i=0; i<n; i++) {
      tempSa[c[sa[i]+k<n ? ra[sa[i]+k]:0]++]=sa[i];
   }
   for(i=0; i<n; i++) {
      sa[i]=tempSa[i];
   }
}

void constructSa() {
   int i, k, r;
   for(i=0; i<n; i++)
      ra[i]=t[i];
   for(i=0; i<n; i++)
      sa[i]=i;
   for(k=1; k<n; k<<=1) {
      countingSort(k);
      countingSort(0);

      tempRa[sa[0]]=r=0;
      for(i=1; i<n; i++) {
         tempRa[sa[i]]=(ra[sa[i]]==ra[sa[i-1]] && ra[sa[i]+k]==ra[sa[i-1]+k])? r:++r;
      }
      for(i=0; i<n; i++) {
         ra[i]=tempRa[i];
      }
      if(ra[sa[n-1]]==n-1)
         break;
   }
}


int main() {

   IO

   cin >> t;
   t+='$';
   n=t.size();

   constructSa();

   for(int i=0; i<n; i++) {
      cout << sa[i] << " " << t.c_str()+sa[i] << "\n";
   }

   return 0;
}
