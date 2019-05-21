#sliding window


class Solution:
    def lengthOfLongestSubstring(self, s: str):
        i=0
        j=0
        max_str=0    
        d={}
        while (j!=len(s)):
            if s[j] in d:
                i=max(i,d[s[j]]+1)
                d[s[j]]=j
                j=j+1
                max_str=max(max_str,j-i)
            else:
                d[s[j]]=j
                j=j+1
                max_str=max(max_str,j-i)
        return max_str

# sol=Solution()    
# print(sol.lengthOfLongestSubstring("abba"))