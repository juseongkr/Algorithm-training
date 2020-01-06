#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<pair<pair<long long, long long>, int>> env;
	int num, card_width, card_height;
	long long width, height, val;

	scanf("%d %d %d", &num, &card_width, &card_height);

	for (int i=0; i<num; ++i) {
		scanf("%lld %lld", &width, &height);
		if (width > card_width && height > card_height) {
			env.push_back({ {width, height}, i + 1 });
		}
	}
	sort(env.begin(), env.end());
	
	/*
	for (auto it=env.begin(); it!=env.end(); it++) {
		if (it->first == next(it)->first)
			env.erase(next(it));
	}
	*/

	printf("%lu\n", env.size());

	for (int i=0; i<env.size(); ++i)
		printf("[%d: %lld, %lld] ", env[i].second, env[i].first.first, env[i].first.second);

	printf("\n");

	return 0;
}
