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

	int house[101];
	int num, cnt = 0;

	cin >> num;

	for (int i=0; i<num; ++i) {
		cin >> house[i];
	}

	for (int i=1; i<num-1; ++i) {
		if (house[i-1] == 1 && house[i+1] == 1 && house[i] == 0) {
			house[i+1] = 0;
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}
