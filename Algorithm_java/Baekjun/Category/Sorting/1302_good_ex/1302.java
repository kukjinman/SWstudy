import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		Map<String,Integer> map = new HashMap<>();
		
		for(int i = 0; i < n ; i++)
		{
			String book = br.readLine();
			map.put(book, map.getOrDefault(book,0) + 1);
			
		}
		
		List<Entry<String,Integer>> list_ent = new ArrayList<Entry<String,Integer>>(map.entrySet());
		
		Collections.sort(list_ent, new Comparator<Entry<String,Integer>>(){
			public int compare(Entry<String,Integer> a, Entry<String,Integer> b)
			{
				
//				return a.getValue().compareTo(b.getValue());
//				return b.getValue().compareTo(a.getValue());		
				
				if(a.getValue() < b.getValue())
				{
					return 1;
					
				}
				else if(a.getValue() > b.getValue())
				{
					
					return -1;
				}
				else {
					
					if(a.getKey().compareTo(b.getKey()) > 0)
					{
						return 1;
					}
					else
					{
						return -1;
					}
					
				}
				
				
			}
			
		});
		
		for(Entry<String,Integer> ent : list_ent)
		{
//			System.out.println(ent.getKey() + " : " + ent.getValue());
		}
		
	
		System.out.println(list_ent.get(0).getKey());
		
	}
}