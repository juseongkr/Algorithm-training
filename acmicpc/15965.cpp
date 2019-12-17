#include <iostream>
#include <vector>
using namespace std;
#define MAX 10000001

int n;
bool check[MAX];
vector<int> prime;

int main()
{
	for (int i=2; i*i<MAX; ++i) {
		if (check[i])
			continue;
		for (int j=i*i; j<MAX; j+=i)
			check[j] = true;
	}
	for (int i=2; i<MAX; ++i)
		if (!check[i])
			prime.push_back(i);
	cin >> n;
	cout << prime[n-1] << '\n';

	return 0;
}
