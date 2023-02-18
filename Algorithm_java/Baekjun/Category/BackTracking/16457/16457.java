import java.io.*;
import java.util.*;


class Main {
	
	int[][] list;
    int n;
    int m;
    int k;
    int ans = 0;
	
	void recursive(int cnt,int num, ArrayList<Integer> arr)
	{
		if(cnt >=n)
		{
			
			for(int i = 0; i<n;i++)
			{
//				System.out.print(arr.get(i) + " ");
			}
//			System.out.println();
			
			int cnt_max = 0;
			for(int i = 0; i <m;i++)
			{
				boolean cntUpflag = true;
				
				for(int j = 0; j < k;j++)
				{
					
					if(arr.contains(list[i][j]))
					{
						
					}
					else
					{
						cntUpflag = false;
					}
				}
				
				if(cntUpflag == true)
				{
					cnt_max++;
				}
				
				if(ans < cnt_max)
				{
					ans = cnt_max;
				}
				
			}
			
			
			return;
			
		}
		
		ArrayList<Integer> cur = new ArrayList<Integer>(arr);
		
		
		
		
		for(int i = num; i <= 2*n;i++)
		{
		
			cur.add(i);
			recursive(cnt+1,i+1,cur);
			cur.remove(cnt);
		}
		
		
		
	}
    
	void solve() throws Exception
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

    	list = new int[m][k];
    	
        
        for(int i = 0; i < m;i++)
        {
        	
        	st = new StringTokenizer(br.readLine());
        	        	
        	for(int j = 0; j<k;j++)
        	{
        		list[i][j] = Integer.parseInt(st.nextToken());
        	}
        }
        ArrayList<Integer> tmp = new ArrayList<Integer>();
        recursive(0,0,tmp);
        
        
        System.out.println(ans);

	}
	
	public static void main(String[] args) throws Exception {

		new Main().solve();
	}
}
