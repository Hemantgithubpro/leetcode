#include <bits/stdc++.h>
using namespace std;

int numberOfSpecialChars(string word)
{

    // map<char, int> mp;
    // for (char c : word)
    //     mp[c]++;

    // second method
    // 26 * n
    // 26 iterations (loop over word), checking eligibility of each letter
    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        char low = 'a' + i;
        char upp = 'A' + i;
        bool seenLower = false;
        bool seenUpper = false;
        bool isvalid = true;

        for (char c : word)
        {
            if (c == low)
            {
                if (seenUpper)
                {
                    isvalid = false;
                    break;
                }
                seenLower = true;
            }
            else if (c == upp)
            {
                seenUpper = true;
            }
        }

        if (isvalid && seenLower && seenUpper)
            res++;
    }
    return res;
}
// int numberOfSpecialChars(string word)
// {

//     // map<char, int> mp;
//     // for (char c : word)
//     //     mp[c]++;

//     // second method
//     // 26 * n
//     // 26 iterations (loop over word), checking eligibility of each letter
//     int res = 0;
//     for (int i = 0; i < 26; i++)
//     {
//         char low = 'a' + i;
//         char upp = toupper(low);
//         bool isupper = false;
//         bool isvalid = true;
//         bool issmallthere = false;
//         bool isupperthere = false;

//         for (int j = 0; j < word.size(); j++)
//         {
//             char lett = word[j];
//             char letup = toupper(lett);
//             if (!isupper)
//             {
//                 if (lett != letup)
//                 {
//                     issmallthere = true;
//                 }
//                 else
//                 {
//                     isupper = true;
//                     isupperthere = true;
//                 }
//             }
//             else
//             {
//                 if (lett == letup)
//                     continue;
//                 else
//                 {
//                     isvalid = false;
//                 }
//             }
//         }
//         if (isvalid && issmallthere && isupperthere)
//             res++;
//     }
//     return res;
// }
//    int numberOfSpecialChars(string word) {
//         // keep account of both lower and uppercase of a letter, and the last occurence of a letter should be uppercase, and it should then be only uppercase of that letter.

//         map<char,int> mp;
//         for(char c:word) mp[c]++;

//         char low;
//         char upp = toupper(low);

//     }

int main()
{

    string word = "aaAbcBC";
    numberOfSpecialChars(word);
}