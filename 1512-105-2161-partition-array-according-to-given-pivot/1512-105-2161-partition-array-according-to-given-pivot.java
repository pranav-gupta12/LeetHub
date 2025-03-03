class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n_ = nums.length;
        int[] ans = new int[n_];
        int less=0;
        int equal = 0;
        for(int n : nums){
if(n<pivot)less++;
if(n==pivot)equal++;
        }
        int left = 0;
        int right = less+equal;
             for(int n : nums){
   if(n > pivot){
ans[right++] = n;
   }
   else if(n==pivot){
ans[less++]=n;
   }
   else{
    ans[left++] = n;

   }
    
        }
    return ans;
    }
}