import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;


class Main {
	
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	ArrayList<Edge>[] arr;
	boolean[] visited;
	int n = 0;
	long ans = 0;
	
	class Edge{
		
		int to;
		int c;
		Edge(int to, int c)
		{
			this.to = to;
			this.c = c;
		}
	}
	
	
	void dfs(int cur, long dist) throws Exception
	{

		
		if(ans < dist)
			ans = dist;
		
//		bw.write(" ans : " + ans + "\n");
//		bw.flush();
//		
		for(int i = 0; i < arr[cur].size();i++)
		{
			
			if(visited[arr[cur].get(i).to]) continue;
			visited[arr[cur].get(i).to] = true;
			dfs(arr[cur].get(i).to, dist + arr[cur].get(i).c);
			
		}
			
			
		
	}
	
	
	void Solution() throws Exception
	{

	}
	
	void Input() throws Exception
	{
		n = Integer.parseInt(br.readLine());
		arr = new ArrayList[n+1];
		visited = new boolean[n+1];
		
		for(int i = 1; i <= n;i++)
			arr[i] = new ArrayList<>();
		
		for(int i = 1; i <n;i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			arr[a].add(new Edge(b,c));
			arr[b].add(new Edge(a,c));
//			bw.write("[] : " + a + " " + b + " " + c + "\n");
		}
//		bw.flush();
		
		visited[1] = true;
		dfs(1,0);
		bw.write(ans + "\n");
		bw.flush();
		
	}
	
	public static void main(String[] args) throws Exception {
		
		new Main().Input();
//		new Main().Solution();
	
	
	}
}