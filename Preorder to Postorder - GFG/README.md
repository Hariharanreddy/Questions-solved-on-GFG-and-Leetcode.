# Preorder to Postorder
## Medium 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.<br>
In Pre-Order traversal,&nbsp;<strong>the root node is visited before the left child and right child nodes</strong>.<br>
Post-order traversal is&nbsp;<strong>one of the multiple methods to traverse a tree</strong>.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 5
arr[]  = {40,30,35,80,100}
<strong>Output: </strong>35 30 100 80 40<strong>
Explanation:</strong>&nbsp;PreOrder: 40 30 35 80 100
InOrder: 30 35 40 80 100
Therefore, the BST will be:
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 40
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;/&nbsp; &nbsp;&nbsp; &nbsp;\
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;30&nbsp; &nbsp; &nbsp; &nbsp;80
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;\&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;\&nbsp; &nbsp;
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;35&nbsp; &nbsp; &nbsp; 100
Hence, the postOrder traversal will
be: 35 30 100 80 40</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 8
arr[]  = {40,30,32,35,80,90,100,120}
<strong>Output: </strong>35 32 30 120 100 90 80 40</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You need to complete the given function and<strong> return the root </strong>of the tree. The driver code will then use this root to print the post order traversal.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>3</sup><br>
1 &lt;= arr[i] &lt;= 10<sup>4</sup></span></p>
 <p></p>
            </div>