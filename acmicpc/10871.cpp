#include <stdio.h>
#include <vector>

int main()
{
	std::vector<int> vec;
	int num, x, tmp;

	scanf("%d %d", &num, &x);

	for (int i=0; i<num; ++i) {
		scanf("%d", &tmp);
		vec.push_back(tmp);
	}

	for (int i=0; i<vec.size(); ++i) {
		if (vec[i] < x)
			printf("%d ", vec[i]);
	}
	printf("\n");

	return 0;
}
