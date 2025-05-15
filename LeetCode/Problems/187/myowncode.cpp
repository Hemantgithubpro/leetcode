#include <bits/stdc++.h>
using namespace std;
// i guess i understood the approach, by hash function but i guess sliding window is better(which i will use later)
int findsum(string &str, int index)
{
    int sum = 0;
    for (int i = index; i < index + 10; i++)
    {
        sum += str[i];
    }
    return sum;
}

vector<string> findRepeatedDnaSequences(string s)
{
    // sliding window of size 10
    // i will just calculate the sum
    // map<string,int> mpp;
    // for(int i=0; i<s.size()-9; i++){
    //     string str="";
    //     int sum=0;
    //     for(int j=i; j<i+10; j++){
    //         str+=s[j];
    //         sum+=s[j];
    //     }
    //     mpp[str]++;
    //     if(mpp[str]==2){
    //         ans.push_back(str);
    //     }
    // }

    vector<string> ans;
    string str1 = "";
    map<int, int> mpp;
    for (int i = 0; i < s.size() - 9; i++)
    {
        int sum = findsum(s, i);
        mpp[sum]++;
        if (mpp[sum] == 2)
        {
            for (int j = i; j < i + 10; j++)
            {
                str1 += s[j];
            }
            ans.push_back(str1);
            str1 = "";
        }
    }

    return ans;
}

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    //        i
    findRepeatedDnaSequences(s);
}