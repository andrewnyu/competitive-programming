int binary_search(vector<idx>arr, int val, int l, int r){
    //returns for position of val in vector arr
    if(r<l){
        return -1;
    }
    else{
        int mid = l + (r-l)/2;
        if(arr[mid].value==val){
            return mid;
        }
        else if(arr[mid].value<val){
            return binary_search(arr, val, mid+1, r);
        }
        else{
            return binary_search(arr, val, l, mid-1);
        }
    }
}