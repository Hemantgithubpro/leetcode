# What to do
- I have to find the longest subarray having difference between adjacent elements at most `k`.
- I can use a two-pointer technique to find the longest subarray.

## Rough Notes Method 1
- I guess this method is flawed.
i: from left to right
j: from right to left
to delete out of n: min(n-i+1, j), indexed from 1 not 0

5 1
1 2 4 5 6
    i
  j

8 3
17 3 1 20 12 5 17 12
1 3 5 12 12 17 17 20
            i
         j          


5 3
2 3 19 10 8
2 3 8 10 19
    i     



3 4
1 10 5



8 1
8 3 1 4 5 10 7 3
1 3 3 4 5 7 8 10
              i
j 

## Method 2
- Sort the array.
- use two pointers to find the longest subarray where the difference between adjacent elements is at most `k`.
- keep track of the maximum length found.
- Initialize two pointers `i` and `j` at the start of the array.
- keep moving `j` to the right until the difference between `arr[j]` and `arr[j-1]` exceeds `k`.
- If it does, move `i` to the right until the difference is within `k`.

### Rough Notes Method 2

1 2 4 5 6
        i
    j


# Summary till now
`main2.cpp` is giving correct output till 4th test case, and rest is wrong.
`main.cpp` is totally wrong.

## Approach
1. Sort the array.

# Summary end summary
Yes! I did it myself. It used two pointer approach, method 2 worked.