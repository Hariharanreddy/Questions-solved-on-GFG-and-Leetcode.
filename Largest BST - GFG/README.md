# Largest BST
## Medium 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.<br>
<strong>Note: </strong>Here Size is equal to the number of nodes in the subtree.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
&nbsp;       1
&nbsp;     /   \
&nbsp;    4     4
&nbsp;  /   \
&nbsp; 6     8<strong>
Output: </strong>1<strong>
Explanation: </strong>There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>6 6 3 N 2 9 3 N 8 8 2
&nbsp;           6
&nbsp;       /       \
&nbsp;      6         3
&nbsp;       \      /   \
&nbsp;        2    9     3
&nbsp;         \  /  \
&nbsp;         8 8    2 <strong>
Output: </strong>2<strong>
Explanation: </strong>The following sub-tree is a
BST of size 2:&nbsp;
&nbsp; &nbsp; &nbsp;  2
&nbsp; &nbsp; /&nbsp; &nbsp; \&nbsp;
&nbsp;  N&nbsp; &nbsp; &nbsp; 8</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function</span><span style="font-size:18px"><strong> largestBst()&nbsp;</strong>that takes the root node of the Binary Tree<strong>&nbsp;</strong>as its input&nbsp;and returns the size&nbsp;of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(Height of the BST).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ Number of nodes ≤ 10<sup>5</sup><br>
1 ≤ Data of a node ≤ 10<sup>6</sup></span></p>
 <p></p>
            </div>