class Solution {
    public int reverse(int x){
        long i,digit,sum=0;
        if(x<0){
            x = Math.abs(x);
            while(x>0){
                digit=x%10;
                x=x/10;
                sum=sum*10+digit;
            }
            sum=sum*-1;
        }
        else if(x>0){
            while(x>0){
                digit=x%10;
                x=x/10;
                sum=sum*10+digit;
            }
        }

        if(sum<Integer.MIN_VALUE || sum>Integer.MAX_VALUE)
        return 0;

        return (int)sum;
    }
}