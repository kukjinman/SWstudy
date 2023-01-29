import java.io.*;
import java.util.*;


// java에서 println을 많이 사용하면 시간초과가 발생한다
// String Builder로 무조건 "\n"넣어서 사용하도록 할 것
// 

class Main {
	
	static int[] note_f;
	static int[] note_s;
	
	
	
	static boolean binary_search(int f_size, int target)
	{
		boolean ret = false;
		
		int s = 0;
		int e = f_size -1;
		
		while(s<=e)
		{
			int mid = (s + e )/2;
//			System.out.println(mid + " s " + s + " e " + e );

			if(target < note_f[mid])
			{
				e = mid-1;
			}
			else if(target > note_f[mid])
			{
				s = mid +1;
			}
			else
			{
				ret = true;
				return ret;
			}
			
			
		}
		
		
		return ret;
	}
	
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		

		for(int i = 0; i < t;i++)
		{
			
            StringBuilder sb = new StringBuilder();

			
			
			int firstNote = Integer.parseInt(br.readLine());
			note_f = new int[firstNote];
			StringTokenizer st = new StringTokenizer(br.readLine());

			for(int j = 0; j < firstNote;j++)
			{
				note_f[j] = Integer.parseInt(st.nextToken());
				
			}

			Arrays.sort(note_f);
			
			int secondNote = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());

			for(int j = 0; j < secondNote;j++)
			{
				int num = Integer.parseInt(st.nextToken());
			
				boolean ans = binary_search(firstNote,num);
				sb.append(ans?1:0).append("\n");
				
			}

			System.out.print(sb);

		}
		
		
	}
}