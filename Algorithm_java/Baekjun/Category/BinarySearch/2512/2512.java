import java.io.*;
import java.util.*;
import java.math.*;

class Main {
	
	int n;
	int[] area;
	
	// 정답이 될 최대값의 정수
	int ans = 0;
	
	
	void binary_search(int budget)
	{		
		
		int s = 0;
		//최대의 값은 예산을 넘을 수 없음으로 예산값으로 정함
		int e = budget;
		
		while(s<= e)
		{
			int mid = (s+e)/2;
			
			//mid 값이 구하고 싶은 최대 정수값이므로
			//mid 값이 각각의 area의 최대액이 되는지 확인하고
			//예산이 넘는지 확인한다
			
			int tmp_sum = 0;
			for(int i = 0;i<n;i++)
			{
				if(area[i] <= mid)
				{
					tmp_sum += area[i];
				}
				else
				{
					tmp_sum += mid;
				}
				
				
			}
			System.out.println("tmp_sum : " + tmp_sum);
			System.out.println("s : " + s + " e : " + e + " mid : " + mid);
//
//			
			//tmp_sum == budget이 같을때 해당 mid값을 ans로 처리해버리고
			//while을 종료시켜버리면
			//이진탐색을 끝까지 탐색하지 않고 끝나게됨.
			//이진탐색은 while의 조건이 탈출되도록 만들어야 완전탐색이 가능함
			// 
			
			
			if(tmp_sum > budget)
			{
				//예산을 넘을 시 e = mid - 1
				e = mid - 1;
				ans = e;
				
			}
			else
			{
				//예산을 안넘을 시 s = mid + 1
				s = mid + 1;
			}
			
		}
		
		//만약에 이진 탐색에서의 어떠한 mid정수를 하여도 예산을 넘지 않는경우는
		//ans가 0으로 나온다.
		//이런경우 area의 값중 가장 큰값을 최대정수로 하여
		//최대액이 깍이지 않는 최대정수값으로 둔다
		if(ans == 0)
		ans = Arrays.stream(area).max().getAsInt();
		
		
		
	}
	
	
	
	void solve() throws Exception
	{
		
		// Input
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());

		// 
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		// n개의 지방이 들어갈 int array
		area = new int[n];
		
		
		for(int i = 0; i < n; i++)
		{
			area[i] = Integer.parseInt(st.nextToken());
		}
		
		int m = Integer.parseInt(br.readLine());
		
		// input -- end
		
		// 주어진 예산에서 최대값을 가질 수 있는 정수를 찾기 위한 문제이므로
		// 이진탐색으로 주어진 예산을 넘지 않는 최대를 찾도록 한다.
		
		binary_search(m);
		
		System.out.println(ans);
		
	}
	
	
	public static void main(String[] args) throws Exception {
		
		new Main().solve();
	}
}