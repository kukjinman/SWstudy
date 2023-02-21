import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	int[] list;
	int[] cnt;
	// input시에 각 key의 value값 저장용도
	HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();

	// 1 1 2 3 4 2 1
	// <- 역순으로 오면 정방향으로 검색할때의 log(n^2)을
	// - lon(n)에 가까지 줄일 수 있다.
	// 문제에서 원하는 것은 현재 key의 value보다 큰 가장 왼쪽!! 이므로
	// 역순으로 stack에 담으면서 현재의 바로 왼쪽에 있는 값을 검사하고 없으면
	// 그 다음 stack값으로 가져와서 나올때까지만 해주면 된다.
	// 만약 만족하는 값이 있으면 바로 다음 key로 넘어가면 된다.
	Stack<Integer> st_item = new Stack<Integer>();

	// 퍼포먼스에 영향주는 2요인
	int cur_max = -1;
	int ans[];

	void solve() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		// Input

		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		list = new int[n];
		cnt = new int[1000001];
		ans = new int[n];

		for (int i = 0; i < n; i++) {
			int cur = Integer.parseInt(st.nextToken());
//        	mp.put(cur, mp.getOrDefault(cur, 0) + 1);
			list[i] = cur;
			cnt[cur]++;
		}

		// map에 잘들어갔는지 확인 코드
//        Set<Integer> keySet = mp.keySet();
//        
//        for(Integer key : keySet)
//        {
//        	System.out.println(key + " " + mp.get(key));
//        }
//        

		for (int i = n - 1; i >= 0; i--) {

//			System.out.println("i: " + i + " " + list[i]);

			if (!st_item.isEmpty() && cur_max <= cnt[list[i]])
				st_item.clear();

			while (!st_item.isEmpty()) {
				int st_cur = st_item.peek();

				if (cnt[list[i]] < cnt[st_cur]) {
//    				sb.insert(0,st_cur + " ");
					ans[i] = st_cur;
					break;
				} else {
					st_item.pop();
				}

			}

			cur_max = Math.max(cur_max, cnt[list[i]]);

			if (st_item.isEmpty()) {
//    			sb.insert(0,-1+ " ");
				ans[i] = -1;
			}

			st_item.add(list[i]);

		}

		for (int i = 0; i < n; i++) {
			sb.append(ans[i] + " ");
		}

		System.out.println(sb);

	}

	public static void main(String[] args) throws IOException {

		new Main().solve();

	}
}