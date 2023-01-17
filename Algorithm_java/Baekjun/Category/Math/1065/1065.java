import java.io.*;
import java.util.*;


class Main {
	
	int n = 0;
	
	void solve() throws Exception
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n =Integer.parseInt(br.readLine());
        int res = 0;
        if(n < 100)
        {
        	res = n;
//        	System.out.println(n);
        }
        else
        {
        	res= 99;
        	for(int i = 100; i <= n;i++)
        	{
            	int h = i / 100;
            	int t = (i/10)% 10;
            	int o = i % 10;
            	
            	
//            	System.out.println(" h : " + h + " t : "  + t + " o : " + o);
            	if(h - t == t - o)
            	{
            		res++;
            	}
        		
        	}
        	
        	
        	
        	
        }
        
        System.out.println(res);
	
	}
	
	public static void main(String[] args) throws Exception {

		new Main().solve();
	}
}