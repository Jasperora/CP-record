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
###### 1/16
- [678. Valid Parenthesis String](678.%20Valid%20Parenthesis%20String.cpp.cpp) 紀錄左括號的可能range，檢查兩種錯誤情形：左括號太多或右括號太多。
###### 1/17
- [518. Coin Change II](518.%20Coin%20Change%20II.cpp) 2D dp，但因為只需要用到兩個row，且計算有順序，所以可只用一排row的記憶體來算。[494. Target Sum](494.%20Target%20Sum.cpp) 可以用backtrack+caching的方式解，也可以用2D dp，而且也只需要兩個row就可完成計算
###### 1/21
- [130. Surrounded Regions](130.%20Surrounded%20Regions.cpp) 找沒被surrounded的更快，只要從外圍開始dfs就可
- [4. Median of Two Sorted Arrays](4.%20Median%20of%20Two%20Sorted%20Arrays.cpp) 挑長度小的一邊做binary search，並根據次結果把兩個array拆成左右兩邊，檢查這樣是否符合條件，不符合就繼續binary search，符合就可以找出答案
###### 1/22
- [124. Binary Tree Maximum Path Sum](124.%20Binary%20Tree%20Maximum%20Path%20Sum.cpp) 如果此node底下的path sum比目前的path sum還大就更新，但向上回傳時只能回傳直線的path
- [297. Serialize and Deserialize Binary Tree](297.%20Serialize%20and%20Deserialize%20Binary%20Tree.cpp) 用preorder traversal就可以encode binary tree，用dfs decode
- [1851. Minimum Interval to Include Each Query](1851.%20Minimum%20Interval%20to%20Include%20Each%20Query.cpp) ascending sort queries和intervals，之後從queries小到大去把已經碰到的intervals加到一個min heap(interval的長度，interval的右端點)，當query超過interval右端點時就把它pop掉
###### 1/23
- [211. Design Add and Search Words Data Structure](211.%20Design%20Add%20and%20Search%20Words%20Data%20Structure.cpp) 用Trie，遇到.時用dfs
- [295. Find Median from Data Stream](295.%20Find%20Median%20from%20Data%20Stream.cpp) 把數字用一個min heap、一個max heap存。min heap最小的數比max heap最大的數還要大，此時median只跟這兩個heap的top有關
- [684. Redundant Connection](684.%20Redundant%20Connection.cpp) 用union-find演算法，一旦遇到edge兩端同屬一個union即是答案
###### 2/9
- [2013. Detect Squares](2013.%20Detect%20Squares.cpp) 先找可能成為對角的點，再檢查有沒有可能形成正方形，這麼做比列出任三點檢查正方形快
- [210. Course and Schedule II](210.%20Course%20Schedule%20II.cpp) 用dfs完成topological sort
###### 2/11
- [212. Word Search II](212.%20Word%20Search%20II.cpp) 把所有要找的word加進去trie，一旦dfs search出來的prefix不對就停止search以增加效率
- [329. Longest Increasing Path in a Matrix](329.%20Longest%20Increasing%20Path%20in%20a%20Matrix.cpp) 用dfs算LIP(Longeset Increasing Path)，且LIP算過之後可以重複利用，所以可用dp
###### 2/14
- [127. Word Ladder](127.%20Word%20Ladder.cpp) 難點在於把word用短一點的時間轉成adjacency list，辦法是用一個ｍap把有著相同pattern的word放在一起。做完graph之後用bfs就可以了
- [115. Distinct Subsequences](115.%20Distinct%20Subsequences.cpp) 2D dp，用dfs解不用把整張表算完，不要用for loop去算dp的每一個entry
###### 2/17
- [743. Network Delay Time](743.%20Network%20Delay%20Time.cpp) Dijkstra's algorithm，用bfs把neighboring node按照distance加到min heap，從min heap top裡挑沒有visit過的走
- [1584. Min Cost to Connect All Points](1584.%20Min%20Cost%20to%20Connect%20All%20Points.cpp) Minimum Spanning Truee(MST)，需要Prim's algorithm，使用min heap，greedy的挑距離最短的加入現有的spanning tree，直到加完全部的點
###### 2/18
- [787. Cheapest Flights Within K Stops](787.%20Cheapest%20Flights%20Within%20K%20Stops.cpp) 用Bellman-Ford algorithm可以強制限定最多能走幾個stop，注意要多開一個tmp array否則會錯