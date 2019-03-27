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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef DEBUG_MODE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;

	cin >> n >> k;
	if (n < k) {
		cout << "NO\n";
		return 0;
	}
	vector<int> digit(k, 1);

	n -= k;
	for (int i=0; i<k; ++i) {
		while (n >= digit[i]) {
			n -= digit[i];
			digit[i] *= 2;
		}
	}

	if (n) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i=0; i<k; ++i)
			cout << digit[i] << " ";
		cout << '\n';
	}

	return 0;
}
