bool checkSorted(vector<int>& arr) {
    int count=0;
    for(int i=0; i<arr.size(); ){
        if(arr[i] != i+1){
            swap(arr[i], arr[arr[i]-1]);
            count++;
        }else{
            i++;
        }
    }
    if(count==2 || count == 0){
        return true;
    }
    return false;
}