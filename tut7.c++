/*
Question Link -> https://www.geeksforgeeks.org/problems/word-break-part-23249/1
Question -> Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.

Follow examples for better understanding.

Example 1:
Input: s = "catsanddog", n = 5
dict = {"cats", "cat", "and", "sand", "dog"}
Output: (cats and dog)(cat sand dog)
Explanation: All the words in the given
sentences are present in the dictionary
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
void solve(string &input, int index, vector<string> &temp, unordered_set<string> dict_set)
{
    if (index == input.size())
    {
        string sentence;
        for (int i = 0; i < temp.size(); i++)
        {
            sentence += temp[i];
            if (i != temp.size() - 1)
            {
                sentence += " ";
            }
        }
        // cout << "-->" << sentence << endl;
        ans.push_back(sentence);
        return;
    }

    string word;
    for (int i = index; i < input.size(); i++)
    {
        word += input[i];
        // if "word" is present in the set
        if (dict_set.find(word) != dict_set.end())
        {
            temp.push_back(word);
            solve(input, i + 1, temp, dict_set);
            temp.pop_back();
        }
    }
}

vector<string> wordBreak(int n, vector<string> &dict, string &input)
{
    vector<string> temp;
    unordered_set<string> dict_set;
    for (int i = 0; i < dict.size(); i++)
    {
        dict_set.insert(dict[i]);
    }
    solve(input, 0, temp, dict_set);
    return ans;
}

int main()
{
    string input = "catsanddog";
    int n = 5;
    vector<string> dict = {"cats", "cat", "and", "sand", "dog"};

    vector<string> ans = wordBreak(n, dict, input);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "}";
        cout << endl;
    }

    return 0;
}
