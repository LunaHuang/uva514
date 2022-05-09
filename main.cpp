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
    void show(void)
    {
        for (auto &it : on_rail_) {
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }

    bool permutations_valid(int numbers)
    {

        int end;
        while (numbers != 0) {
            if (!on_station_.empty()) {
                end = on_station_.back();
                if (end == numbers) {
                    numbers--;
                    on_station_.pop_back();
                    continue;
                }
            }

            if (on_rail_.empty())
                return false;
            end = on_rail_.back();
            while (end != numbers) {
                on_station_.push_back(end);
                on_rail_.pop_back();
                if (on_rail_.empty())
                    return false;
                end = on_rail_.back();
            }
            numbers--;
            on_rail_.pop_back();
        }

        return true;
    }

    void operator<<(const std::string &line)
    {
        char *token = strtok(const_cast< char * >(line.c_str()), " ");
        while (token != nullptr) {
            on_rail_.push_back(std::stoi(std::string(token)));
            token = strtok(nullptr, " ");
        }
    }

private:
    std::deque< int > on_rail_;
    std::deque< int > on_station_;
};

bool check_permutations(std::string &line, int num)
{
    Train trains;
    trains << line;
    //trains.show();
    return trains.permutations_valid(num);
}

void solve_uva_problem(std::istream &is, std::ostream &os)
{
    bool double_check_zero = false;
    std::string numbers;
    std::getline(is, numbers);
    int num = std::stoi(numbers);
    while (1) {
        if (double_check_zero == true) {
            std::getline(is, numbers);
            if (numbers.compare("0") == 0)
                break;
            else {
                double_check_zero = false;
                num = std::stoi(numbers);
            }
        }

        std::getline(is, numbers);
        if (numbers.compare("0") == 0) {
            double_check_zero = true;
            os << std::endl;
        } else {
            double_check_zero = false;
            if (check_permutations(numbers, num) == true)
                os << "Yes" << std::endl;
            else
                os << "No" << std::endl;
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
