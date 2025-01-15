#### 2025
###### 1/12
- 奇數個XOR會留著，偶數個會消掉，bitwise XOR可用來找array裡出現次數跟別人不一樣的element
- 檢查palindrome的時候由中間向兩邊擴張檢查比由左至右檢查還要快，還可以加上dp查表會更快
- Floyd's algorithm: 用在linked list的cycle detection，一開始有fast, slow兩個ptr從原點出發，fast一次跳兩格、slow一次跳一格。直到兩者重合時，把fast拿掉，再從原點多加一個slow ptr，原本的slow ptr從交會處繼續走，直到跟新的slow ptr交會，交會點即為cycle的開始。
- [300. Longest Increasing Subsequence](300.%20Longest%20Increasing%20Subsequence.cpp) dp[i]=LIS in nums[0..i], dp[i]的求法是for all 0≤j≤i-1，dp[i]=dp[j]+1 if nums[i]>nums[j]。但重點是要先確保dp[0..i-1]的答案都是正確的。因此要從dp[0]一路求到dp[i]。
- [139. Word Break](139.%20Word%20Break.cpp) 可以用DFS，從左至右，每當遇到wordDict＝prefix的情況就往下搜尋，但會TLE。可用dp，dp[i]=s[i:]是否可被wordDict表示。只要由右至左求dp就可。如果dp[j] is true且s[i..j]被包含在wordDict，則dp[j] is true。
- [312. Burst Balloons](312.%20Burst%20Balloons.cpp) dp[i][j]=把balloon i到ballon j炸光所得的最大值，dp[i][j] = max(dp[i][k-1]+nums[i-1]*nums[k]*nums[j+1]+dp[k+1][j]) for i≤k≤j，k超出邊界的話要設限制。重點是k是最後炸的，若用最早炸的氣球去想，則k被炸完後，k左右的氣球炸了會需要乘以原本沒考慮到的氣球(k-1、k+1)，因此k必須是最後炸的
###### 1/13
- [416. Partition Equal Subset Sum](416.%20Partition%20Equal%20Subset%20Sum.cpp) dp[i]=subset sum是否可產生i，掃過nums一輪把dp填好。技巧是從數字大檢查到數字小的，這樣才不會重複用到同一個數字
- 很多題目最直觀的想法都是recursion，可用decision tree的dfs處理，為了避免重複計算才用dp存答案查表
- [435. Non-overlapping Intervals](435.%20Non-overlapping%20Intervals.cpp) 在一群intervals裡挑出最大數量的non-overlapping intervals。可用decision tree dfs，也可用dp、greedy。每次決定要留哪個interval時，greedy去選最早結束的interval，最大化後面intervals可使用的空間。
- [84. Largest Rectangle in Histogram](84.%20Largest%20Rectangle%20in%20Histogram.cpp) 由左至右把heights存成monotonic stack，要存height和index，index是此height可以往左extend的最遠處
###### 1/14
- [48. Rotate Image](48.%20Rotate%20Image.cpp) 利用左上、右上、左下、右下四個位置，從matrix外圍向內一層一層的旋轉
- [73. Set Matrix Zeroes](73.%20Set%20Matrix%20Zeroes.cpp) 檢查一個matrix，若出現0則將該行與該列都設為0。可利用第一行與第一列存哪幾行哪幾列要換成0，最後再特別檢查是否第一行或第一列要全設為0，這樣只需要額外O(1) space
###### 1/15
- `priority_queue<type>`是max heap，`priority_queue<type, vector<type>, greater<type>>`是min heap
- [703. Kth Largest Element in a Stream](703.%20Kth%20Largest%20Element%20in%20a%20Stream.cpp) 求一串數字裡第k大的數字時，可以用min heap存這些數字，並確保min heap的size==k，比k大就pop。這樣min heap的top就會是所求
- [90. Subsets II](90.%20Subsets%20II.cpp) 有重複的數字並要求所有subset。為了避免產生重複的subset，要調整取的index。[40. Combination Sum II](40.%20Combination%20Sum%20II.cpp) 也是一樣的想法
- map: lower_bound(k)回傳≥k的第一個element的ptr，upper_bound(k)回傳>k的第一個element的ptr。prev(it) or it-1會回傳it的前一個ptr
- [621. Task Scheduler](621.%20Task%20Scheduler.cpp) 只記task的freq，把他們存成max heap(最多26個elements)，並利用queue決定什麼時候從pq被pop的element要push回去
- [134. Gas Station](134.%20Gas%20Station.cpp) 要是sum(gas[i])-sum(cost[i])≥0的話則必有解，用greedy只需要O(n)。greedy會成功是因為任何經過的gas station的sum(gas[i])-sum(cost[i]) prefix都有surplus或至少沒有deficit，否則也不可能走得到這裡，那扣除了prefix之後(也就是考慮已經經過的gas station是starting point的可能性)只會更無法達成條件，因此可以一次否決掉已經經過的gas station，在剩下的gas station中找答案