import java.io.*;
import java.util.*;
import java.math.*;

class Main {
	
	int n;
	int[] area;
	
	// ������ �� �ִ밪�� ����
	int ans = 0;
	
	
	void binary_search(int budget)
	{		
		
		int s = 0;
		//�ִ��� ���� ������ ���� �� �������� ���갪���� ����
		int e = budget;
		
		while(s<= e)
		{
			int mid = (s+e)/2;
			
			//mid ���� ���ϰ� ���� �ִ� �������̹Ƿ�
			//mid ���� ������ area�� �ִ���� �Ǵ��� Ȯ���ϰ�
			//������ �Ѵ��� Ȯ���Ѵ�
			
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
			//tmp_sum == budget�� ������ �ش� mid���� ans�� ó���ع�����
			//while�� ������ѹ�����
			//����Ž���� ������ Ž������ �ʰ� �����Ե�.
			//����Ž���� while�� ������ Ż��ǵ��� ������ ����Ž���� ������
			// 
			
			
			if(tmp_sum > budget)
			{
				//������ ���� �� e = mid - 1
				e = mid - 1;
				ans = e;
				
			}
			else
			{
				//������ �ȳ��� �� s = mid + 1
				s = mid + 1;
			}
			
		}
		
		//���࿡ ���� Ž�������� ��� mid������ �Ͽ��� ������ ���� �ʴ°���
		//ans�� 0���� ���´�.
		//�̷���� area�� ���� ���� ū���� �ִ������� �Ͽ�
		//�ִ���� ������ �ʴ� �ִ����������� �д�
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
		
		// n���� ������ �� int array
		area = new int[n];
		
		
		for(int i = 0; i < n; i++)
		{
			area[i] = Integer.parseInt(st.nextToken());
		}
		
		int m = Integer.parseInt(br.readLine());
		
		// input -- end
		
		// �־��� ���꿡�� �ִ밪�� ���� �� �ִ� ������ ã�� ���� �����̹Ƿ�
		// ����Ž������ �־��� ������ ���� �ʴ� �ִ븦 ã���� �Ѵ�.
		
		binary_search(m);
		
		System.out.println(ans);
		
	}
	
	
	public static void main(String[] args) throws Exception {
		
		new Main().solve();
	}
}