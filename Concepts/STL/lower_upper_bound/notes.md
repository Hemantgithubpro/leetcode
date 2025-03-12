# std::upper_bound and std::lower_bound for Vector in C++ STL
<h2>These are included in `algorithms` library</h2>

## std::lower_bound
- Returns an iterator pointing to the first element in the range [first, last] which has a value not less than `val`. It means the function returns the first element that is greater or equal to `val`.
- The range [first, last] must be sorted in ascending order.
- If `val` is greater than the last element in the range, the function returns `last`.
- If `val` is less than the first element in the range, the function returns `first`.
    
    ```cpp
    std::vector<int> v = {1, 2, 4, 4, 5, 6, 7};
    auto it = std::lower_bound(v.begin(), v.end(), 4);
    std::cout << *it; // 4
    ```

## std::upper_bound
- Returns an iterator pointing to the first element in the range [first, last] which has a value greater than `val`. It means the function returns the first element that is strictly greater than `val`.
- The range [first, last] must be sorted in ascending order.
- If `val` is greater than the last element in the range, the function returns `last`.
- If `val` is less than the first element in the range, the function returns `first`.
    
    ```cpp
    std::vector<int> v = {1, 2, 4, 4, 5, 6, 7};
    auto it = std::upper_bound(v.begin(), v.end(), 4);
    std::cout << *it; // 5
    ```

## Time Complexity
- Both functions have a time complexity of O(log n) where n is the number of elements in the range [first, last].
- Both functions use binary search to find the element.
- The functions are implemented using the lower_bound and upper_bound functions of the binary search algorithm.