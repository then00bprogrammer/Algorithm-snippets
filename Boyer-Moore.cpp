#include <bits/stdc++.h>
using namespace std;

//Boyre Moore Algorithm - Majority element in O(N) time and O(1) space.

// The basic concept is “Let’s cancel each others’ vote!”

// When there are n votes and two majorities in it. Cancel everybody’s vote 1 by 1 is a good way. Because two majorities has the confidence to have remaining votes while others die out.

//Simplest Case - https://www.youtube.com/watch?v=nP_ns3uSh80&t=964s&ab_channel=takeUforward


// Given n numbers and the k counters, only less than n/(k+1) times pair-out can happen.
// That is to say:

// Given n numbers and 1 counter (which is the majority element problem), at most (n/2) times pair-out can happen, which will lead to the survival of the only element that appeared more than n/2 times.
// Given n numbers and 2 counters (which is our case), at most n/3 times of pair-out can happen, which will lead to the survival of elements that appeared more than n/3 times.
// Given n numbers and k counters, at most (n/k+1) times of pair-out can happen, which will lead to the survival of elements that appeared more than n/(k+1) times.
// If this is the case, then n elements using two counters can at most pair out less than (n/3) times, which will result in the survival of the elements that appears more than (n/3) times.


int main(){
        vector <int> nums={1,1,1,1,2,3};

        //1 MAJORITY CASE
        int ele=-1;
        int count=0;
        for(auto num:nums){
            if(count==0){
                ele=num;
                count=1;
            }
            else if(num==ele)++count;
            else --count;
        }
        //If we are not sure if there's a majority element
        // for(auto num:nums)if(num==ele)++count;
        //If count>(n/2) majority element exists
        return ele;

        //2 MAJORITY CASE 
        int n=nums.size();
        int num1=INT_MIN,num2=INT_MIN;
        int count1=0,count2=0;
        for(auto num:nums){
            if(num==num1)++count1;
            else if(num==num2)++count2;
            else if(count1==0){
                num1=num;
                count1=1;
            }
            else if(count2==0){
                num2=num;
                count2=1;
            }
            else{
                --count1;--count2;
            }
        }
        count1=0;count2=0;
        for(auto num:nums){
            if(num==num1)++count1;
            else if(num==num2)++count2;
        }
        vector <int> ans;
        if(count1>(n/3))ans.push_back(num1);
        if(count2>(n/3))ans.push_back(num2);
    return 0;
}


//DRY RUN OF THE ALGORITHM

// First we look at an example of one counter:
// suppose nums = [1, 2, 3, 4, 5, 6], and we are finding only one candidate and we have only one counter.

// the procedure will be like this:

// candidate = 1, counter = 1

// current number = 2
// candidate = 1, counter = 0
// (one pair-out happens)

// current number = 3
// candidate = 3, counter = 1
// (pair-out cannot happen now since there's nothing to pair out! Instead, counter got increased!)

// current number = 4
// candidate = 3, counter = 0
// (one pair-out happens)

// current number = 5
// candidate = 5, counter = 1
// (pair-out cannot happen and counter increased!)

// curent number = 6
// candidate = 5, counter = 0
// (one pair-out happens)

// From the above example, there are 6 elements in nums and we paired out 3 times, which is the most we can get. Suppose nums = [1,1,1,1,2,3], now we see that pair-out can happen only twice in this case.

// From the above example, it's obvious that to pair out once, you have to increase the counter at least once.
// And to pair out some candidate, you need first increase the counter. And every time you increase the counter, you waste one chance to pair out. So given n numbers, you can at most pair out (n/2) times, since you have to at least increase the counter (n/2) times to let you have something to pair out. It's quite like the amortized analysis, but if you don't know that, it doesn't matter though.

// Now we still use the example above but we hope to find two candidates:
// suppose nums = [1, 2, 3, 4, 5, 6], and we are finding two candidates and we have two counters.

// the procedure will be like this:

// candidate1 = 1, counter1 = 1
// candidate2 = 2, counter2 = 1

// current number = 3
// candidate1 = 1, counter1 = 0
// candidate2 = 2, counter2 = 0
// (one pair-out happens and both counters got decreased.)

// current number = 4
// candidate1 = 4, counter = 1
// candidate2 = 2, counter2 = 0
// (pair-out cannot happen and counter1 got increased)

// current number = 5
// candidate1 = 4, counter1 = 1
// candidate2 = 5, counter2 = 1
// (pair-out can still not happen and counter2 got incresed)

// current number = 6
// candidate1 = 4, counter1 = 0
// candidate2 = 5, counter2 = 0
// (pair-out happens and both counters become 0)

// Now we see, there are 6 elements in nums and we paired out 2 times, which is also the most we can get. Suppose nums = [1,1,1,1,2,3], pair-out can happen only once in this case.

// This is because once pair-out happens, both counters decrease. And when some counter becomes 0, only one counter will get increased at a time. So to pair out m times, each counter have to be increased at least m times, which is to increase 2*m times totally.

// It's not difficult to generalize to k counters. Of course, when k is large, it may be not efficient to use this count-and-pair-out method. However, the algorithm is still worth learning.

//Credits - https://leetcode.com/ZhaoJing_0x/
//https://leetcode.com/liji94188/