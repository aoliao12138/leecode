# -*- coding: UTF-8 -*-

#method 1 DP
# dp[i][i]=1;//单个字符是回文串
# dp[i][i+1]=1 if s[i]=s[i+1];//连续两个相同字符是回文串

#method2 中心拓展
#2n-1个中心 奇偶

#Manache
#1插入$# 来变成奇数和统一算半径
#2p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1; 至少这么长
#mx 是回文串能延伸到的最右端的位置 id 是mx 对应的中心
#见https://www.cnblogs.com/grandyang/p/4475985.html

class Solution:
    def longestPalindrome(self, s):
        sc="$#"
        for i in s:
            sc=sc+i+"#"
        sc=sc+"]"
        p={}
        mx=0
        id=0
        longestlen=0
        longestcenter=0
        for i in range(1,len(sc)-1):
            if mx>i:
                p[i]=min(p[2*id-i],mx-i)
            else:
                p[i]=1
            while (sc[i+p[i]]==sc[i-p[i]]):
                p[i]=p[i]+1
            if mx<i+p[i]:
                mx=i+p[i]
                id =i
            if longestlen<p[i]:
                longestlen=p[i]
                longestcenter=i
        return s[int((longestcenter-longestlen)/2):int((longestcenter-longestlen)/2)+longestlen-1]




s=Solution()
print(s.longestPalindrome("cbbd"))