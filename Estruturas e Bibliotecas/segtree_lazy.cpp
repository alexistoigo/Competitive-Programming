#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define ull unsigned long long int
#define ll long long int
#define pii pair<int, int>
#define pb push_back
#define MAX int(5*1e5+6)

const int INF = 0x3f3f3f3f;
using namespace std;

int n;
int arr[MAX];
int tree[4*MAX];
int lazy[4*MAX];

int op(int a, int b) {
   return max(a, b);
}

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
   if(a > b)
      return; // Out of range

   if(a == b) { // Leaf node
      tree[node] = arr[a]; // Init value
      return;
   }

   build_tree(node*2, a, (a+b)/2); // Init left child
   build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

   tree[node] = op(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

   if(lazy[node] != 0) { // This node needs to be updated
      tree[node] += lazy[node]; // Update it

      if(a != b) {
         lazy[node*2] += lazy[node]; // Mark child as lazy
         lazy[node*2+1] += lazy[node]; // Mark child as lazy
      }

      lazy[node] = 0; // Reset it
   }

   if(a > b || a > j || b < i) // Current segment is not within range [i, j]
      return;

   if(a >= i && b <= j) { // Segment is fully within range
      tree[node] += value;

      if(a != b) { // Not leaf node
         lazy[node*2] += value;
         lazy[node*2+1] += value;
      }

      return;
   }

   update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
   update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

   tree[node] = op(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

   if(a > b || a > j || b < i)
      return -INF; // Out of range

   if(lazy[node] != 0) { // This node needs to be updated
      tree[node] += lazy[node]; // Update it

      if(a != b) {
         lazy[node*2] += lazy[node]; // Mark child as lazy
         lazy[node*2+1] += lazy[node]; // Mark child as lazy
      }

      lazy[node] = 0; // Reset it
   }

   if(a >= i && b <= j) // Current segment is totally within range [i, j]
      return tree[node];

   int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
   int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

   int res = op(q1, q2); // Return final result

   return res;
}

int main() {

   IO

   cin >> n;

   for(int i = 0; i < n; i++)
      arr[i] = 1;

   build_tree(1, 0, n-1);

   memset(lazy, 0, sizeof lazy);

   update_tree(1, 0, n-1, 0, 6, 5); // Increment range [0, 6] by 5. here 0, N-1 represent the current range.
   update_tree(1, 0, n-1, 7, 10, 12); // Incremenet range [7, 10] by 12. here 0, N-1 represent the current range.
   update_tree(1, 0, n-1, 10, n-1, 100); // Increment range [10, N-1] by 100. here 0, N-1 represent the current range.

   cout << query_tree(1, 0, n-1, 0, n-1) << "\n"; // Get max element in range [0, N-1]

   return 0;
}
