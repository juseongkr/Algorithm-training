#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10001

int n;
int vec[MAX];

bool next_permutation()
{
	int i = n-1;
	while (i && vec[i-1] <= vec[i])
		i--;

	if (i == 0)
		return false;

	int j = n-1;
	while (vec[i-1] <= vec[j])
		j--;

	swap(vec[j], vec[i-1]);
	
	j = n-1;
	while (i < j) {
		swap(vec[i], vec[j]);
		i++;
		j--;
	}
	return true;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> vec[i];

	if (next_permutation()) {
		for (int i=0; i<n; ++i)
			cout << vec[i] << " ";
	} else {
		cout << "-1\n";
	}

	return 0;
}
