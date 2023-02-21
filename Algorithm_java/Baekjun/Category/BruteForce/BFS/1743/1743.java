import java.io.*;
import java.util.*;

class Main {

	int n,m,k;
	int[][] map;
	boolean[][] visited;
	int[] dy = {0,0,-1,1};
	int[] dx = {-1,1,0,0};
	
	class Node {
		
		int y;
		int x;
		
		Node(int y, int x)
		{
			this.y = y;
			this.x = x;
		}
		
	}
	
	int bfs(int y , int x)
	{
		int ret = 0;
		Queue<Node> q = new LinkedList<Node>();	
		q.offer(new Node(y,x));
		visited[y][x] = true;
		ret++;
		
		while(!q.isEmpty())
		{
			Node cur = q.poll();
			
			// System.out.println("y : " + cur.y + " x : " + cur.x);
		
			for(int i = 0 ; i < 4;i++)
			{
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];
				
				if(ny< 1|| ny>n || nx <1 || nx > m) continue;
				if(visited[ny][nx] == true) continue;
				
				if(map[ny][nx] == 1)
				{
					ret++;
					q.offer(new Node(ny,nx));
					visited[ny][nx] = true;
				}
			
			}
		
		}
		
		return ret;
	}
	
	void solve() throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		map = new int[n+1][m+1];
		visited = new boolean[n+1][m+1];
		
		for(int i = 0; i < k;i++)
		{
			st = new StringTokenizer(br.readLine());
			int y = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			
			map[y][x] = 1;
		}
		
	
		int max = 0;
		for(int i = 1; i <= n;i++)
		{
			for(int j = 1; j <= m;j++)
			{
				if(map[i][j] == 1)
				{
					
					int res = bfs(i,j);
					
					if(res> max)
					{
						max = res;
					}
				}
			}
		}
	
		System.out.println(max);
		
		
	}
	
	
	public static void main(String[] args) throws Exception {

		new	Main().solve();
		
	}
}