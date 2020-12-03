#include <algorithm>
#include <iostream>
#include <vector>

std::pair<int, int> indices_that_sum(std::vector<int> const& v, int value) {
	// PRE: is_sorted(v)

	int i = 0;
	int j = v.size()-1;

	while (i < j) {
		int s = v[i] + v[j] - value;
		if(s == 0) return {i, j};
		if(s <  0) ++i;
		else       --j;
	}
	return {-1, -1};
}

int main () {
	std::vector<int> v;
	for (int a; std::cin >> a;)
		v.push_back(a);
	std::sort(v.begin(), v.end());
	auto [i, j] = indices_that_sum(v, 2020);
	std::cout << v[i] * v[j] << '\n';
}
