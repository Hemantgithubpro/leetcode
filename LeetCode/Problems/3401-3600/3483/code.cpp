#include <bits/stdc++.h>
using namespace std;
int totalNumbers(vector<int> &digits)
{
    vector<int> result;
    unordered_set<int> unique_numbers;
    // sort(digits.begin(),digits.end());
    for (int i = 0; i < digits.size(); i++)
    {
        for (int j = 0; j < digits.size(); j++)
        {
            for (int k = 0; k < digits.size(); k++)
            {
                if (i != j && j != k && i != k)
                {
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num % 2 == 0 && num >= 100)
                    {
                        unique_numbers.insert(num);
                    }
                }
            }
        }
    }
    for (auto num : unique_numbers)
    {
        result.push_back(num);
    }
    return result.size();
}