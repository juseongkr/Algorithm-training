#include <stdio.h>
#include <vector>
using namespace std;

vector<int> vec;

void post(int l, int r)
{
	if (l > r)
		return;

	int root = l;
	int a = l, b = r;
	while (vec[a] >= vec[root])
		a++;
	while (vec[root] < vec[b])
		b--;

	post(a, b);
	post(b+1, r);

	printf("%d\n", vec[root]);
}

int main()
{
	int n;

	while (~scanf("%d", &n))
		vec.push_back(n);

	post(0, vec.size()-1);

	return 0;
}
