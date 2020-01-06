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
	
	int a[101];
	int num;
	int max_idx = 0, min_idx = 0, max_val = 0;

	cin >> num;
	for (int i=0; i<num; ++i) {
		cin >> a[i];

		if (a[i] == 1)
			min_idx = i;
		
		if (max_val < a[i]) {
			max_val = a[i];
			max_idx = i;
		}
	}

	cout << max(max(min_idx, num - max_idx - 1), max(max_idx, num - min_idx - 1)) << '\n';
	
	return 0;
}
