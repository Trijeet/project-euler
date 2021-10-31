#include <iostream>
#include <math.h>
#include <vector>

std::vector<int> get_all_primes_in_range(int limit)
{
    std::vector<bool> is_prime(limit + 1, true);
    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

long long int get_largest_prime_divisor(long long int number)
{
    long long int square_root = sqrt(number);
    std::vector<int> all_primes = get_all_primes_in_range(square_root);
    for (int i = all_primes.size() - 1; i >= 0; i--) {
        if (number % all_primes[i] == 0) {
            return all_primes[i];
        }
    }
    return -1;
}


int main()
{
    long long int number = 600851475143;
    std::cout << get_largest_prime_divisor(number) << "\n";

    return 0;
}
