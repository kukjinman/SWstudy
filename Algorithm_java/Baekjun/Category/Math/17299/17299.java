import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	int[] list;
	int[] cnt;
	// input�ÿ� �� key�� value�� ����뵵
	HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();

	// 1 1 2 3 4 2 1
	// <- �������� ���� ���������� �˻��Ҷ��� log(n^2)��
	// - lon(n)�� ������ ���� �� �ִ�.
	// �������� ���ϴ� ���� ���� key�� value���� ū ���� ����!! �̹Ƿ�
	// �������� stack�� �����鼭 ������ �ٷ� ���ʿ� �ִ� ���� �˻��ϰ� ������
	// �� ���� stack������ �����ͼ� ���ö������� ���ָ� �ȴ�.
	// ���� �����ϴ� ���� ������ �ٷ� ���� key�� �Ѿ�� �ȴ�.
	Stack<Integer> st_item = new Stack<Integer>();

	// �����ս��� �����ִ� 2����
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

		// map�� �ߵ����� Ȯ�� �ڵ�
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