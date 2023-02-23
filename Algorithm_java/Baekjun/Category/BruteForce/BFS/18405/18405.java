import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	int n, k;
	int s, x, y;

	int[][] map;

	int[] dy = { 0, 0, -1, 1 };
	int[] dx = { -1, 1, 0, 0 };

	Queue<Node> q = new LinkedList<>();

	class Node implements Comparator<Node> {

		int y;
		int x;
		int val;
		int time;

		Node(int y, int x, int val, int time) {
			this.y = y;
			this.x = x;
			this.val = val;
			this.time = time;
		}

		@Override
		public int compare(Node o1, Node o2) {
			return o1.val - o2.val;
		}

	}

	void bfs() {

		while (!q.isEmpty()) {
			Node cur = q.poll();

			if (cur.time >= s) {
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];

				if (ny >= n || ny < 0 || nx >= n || nx < 0) {
					continue;
				}
				if (map[ny][nx] != 0)
					continue;

				map[ny][nx] = cur.val;
				q.offer(new Node(ny, nx, cur.val, cur.time + 1));

			}

		}

	}

	void solve() throws IOException {

		// Input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		map = new int[n][n];

		ArrayList<Node> list = new ArrayList<>();

		for (int i = 0; i < n; i++) {

			st = new StringTokenizer(br.readLine());

			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] != 0) {
					list.add(new Node(i, j, map[i][j], 0));
				}

			}
		}
		Collections.sort(list, new Comparator<Node>() {

			@Override
			public int compare(Node a, Node b) {
				return a.val - b.val;
			}
		});

		st = new StringTokenizer(br.readLine());

		s = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());

		for (int i = 0; i < list.size(); i++) {
			q.offer(list.get(i));
		}

		bfs();

//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				System.out.print(map[i][j]);
//			}
//			System.out.println();
//		}

		System.out.println(map[x - 1][y - 1]);

	}

	public static void main(String[] args) throws IOException {

		new Main().solve();

	}
}