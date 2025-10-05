

## Intuition
- for this array, it is
    - either to maximize last index of array
    - or to minimize first index of array
- find the max and min of the array

- maybeachieved=max-min

### Rough

2 1 3 4 5 7 6

maybeachieved=7-1=6
- so we can either make the max to the end or min to the start

1 3 9 11 5 7

## Another Method
- There are three cases:
    - move minimum it to the start
    - move maximum it to the end
    - otherwise, move the whole array 'n' times, meaning find the difference of '0' and 'n-1' index with modulo 'n'
- The answer is the maximum of these three cases.

### Rough

2 1 8 1
- one cyclic rotation gives 1 2 1 8

2 2 2 2 2 1 8 1

1 8 1 2 2 2 2 2

2 1 8 1 2
2 2 1 8 1
1 2 2 1 8


## Method 3
- find the cases where maxi and mini can't reach the ends.

### Rough

3 4 1 3 2 8 7 6
index: a[n-1]-a[0]

# both main and main2.cpp are stuck on testcase 2 with output=967 and answer=962


# Solution
so my solution was correct, and this 'abs()' function was the problem. i guess it was the problem of codeforces, not mine.