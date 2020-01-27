#include <iostream>
using namespace std;

int n;

bool check(int k)
{
	if (k == 1)
		return false;

	for (int i=2; i*i<=k; ++i)
		if (k % i == 0)
			return false;
	return true;
}

void solve(int cur, string s)
{
	if (cur == n)
		cout << s << '\n';

	for (int i=1; i<10; ++i) {
		string next = s + to_string(i);
		if (check(stoi(next)))
			solve(cur+1, next);
	}
}

int main()
{
	cin >> n;
	solve(0, "");

	return 0;
}
