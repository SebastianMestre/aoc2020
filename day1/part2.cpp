#include <algorithm>
#include <iostream>
#include <vector>

template<typename BidirectionalIterator>
std::pair<BidirectionalIterator, BidirectionalIterator> indices_that_sum(BidirectionalIterator l, BidirectionalIterator r, int value) {
	if (r <= l)
		return {r, r};
	// PRE: is_sorted(l, r)
	for (auto m = std::prev(r); l != m;) {
		int s = *l + *m - value;
		if(s == 0) return {l, m};
		if(s <  0) ++l;
		else       --m;
	}
	return {r, r};
}

int main () {
	std::vector<int> v;
	for (int a; std::cin >> a;)
		v.push_back(a);
	std::sort(v.begin(), v.end());
	for (auto i = v.begin(); i != v.end(); ++i) {
		auto [j, k] = indices_that_sum(i+1, v.end(), 2020 - *i);
		if (j != v.end()) {
			std::cout << *i * *j * *k << '\n';
		}
	}
}
