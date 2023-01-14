import java.io.*;
import java.util.*;

class Main {

	int[][] map;
	boolean[][] visited;
	
	int n;
	int m;
	int ans = 1;

	void printer()
	{
		for(int i = 0; i< n;i++)
		{
			for(int j = 0; j < m;j++)
			{
				
				System.out.print(map[i][j]);

				
			}
			
			System.out.println();
			
		}
		
	}
	
	
	void finder(int y,int x) throws Exception
	{
		int cnt = 1;
		int val = map[y][x];
		
		while(y + cnt < n && x + cnt < m)
		{
			
			if(val == map[y+cnt][x] && val == map[y][x+cnt] && val == map[y+cnt][x+cnt])
			{
				
//				System.out.println(" y : " + y + " x : " + x);

				
//				System.out.println(" cnt : " + cnt);
				if(ans < (cnt+1) * (cnt+1))
				{
					ans = (cnt+1) * (cnt+1);
				}
				
			}
			else
			{
			}
			
			cnt++;

		}
		
	}
	
	
	void solve() throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		visited = new boolean[n][m];
		for(int i = 0; i< n;i++)
		{
			
			String str = br.readLine();
			for(int j = 0; j < m;j++)
			{
				
				map[i][j] = str.charAt(j) - '0';
			}
			
		}
		
		for(int i = 0; i< n;i++)
		{
			
			for(int j = 0; j < m;j++)
			{
				finder(i,j);
			}
			
		}
		
		
		
		
		
		System.out.println(ans);
	}
	
	
	
	
	
	
	public static void main(String[] args) throws Exception {

		new Main().solve();
	}
}