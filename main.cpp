#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <regex>
#include <cctype>
#include <map>
#include <vector>

#if defined(WITH_GTEST)
#include <gtest/gtest.h>
#endif

class WorkTime
{

public:
    std::map< int, int > const &map() const { return occurrences_; }
    std::pair< int, int > get_work_time(const std::string &line)
    {
        int hh_s, mm_s, hh_e, mm_e;
        char c_s, c_e;
        std::istringstream ss(line);
        ss >> hh_s >> c_s >> mm_s >> hh_e >> c_e >> mm_e;
        return std::make_pair(hh_s * 60 + mm_s, hh_e * 60 + mm_e);
    }
    void show(void)
    {
        for (auto &it : occurrences_) {
            std::cout << it.first << ":" << it.second << std::endl;
        }
    }
    WorkTime &operator<<(const std::string &line)
    {
        std::pair< int, int > p = get_work_time(line);
        int first = p.first;
        int second = p.second;
        for (auto &it : occurrences_) {
            if (it.second == first) {
                occurrences_.erase(it.first);
                first = it.first;
                break;
            }
            if (it.first == second) {
                occurrences_.erase(it.first);
                second = it.second;
                break;
            }

            if (it.first <= first) {
                if (first > it.second)
                    break;
                else {
                    if (it.second >= second)
                        return *this;
                    else {
                        occurrences_.erase(it.first);
                        first = it.first;
                        break;
                    }
                }
            }

            if (it.first > first) {
                if (it.first > second)
                    break;
                else {
                    occurrences_.erase(it.first);
                    if (it.second > second)
                        second = it.second;
                    break;
                }
            }
        }

        if (first != second)
            occurrences_[first] = second;

        return *this;
    }

    // data
private:
    std::map< int, int > occurrences_;
};

#define DAY_START 10 * 60
#define DAY_END   18 * 60
struct NAP_TimeData {
    int nap_start;
    int nap_total;
};

std::string counter_nap_time(std::map< int, int > const &map)
{
    int last_end = 0;
    int count = 0;
    int tmp_nap = 0;
    struct NAP_TimeData nap = { DAY_START, 0 };

    for (auto m = map.cbegin(); count != map.size(); ++m, ++count) {
        if (m == map.cbegin()) {
            tmp_nap = m->first - DAY_START;
            if (tmp_nap > nap.nap_total) {
                nap.nap_total = tmp_nap;
            }
            last_end = m->second;
        } else {
            if (m->first >= last_end) {
                tmp_nap = m->first - last_end;
                if (tmp_nap > nap.nap_total) {
                    nap.nap_total = tmp_nap;
                    nap.nap_start = last_end;
                }
                last_end = m->second;
            } else {
                if (m->second > last_end) {
                    last_end = m->second;
                }
            }
        }
        if (count == (map.size() - 1)) {
            tmp_nap = DAY_END - last_end;
            if (tmp_nap > nap.nap_total) {
                nap.nap_total = tmp_nap;
                nap.nap_start = last_end;
            }
        }
    }

    char buffer[512];
    int hh = nap.nap_total / 60;
    if (hh == 0)
        snprintf(buffer, sizeof(buffer), "the longest nap starts at %02d:%02d and will last for %d minutes.", nap.nap_start / 60, nap.nap_start % 60, nap.nap_total % 60);
    else
        snprintf(buffer, sizeof(buffer), "the longest nap starts at %02d:%02d and will last for %d hours and %d minutes.", nap.nap_start / 60, nap.nap_start % 60, hh, nap.nap_total % 60);

    std::string nap_string(buffer);
    return nap_string;
}

std::string longest_nap_function(std::istream &is, int num)
{
    WorkTime work_time;
    while (num) {
        std::string line;
        std::getline(is, line);
        work_time << line;
        num--;
    }
    //	work_time.show();
    std::string nap = counter_nap_time(work_time.map());
    return nap;
}

void solve_uva_problem(std::istream &is, std::ostream &os)
{
    int day = 0;
    while (1) {
        std::string line;
        std::getline(is, line);
        if (line.length() == 0)
            break;
        int line_num = std::stoi(line);
        day++;
        std::string nap_string = longest_nap_function(is, line_num);
        std::string nap = "Day #" + std::to_string(day) + (std::string) ": " + nap_string;
        os << nap << std::endl;
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
