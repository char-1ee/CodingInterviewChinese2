// Q67: Implement atoi() functioon in cpp

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll StrToInt(const char* str, bool is_negative);
enum Status { VALID = 0, INVALID };
int g_nStatus = VALID;

int StrToInt(const char* str) {
    g_nStatus = INVALID;

    // Check nullptr and empty string
    if (str == nullptr || *str == '\0') {
        return 0;
    }

    bool is_negative = false;
    long long num = 0;

    // Check leading sign
    if (*str == '+' || *str == '-') {
        is_negative = *str == '+' ? false : true;
        str++;
    }
    if (*str == '\0') {
        return 0;
    }

    // Check leading zeros
    while (*str != '\0' && *str == 0) {
        str++;
    }
    if (*str == '\0') {
        g_nStatus = VALID;
        return 0;
    }

    num = StrToInt(str, is_negative);
    return (int)num;
}

ll StrToInt(const char* str, bool is_negative) {
    ll num = 0;
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            num = num * 10 + (*str - '0');
            if ((!is_negative && num > 0x7FFFFFFF) ||
                (is_negative && -num < (signed int)0x80000000)) {
                num = 0;
                break;
            }
            str++;
        } else {
            num = 0;
            break;
        }
    }

    if (*str == '\0') {
        g_nStatus = VALID;
    }
    return is_negative ? num * -1 : num;
}

void Test(const char* str) {
    int res = StrToInt(str);
    if (res == 0 && g_nStatus == INVALID) {
        printf("%s is invalid input.\n", str);
    } else {
        printf("%s to int is: %d\n", str, res);
    }
}

int main(int argc, char** argv) {
    Test(nullptr);
    Test("");

    Test("123");
    Test("+123");
    Test("-123");
    Test("1a33");
    Test("+0");
    Test("-0");
    Test("000000");
    Test("00000123");
    Test("-000123");

    // Valid INT_MAX, 0x7FFFFFFF
    Test("+2147483647");
    Test("-2147483647");
    Test("+2147483648");

    // Valid INT_MIN, 0x80000000
    Test("-2147483648");
    Test("+2147483649");
    Test("-2147483649");

    Test("+");
    Test("-");

    return 0;
}