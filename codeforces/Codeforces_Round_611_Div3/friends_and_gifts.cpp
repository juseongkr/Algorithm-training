#include <iostream>
#include <vector>
using namespace std;
#define MAX 200001

int n;
int to[MAX], from[MAX];
vector<int> vec;

int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> to[i];
		from[to[i]] = i;
	}

	for (int i=1; i<=n; ++i)
		if (!from[i])
			vec.push_back(i);

	int last = vec[0], k = 0;
	for (int i=1; i<=n; ++i) {
		if (!to[i]) {
			to[i] = vec[k++];
			if (to[i] != i)
				last = i;
		}
	}

	for (int i=1; i<=n; ++i)
		if (to[i] == i)
			swap(to[i], to[last]);

	for (int i=1; i<=n; ++i)
		cout << to[i] << " ";
	cout << '\n';

	return 0;
}
