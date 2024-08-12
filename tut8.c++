/*
Question Link -> https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
Question -> Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
void solve(int index, string &digits, map<char, string> &mapping, string &curr_str)
{
    if (index == digits.size())
    {
        ans.push_back(curr_str);
        return;
    }

    char ch = digits[index];
    for (char ch : mapping[ch])
    {
        curr_str.push_back(ch);
        solve(index + 1, digits, mapping, curr_str);
        curr_str.pop_back(); // backtracking
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0)
    {
        return ans;
    }

    map<char, string> mapping;
    mapping['2'] = {"abc"};
    mapping['3'] = {"def"};
    mapping['4'] = {"ghi"};
    mapping['5'] = {"jkl"};
    mapping['6'] = {"mno"};
    mapping['7'] = {"pqrs"};
    mapping['8'] = {"tuv"};
    mapping['9'] = {"wxyz"};

    string curr_str;
    solve(0, digits, mapping, curr_str);
    return ans;
}

int main()
{
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
