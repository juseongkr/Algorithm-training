#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
char s[11][11];
int n, idx;
string p;

bool check(int k)
{
	int sum = 0;
	for (int i=k; i>=0; i--) {
		sum += vec[i];
		if ((s[i][k] == '+' && sum <= 0) || (s[i][k] == '0' && sum != 0) || (s[i][k] == '-' && sum >= 0))
			return false;
	}
	return true;
}

void solve(int cnt)
{
	if (cnt == n) {
		for (int i=0; i<n; ++i)
			cout << vec[i] << " ";
		exit(0);
	}

	for (int i=-10; i<=10; ++i) {
		vec.push_back(i);
		if (check(cnt))
			solve(cnt+1);
		vec.pop_back();
	}
}

int main()
{
	cin >> n >> p;
	for (int i=0; i<n; ++i)
		for (int j=i; j<n; ++j)
			s[i][j] = p[idx++];
	
	solve(0);

	return 0;
}
