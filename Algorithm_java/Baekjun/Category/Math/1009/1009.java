import java.io.*;
import java.util.*;


/*
 * Overflow 를 계산해두고 풀어야 하는 문제라
 * 까다롭다. 
 * 비효율적이지만 for loop를 돌몇서 %10을 해주어 커지지 않게 만들어주는
 * 원초적인 방법을 사용한다. 
 * 
 * 		int[] table = new int[] {1,4,4,2,1,1,4,4,2};
 * 위와 같이 각 숫자별로 반복되는 주기가 있는데
 * 해당 방법을 사용하면 더 시간을 줄일 수 있을 것 같다. 
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