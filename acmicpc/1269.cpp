#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	int n, m, v;

	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) {
		scanf("%d", &v);
		s.insert(v);
	}

	for (int i=0; i<m; ++i) {
		scanf("%d", &v);
		if (s.count(v))
			s.erase(v);
		else
			s.insert(v);
	}

	printf("%lu\n", s.size());

	return 0;
}
