public class Solution {
    public bool can(int h, int mid, int[] piles){
        long ans = 0;
        foreach(int x in piles) ans += (x + mid - 1) / mid;
        return ans <= h;
    }
    public int sol(int left, int right, int h, int[] piles){
        int mid = left + (right - left) / 2;
        while(left < right){
            if(can(h, mid, piles)) right = mid;
            else left = mid + 1;
            mid = left + (right - left) / 2;
        }
        return right;
    }
    public int MinEatingSpeed(int[] piles, int h) {
        int left = 1;
        int right = piles.Max();
        return sol(left, right, h, piles);
    }
}
