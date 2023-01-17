import java.io.*;
import java.util.*;


/*
 * Overflow �� ����صΰ� Ǯ��� �ϴ� ������
 * ��ٷӴ�. 
 * ��ȿ���������� for loop�� ��� %10�� ���־� Ŀ���� �ʰ� ������ִ�
 * �������� ����� ����Ѵ�. 
 * 
 * 		int[] table = new int[] {1,4,4,2,1,1,4,4,2};
 * ���� ���� �� ���ں��� �ݺ��Ǵ� �ֱⰡ �ִµ�
 * �ش� ����� ����ϸ� �� �ð��� ���� �� ���� �� ����. 
 * 
 */

class Main {
	
	void solve() throws Exception
	{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        
        int t = Integer.parseInt(bf.readLine());
        
        for(int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            
            int result = 1;
            for(int j = 0; j < b; j++) {
                result = (result * a) % 10;    
            }
            if(result == 0) {
                System.out.println(10);
            }else {
                System.out.println(result);
            }
        }
		
	}
	
	public static void main(String[] args) throws Exception {

		new Main().solve();
	}
}