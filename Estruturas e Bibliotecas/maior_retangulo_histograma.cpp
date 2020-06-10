#include <bits/stdc++.h>

#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.in", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define MAX int(40)+10

const int INF = 0x3f3f3f3f;
using namespace std;

int n;
vector<int> vet;

ll getMaxArea() {
    stack<ll> s;
    ll max_area = 0, tp, area_with_top, i = 0;
    while (i < n) {
        if (s.empty() || vet[s.top()] <= vet[i])
            s.push(i++);
        else {
            tp = s.top();
            s.pop();
            area_with_top = vet[tp] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(max_area, area_with_top);
        }
    }
    while (!s.empty()) {
        tp = s.top();
        s.pop();
        area_with_top = vet[tp] * (s.empty() ? i : i - s.top() - 1);
        max_area = max(max_area, area_with_top);
    }
    return max_area;
}

int main() {

    IO

    while (cin >> n, n) {
        vet.resize(n);
        for (int &i:vet)
            cin >> i;
        cout << getMaxArea() << "\n";
    }

    return 0;
}
