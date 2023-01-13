import java.io.*;
import java.util.*;
import java.math.BigInteger;



/*
 * n = 1           1
 * n = 2          1 1
 * n = 3         1 2 1 
 * n = 4        1 3 3 1
 * n = 5       1 4 6 4 1
 * n = 6     1 5 10 10 5 1
*/


class Main {
	
	static int[][] dp = new int[11][11];
		
	
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        
        for(int i = 0; i <=n; i++)
        {
        	for(int j = 0; j <= i; j++)
        	{
        		if(j == 0 || j== i) dp[i][j] =1;
        		else
        		{
        			dp[i][j] = dp[i -1][j -1] + dp[i -1][j];
        		}
        	}
        	
        	
        	
        }
        
        System.out.println(dp[n][k]);
        
	}
}