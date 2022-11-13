class Solution(object):
    # Recursive function to return gcd of a and b
   

    # Function to return LCM of two numbers
    
    def subarrayLCM(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def gcd(a,b):
            if a == 0:
                return b
            return gcd(b % a, a)
        def lcm(a,b):
            return (a / gcd(a,b))* b
        n = len(nums)
        cnt = 0
        for i in range (0,n):
            l = nums[i]
            for j in range(i,n):
                l = lcm(l,nums[j])
                if(l == k):
                    cnt += 1
                
        
        
        return cnt
