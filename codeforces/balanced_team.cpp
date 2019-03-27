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
	
	int s[200001];
	int n, pre = 0, max_cnt = 0;

	scanf("%d", &n);

	for (int i=0; i<n; ++i)
		scanf("%d", &s[i]);

	sort(s, s+n);
	s[n++] = INT_MAX;

	for (int i=0; i<n; ++i) {
		if (s[i] - s[pre] > 5) {
			max_cnt = max(max_cnt, i - pre);
			pre++;
		}
	}
	
	printf("%d\n", max_cnt);

	return 0;
}
