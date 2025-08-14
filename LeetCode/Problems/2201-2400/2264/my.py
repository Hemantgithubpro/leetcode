class Solution(object):
    def largestGoodInteger(self, num):
        if len(num)<3:
            return ""
        maxi=-1
        for i in range(len(num)-2):
            temp=num[i:i+3]
            if temp[0]==temp[1] and temp[1]==temp[2]:
                maxi=max(maxi,int(temp))
        if maxi==0: return "000"
        return str(maxi) if maxi!=-1 else ""

if __name__ == "__main__":
    num = input("Enter the number string: ")
    solution = Solution()
    print(solution.largestGoodInteger(num))