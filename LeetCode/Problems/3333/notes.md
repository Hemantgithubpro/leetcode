
# Intuition
- It's just the combined question of the previous potd 3330.
- They just added the minimum size of string to k.
- ans=(all possible combinations of characters in the string) - (combination with length < k).


## rough
- aaabbb k=3
[]: #          um[word[i]]++;
[]: #      }
[]: #      for (auto it : um)
[]: #      {
[]: #          if (it.second > candelete)
[]: #              ans *= it.second - candelete + 1;
[]: #      }
[]: #      return ans;
[]: #  }