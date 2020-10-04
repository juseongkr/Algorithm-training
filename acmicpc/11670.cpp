#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#define MAX 2501
#define ll long long

int n;
vector<ll> graph[MAX];
ll A[MAX], visit[MAX], x[MAX], y[MAX];
unordered_map<ll, ll> B;

bool dfs(int a)
{
	visit[a] = 1;
	for (int i=0; i<graph[a].size(); ++i) {
		ll b = graph[a][i];
		ll nb = B.count(b) ? B[b] : -1;
		if (nb == -1 || (!visit[nb] && dfs(nb))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

bool match()
{
	fill(A, A+n, -1);
	for (int i=0; i<n; ++i) {
		fill(visit, visit+n, 0);
		if (!dfs(i))
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x[i] >> y[i];
		graph[i].push_back(x[i] + y[i]);
		graph[i].push_back(x[i] - y[i]);
		graph[i].push_back(x[i] * y[i]);
	}

	if (match()) {
		cout << "impossible\n";
		return 0;
	}

	string c;
	for (int i=0; i<n; ++i) {
		if (x[i] + y[i] == A[i])
			c = " + ";
		else if (x[i] - y[i] == A[i])
			c = " - ";
		else if (x[i] * y[i] == A[i])
			c = " * ";

		cout << x[i] << c << y[i] << " = " << A[i] << '\n';
	}

	return 0;
}
