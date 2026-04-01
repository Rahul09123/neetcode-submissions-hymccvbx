class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer>mp = new HashMap<>();
        for(int i = 0 ; i < nums.length;i++){
           if(mp.containsKey(nums[i])){
                mp.put(nums[i],mp.get(nums[i])+1);
           }
           else{
                mp.put(nums[i],1);
           }
        }
        PriorityQueue<Map.Entry<Integer,Integer>>pq = new PriorityQueue<>((a,b)->b.getValue() - a.getValue());
        pq.addAll(mp.entrySet());
        int[] res = new int[k];
        for(int i = 0 ; i < k ;i++){
            res[i] = pq.poll().getKey();
        }
        return res;
    }
}
