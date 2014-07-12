

struct triple {
    int max_left;
    int max_right;
    int lr_sum;
};

triple findMaxCrossingSubarray (vector<int> ar, int low, int mid, int high) {
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int sum;
    int max_left, max_right;
    triple result;
    
    sum = 0;
    for (int i = mid; i >= low; i--) {
        sum = sum + ar[i];
        if (sum > left_sum) {
            left_sum = sum;
            result.max_left = i;
        }
    }
    
    sum = 0;
    for (int i = mid+1; i <= high; i++) {
        sum = sum + ar[i];
        if (sum > right_sum) {
            right_sum = sum;
            result.max_right = i;
        }
    }
    result.lr_sum = left_sum + right_sum;
    return result;
}

triple findMaximumSubarray (vector<int> ar, int low, int high) {
    triple base, left, right, cross;
    base.max_left = low;
    base.max_right = high;
    base.lr_sum = ar[low];
    
    int mid;
    if (high == low){
        return base;
    } else {
        mid = floor((low+high)/2);
        left = findMaximumSubarray(ar, low, mid, sum);
        right = findMaximumSubarray(ar, mid+1, high, sum);
        cross = findMaxCrossingSubarray(ar, low, mid, high);
        if (left.lr_sum < 0) left.lr_sum = 0;
        if (right.lr_sum < 0) right.lr_sum = 0;
        if (cross.lr_sum < 0) cross.lr_sum = 0;
        if (left.lr_sum >= right.lr_sum && left.lr_sum >= cross.lr_sum)
            return left;
        else if (right.lr_sum >= left.lr_sum && right.lr_sum >= cross.lr_sum)
            return right;
        else
            return cross;
    }   
}
