import java.io.*;
import java.util.*;

class Main {

	
	int n;
	int ans = -1;

	
	/*
	 * �ּ��� ������ �� �� ���̸� ������ ���� ��ġ�� ���� ���Ϸ���
	 * �ܼ��� �ش� ������ �� �ȿ� ���ӵǾ��ִ����� �Ǵ��ϸ� �ȴ�.
	 * 
	 * ���ܷ� �� ���� ���� ���� �ִ� �κ��� ������� 
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
					// �ΰ��� ���� �ѿ��� �ִ°��
				}
				else if(dot1flag == false && dot2flag == false)
				{
					// �ΰ��� ���� ��� ������ ������ ���� ���
				}
				else
				{
					// �ΰ��� ���� �ٸ����� �ִ°��
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