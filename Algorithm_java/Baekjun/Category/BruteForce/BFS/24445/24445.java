import java.io.*;
import java.util.*;


public class Main {
	
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int n, m, r;
	// int[][] 대신 ArrayList<Integer>[]를 사용해야 동적으로 할당되는 요소들의 size를 
	// for loop 돌릴 수 있다. 
	ArrayList<Integer>[] arr;
	int[] ans;

	boolean[] v;
	Queue<Integer> q = new LinkedList<Integer>();
	
	void printer()
	{
		System.out.println("==start==");

		for(int i = 1; i <=n;i++)
		{
			for(int j = 0; j<arr[i].size();j++) {
				System.out.println(i + " : " + arr[i].get(j));
			}
		}
		System.out.println("==end==");

	}

	
	int cnt = 1;
	void bfs(int r_)
	{	
		
		q.add(r_);
		v[r_] = true;
		ans[r_] = cnt;
		cnt++;
		
		while(!q.isEmpty())
		{
			int cur = q.element();
			q.poll();
			for(int i = 0; i < arr[cur].size();i++)
			{
			
				if(v[arr[cur].get(i)] == true) continue;
				
				v[arr[cur].get(i)] = true;
				ans[arr[cur].get(i)] = cnt;
				cnt++;
				q.add(arr[cur].get(i));
				
			}
			
		}
		
		
	}
	
	void Solve() throws Exception
	{
		
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken()); 
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
			
		arr = new ArrayList[n+1];
		ans = new int[n+1];
		v = new boolean[n+1];
	
		for(int i = 1;i <= n;i++)
		{
			arr[i] = new ArrayList<>();
		}

		
		for(int i = 1;i<= m;i++)
		{
			st = new StringTokenizer(br.readLine());
			int i_from = Integer.parseInt(st.nextToken());
			int i_to = Integer.parseInt(st.nextToken());
			
			arr[i_from].add(i_to);
			arr[i_to].add(i_from);
			
		}
		
		
//		printer();

		for(int i = 1; i <=n;i++)
		{
			Collections.sort(arr[i],Collections.reverseOrder());
		}
		
//		printer();
		
		bfs(r);
		
		for(int i =1; i <= n;i++)
		{
			
			System.out.println(ans[i]);

		}
	}
	
	
	
	
	public static void main(String[] args) throws Exception {
		
		new Main().Solve();
		
		
		
//		System.out.println("Hello Goorm! Your input is " + input);
	}
}