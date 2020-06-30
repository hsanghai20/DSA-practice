// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array
// also consider nums1 have space n+m

// method-1 (Not good)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=0;i<m;i++)
        {
            swap(nums1[m-i-1],nums1[m+n-i-1]);
        }
        int upptr=n;
        int lowptr=0;
        int ansptr=0;
        while(ansptr<m+n && lowptr<n && upptr<m+n)
        {
            if(nums1[upptr]>=nums2[lowptr])
                nums1[ansptr++]=nums2[lowptr++];
            else
                nums1[ansptr++]=nums1[upptr++];
        }
        for (int i=lowptr;i<n;i++)
            nums1[ansptr++]=nums2[i];
        for (int i=upptr;i<m;i++)
            nums1[ansptr++]=nums1[i];
    }


    // second method to merge oppositely and after lower array get finished then dont do anything
    int upptr=m-1,lowptr=n-1,ansptr=m+n-1;
        while(lowptr>=0)
        {
            if(upptr>=0 && nums1[upptr]>nums2[lowptr])
                nums1[ansptr--]=nums1[upptr--];
            else
                nums1[ansptr--]=nums2[lowptr--];
        }