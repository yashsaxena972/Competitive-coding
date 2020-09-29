// New Year Chaos
/*

It's New Year's Day and everyone's in line for the Wonderland rollercoaster ride! 
There are a number of people queued up, and each person wears a sticker indicating 
their initial position in the queue. Initial positions increment by  from  at the 
front of the line to  at the back.

Any person in the queue can bribe the person directly in front of them to swap positions. 
If two people swap positions, they still wear the same sticker denoting their original 
places in line. One person can bribe at most two others. For example, if  and  bribes , 
the queue will look like this: .

Fascinated by this chaotic queue, you decide you must know the minimum number of bribes 
that took place to get the queue into its current state!

*/

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    bool chaotic = false;
    int bribes = 0;

    for(int i=0;i<q.size();i++){
        if(q[i]-(i+1) > 2){
            chaotic = true;
        }
        for(int j=q[i]-2;j<i;j++){
            if(q[j] > q[i]){
                bribes++;
            }
        }
    }

    if(chaotic == true){
        cout<<"Too chaotic"<<endl;
    }
    else{
        cout<<bribes<<endl;
    }
}