#include <random>

int get_int_random_number(int min, int max) {
	if (min> max)
		std::swap(min, max);
	long long lmin = static_cast<long long>(min);
	long long lmax = static_cast<long long>(max);
	std::random_device rd;
	std::mt19937 mersenne(rd());
	const long long max_64{std::numeric_limits<int>::max()};
	static const double fraction = 0.5 / (static_cast<double>(max_64) + 1.0);
	return static_cast<int>(mersenne() * fraction * (lmax - lmin + 1) + min);
}