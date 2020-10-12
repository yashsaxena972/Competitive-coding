// Angry Professor
/*

A Discrete Mathematics professor has a class of students. Frustrated with their lack of 
discipline, he decides to cancel class if fewer than some number of students are present 
when class starts. Arrival times go from on time () to arrived late ().

Given the arrival time of each student and a threshhold number of attendees, determine if 
the class is canceled.

*/

// Complete the angryProfessor function below.
string angryProfessor(int k, vector<int> a) {
    int n = a.size();
    while(n--){
        if(a[n] <= 0){
            k--;
        }
    }

    if(k <= 0){
        return "NO";
    }
    else{
        return "YES";
    }
}