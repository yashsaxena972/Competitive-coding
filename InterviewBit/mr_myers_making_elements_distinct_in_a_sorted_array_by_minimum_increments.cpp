// Mr. Myers     or     Making elements distinct in a sorted array by minimum increments

int minSum(vector<int> A){
	int n = A.size();
	int sum = A[0];

	for(int i=1;i<n;i++){
		if(A[i] == A[i-1]){
			int j = i;
			while(j<n && A[j] <= A[j-1]){
				A[j] = A[j] + 1;
				j++;
			}
		}

		sum += A[i];
	}

	return sum;
}