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

			// �ϱ�� ���� �Ź� System out�� ����ϸ� �ð��ʰ���
//			System.out.println(val);
			
		}
		System.out.println(sb);

	}



}
