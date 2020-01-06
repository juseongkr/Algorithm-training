#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

#define ll		long long
#define	ull		unsigned long long
#define ld		long double
#define fi		first
#define se		second
#define pb		push_back
#define all(a)		(a).begin(), (a).end()
#define fill(a, x)	memset(a, x, sizeof(a))
#define REP(i, n)	for (int i=0; i<(n); ++i)
#define FOR(i, a, b)	for (int i=(a); i<=(b); ++i)
#define FORR(i, a, b)	for (int i=(a); i>=(b); --i)

const int mod = 1e9+7;
const ll inf = 1ll<<55;
const ld pi = 3.1415926535897932384626433;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef DEBUG_MODE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll q, n, a, b;

	cin >> q;
	for (int k=0; k<q; ++k) {
		cin >> n >> a >> b;
		if (n%2 != 0)
			cout << min(n * a, (n/2 * b) + (n%2 * a)) << '\n';
		else
			cout << min(n * a, (n/2) * b) << '\n';
	}

	return 0;
}
