#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, c;
vi house;

int check(int m) {
	auto ret = int{ 1 };
	auto last = house[0];

	for (auto i = 1; i < house.size(); ++i) {
		if (m <= house[i] - last) {
			++ret;
			last = house[i];
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> c;
	house = vi(n);
	for (auto&& x : house) {
		cin >> x;
	}

	sort(house.begin(), house.end());

	auto l = int{ 1 };
	auto r = int{ house.back() - house[0] + 1 };
	while (l < r) {
		auto m = (l + r) / 2;

		if (check(m) < c) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}

	cout << l - 1;

	return 0;
}