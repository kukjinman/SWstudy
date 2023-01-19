import java.io.*;
import java.util.*;


class Main {
	
	int n = 0;
	
	void solve() throws Exception
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int f = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        
        ArrayList<Integer> f_arr = new ArrayList<>();
        ArrayList<Integer> s_arr = new ArrayList<>();
        
        // contains 속보 비교
        // ArrayList << Set << HashSet
        
        // hashing 사용 이진탐색트리보다 빠름
        HashSet<Integer> f_set = new HashSet<>();
        
        // 이진탐색트리 사용
        Set<Integer> s_set = new HashSet<>();
        
        int intersection = 0; 
        
        
        st = new StringTokenizer(br.readLine());
        
        for(int i = 0; i < f;i++)
        {
        	int tmp = Integer.parseInt(st.nextToken());
        	f_arr.add(tmp);
        	f_set.add(tmp);
        }
        
//        System.out.println(f_arr.size());
        
        st = new StringTokenizer(br.readLine());
        
        for(int i = 0; i < s;i++)
        {
        	int tmp = Integer.parseInt(st.nextToken());
        	s_arr.add(tmp);
        	s_set.add(tmp);
        }
        
//        System.out.println(s_arr.size());

        if(f_arr.size() < s_arr.size())
        {
        	for(int i = 0; i < f_arr.size();i++)
        	{
        		if(s_set.contains(f_arr.get(i)) != false)
        		{
        			intersection++;
        		}
        	}
        	
        	
        }
        else
        {
        	for(int i = 0; i < s_arr.size();i++)
        	{
        		if(f_set.contains(s_arr.get(i)) != false)
        		{
        			intersection++;
        		}
        		
        	}
        	
        	
        }
        int ans = f_arr.size() + s_arr.size() - (2 * intersection);
        
        
        System.out.println(ans);
	
	}
	
	public static void main(String[] args) throws Exception {

		new Main().solve();
	}
}
