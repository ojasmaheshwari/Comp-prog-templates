#include <bits/stdc++.h>

using namespace std;

#define int long long

template<typename T>concept Printable = requires(T a){	cout << a;};
template<typename T>concept ContainerPrintable = requires(T coll){	cout << *coll.begin();};
template<ContainerPrintable Coll>void dbg(const Coll &collection) {	for (const auto &x : collection){cout<<x<<' ';}	cout << '\n';}
template<Printable T, typename... Args>void dbg(const T &t, Args... args) {	cout<<t<<' '; dbg(args...);}

void solve() {
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
		solve();
    }
    return 0;
}
