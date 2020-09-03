// Smallest sequence with given Primes
/*

GIven three prime numbers A, B and C and an integer D.

You need to find the first(smallest) D integers which only have A, B, C or a combination of them as their prime factors.

Example Input
Input 1:

 A = 2
 B = 3
 C = 5
 D = 5


Example Output
Output 1:

 [2, 3, 4, 5, 6]


Example Explanation
Explanation 1:

 4 = A * A i.e ( 2 * 2 ) 
 6 = A * B i.e ( 2 * 3 )

*/

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> numbers;
    
    if(D==0)
        return numbers;
    
    set<int> st;
    st.insert(A);
    st.insert(B);
    st.insert(C);
    
    while(!st.empty()) {
        int curr = *st.begin();
        st.erase(st.begin());
        numbers.push_back(curr);
        if(numbers.size()==D)
            break;
        int p1 = curr*A;
        int p2 = curr*B;
        int p3 = curr*C;
        st.insert(p1);
        st.insert(p2);
        st.insert(p3);
    }
    return numbers;
}
