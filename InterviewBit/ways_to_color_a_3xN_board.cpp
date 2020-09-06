// Ways to color a 3xN Board
/*

Given a 3 x A board, find the number of ways to color it using at most 4 colors 
such that no 2 adjacent boxes have same color.
Diagonal neighbors are not treated as adjacent boxes.
Return the ways modulo 109 + 7 as the answer grows quickly.

*/

int Solution::solve(int A) {
    // When we to fill single column 
    long int color3 = 24; 
    long int color2 = 12; 
    long int temp = 0; 
      
    for (int i = 2; i <= A; i++)  
    { 
        temp = color3; 
        color3 = (11 * color3 + 10 * color2 ) % 1000000007; 
                
        color2 = ( 5 * temp + 7 * color2 ) % 1000000007; 
    } 
      
    long num = (color3 + color2) % 1000000007; 
                         
    return (int)num;
}
