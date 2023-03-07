import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	int[] item;

	// r���� ���� ��Ƶ� ArrayList : loc.get(from)�� from�� ����� �� �� ��ŭ �߰�
	// from�� ���� ���� �������� ���� �� �־ ArrayList�� ���.
	ArrayList<ArrayList<Node>> loc = new ArrayList<>();

	// ������ n���� �������� ����Ͽ� �� ������ �ɸ��� dist ����
	int[][] dist;
	int n, m, r;

	class Node implements Comparable<Node> {

		int idx;
		int cost;

		public Node(int idx, int cost) {
			this.idx = idx;
			this.cost = cost;
		}

		public int compareTo(Node o) {
			return this.cost - o.cost;
		}

	}

	void dijkstra(int start) {

		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		pq.add(new Node(start, 0));
		// �ڱ������� �Ÿ��� 0���� ����
		dist[start][start] = 0;

		while (!pq.isEmpty()) {
			Node cur = pq.poll();
//			System.out.println("cur : " + cur.idx);

			// while�� Ż�������� ����� �κ�
			// dist[start][cur.idx]�� ���� ��� route�� �� ���ļ� �ּҰ��� �Ǹ�
			// ���Ŀ� pq.add�� ���� ���ϵ��� �� �κп��� continue���ش�.
			// ���� �������� �̾����� while�� Ż������ ������ ����.
			if (dist[start][cur.idx] < cur.cost) {
				continue;
			}
//			System.out.println("cdist : " + loc.get(cur.idx).size());

			// cur �������� ����� �渶�� ����� ���� for loop
			for (int i = 0; i < loc.get(cur.idx).size(); i++) {
				int next = loc.get(cur.idx).get(i).idx;
				int ncost = loc.get(cur.idx).get(i).cost;

//				System.out.println("next : " + next);

				if (dist[start][next] > (ncost + dist[start][cur.idx])) {
					dist[start][next] = ncost + dist[start][cur.idx];

					// �� if���� �Դ���� �ǵ��ư��� ���� �������ش�.
					// ���� pq.add�� if�� �ۿ� ������. �Դ� �浵 pq�� �־� ���� �ݺ��� ����Ų��.
					pq.add(new Node(next, ncost));

//					System.out.println("dist : " + dist[start][next]);
				}

			}

		}

	}

	void solve() throws IOException {

		// Input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());

		item = new int[n + 1];

		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++) {
			item[i] = Integer.parseInt(st.nextToken());
		}

		// loc �ʱ�ȭ
		// 0�� ��� n���� �����༭ overflow�� ���ƾ��Ѵ�.
		for (int i = 0; i <= n; i++) {
			loc.add(new ArrayList<Node>());
		}

		// n���� ���������� n���� ������ �� �� �������� [n][n]
		dist = new int[n + 1][n + 1];

		// �ּҰ��� update�ϱ� ���� dist�� ��� int Max�� ����
		for (int i = 1; i <= n; i++) {
			Arrays.fill(dist[i], Integer.MAX_VALUE);
		}

		for (int i = 0; i < r; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());

			// loc�� ArrayList ���� ArrayList�� Node�߰�
			// loc.get(from)�� from�� ����� �� �� ��ŭ �߰�
			loc.get(from).add(new Node(to, cost));
			// �������� ���� ���� �����ϴ�.
			// �߰��ϴ� ������ ��������� �޶��� �� �ֱ� �����̴�.
			loc.get(to).add(new Node(from, cost));
//			System.out.println("f size : " + loc.get(from).size());

		}

		// 0 ~ n-1�� ������ �������� dijkstra ����Ͽ� dist update

		for (int i = 1; i <= n; i++) {
			dijkstra(i);
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= n; j++) {
//				System.out.print(dist[i][j] + " ");

				if (dist[i][j] <= m)
					sum += item[j];
			}

			if (sum > ans) {
				ans = sum;
			}

		}

		System.out.println(ans);

	}

	public static void main(String[] args) throws IOException {

		new Main().solve();

	}
}