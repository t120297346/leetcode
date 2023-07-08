double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int total = nums1Size + nums2Size;
    int* tmp = malloc(sizeof(int) * total);
    memset(tmp, 0, sizeof(int) * total);

    int index = 0, first = 0, second = 0;
    while (first < nums1Size && second < nums2Size) {

        if (nums1[first] <= nums2[second]) {
            tmp[index] = nums1[first];
            first++;
        } else if (nums1[first] > nums2[second]) {
            tmp[index] = nums2[second];
            second++;
        }
        index++;
    }

    while (first < nums1Size) {
        tmp[index] = nums1[first];
        first++;
        index++;
    }

    while (second < nums2Size) {
        tmp[index] = nums2[second];
        second++;
        index++;
    }
    
    if (total % 2 != 0) {
        return (double)tmp[total / 2];
    } else {
        return (double)(tmp[total / 2 - 1] + tmp[total / 2]) / 2;
    }
}
