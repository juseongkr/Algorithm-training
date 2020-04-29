#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;
const double PI = acos(-1);
typedef complex<double> cpx;

void fft(vector<cpx> &a, bool inv=false)
{
	int n = a.size();
	for (int i=1, j=0; i<n; ++i) {
		int bit = (n >> 1);
		while (!((j ^= bit) & bit))
			bit >>= 1;
		if (i < j)
			swap(a[i], a[j]);
	}

	for (int i=1; i<n; i<<=1) {
		double x = inv ? (PI / i) : (-PI / i);
		cpx w = {cos(x), sin(x)};
		for (int j=0; j<n; j+=(i << 1)) {
			cpx th = {1, 0};
			for (int k=0; k<i; ++k) {
				cpx tmp = a[i+j+k] * th;
				a[i+j+k] = a[j+k] - tmp;
				a[j+k] += tmp;
				th *= w;
			}
		}
	}

	if (inv)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

vector<cpx> multiply(vector<cpx> &a, vector<cpx> &b)
{
	int n = 1;
	while (n <= a.size() || n <= b.size())
		n <<= 1;
	n <<= 1;

	a.resize(n);
	b.resize(n);
	vector<cpx> c(n);

	fft(a);
	fft(b);
	for (int i=0; i<n; ++i)
		c[i] = a[i] * b[i];
	fft(c, 1);

	return c;
}

int n, m, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	vector<cpx> x, y;
	for (int i=0; i<n; ++i) {
		cin >> k;
		x.push_back(cpx(k, 0));
	}
	for (int i=0; i<n; ++i)
		x.push_back(x[i]);

	for (int i=0; i<n; ++i) {
		cin >> k;
		y.push_back(cpx(k, 0));
	}
	reverse(y.begin(), y.begin()+n);

	auto z = multiply(x, y);

	int ans = 0;
	for (int i=0; i<z.size(); ++i)
		ans = max(ans, (int)round(z[i].real()));
	cout << ans << '\n';

	return 0;
}
