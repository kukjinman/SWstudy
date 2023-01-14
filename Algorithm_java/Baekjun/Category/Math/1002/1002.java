import java.io.*;
import java.util.*;

class Main {

	
	int n;
	int ans = -1;

	
	void solve() throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < n;i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x1,y1,r1;
			int x2,y2,r2;
			
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());
			r1 = Integer.parseInt(st.nextToken());
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());
			r2 = Integer.parseInt(st.nextToken());
			
			int dist = (y1 - y2) * (y1 -y2) + (x1 - x2) * (x1 - x2);
//			System.out.println("dist " + dist);

			
			if(dist == 0)
			{
				if(r1 == r2)
				{
					// 두 원이 똑같은 위치 똑같은 크기
					// 원주 어디에든 존재할 수있음 무한대로
					
//					System.out.println("case 1");

					System.out.println(-1);
				}
				else
				{
					// 두 원이 같은 위치에 있으나
					// r1 r2가 달라 류재명이 존재 할 수 없음
//					System.out.println("case 2");

					
					System.out.println(0);
						
				}
				
				
			}
			else if( dist == ((r1+r2) * (r1 + r2)) || dist == (r1-r2) * (r1-r2))
			{
//				System.out.println("case 3");

				System.out.println(1);

			}
			else if( dist > ((r1+ r2) * (r1 + r2)) || dist < (r1-r2) * (r1-r2))
			{
//				System.out.println("case 4");

				System.out.println(0);

			}
			else
			{
				System.out.println(2);

			}
			
					
					
					
			
			
		}
		
	}
	
	public static void main(String[] args) throws Exception {

		new Main().solve();
	}
}