#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include "main.cpp"

TEST(TestCase1, Solution)
{
    auto Solve = [](std::istream &is) -> std::string {
        std::ostringstream oss;
        solve_uva_problem(is, oss);
        return std::string("\n") + oss.str();
    };
    {
        std::stringstream fake_cin;
        fake_cin << R"(5
1 2 3 4 5
5 4 1 2 3
1 4 3 2 5
3 4 2 5 1
3 4 2 1 5
4 3 5 2 1
0
3
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
0
4
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
0
10
5 7 10 9 8 6 4 3 2 1
5 6 4 8 7 3 2 9 1 10
0
0
)";

EXPECT_EQ(
R"(
Yes
No
Yes
Yes
Yes
Yes

Yes
Yes
Yes
Yes
No
Yes

Yes
Yes
Yes
Yes
No
Yes
Yes
Yes
Yes
Yes
No
Yes
No
No
Yes
Yes
No
Yes
No
No
No
No
No
Yes

Yes
Yes

)",Solve(fake_cin));
    }
}

TEST(TestCase2, Solution)
{
    auto Solve = [](std::istream &is) -> std::string {
        std::ostringstream oss;
        solve_uva_problem(is, oss);
        return std::string("\n") + oss.str();
    };
    {
        std::stringstream fake_cin;
        fake_cin << R"(5
1 2 3 4 5
5 4 1 2 3
3 5 4 2 1
3 4 2 5 1
0
6
6 5 4 3 2 1
0
0
)";

        EXPECT_EQ(
R"(
Yes
No
Yes
Yes

Yes

)", Solve(fake_cin));
    }
}

TEST(TestCase3, Solution)
{
    auto Solve = [](std::istream &is) -> std::string {
        std::ostringstream oss;
        solve_uva_problem(is, oss);
        return std::string("\n") + oss.str();
    };
    {
        std::stringstream fake_cin;
        fake_cin << R"(5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
)";

        EXPECT_EQ(
                R"(
Yes
No

Yes

)",
                Solve(fake_cin));
    }
}

#if 1
TEST(TestCase5, Solution)
{
    auto Solve = []() -> std::string {
        std::ifstream fs("./data1");
        std::ostringstream oss;
        solve_uva_problem(fs, oss);
        return std::string("\n") + oss.str();
    };
    {
        EXPECT_EQ(
                R"(
Yes
No
Yes
Yes
No
Yes
Yes
No
No
No
Yes
Yes
No
No
No
Yes
Yes
Yes
Yes
No

Yes
Yes
No
Yes
No
No
Yes
No
No

Yes
No
Yes
Yes
Yes
No
No
Yes
No
Yes

Yes
Yes
No
No
No
No
Yes
No
No
Yes
No
No
Yes
Yes
No
Yes
Yes
No
Yes
Yes
No

No
Yes
Yes
Yes
No
Yes
No
No
No
No
No
Yes
No
Yes
Yes
Yes
No
No
No

No
Yes
Yes
No
No
Yes
Yes
Yes
No
No
Yes
Yes
Yes
Yes
No

No
No
No
Yes
No
No
No
No
Yes
Yes
Yes
No

No
No
No
No
Yes
No
Yes
Yes
No
No
Yes
Yes

No
No
Yes
No
Yes
No
Yes
No
No
Yes
No
Yes
Yes
No
No
No
No
Yes
Yes
Yes
Yes

Yes
No
Yes
Yes
Yes
Yes
Yes
No
No
Yes
Yes

No
No
Yes
No
Yes
Yes
Yes
Yes
Yes
Yes
Yes
Yes

Yes
Yes
Yes
No
Yes
Yes
No
Yes
No
Yes
Yes
Yes
No
Yes
Yes
No
Yes
Yes
No
Yes
No

Yes
No
No
No
Yes
No
Yes
No
No
Yes
Yes
No
Yes
Yes
No
Yes
No
No
No

No
Yes

Yes
No
No
Yes
Yes
No
Yes
No
Yes
Yes
No
Yes
No
No
Yes
Yes

No
No
No
No
No
No
No
Yes
No
No
No
No
No
Yes
No
No
No
Yes
Yes

No
Yes
No

Yes
Yes
No
No
No
Yes
No
No

No
No
No
No
Yes
Yes
No
Yes
Yes
No
No
Yes
No
Yes
No
Yes

Yes
Yes
Yes
Yes
Yes
No

No
Yes
No
No
No
Yes
Yes

)",Solve());
    }
}
#endif
