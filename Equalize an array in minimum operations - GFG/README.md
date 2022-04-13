# Equalize an array in minimum operations
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">You are given an array of <strong>N</strong> integers <strong>A[0]</strong>, <strong>A[1]</strong>, …, <strong>A[N-1]</strong>, and an integer <strong>k</strong>. Your task is to make all the elements of the given array equal in a minimum number of ‘moves’. &nbsp;All the elements of the array are non-negative. In each ‘move,’ you may add or subtract k from any element of the array. Give the answer modulo 10<sup>9</sup>+7.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 4, k = 2
A = {7, 5, 21, 17}
<strong>Output:</strong> 13
<strong>Explaination:</strong> We can add k = 2 to A[1] 
once and subtract k = 2 from A[2] seven 
times and from A[3] five times.The 
resulting array would be- 7 7 7 7. 
Number of moves = 1 + 7 + 5 = 13.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 4, k = 3
A = {7, 5, 21, 17}
<strong>Output:</strong> -1
<strong>Explaination:</strong> No matter how many moves 
are made, all the elements of the array 
cannot be made equal.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do&nbsp;not need to read input or print anything. Your task is to complete the function <strong>equalizeArray()</strong> which takes N, k, and A as input parameters and returns the minimum number of moves to make all the elements of the array equal. Return <strong>-1</strong> if it is not possible.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N*logN)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>6</sup><br>
1 ≤ k, A[i] ≤ 1000</span></p>
 <p></p>
            </div>