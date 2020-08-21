// Pretty JSON

vector<string> Solution::prettyJSON(string A) {
    vector<string> ans;
    int tabs=0;
    string temp="";
    
    for(int i=0;i<A.length();i++){
        if(A[i] == ' '){
            continue;
        }
        
        else if(A[i]=='{' || A[i]=='['){
            if(temp!=""){
                ans.push_back(temp);
            }
            temp="";
       
            for(int k=0;k<tabs;k++){
                temp+="\t";    
            }
            
            temp+=A[i];
            ans.push_back(temp);
            temp="";
            tabs++;
        }

        else if(A[i]=='}' || A[i]==']'){
            if(temp!=""){
                ans.push_back(temp);
            }
            temp="";
            for(int k=0;k<tabs-1;k++){
                temp+="\t";    
            }
            
            temp+=A[i];
            if(i<A.length() && A[i+1]==','){
                temp+=A[++i];
            }
            ans.push_back(temp);
            temp="";
            tabs--;
        }

        else{
            if(temp==""){
                for(int k=0;k<tabs;k++){
                    temp+="\t";    
                }
            }
            temp+=A[i];
            if(A[i]==','){
                ans.push_back(temp);
                temp="";
            }
        }
    }
    return ans;
}
