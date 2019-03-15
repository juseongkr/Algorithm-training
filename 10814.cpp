#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct obj {
	int age;
	string name;
};

bool comp(const struct obj &a, const struct obj &b)
{
	return a.age < b.age;
}

int main()
{
	int num;
	cin >> num;
	vector<struct obj> users(num);

	for (int i=0; i<num; ++i)
		cin >> users[i].age >> users[i].name;

	stable_sort(users.begin(), users.end(), comp);

	for (int i=0; i<num; ++i)
		cout << users[i].age << " " << users[i].name  << '\n';

	return 0;
}
