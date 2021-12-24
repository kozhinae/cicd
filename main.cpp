#include <iostream>
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

string psp(const string& line);

TEST(BracketsOrder, EmptyTest) {
EXPECT_EQ("YES", psp(""));
}
TEST(BracketsOrder, SingleSquareTest) {
EXPECT_EQ("NO", psp("["));
EXPECT_EQ("NO", psp("]"));
}
TEST(BracketsOrder, SingleRoundTest) {
EXPECT_EQ("NO", psp("("));
EXPECT_EQ("NO", psp(")"));
}
TEST(BracketsOrder, WrongOrderTest) {
EXPECT_EQ("NO", psp("[])"));
}
TEST(BracketsOrder, RightOrderTest) {
EXPECT_EQ("YES", psp("()"));
EXPECT_EQ("YES", psp("[]"));
EXPECT_EQ("YES", psp("[]()"));
}
TEST(BracketsOrder, HardWrongOrderTest) {
EXPECT_EQ("NO", psp("[()[)]()(]([][[[)))))"));
}
TEST(BracketsOrder, HardRightOrderTest) {
EXPECT_EQ("YES", psp("[[()[]()](())][]()([])"));
}

string psp(const string& line) {
    int pointer = 0, flag = 1;
    char arr[10000];
    if (line != ""){
        for (char i: line) {
            if (i == '(' or i == '[') {
                arr[pointer] = i;
                pointer++;
            } else {
                if (pointer) {
                    if (i == ')') {
                        if (arr[pointer - 1] == '(') {
                            pointer--;
                        } else {
                            flag = 0;
                            break;
                        }
                    } else {
                        if (arr[pointer - 1] == '[') {
                            pointer--;
                        } else {
                            flag = 0;
                            break;
                        }
                    }
                } else {
                    flag = 0;
                    break;
                }
            }
        }
        if (pointer > 0) {
            flag = 0;
        }
        if (line.length()) {
            if (flag) {
                return "YES";
            } else {
                return "NO";
            }
        }
    } else {
        return "YES";
    }
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
