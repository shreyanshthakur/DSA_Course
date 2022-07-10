int binarySearch (int arr[], int s, int e, int k) {
    //base case
    int mid = s + (e-s)/2;
    if (arr[mid] == k)
        return mid;
    if (s > e) 
        return -1;
    if (arr[mid] < k)
        return binarySearch(arr, mid+1, e, k);
    else
        return binarySearch(arr, s, mid-1, k);
}

int binarySearch(int *input, int n, int val)
{
    //Write your code here
    int s = 0;
    int e = n -1;
    return binarySearch(input, s, e, val);
}