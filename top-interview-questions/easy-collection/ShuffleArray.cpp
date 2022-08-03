/*
Shuffle an Array

Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.


Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]



Constraints:

1 <= nums.length <= 200
-106 <= nums[i] <= 106
All the elements of nums are unique.
At most 5 * 104 calls in total will be made to reset and shuffle.


Initial Thoughts
Normally I would display more than two approaches, but shuffling is deceptively easy to do almost properly, 
and the Fisher-Yates algorithm is both the canonical solution and asymptotically optimal.

A few notes on randomness are necessary before beginning - both approaches displayed below assume that the 
languages' pseudorandom number generators (PRNGs) are sufficiently random. The sample code uses the simplest 
techniques available for getting pseudorandom numbers, but for each possible permutation of the array to be 
truly equally likely, more care must be taken. For example, an array of length nn has n!n! distinct permutations. 

Therefore, in order to encode all permutations in an integer space, \lceil lg(n!)\rceil⌈lg(n!)⌉ bits are necessary,
which may not be guaranteed by the default PRNG.


*/

#if 0
Approach #1 Brute Force[Accepted]
Intuition

If we put each number in a "hat" and draw them out at random, the order in which we draw them will define a random ordering.

Algorithm

The brute force algorithm essentially puts each number in the aforementioned "hat", and draws them at random(without replacement) 
until there are none left.Mechanically, this is performed by copying the contents of array into a second auxiliary array named 
aux before overwriting each element of array with a randomly selected one from aux.After selecting each random element, it is 
removed from aux to prevent duplicate draws.The implementation of reset is simple, as we just store the original state of nums
on construction.

The correctness of the algorithm follows from the fact that an element(without loss of generality) is equally likely to be selected
during all iterations of the for loop.To prove this, observe that the probability of a particular element ee being chosen on the kkth 
iteration(indexed from 0) is simply P(eP(e being chosen during the kkth iteration)\cdot P(e)⋅P(e not being chosen before the kkth 
    iteration)).Given that the array to be shuffled has nn elements, this probability is more concretely stated as the following :

\frac{ 1 }{n - k} \cdot \prod_{ i = 1 }^ {k} \frac{ n - i }{n - i + 1}
n−k
1
​
⋅∏
i = 1
k
​

n−i + 1
n−i
​


When expanded(and rearranged), it looks like this (for sufficiently large kk) :

    (\frac{ n - 1 }{n} \cdot \frac{ n - 2 }{n - 1} \cdot(\ldots) \cdot \frac{ n - k + 1 }{n - k + 2} \cdot \frac{ n - k }{n - k + 1}) \cdot \frac{ 1 }{n - k}(
        n
        n−1
        ​
        ⋅
        n−1
        n−2
        ​
        ⋅(…)⋅
        n−k + 2
        n−k + 1
        ​
        ⋅
        n−k + 1
        n−k
        ​
        )⋅
    n−k
    1
    ​


    For the base case (k = 0k = 0), it is trivial to see that \frac{ 1 }{n - k} = \frac{ 1 }{n}
n−k
1
​
=
n
1
​
.For k > 0k > 0, the numerator of each fraction can be cancelled with the denominator of the next, leaving the nn from the 0th draw as the only uncancelled denominator.Therefore, no matter on which draw an element is drawn, it is drawn with a \frac{ 1 }{n}
n
1
​
chance, so each array permutation is equally likely to arise.

class Solution {
    private int[] array;
    private int[] original;

    private Random rand = new Random();

    private List<Integer> getArrayCopy() {
        List<Integer> asList = new ArrayList<Integer>();
        for (int i = 0; i < array.length; i++) {
            asList.add(array[i]);
        }
        return asList;
    }

    public Solution(int[] nums) {
        array = nums;
        original = nums.clone();
    }

    public int[] reset() {
        array = original;
        original = original.clone();
        return array;
    }

    public int[] shuffle() {
        List<Integer> aux = getArrayCopy();

        for (int i = 0; i < array.length; i++) {
            int removeIdx = rand.nextInt(aux.size());
            array[i] = aux.get(removeIdx);
            aux.remove(removeIdx);
        }

        return array;
    }
}

Complexity Analysis

Time complexity : \mathcal{ O }(n ^ 2)O(n
    2
)

The quadratic time complexity arises from the calls to list.remove(or list.pop), which run in linear time.nn linear list removals occur, which results in a fairly easy quadratic analysis.

Space complexity : \mathcal{ O }(n)O(n)

Because the problem also asks us to implement reset, we must use linear additional space to store the original array.Otherwise, it would be lost upon the first call to shuffle.

#endif

#if 0
Approach #2 Fisher - Yates Algorithm[Accepted]
Intuition

We can cut down the time and space complexities of shuffle with a bit of cleverness - namely, by swapping elements around within the array itself, we can avoid the linear space cost of the auxiliary arrayand the linear time cost of list modification.

Algorithm

The Fisher - Yates algorithm is remarkably similar to the brute force solution.On each iteration of the algorithm, we generate a random integer between the current indexand the last index of the array.Then, we swap the elements at the current indexand the chosen index - this simulates drawing(and removing) the element from the hat, as the next range from which we select a random index will not include the most recently processed one.One small, yet important detail is that it is possible to swap an element with itself - otherwise, some array permutations would be more likely than others.To see this illustrated more clearly, consider the animation below :

class Solution {
    private int[] array;
    private int[] original;

    Random rand = new Random();

    private int randRange(int min, int max) {
        return rand.nextInt(max - min) + min;
    }

    private void swapAt(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public Solution(int[] nums) {
        array = nums;
        original = nums.clone();
    }

    public int[] reset() {
        array = original;
        original = original.clone();
        return original;
    }

    public int[] shuffle() {
        for (int i = 0; i < array.length; i++) {
            swapAt(i, randRange(i, array.length));
        }
        return array;
    }
}

Complexity Analysis

Time complexity : \mathcal{ O }(n)O(n)

The Fisher - Yates algorithm runs in linear time, as generating a random indexand swapping two values can be done in constant time.

Space complexity : \mathcal{ O }(n)O(n)

Although we managed to avoid using linear space on the auxiliary array from the brute force approach, we still need it for reset, so we're stuck with linear space complexity.


#endif



using namespace std;

#include <vector>
#include <random>


class Solution {
    vector<int> shuffled;
    vector<int> original;

public:
    Solution(vector<int>& nums) {
        shuffled = original = nums;
    }

    vector<int> reset() {
        shuffled = original;
        return shuffled;
    }

    int randomRange(int min, int max) {
        srand(time(min));
        return rand() % max;
    }

    vector<int> shuffle() {
        vector<bool>visited(shuffled.size(), false);
        for (int i = 0; i < shuffled.size(); i++) {
            int p = rand() % shuffled.size();

            while (visited[p] == true)
                p = rand() % shuffled.size();

            shuffled[i] = original[p];
            visited[p] = true;
        }
        return shuffled;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */