import java.io.*;
import java.util.*;



// 진짜 더러운 문제다. 할게 많다.
class Main {
	
	int n = 0;
	
	void solve() throws Exception
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        
        List<String> list = new ArrayList<>();
        
        String ans = "";
        
        for(int i = 0; i < n;i++)
        {
        	list.add(br.readLine());
        	
        }
        
        ans = list.get(0);
        
//        System.out.println(ans);
        for(int i = 1; i < n;i++)
        {
        	
        	
        	for(int j = 0; j < list.get(0).length();j++)
        	{
        		if(list.get(i).charAt(j) != list.get(0).charAt(j))
        		{
        			ans = ans.substring(0,j) + '?' + ans.substring(j +1);
        		}
        		
        	}
        	
        }
        
        
    	System.out.println(ans);

        
        
        
	}
	
	public static void main(String[] args) throws Exception {

		new Main().solve();
	}
}