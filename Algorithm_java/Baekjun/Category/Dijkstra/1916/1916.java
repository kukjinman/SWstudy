import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	ArrayList<ArrayList<Node>> city = new ArrayList<>();
	int[] dist;
	boolean[] visited;
	int n;
	int m;
	int s, e;

	class Node implements Comparable<Node> {
		int idx;
		int cost;

		public Node(int idx, int cost) {
			this.idx = idx;
			this.cost = cost;
		}

		@Override
		public int compareTo(Node o) {
//			System.out.println("this.cost : " + this.cost + " o cost :" + o.cost);
			//
			if (this.cost < o.cost) {
				return -1;
			}
			return 1;
		}

	}

	void dijkstra() {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(s, 0));
		dist[s] = 0;
		visited = new boolean[n + 1];

		while (!pq.isEmpty()) {
			Node cur = pq.poll();
			int cur_idx = cur.idx;

//			System.out.println("cur_idx : " + cur_idx + " pq size : " + pq.size());

			// ���� �湮�ߴ��� visited�� üũ�Ͽ� �ٽ� �湮���� �ʰ� ���ִ� ���
			// pq�� Ư���� cost�� ������ pq���� ���� �������� visited�� üũ�ǹǷ�
			// ���߿� ���� ��ο��� �̹� üũ�� ��η� ���� ���� ������������ cost�� �� ���� ���
			// �׷��Ƿ� pass ���ָ� �ȴ�.

//			if (!visited[cur_idx]) {
//			visited[cur_idx] = true;
//
//			System.out.println("city.get(cur_idx).size() : " + city.get(cur_idx).size());
//
//			// current index�� �����ִ� city�� ��� ��ε��� Ž��
//			for (int i = 0; i < city.get(cur_idx).size(); i++) {
//				Node next = city.get(cur_idx).get(i);
//
//				if (!visited[next.idx]) {
//					// ������ �� ����� dist�� ����Ǿ� �Դ� �ּ� ���� ���� ��ο��� �������� �� ����� cost��
//					// ���Ͽ��� ���� ��ο��� ���İ��°� �� ���� cost�� update�ϰ� ���� ��θ� pq�� �־� ��.
//					if (dist[next.idx] > (dist[cur_idx] + next.cost)) {
//
//						dist[next.idx] = dist[cur_idx] + next.cost;
//						pq.add(new Node(next.idx, dist[next.idx]));
//						System.out.println("next.idx : " + next.idx);
//
//					}
//
//				}
//
//			}
//
//		}

			// �̹���� �Ⱦ��� ��������� dist�� ���ο� cost�� ���Ͽ� �� ������ visited�� ���� ���õǰ� ���ִ�
			// �ڵ�� ¥�൵ �ȴ�.

			if (dist[cur_idx] < cur.cost) {
				continue;
			}

//			System.out.println("city.get(cur_idx).size() : " + city.get(cur_idx).size());

			// current index�� �����ִ� city�� ��� ��ε��� Ž��
			for (int i = 0; i < city.get(cur_idx).size(); i++) {
				Node next = city.get(cur_idx).get(i);

				// ������ �� ����� dist�� ����Ǿ� �Դ� �ּ� ���� ���� ��ο��� �������� �� ����� cost��
				// ���Ͽ��� ���� ��ο��� ���İ��°� �� ���� cost�� update�ϰ� ���� ��θ� pq�� �־� ��.
				if (dist[next.idx] > (dist[cur_idx] + next.cost)) {

					dist[next.idx] = dist[cur_idx] + next.cost;
					pq.add(new Node(next.idx, dist[next.idx]));
//					System.out.println("next.idx : " + next.idx);
				}
			}

		}

		System.out.println(dist[e]);
	}

	void solve() throws IOException {

		// Input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());
		dist = new int[n + 1];

		for (int i = 0; i <= n; i++) {
			city.add(new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());

			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());

			city.get(from).add(new Node(to, cost));
		}

		StringTokenizer st = new StringTokenizer(br.readLine());

		s = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());

		Arrays.fill(dist, Integer.MAX_VALUE);

		// Input -- end

//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < city.get(i).size(); j++) {
//
//				System.out.println("idx : " + city.get(i).get(j).idx + " cost : " + city.get(i).get(j).cost);
//			}
//
//			System.out.println("--------------------");
//		}

		dijkstra();

	}

	public static void main(String[] args) throws IOException {

		new Main().solve();

	}
}