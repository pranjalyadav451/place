/*
Geek is a software engineer at Amazon. He wants to develop a software that discards all the cities where delivery is not possible due to road blockage. For the remaining cities, the software calculates the maximum distance an item has to travel from city 0 to the customer living in any connected city x.
You are given Q queries; in the ith query, the road connecting city query[i][0] and query[i][1] is blocked by the rebel group. Help Geek to find the maximum distance for each query.



<div class="problem-statement"><p><span style="font-size:18px">There are <strong>N cities</strong> in Geekland numbered <strong><em>0, 1,.., N - 1</em></strong>. There are <strong>(N-1) bidirectional roads</strong>, the i<sup>th</sup> road connects city Edge[i][0] and Edge[i][1]. You can consider the length of each road as 1 unit. At least one path can be found between any two cities in Geekland.</span></p>

<p><span style="font-size:18px">People of Geekland love ordering from Amazon. Its warehouse is located in <strong>city 0</strong>. But there is a rebel group in the country that can block any road and disrupt deliveries.&nbsp;</span></p>

<p><span style="font-size:18px">Geek is a software engineer at Amazon. He wants to develop a software that discards all the cities where delivery is not possible due to road blockage. For the remaining cities, the software <strong>calculates the maximum distance an item has to travel from city 0 to the customer living in any connected city x</strong>.&nbsp;</span></p>

<p><span style="font-size:18px">You are given Q queries; in the ith query, the road connecting city query[i][0] and query[i][1] is blocked by the rebel group. Help Geek to find the maximum distance for each query.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 5, Q = 2
Edge[][] = {{0, 1},
            {0, 2},
            {1, 3},
            {1, 4}}
query = {{0, 1},
         {1, 4}}
<strong>Output:
</strong>1 2
<strong>Explanation: </strong>
Geekland looks like:
            0
           / \
         1    2
       /   \
     3      4
<strong>Query 1:</strong> the road connecting (0,1)
is blocked. Only people living in
city 0 and 2 can place delivery orders.
For city 0, distance = 0.
For city 2, distance = 1.
Maximum (city 0, city 1) = 1</span>

<span style="font-size:18px"><strong>Query 2:</strong> The road connecting
(1, 4) is blocked. Only people living in
city 0,1,2 and 3 can place delivery orders.
For city 0, distance = 0.
For city 1, distance = 1.
For city 2, distance = 1.
For city 3, distance = 2.
A maximum distance of 2 has to be travelled
for people of city 3. 0 -&gt; 1 -&gt; 3</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 3, Q = 1
Edge[][] = {{0, 1},
&nbsp;           {0, 2}}
query[][] = {{0, 1}}
<strong>Output:</strong> 1
<strong>Explanation</strong>:
Geekland looks like:
              0
            /   \
           1     2

</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read, input, or print anything. Your task is to complete the function <strong><em>solve( )</em>,&nbsp;</strong>which takes integer&nbsp;<strong>N, </strong>integer&nbsp;<strong>Q, </strong>a 2d array<strong> Edge[ ][ ]</strong><strong>,&nbsp;</strong>and a 2d array&nbsp;<strong>query[ ][ ]&nbsp;</strong>as input parameters and returns an array of size <strong>Q</strong> answers to each query in the given order.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N, Q ≤ 10<sup>5</sup><br>
0 ≤ Edge[i][0] &lt;&nbsp;Edge[i][0] &lt; N<br>
0 ≤ query[i][0] &lt; query[i][1] &lt; N<br>
Each query has some valid road.</span></p>
</div>
*/