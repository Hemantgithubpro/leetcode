def productOfDigits(n:int)->int:
    temp=1
    while n>0:
        temp*=n%10
        n//=10
    return temp

def smallestNumber(n: int, t: int) -> int:
    if t == 1:
        return n
    
    # since n is small, i can try all combinations linearly
    for i in range(n,2*n,1):
        prod=productOfDigits(i)
        if prod%t==0:
            return i
    return -1


n=10
t=2
print(smallestNumber(n,t))
# print(productOfDigits(n))