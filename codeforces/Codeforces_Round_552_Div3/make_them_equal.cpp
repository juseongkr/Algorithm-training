#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#include <algorithm>
#include <bitset>
#include <cmath>
#include <climits>
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

int dict[101];

int main()
{

#ifdef DEBUG_MODE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector<int> vec;
	int num[101];
	int n, ans, len;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		dict[num[i]]++;
	}

	for (int i=0; i<=100; ++i)
		if (dict[i])
			vec.push_back(i);

	len = vec.size();
	if (len == 1) {
		ans = 0;
	} else if (len == 2) {
		int t = (abs(vec[0]-vec[1]));
		ans = (t % 2 == 0) ? t/2 : t;
	} else if (len == 3) {
		sort(vec.begin(), vec.end());
		int t = vec[1] - vec[0];
		int k = vec[2] - vec[1];
		ans = (t == k) ? t : -1;
	} else {
		ans = -1;
	}

	cout << ans << '\n';
	
	return 0;
}
