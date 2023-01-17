import java.io.*;
import java.util.*;

class Main {

	
	int n;
	int ans = -1;

	
	/*
	 * 최소의 값으로 두 점 사이를 지날때 원을 거치는 값을 구하려면
	 * 단순히 해당 점들이 원 안에 구속되어있는지만 판단하면 된다.
	 * 
	 * 예외로 두 점이 같은 원에 있는 부분은 빼줘야함 
	 * 
	 */
	
	void solve() throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int i = 0; i <T;i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x1,y1;
			int x2,y2;
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());
			
			int n = Integer.parseInt(br.readLine());
			
			int ans = 0;
//			System.out.println("n : "  + n );

			for(int j = 0; j<n;j++)
			{
				int cx,cy,r;
				st = new StringTokenizer(br.readLine());
				cx = Integer.parseInt(st.nextToken());
				cy = Integer.parseInt(st.nextToken());
				r = Integer.parseInt(st.nextToken());
				
				boolean dot1flag , dot2flag;
				dot1flag = false;
				dot2flag = false;
				//check dot 1
				int dist = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
				
				if(dist > r * r)
				{
//					System.out.println("1]not in the circle");
				}
				else
				{
//					System.out.println("1]In the circle");
					dot1flag = true;
				}
				
				//check dot 1
				int dist2 = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);
				
				if(dist2 > r * r)
				{
//					System.out.println("2]not in the circle");

				}
				else
				{
//					System.out.println("2]In the circle");

					dot2flag = true;
					
				}
				
				if(dot1flag == true && dot2flag == true)
				{
					// 두개의 점이 한원에 있는경우
				}
				else if(dot1flag == false && dot2flag == false)
				{
					// 두개의 점이 어느 원에도 속하지 않은 경우
				}
				else
				{
					// 두개의 점이 다른원에 있는경우
					ans++;
				}

			}
			System.out.println(ans);
//			System.out.println("===========================================");

		}
		
		
		
		
	}
	
	public static void main(String[] args) throws Exception {

		new Main().solve();
	}
}