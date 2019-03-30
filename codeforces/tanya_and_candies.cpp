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

	int num[1000001];
	int n, t, cnt = 0;
	int even_sum = 0, odd_sum = 0;
	int even_pre = 0, odd_pre = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &num[i]);

		if (i%2 == 0)
			even_sum += num[i];
		else
			odd_sum += num[i];
	}

	for (int i=0; i<n; ++i) {
		if (i%2 == 0)
			even_sum -= num[i];
		else
			odd_sum -= num[i];

		if (even_pre + odd_sum == odd_pre + even_sum)
			cnt++;

		if (i%2 == 0)
			even_pre += num[i];
		else
			odd_pre += num[i];
	}

	printf("%d\n", cnt);

	return 0;
}
