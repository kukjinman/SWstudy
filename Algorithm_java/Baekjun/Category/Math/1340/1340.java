import java.io.*;
import java.util.*;



// 진짜 더러운 문제다. 할게 많다.
class Main {
	
	int n = 0;
	
	void solve() throws Exception
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
                String month = st.nextToken();
        String s_day = st.nextToken();
        
        int day = Integer.parseInt(s_day.split(",")[0]);
        int year =Integer.parseInt(st.nextToken());
        String time =st.nextToken();
        int hour = Integer.parseInt(time.split(":")[0]);
        int min = Integer.parseInt(time.split(":")[1]);
        
      
        
        //yearFlag true is for Leap year
        boolean yearFlag = false;
        
        int[] days = new int[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String[] months = new String[] {"January", "February","March","April","May","June","July","August","September","October","November","December"};
        
        double total_time = 365 * 24* 60;
        
        int cur_time = 0;
        
        if(year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0 )))
        {
        	yearFlag = true;
        	total_time = 366 * 24* 60;
//        	System.out.println("Leap");
        	days[1] = 29;
        }
        
        ArrayList<String> mon = new ArrayList<>(List.of("January", "February","March","April","May","June","July","August","September","October","November","December"));
        
        int i_month = mon.indexOf(month);
        
        int cur_day = 0;
        // day count
        if(i_month == 0)
        {
        	cur_day = day -1;
        }
        else
        {
        	for(int i = 0; i < i_month;i++)
        	{
        		cur_day += days[i];
        	}
        	
        	
        	
        	cur_day += day -1;
        }

        cur_time = cur_day*24* 60;
        
        cur_time += hour * 60;
        cur_time += min;
        
        System.out.println(cur_time * 100 / total_time);
        
        
        
        
        
        
        
        
	}
	
	public static void main(String[] args) throws Exception {

		new Main().solve();
	}
}