#### 2025
###### 1/12
- 奇數個XOR會留著，偶數個會消掉，bitwise XOR可用來找array裡出現次數跟別人不一樣的element
- 檢查palindrome的時候由中間向兩邊擴張檢查比由左至右檢查還要快，還可以加上dp查表會更快
- Floyd's algorithm: 用在linked list的cycle detection，一開始有fast, slow兩個ptr從原點出發，fast一次跳兩格、slow一次跳一格。直到兩者重合時，把fast拿掉，再從原點多加一個slow ptr，原本的slow ptr從交會處繼續走，直到跟新的slow ptr交會，交會點即為cycle的開始。
- [300. Longest Increasing Subsequence](300.%20Longest%20Increasing%20Subsequence.cpp) dp[i]=LIS in nums[0..i], dp[i]的求法是for all 0<=j<=i-1，dp[i]=dp[j]+1 if nums[i]>nums[j]。但重點是要先確保dp[0..i-1]的答案都是正確的。因此要從dp[0]一路求到dp[i]。
- [139. Word Break](139.%20Word%20Break.cpp) 可以用DFS，從左至右，每當遇到wordDict＝prefix的情況就往下搜尋，但會TLE。可用dp，dp[i]=s[i:]是否可被wordDict表示。只要由右至左求dp就可。如果dp[j] is true且s[i..j]被包含在wordDict，則dp[j] is true。