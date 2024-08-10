/*
BackTracking ==> Controlled Recursion + Pass By Reference

Question Link -> https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
Question -> Permutation of Strings -> You don't need to read input or print anything. Your task is to complete the function find_permutation() which takes the string S as input parameter and returns a vector of string in lexicographical order.
*/

// Optimised Approach
#include <bits/stdc++.h>
using namespace std;

void permute(string &input, int start, vector<string> &v)
{
    if (start == input.size() - 1)
    {
        v.push_back(input);
        return;
    }

    unordered_set<char> mp;
    for (int i = start; i < input.size(); i++)
    {
        if (mp.find(input[i]) == mp.end())
        {
            mp.insert(input[i]);
            swap(input[start], input[i]);
            permute(input, start + 1, v);
            swap(input[start], input[i]); // backtrack
        }
    }
}

int main()
{
    string input = "ABC";
    vector<string> ans;
    permute(input, 0, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}