@Test
public void testMaxNum() {
   
//  int[] nums = {12, 121};  错误
    int[] nums = {12, 123};
    String result = maxNum(nums);
    System.out.println("组成最大整数:" + result);
}
 
public String maxNum(int[] nums) {
    String result = "";
    for (int i = 0; i < nums.length; i++) {
        String num1 = nums[i] + "";
        for (int j = 1; j < nums.length; j++) {
            String num2 = nums[j] + "";
            if ((num1 + num2).compareTo(num2 + num1) < 0) {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
    }
    for (int i = 0; i < nums.length; i++) {
        result += nums[i];
    }
    return result;
}
