#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

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
#include <tuple>
#include <vector>
using namespace std;

#define ll		long long
#define ull		unsigned long long
#define fi		first
#define se		second
#define pb		push_back
#define all(a)		(a).begin(), (a).end()
#define sz(a)		((int)(a.size()))
#define REP(i, n)	for (int i=0; i<(n); ++i)
#define FOR(i, a, b)	for (int i=(a); i<=(b); ++i)
#define FORR(i, a, b)	for (int i=(a); i>=(b); --i)

typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;
typedef stack<ll> sl;
typedef queue<ll> ql;
typedef priority_queue<ll> pql;

const int mod = 1e9+7;
const ll inf = 1ll<<55;
const ld pi = 3.1415926535897932384626433;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
const int ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1};

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) { return (a*b)/GCD(a, b); }

int main()
{

#ifdef DEBUG_MODE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num[101];
	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	bool flag = false;
	int ans = 0;
	for (int i=0; i<n-1; ++i) {
		if (num[i] == 1) {
			if (num[i+1] == 2)
				ans += 3;
			else if ( num[i+1] == 3)
				ans += 4;
		} else if (num[i] == 2) {
			if (num[i+1] == 1)
				ans += 3;
			else if (num[i+1] == 3) {
				flag = true;
				break;
			}
		} else if (num[i] == 3) {
			if (num[i+1] == 1)
				ans += 4;
			else if (num[i+1] == 2) {
				flag = true;
				break;
			}
		}
	}

	for (int i=0; i<n-2; ++i)
		if (num[i] == 3 && num[i+1] == 1 && num[i+2] == 2)
			ans--;

	if (flag)
		cout << "Infinite\n";
	else
		cout << "Finite\n" << ans << '\n';

	return 0;
}
