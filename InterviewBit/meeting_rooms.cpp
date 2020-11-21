// Meeting rooms
/*

Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.

*/

int Solution::solve(vector<vector<int> > &A) {
    
    // Sorting array with respect to the starting time
    sort(A.begin(), A.end());

    // min Heap through priority queue to get the minimum of the end times in queue at top
    priority_queue<int, vector<int>, greater<int> > minEndTime;

    // if there are no meetings
    if(A.size() == 0)
        return 0;

    // Pushing the end time of 1st meeting in queue
    minEndTime.push(A[0][1]);

    //rooms required
    int maxRooms = 1;
    int presentRooms;

    for (int i = 1; i < A.size(); i++){
        // till start time of a meeting is greater than the stortest end time in queue
        // then pop out the meeting that are over
        while(A[i][0] >= minEndTime.top() && !minEndTime.empty()){
            // meeting is over
            minEndTime.pop();
        }
    
        // pushing end time of ith meeting in the queue
        minEndTime.push(A[i][1]);
    
        // No. of meetings that are presently going on
        presentRooms = minEndTime.size();
    
        // Storing the maximum no. of rooms
        maxRooms = max(maxRooms, presentRooms);
    }
    return maxRooms;
}
