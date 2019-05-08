#include <iostream>
#include <map>
using namespace std;

#define MAX 200001
int root[MAX], num[MAX];

int find(int n)
{
	if (n == root[n])
		return n;
	root[n] = find(root[n]);
	return root[n];
}

int uni(int a, int b)
{
	int x = find(a);
	int y = find(b);

	if (x != y) {
		root[y] = x;
		num[x] += num[y];
		num[y] = 1;
	}
	return num[x];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=1; i<=n*2; ++i) {
			root[i] = i;
			num[i] = 1;
		}

		map<string, int> dict;
		int label = 1;
		for (int i=0; i<n; ++i) {
			cin >> a >> b;
			if (dict.count(a) == 0)
				dict[a] = label++;
			if (dict.count(b) == 0)
				dict[b] = label++;

			cout << uni(dict[a], dict[b]) << '\n';
		}
	}
	return 0;
}
