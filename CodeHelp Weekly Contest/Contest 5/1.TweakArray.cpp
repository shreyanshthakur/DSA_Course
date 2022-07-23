vector<int> tweakTheArray(vector<int> arr, int n){
    int totalSum = 0;
    
    //step 1: calculate TotalSum
    for(int i = 0; i < n; i++) {
        totalSum += arr[i];
    }
    //step 2: write a loop and subtract the ith element from TotalSum
    for (int i = 0; i < n; i++) {
        arr[i] = totalSum - arr[i];
    }
    //step 3: return ans vector
    return arr;
}