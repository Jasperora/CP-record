#### 2025
###### 1/12
- 奇數個XOR會留著，偶數個會消掉，bitwise XOR可用來找array裡出現次數跟別人不一樣的element
- 檢查palindrome的時候由中間向兩邊擴張檢查比由左至右檢查還要快，還可以加上dp查表會更快
- Floyd's algorithm: 用在linked list的cycle detection，一開始有fast, slow兩個ptr從原點出發，fast一次跳兩格、slow一次跳一格。直到兩者重合時，把fast拿掉，再從原點多加一個slow ptr，原本的slow ptr從交會處繼續走，直到跟新的slow ptr交會，交會點即為cycle的開始。
- [300. Longest Increasing Subsequence](300.%20Longest%20Increasing%20Subsequence.cpp) dp[i]=LIS in nums[0..i], dp[i]的求法是for all 0<=j<=i-1，dp[i]=dp[j]+1 if nums[i]>nums[j]。但重點是要先確保dp[0..i-1]的答案都是正確的。因此要從dp[0]一路求到dp[i]。
- [139. Word Break](139.%20Word%20Break.cpp) 可以用DFS，從左至右，每當遇到wordDict＝prefix的情況就往下搜尋，但會TLE。可用dp，dp[i]=s[i:]是否可被wordDict表示。只要由右至左求dp就可。如果dp[j] is true且s[i..j]被包含在wordDict，則dp[j] is true。
- [312. Burst Balloons](312.%20Burst%20Balloons.cpp) dp[i][j]=把balloon i到ballon j炸光所得的最大值，dp[i][j] = max(dp[i][k-1]+nums[i-1]*nums[k]*nums[j+1]+dp[k+1][j]) for i<=k<=j，k超出邊界的話要設限制。重點是k是最後炸的，若用最早炸的氣球去想，則k被炸完後，k左右的氣球炸了會需要乘以原本沒考慮到的氣球(k-1、k+1)，因此k必須是最後炸的
###### 1/13
- [416. Partition Equal Subset Sum](416.%20Partition%20Equal%20Subset%20Sum.cpp) dp[i]=subset sum是否可產生i，掃過nums一輪把dp填好。技巧是從數字大檢查到數字小的，這樣才不會重複用到同一個數字
- 很多題目最直觀的想法都是recursion，可用decision tree的dfs處理，為了避免重複計算才用dp存答案查表
- [435. Non-overlapping Intervals](435.%20Non-overlapping%20Intervals.cpp) 在一群intervals裡挑出最大數量的non-overlapping intervals。可用decision tree dfs，也可用dp、greedy。每次決定要留哪個interval時，greedy去選最早結束的interval，最大化後面intervals可使用的空間。
- [84. Largest Rectangle in Histogram](84.%20Largest%20Rectangle%20in%20Histogram.cpp) 由左至右把heights存成monotonic stack，要存height和index，index是此height可以往左extend的最遠處