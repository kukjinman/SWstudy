import java.io.*;
import java.util.*;

class Main {

	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		ArrayList<Integer> list = new ArrayList<>();
		
		for(int i = 0; i < n; i++)
		{
//			System.out.println("i : " + i);

			
			list.add(Integer.parseInt(br.readLine()));
		}
		
		Collections.sort(list);
		
		StringBuilder sb = new StringBuilder();

		for(int val : list)
		{
			
			sb.append(val).append('\n');

			// 하기와 같이 매번 System out을 사용하면 시간초과남
//			System.out.println(val);
			
		}
		System.out.println(sb);

	}



}
