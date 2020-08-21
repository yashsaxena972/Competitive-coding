// Merge Overlapping Intervals


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
} 

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> B(A.begin(), A.end());
    vector<Interval> answer;
    
    if (B.size() <= 0) {
        return B;
    }
        
    stack<Interval> s; 
    
    sort(B.begin(), B.end(), compareInterval);
    s.push(B[0]);
    
    for (int i = 1 ; i < B.size(); i++) 
    { 
        // get interval from stack top 
        Interval top = s.top(); 
  
        // if current interval is not overlapping with stack top, 
        // push it to the stack 
        if (top.end < B[i].start) 
            s.push(B[i]); 
  
        // Otherwise update the ending time of top if ending of current 
        // interval is more 
        else if (top.end < B[i].end) 
        { 
            top.end = B[i].end; 
            s.pop(); 
            s.push(top); 
        } 
    }
    
    while(!s.empty()){
        Interval t = s.top();
        answer.push_back(t);
        s.pop();
    }
    
    return answer;
}
