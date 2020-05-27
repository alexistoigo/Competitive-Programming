#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define ull unsigned long long int
#define ll long long int
#define pii pair<int, int>
#define pb push_back
#define MAX int(1000+2)

const int INF = 0x3f3f3f3f;
using namespace std;

/*

	REQUER CONSTRUCTSA()
*/

string p;
int m;

pii stringMatching() {
   int  lo=0, hi=n-1, mid=0;
   ///lowerbound
   while(lo<hi) {
      mid=(lo+hi)/2;
      int res=strncmp(t.c_str()+sa[mid], p.c_str(), m);
      if(res>=0)
         hi=mid;
      else
         lo=mid+1;
   }
   if(strncmp(t.c_str()+sa[lo], p.c_str(), m)!=0)
      return {-1, -1};
   pii ans;
   ans.first=lo;
   lo=0, hi=n-1, mid=0;
   ///upperbound
   while(lo<hi) {
      mid=(lo+hi)/2;
      int res=strncmp(t.c_str()+sa[mid], p.c_str(), m);
      if(res>0)
         hi=mid;
      else
         lo=mid+1;
   }
   if(strncmp(t.c_str()+sa[hi], p.c_str(), m)!=0)
      hi--;
   ans.second=hi;

   return ans;
}


int main() {

   //IO


   cin >> t;
   t+='$';
   n=t.size();

   constructSa();

   for(int i=0; i<n; i++)
      cout << sa[i] << " " << t.c_str()+sa[i] << "\n";


   while(cin >> p, p!="0") {
      m=p.size();
      pii pos=stringMatching();
      if(pos.first!=-1 && pos.second!=-1) {
         cout << p << " found sa["<< pos.first << "..." << pos.second<< "] in string " << t << "\n";
         cout << "They are:\n";
         for(int i=pos.first; i<=pos.second; i++) {
            cout << t.c_str()+sa[i] << "\n";
         }
      } else
         cout << "not found\n";
   }

   return 0;
}
