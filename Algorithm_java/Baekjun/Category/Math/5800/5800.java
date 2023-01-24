import java.io.*;
import java.util.*;


class Main {
	
	int n = 0;
	
	void solve() throws Exception
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        
        for(int i =0; i < n;i++)
        {
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	int num = Integer.parseInt(st.nextToken());
        	int[] score = new int[num];
        	
        	for(int j = 0;j<num;j++)
        	{
        		score[j] = Integer.parseInt(st.nextToken());
        	}
        	
        	// Arrays.stream 사용하는 방법
        	int max = Arrays.stream(score).max().getAsInt();
        	
        	
        	// for loop돌리는 방법
        	int min = Integer.MAX_VALUE;
        	for(int j = 0; j<num;j++)
        	{
        		if(min > score[j])
        		{
        			min = score[j];
        		}
        	}
        	
        	Arrays.sort(score);

        	int gap = Integer.MIN_VALUE;
        	for(int j = 0; j < num-1;j++)
        	{
        		if(gap < (score[j+1] - score[j]))
        		{
        			gap = (score[j+1] - score[j]);
        		}
        	}
        	
        	System.out.println("Class " + (i+1));
        	System.out.println("Max " + max + ", Min " + min + ", Largest gap " + gap);
        	
        	
        }
        
	}
	
	public static void main(String[] args) throws Exception {

		new Main().solve();
	}
}