///https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

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
#define MAX 503

const int INF = 0x3f3f3f3f;
using namespace std;

struct MyStack {
   stack<int> s;
   int minEle;

   void getMin() {
      if(s.empty())
         cout << "EMPTY\n";

      else
         cout << minEle << "\n";
   }

   // Prints top element of MyStack
   void peek() {
      if(s.empty()) {
         cout << "EMPTY\n";
         return;
      }

      int t = s.top();

      (t < minEle)? cout << minEle: cout << t;
   }

   void pop() {
      if(s.empty()) {
         cout << "EMPTY\n";
         return;
      }

      int t = s.top();
      s.pop();

      if(t < minEle) {
         //cout << minEle << "\n";
         minEle = 2*minEle - t;
      }
   }
   void push(int x) {
      if(s.empty()) {
         minEle = x;
         s.push(x);
         return;
      }
      if(x < minEle) {
         s.push(2*x - minEle);
         minEle = x;
      } else
         s.push(x);
   }
};



int main() {

   IO

   int n, x;
   string a;

   cin >> n;

   MyStack vet;

   while(n--) {
      cin >> a;

      if(a=="PUSH") {
         cin >> x;
         vet.push(x);
      }
      if(a=="MIN")
         vet.getMin();
      if(a=="POP") {
         vet.pop();
      }
   }

   return 0;
}
