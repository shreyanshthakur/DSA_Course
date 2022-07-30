int tileCleaning(int n, int k){
    //left jao
    if ((k-1) < (n-k)) 
        return 2*(k-1) + (n-k);
        
    //right jao
    else {
        return 2*(n-k) + (k-1);
    }
}