#include <bits/stdc++.h>

using namespace std;

#define int long long

template<typename T>concept Printable = requires(T a){	cout << a;};
template<typename T>concept SingularContainerPrintable = requires(T coll){	cout << *coll.begin();};
template<typename T>concept PairLikeContainerPrintable = requires(T coll){	cout << coll.begin()->first << coll.begin()->second;};

template<SingularContainerPrintable Cont>
void dbg(const Cont &cont) {
	for (const auto &x : cont) {
		cout << x <<' ';
	}
	cout << '\n';
}

template<PairLikeContainerPrintable Cont>
void dbg(const Cont &cont) {
	for (const auto &[first, second] : cont) {
		cout << "(" << first << " " << second << ") ";
	}
	cout << '\n';
}

template<Printable T, typename... Args>
void dbg(const T &t, Args... args) {
	cout<<t<<' ';
	dbg(args...);
}

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
