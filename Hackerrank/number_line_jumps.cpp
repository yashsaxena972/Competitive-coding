// Number Line Jumps
/*

You are choreographing a circus show with various animals. For one act, you are 
given two kangaroos on a number line ready to jump in the positive direction (i.e, 
toward positive infinity).

The first kangaroo starts at location  and moves at a rate of  meters per jump.
The second kangaroo starts at location  and moves at a rate of  meters per jump.
You have to figure out a way to get both kangaroos at the same location at the same 
time as part of the show. If it is possible, return YES, otherwise return NO.

For example, kangaroo  starts at  with a jump distance  and kangaroo  starts at  with 
a jump distance of . After one jump, they are both at , (, ), so our answer is YES.

*/

// Complete the kangaroo function below.
string kangaroo(int x1, int v1, int x2, int v2) {
    if(x1 > x2 && v1 > v2){
        return "NO";
    }
    else if(x1 <x2 && v1 <v2){
        return "NO";
    }

    if(v1 == v2){
        return "NO";
    }

    if(((x2-x1)%(v1-v2) == 0) || ((x2-x1)%(v2-v1) == 0))
        return "YES";
    else
        return "NO";    
}