#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define MOD 1000000007
#define ull unsigned long long int
#define ll  long long int
#define pii pair<int, int>
#define pb push_back
#define MAX int(10e5+2)

const int INF = 0x3f3f3f3f;
using namespace std;


int getSum(int BITree[], int index) {
   int sum = 0;
   while(index > 0) {
      sum += BITree[index];
      index -= index & (-index);
   }
   return sum;
}

void updateBIT(int BITree[], int n, int index, int val) {
   while(index <= n) {
      BITree[index] += val;
      index += index & (-index);
   }
}

void convert(int arr[], int n) {

   int temp[n];
   for(int i=0; i<n; i++)
      temp[i] = arr[i];
   sort(temp, temp+n);
   for(int i=0; i<n; i++) {
      arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
   }
}

int getInvCount(int arr[], int n) {
   int invcount = 0;

   convert(arr, n);

   int BIT[n+1];
   for(int i=1; i<=n; i++)
      BIT[i] = 0;
   for(int i=n-1; i>=0; i--) {
      invcount += getSum(BIT, arr[i]-1);
      updateBIT(BIT, n, arr[i], 1);
   }

   return invcount;
}


int main() {

   IO

   int n;
   while(cin >> n, n) {
      int vet[n];
      for(int i=0; i<n; i++)
         cin >> vet[i];

      cout << getInvCount(vet, n) << "\n";
   }


   return 0;
}
