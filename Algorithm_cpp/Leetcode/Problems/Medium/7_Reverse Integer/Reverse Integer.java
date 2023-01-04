public class Solution
{
	public final int reverse(int n)
	{
		boolean neg = n < 0;
		n = Math.abs(n);

		int ans = 0;
		int temp;
		while (n > 0)
		{
			temp = n % 10;


			if ((double)Integer.MAX_VALUE / ans <= 10.0)
			{
                //This returns for the 1534236469 case which cause overflow of int
                //Test cese and Question does not mention what to provide for the overflow case.
				return 0;
			}
			ans *= 10;
			ans += temp;
			n /= 10;
		}

		if (!neg)
		{
		return ans;
		}
		return ans * -1;
	}
}