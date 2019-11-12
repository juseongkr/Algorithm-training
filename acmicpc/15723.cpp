#include <iostream>
using namespace std;
#define MAX 27
const int INF = 1e9+7;

int map[MAX][MAX];

int main()
{
	int n, m;
	string s, flush;

	for (int i=0; i<MAX; ++i)
		for (int j=0; j<MAX; ++j)
			if (i != j)
				map[i][j] = INF;

	cin >> n;
	getline(cin, flush);
	for (int i=0; i<n; ++i) {
		getline(cin, s);
		map[s[0]-'a'][s[s.length()-1]-'a'] = 1;
	}

	for (int k=0; k<MAX; ++k)
		for (int i=0; i<MAX; ++i)
			for (int j=0; j<MAX; ++j)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

	cin >> m;
	getline(cin, flush);
	for (int i=0; i<m; ++i) {
		getline(cin, s);
		if (map[s[0]-'a'][s[s.length()-1]-'a'] == INF)
			cout << "F\n";
		else
			cout << "T\n";
	}

	return 0;
}
