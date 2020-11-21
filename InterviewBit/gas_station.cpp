// Gas Station
/*

Given two integer arrays A and B of size N.
There are N gas stations along a circular route, where the amount of gas at station i is A[i].

You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i
to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.

You can only travel in one direction. i to i+1, i+2, … n-1, 0, 1, 2.. Completing the circuit means starting at i and
ending up at i again.

*/

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int tank = 0, start = 0, sumGas = 0, sumCost = 0;
    
    for (int i = 0; i<A.size(); ++i)
    {
        sumGas += A[i];
        sumCost += B[i];
        tank += (A[i] - B[i]);
        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }
    
    if (sumGas < sumCost)
        return -1;
        
    return start;
}
