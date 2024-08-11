/*
Question Link -> https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1
Question -> Given a String S, Find all possible Palindromic partitions of the given String.

Example 1:
Input:
S = "geeks"
Output:
g e e k s
g ee k s
Explanation:
All possible palindromic partitions
are printed.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
bool isPalindrome(string &s)
{
    int start = 0, end = s.size() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void solve(string &s, vector<string> &temp, int index)
{
    if (index == s.size())
    {
        ans.push_back(temp);
        return;
    }

    string pal_string;
    for (int i = index; i < s.size(); i++)
    {
        pal_string += s[i];
        if (isPalindrome(pal_string))
        {
            // cout<<pal_string<<endl;
            temp.push_back(pal_string);
            solve(s, temp, i + 1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string S)
{
    vector<string> temp;
    solve(S, temp, 0);
    return ans;
}

int main()
{
    string input = "geeks";
    vector<vector<string>> ans = partition(input);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
