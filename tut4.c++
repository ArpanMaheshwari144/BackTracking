/*
Question -> Given an integer N, print all the N digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).

Example 1:

Input:
N = 1
Output:
0 1 2 3 4 5 6 7 8 9
Explanation:
Single digit numbers are considered to be
strictly increasing order.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &v, vector<int> &result)
{
    /* If we have reached n == 0, we have obtained our first number, which is stored in the vector. We need to create a number from the elements in that vector. */
    if (n == 0)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            ans = ans * 10 + v[i];
        }
        result.push_back(ans);
    }

    for (int i = 1; i <= 9; i++)
    {
        if (v.size() == 0 || i > v[v.size() - 1])
        {
            v.push_back(i);
            solve(n - 1, v, result);
            v.pop_back();
        }
    }
}

vector<int> increasingNumbers(int n)
{
    vector<int> ans;
    if (n == 1)
    {
        for (int i = 0; i < 9; i++)
        {
            ans.push_back(i);
        }
        return ans;
    }

    vector<int> v;
    solve(n, v, ans);
}

int main()
{
    int n = 3;
    vector<int> ans = increasingNumbers(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}