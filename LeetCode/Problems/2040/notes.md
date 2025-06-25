
arr1={2,5}
arr2={3,4}

comparision= min(arr1[0]*arr2[1], arr1[1]*arr2[0])

if(smallest in arr1 >0 and smallest in arr2 >0):
    ans= arr1[0]*arr2[0]
else if(smallest in arr1 >0 and smallest in arr2 <0):
    ans= arr1[0]*arr2[1]
else if(smallest in arr1 <0 and smallest in arr2 >0):
    ans= arr1[1]*arr2[0]
else if(smallest in arr1 <0 and smallest in arr2 <0):
    ans= arr1[1]*arr2[1]
