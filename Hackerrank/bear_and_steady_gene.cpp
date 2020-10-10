// Bear and Steady Gene
/*

A gene is represented as a string of length N (where  is divisible by 4), 
composed of the letters A, C, G, and T. It is considered to be steady if 
each of the four letters occurs exactly 1/4 times. For example, GACT and AAGGCCTT are both steady genes.

*/

// Complete the steadyGene function below.
int steadyGene(string gene) {
    int cnt[128] = {0};
    int n = gene.length();
    int i=0,j=n-1,minL = n;

    while(1){
        if(j<0 || cnt[gene[j]]==n/4){
            j++;
            break;
        }
        else{
            cnt[gene[j]]++;
            j--;
        }
    }
    if(j<minL){
        minL = j;
    }
    for(i=0;i<n;i++){
        cnt[gene[i]]++;
        while(j<n && cnt[gene[i]] > n/4){
            cnt[gene[j]]--;
            j++;
        }
        if(j == n){
            break;
        }
        if(j-i-1 < minL){
            minL = j-i-1;
        }
    }

    return minL;
}