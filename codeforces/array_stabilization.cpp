#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
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
#define all(a)		a.begin(), a.end()
#define fill(a, x)	memset(a, x, sizeof(a))

const int mod = 1e9+7;
const ll inf = 1ll<<55;
const ld pi = 3.1415926535897932384626433;

int a[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef DEBUG_MODE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int num;
	cin >> num;

	for (int i=0; i<num; ++i)
		cin >> a[i];

	sort(a, a + num);

	cout << min(a[num-2] - a[0], a[num-1] - a[1]) << '\n';

	return 0;
}
