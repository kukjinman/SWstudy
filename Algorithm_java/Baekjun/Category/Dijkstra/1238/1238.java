import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	int n, m, x;

	int[][] dist;
	ArrayList<ArrayList<Node>> town = new ArrayList<>();

	class Node implements Comparable<Node> {

		int idx;
		int cost;

		public Node(int idx, int cost) {
			this.idx = idx;
			this.cost = cost;
		}

		@Override
		public int compareTo(Node o) {

			return this.cost - o.cost;
		}

	}

	void dijkstra(int start) {

		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(start, 0));
		dist[start][start] = 0;

		while (!pq.isEmpty()) {
			Node cur = pq.poll();

			if (dist[start][cur.idx] < cur.cost)
				continue;

			for (int i = 0; i < town.get(cur.idx).size(); i++) {

				Node next = town.get(cur.idx).get(i);

				if (dist[start][next.idx] > dist[start][cur.idx] + next.cost) {
					dist[start][next.idx] = dist[start][cur.idx] + next.cost;
					pq.add(new Node(next.idx, dist[start][next.idx]));
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
		x = Integer.parseInt(st.nextToken());

		dist = new int[n + 1][n + 1];

		for (int i = 0; i <= n; i++) {

			town.add(new ArrayList<>());
		}

		for (int i = 0; i < dist.length; i++) {

			for (int j = 0; j < dist[i].length; j++) {
				dist[i][j] = Integer.MAX_VALUE;
			}
		}

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());

			town.get(from).add(new Node(to, cost));
		}

		// printer
//		for (int i = 0; i <= n; i++) {
//
//			for (int j = 0; j < town.get(i).size(); j++) {
//				System.out.println(town.get(i).get(j).idx + " : " + town.get(i).get(j).cost);
//			}
//
////			System.out.println("-----------------------------");
//		}

		// x에서 각각의 n까지의 최단시간을 구함
		// 그 최단시간 중 제일 큰 값이 정답

		// Input -- end

		for (int i = 1; i <= n; i++)
			dijkstra(i);

		int[] final_dist = new int[n + 1];
		for (int i = 1; i <= n; i++) {

//			System.out.println(dist[1][i]);

			for (int j = 1; j <= n; j++) {

				// 각 학샐들의 집으로 가는 최단거리
				if (i == x) {
					final_dist[j] += dist[i][j];
//					System.out.println("[x] j : " + j + " f dist : " + final_dist[j]);

				}
				// 학생들의 집에서 파티장 x로 가는 거리
				else {
					// x가 아닌 집으로 가는것은 의미가 없다.
					if (j != x)
						continue;

					final_dist[i] += dist[i][j];
//					System.out.println("j : " + j + " f dist : " + final_dist[i]);

				}

			}

		}
		int max = 0;

		for (int i = 1; i <= n; i++) {
			if (final_dist[i] > max) {
				max = final_dist[i];
			}
		}

		System.out.println(max);

	}

	public static void main(String[] args) throws IOException {

		new Main().solve();

	}
}