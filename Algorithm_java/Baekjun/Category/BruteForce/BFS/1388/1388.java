import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;


public class Main {

	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	
	int[] dy = new int[] {1,0};
	int[] dx = new int[] {0,1};

	int n = 0;
	int m = 0;
	int cnt = 0;

	
	void printer(boolean[][] visited_ , int n_, int m_) throws Exception
	{
		
		for(int i = 0; i < n_; i++)
		{
			
			String str = new String();
			for(int j = 0; j < m_; j++)
			{

				
				str += visited_[i][j];
				str += " ";

				
			}
			bw.write(str);
			bw.write("\n");
			bw.flush();
		}
		
	}
	
	
	void solution() throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		char[][] arr = new char[n][m];
		boolean[][] visited = new boolean[n][m];
		
		Queue<Node> q = new LinkedList<>();

		for(int i = 0; i < n; i++)
		{
			String row = br.readLine();
			for(int j = 0; j < m;j++)
			{
				arr[i][j] = row.charAt(j);
			}
		}
		
//		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//		bw.write(n + " " + m);
//		bw.flush();

//		printer(visited,n,m);
		
		for(int i = 0; i < n;i++)
		{
			
			for(int j = 0; j < m;j++)
			{
				
				if(visited[i][j] != true)
				{
					q.add(new Node(j,i));
					visited[i][j] = true;
					char cur_bar = arr[i][j];
//					bw.write("i : " + i + " j : " + j + "\n");
//					bw.flush();
					cnt++;
					
					
					
					while(!q.isEmpty())
					{
						int x = q.element().x;
						int y = q.element().y;
						q.remove();
						
						if(cur_bar == '|')
						{
							int nx = x;
							int ny = y + 1;
							if(nx>= m || nx<0 || ny>=n || nx < 0) continue;
							
							if(arr[ny][nx] != '|') break;
							
							q.add(new Node(nx,ny));
							visited[ny][nx] = true;
							
						}
						else
						{
							int nx = x + 1;
							int ny = y ;
							if(nx>= m || nx<0 || ny>=n || nx < 0) continue;
							
							if(arr[ny][nx] != '-') break;
							
							q.add(new Node(nx,ny));
							visited[ny][nx] = true;
							
							
						}
						
					}
					
					
					
				}
				else
					
				{
//					bw.write("[] i : " + i + " j : " + j + "\n");

				}
				
				
				
			}
			
			
			
		}
		
		bw.write(cnt + "\n");
		bw.flush();
		
		
	}
	
	public static void main(String[] args) throws Exception
	{
		new Main().solution();
		
	}
	
	class Node
	{
		int x;
		int y;
		
		Node(int x,int y)
		{
			this.x = x;
			this.y = y;
		}
	}
	
}
