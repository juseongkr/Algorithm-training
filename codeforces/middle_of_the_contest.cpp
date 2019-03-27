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

	string start, end;
	int start_m, end_m;
	
	cin >> start >> end;

	start_m = (start[0] - '0') * 600 + (start[1] - '0') * 60 + (start[3] - '0') * 10 + (start[4] - '0');
	
	end_m = (end[0] - '0') * 600 + (end[1] - '0') * 60 + (end[3] - '0') * 10 + (end[4] - '0');
	
	start_m += end_m;
	start_m /= 2;

	cout << start_m / 600;
	start_m %= 600;

	cout << start_m / 60;
	start_m %= 60;

	cout << ":";

	cout << start_m / 10;
	start_m %= 10;

	cout << start_m << '\n';

	return 0;
}
