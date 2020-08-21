// Min Steps to Infinite Grid
// Given x coordinates in A[] and y coordinates in B[], find minimum steps to go from start point to end point

struct point { 
    int x, y; 
};

int shortestPath(point p1, point p2) 
{ 
    // dx is total horizontal 
    // distance to be covered 
    int dx = abs(p1.x - p2.x); 
  
    // dy is total vertical 
    // distance to be covered 
    int dy = abs(p1.y - p2.y); 
  
    // required answer is 
    // maximum of these two 
    return max(dx, dy); 
} 

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int stepCount = 0;
    
    for(int i=0;i<A.size()-1;i++){
        point p1,p2;
        p1.x= A[i];
        p1.y= B[i];
        p2.x= A[i+1];
        p2.y= B[i+1];
        stepCount += shortestPath(p1,p2);
    }
    
    return stepCount; 

}
