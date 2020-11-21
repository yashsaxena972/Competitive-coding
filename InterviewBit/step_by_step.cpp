// Step by Step
/*

Given a target A on an infinite number line, i.e. -infinity to +infinity.
You are currently at position 0 and you need to reach the target by moving according to the below rule:

In ith move you can take i steps forward or backward.
Find the minimum number of moves required to reach the target.

*/

int Solution::solve(int A) {
    int target = abs(A);
    int sum = 0, ans = 0;
    while (sum < target || (sum - target) % 2 != 0) {
        ans++;
        sum += ans;
    }
    return ans;
}
