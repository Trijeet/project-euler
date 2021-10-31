#include <iostream>
#include <algorithm>
#include <string>

bool is_palindrome(int number)
{
    std::string s = std::to_string(number);
    std::string r = s;
    std::reverse(r.begin(), r.end());
    return s == r;
}

int get_largest_palindrome()
{
    int max_number = 0;

    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int pick = i * j;
            if (is_palindrome(pick)) {
                max_number = std::max(max_number, pick);
            }
        }
    }

    return max_number;
}


int main()
{
    std::cout << get_largest_palindrome() << "\n";

    return 0;
}
