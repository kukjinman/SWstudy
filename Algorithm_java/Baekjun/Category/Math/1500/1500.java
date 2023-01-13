import java.util.*;

/*
    ex
    
    7
    3 4
    ****
    ****
    ****
    
    25
    
    *****
    *****
    
    **** -> *
            *
    로 줄어듬
    최고 효율은 더 긴쪽으로 변의 길이를 늘려주다보면
    최대치는 항상 나누는 개수로 나뉜 값이 최대치가 된다.   


*/
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int S = sc.nextInt(); // 정수 S
		int K = sc.nextInt(); // 합이 S인 K개의 정수
		int div = S / K; 
		int mod = S % K;
		long max = 1;
		for (int i=1; i<=K; i++) {
			if(i<=mod) { // 나머지 갯수만큼 +1
				max *= (div+1);
			}else {
				max *= div;
			}
		
		}
		System.out.println(max);
	}	
}