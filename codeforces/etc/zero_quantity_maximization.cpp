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
#include <limits.h>
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

	map<ld, int> dict;
	int a[200001], b[200001];
	int n, cnt = 0, ret = 0;

	scanf("%d", &n);

	for (int i=0; i<n; ++i)
		scanf("%d", &a[i]);

	for (int i=0; i<n; ++i)
		scanf("%d", &b[i]);
	
	for (int i=0; i<n; ++i) {
		if (a[i] == 0 && b[i] == 0) {
			cnt++;
		} else if (a[i] != 0) {
			auto val = (-1.0 * b[i]) / a[i];
			dict[val]++;
			ret = max(ret, dict[val]);
		}
	}
	printf("%d\n", ret + cnt);
	
	return 0;
}
