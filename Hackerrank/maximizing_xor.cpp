// Maximizing XOR
/*

Given two integers,  and , find the maximal value of  xor , 
written , where  and  satisfy the following condition:

For example, if  and , then

Our maximum value is .

*/

// Complete the maximizingXor function below.
int maximizingXor(int l, int r) {
    int max = 0;
    for(int i=l;i<=r;i++){
        for(int j=i;j<=r;j++){
            int xr = j^i;
            if(xr>max){
                max = xr;
            }
        }
    }

    return max;
}