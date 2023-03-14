import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	int n, m;
	int[][] map;

	class Node {
		int y;
		int x;

		public Node(int y, int x) {
			this.y = y;
			this.x = x;
		}

	}

	Node[] store;
	int cnt_s = 0;
	Node[] home;
	int cnt_h = 0;

	int[] visited;
	ArrayList<Integer> arr = new ArrayList<>();

	int ans = Integer.MAX_VALUE;

	void rec(int start, int cnt) {

		if (cnt >= m) {

//			for (int i = 0; i < arr.size(); i++) {
//				System.out.print(arr.get(i));
//			}
//			System.out.println();
			int sum = 0;
			for (int j = 0; j < cnt_h; j++) {
				Node cur_home = home[j];

				int cur_val = Integer.MAX_VALUE;
				for (int i = 0; i < m; i++) {

					Node cur = store[visited[i]];
//					System.out.print(visited[i]);

					int dist = Math.abs(cur.y - cur_home.y) + Math.abs(cur.x - cur_home.x);

					if (cur_val > dist) {
						cur_val = dist;
					}

				}
//				System.out.println();

				sum += cur_val;

			}

//			System.out.println("s : " + sum);

			if (ans > sum) {
				ans = sum;
			}
			return;
		}

		for (int i = start; i < cnt_s; i++) {

			visited[cnt] = i;
			rec(i + 1, cnt + 1);

		}

	}

	void solve() throws IOException {

		// Input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		map = new int[n][n];
		store = new Node[13];
		home = new Node[2 * n];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 2) {
					store[cnt_s] = new Node(i, j);
					cnt_s++;
				} else if (map[i][j] == 1) {
					home[cnt_h] = new Node(i, j);
					cnt_h++;
				} else {

				}
			}
		}
		visited = new int[cnt_s];

		rec(0, 0);

		System.out.println(ans);

	}

	public static void main(String[] args) throws IOException {

		new Main().solve();

	}
}