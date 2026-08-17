class Solution {
    public List<String> summaryRanges(int[] nums) {
        ArrayList<String> al=new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            int st=nums[i];
            while(i+1<nums.length && nums[i]+1==nums[i+1])i++;
            if(st!=nums[i]){
                al.add(""+st+"->"+nums[i]);
            }
            else{
                al.add(""+st);
            }
        }
        return al;
    }
}