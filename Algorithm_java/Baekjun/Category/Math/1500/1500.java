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
    �� �پ��
    �ְ� ȿ���� �� �������� ���� ���̸� �÷��ִٺ���
    �ִ�ġ�� �׻� ������ ������ ���� ���� �ִ�ġ�� �ȴ�.   


*/
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int S = sc.nextInt(); // ���� S
		int K = sc.nextInt(); // ���� S�� K���� ����
		int div = S / K; 
		int mod = S % K;
		long max = 1;
		for (int i=1; i<=K; i++) {
			if(i<=mod) { // ������ ������ŭ +1
				max *= (div+1);
			}else {
				max *= div;
			}
		
		}
		System.out.println(max);
	}	
}