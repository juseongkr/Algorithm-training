#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

int main()
{
	map<string, int> name;
	string number[100001];
	char s[21];
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i) {
		scanf("%s", s);
		name[s] = i;
		number[i] = s;
	}

	for (int i=0; i<m; ++i) {
		scanf("%s", s);
		if (isdigit(s[0]))
			printf("%s\n", number[stoi(s)].c_str());
		else
			printf("%d\n", name[s]);
	}

	return 0;
}
