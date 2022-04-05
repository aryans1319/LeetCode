# Floor in a Sorted Array
## Easy 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor: pointer; background: 0% 0% no-repeat padding-box padding-box rgb(239, 248, 243); align-items: center; position: relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: rgb(51, 51, 51); --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor:#142d23; --darkreader-inline-color:#c8c3bc;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: 0% 0% no-repeat padding-box padding-box transparent; opacity: 1; margin: 0px 16px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor:transparent;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given a sorted array <strong>arr</strong>[] of size <strong>N</strong> without duplicates, and given a value <strong>x</strong>. Floor of x is defined as the largest element <strong>K</strong> in arr[] such that K is smaller than or equal to x.&nbsp;Find the index of K(0-based indexing).</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 7, x = 0 
arr[] = {1,2,8,10,11,12,19}
<strong>Output: </strong>-1<strong>
Explanation: </strong>No element less 
than 0 is found. So output 
is "<strong>-1</strong>".</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 7, x = 5 
arr[] = {1,2,8,10,11,12,19}
<strong>Output: </strong>1<strong>
Explanation: </strong>Largest Number less than 5 is
<strong>2 (i.e K = 2)</strong>, whose index is <strong>1</strong>(0-based 
indexing).</span>
</pre>

<p><span style="font-size:18px"><strong>Your&nbsp;Task:</strong><br>
The task is to complete the function <strong>findFloor</strong>() which returns an&nbsp;integer denoting the index value of K&nbsp;or return <strong>-1</strong> if there isn't any such number.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(log N).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>7</sup><br>
1 ≤ arr[i] ≤ 10<sup>18</sup><br>
0 ≤ X&nbsp;≤<sup> </sup>arr[n-1]</span></p>
 <p></p>
            </div>