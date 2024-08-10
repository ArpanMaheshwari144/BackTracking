/*
BackTracking Means ==> Controlled Recursion + Pass By Reference

Question Link -> https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
Question -> Permutation of Strings -> You don't need to read input or print anything. Your task is to complete the function find_permutation() which takes the string S as input parameter and returns a vector of string in lexicographical order.
*/

#include <bits/stdc++.h>
using namespace std;

void permute(string input, string output, vector<string> &v)
{
    if (input.size() == 0)
    {
        v.push_back(output);
        return;
    }

    unordered_set<char> mp;
    for (int i = 0; i < input.size(); i++)
    {
        if (mp.find(input[i]) == mp.end())
        {
            mp.insert(input[i]);
            string newinput = input.substr(0, i) + input.substr(i + 1);
            string newoutput = output + input[i];
            permute(newinput, newoutput, v); // backtrack
        }
    }
}

int main()
{
    string input = "AB";
    vector<string> ans;
    permute(input, " ", ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}