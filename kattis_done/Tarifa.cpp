#include <iostream>

int main() {
	int X, N, sum = 0, temp;
	std::cin >> X;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> temp;
		sum += X - temp;
	}
	std::cout << sum + X << std::endl;
}