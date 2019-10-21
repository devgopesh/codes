// Thumb rule of backtracking problem :

// choose an option
// explore it
// unchoose the last selected option
// explore
// repeat above cycle until we run out of options.

// Ques- Given a set of distinct integers, S, return all possible subsets.4

function(int[] A,ArrayList temp,ArrayList<ArrayList> output, int index)
{
if(index == A.length)
{
// no more elements to choose/ unchoose from the set , we have reached termination condition , add temp to output as it is one of the subset 
output.add(new ArrayList(temp);
}
else // if current index is valid index 
{ 
// we have two options ::
// include the current index element in our subset : 
temp.add(A[i]); // 1.choose
function(A,index+1,temp,output); //2. explore

// exclude the current index element ( by removing the last element added ) from our set 
temp.remove(temp.size()-1); //3. unchoose

function(A,index+1,temp,output); //4. explore
}