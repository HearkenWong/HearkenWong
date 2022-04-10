class Solution {
    public boolean isPowerOfThree(int n) {
        for(int x=0;x<=31;x++){
            if((long)Math.pow(3,x)==n){
                return true;
            }
        }
        return false;
    }
}
