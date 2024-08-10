/*
Question -> Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.

Example 1:
Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5
*/

#include <bits/stdc++.h>
using namespace std;

void solve(string &str, int k, string &ans, int start)
{
    if (k == 0 || start == str.size() - 1)
    {
        return;
    }

    char max = *max_element(str.begin() + start + 1, str.end());
    for (int i = start + 1; i < str.size(); i++)
    {
        if (str[start] < str[i] && str[i] == max)
        {
            swap(str[start], str[i]);
            // if str > ans
            if (str.compare(ans) > 0)
            {
                ans = str;
            }
            solve(str, k - 1, ans, start + 1);
            swap(str[start], str[i]); // backtrack
        }
    }
    solve(str, k, ans, start + 1); // Horizontal Drifting
}

int main()
{
    string str = "1234567";
    int k = 4;
    string ans = "";
    solve(str, k, ans, 0);
    cout << ans;

    return 0;
}