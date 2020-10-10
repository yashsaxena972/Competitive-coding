// Bigger is Greater   or   Lexicographically next permutation of string

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {

    bool val = next_permutation(w.begin(),w.end()); 
    if(val == false){
        return "no answer";
    }
    return w;
}