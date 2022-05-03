#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <regex>
#include <cctype>
#include <map>
#include <deque>
#include <vector>

#if defined(WITH_GTEST)
#include <gtest/gtest.h>
#endif

class Train
{

public:
    std::deque< int > const &get_on_rail() const { return on_rail_; }

    void show(void)
    {
        //        for (auto &it : occurrences_) {
        //            std::cout << it.first << ":" << it.second << std::endl;
        //        }
    }

    Train &operator<<(const std::string &line)
    {
        return *this;
    }

private:
    std::deque< int > on_rail_;
};

void check_permutations(std::string &line, int num)
{
    std::cout << "num : " << num << std::endl;
    std::cout << "line : " << line << std::endl;
}

void solve_uva_problem(std::istream &is, std::ostream &os)
{
    bool double_check_zero = false;
    std::string numbers;
    std::getline(is, numbers);
    int num = std::stoi(numbers);
    os << "first num : " << num << std::endl;
    while (1) {
        if (double_check_zero == true) {
            std::getline(is, numbers);
            if (numbers.compare("0") == 0)
                break;
            else {
                double_check_zero = false;
                num = std::stoi(numbers);
                os << "first num : " << num << std::endl;
            }
        }

        std::getline(is, numbers);
        if (numbers.compare("0") == 0) {
            double_check_zero = true;
            os << std::endl;
        } else {
            double_check_zero = false;
            check_permutations(numbers, num);
        }
    }
}

int main(int argc, char **argv)
{
#if !defined(WITH_GTEST)
    solve_uva_problem(std::cin, std::cout);
#else
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif
}
