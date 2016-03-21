#include<stdlib.h>

static int max(int a, int b) {
    return a > b ? a : b;
}
static int min(int a, int b) {
    return a < b ? a : b;
}

static double findkth(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    if (nums1Size > nums2Size)
        return findkth(nums2, nums2Size, nums1, nums1Size, k);

    if(nums1Size == 0)
        return nums2[k - 1];
    
    if(k == 1)
        return min(*nums1, *nums2);
        
    int pos1 = min(k / 2, nums1Size);
    int pos2 = k - pos1;
    
    int val1 = *(nums1 + pos1 -1);
    int val2 = *(nums2 + pos2 -1);
    
    if(val1 < val2)
        return findkth(nums1 + pos1, nums1Size - pos1, nums2, nums2Size, k - pos1);
    
    if(val1 > val2)
        return findkth(nums1, nums1Size, nums2 + pos2, nums2Size - pos2, k - pos2);

    return val1;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size + nums2Size;

    if (n % 2 == 1)
        return findkth(nums1, nums1Size, nums2, nums2Size, n / 2 + 1);

    int val1 = findkth(nums1, nums1Size, nums2, nums2Size, n / 2);
    int val2 = findkth(nums1, nums1Size, nums2, nums2Size, n / 2 + 1);

    double c = ((double)val1 + (double)val2) / 2;
    return c;
}
