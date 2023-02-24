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

			// 기존 방문했는지 visited에 체크하여 다시 방문하지 않게 해주는 방법
			// pq의 특성상 cost가 적으면 pq에서 먼저 빠져나와 visited에 체크되므로
			// 나중에 나온 경로에서 이미 체크된 경로로 가는 경우는 무조건적으로 cost가 더 많이 든다
			// 그러므로 pass 해주면 된다.

//			if (!visited[cur_idx]) {
//			visited[cur_idx] = true;
//
//			System.out.println("city.get(cur_idx).size() : " + city.get(cur_idx).size());
//
//			// current index의 갈수있는 city의 모든 경로들을 탐색
//			for (int i = 0; i < city.get(cur_idx).size(); i++) {
//				Node next = city.get(cur_idx).get(i);
//
//				if (!visited[next.idx]) {
//					// 다음의 갈 경로의 dist에 저장되어 왔던 최소 값과 현재 경로에서 다음으로 갈 경로의 cost와
//					// 비교하여서 현재 경로에서 거쳐가는게 더 적은 cost면 update하고 다음 경로를 pq에 넣어 줌.
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

			// 이방법을 안쓰면 현재까지의 dist와 새로운 cost를 비교하여 더 많으면 visited와 같이 무시되게 해주는
			// 코드로 짜줘도 된다.

			if (dist[cur_idx] < cur.cost) {
				continue;
			}

//			System.out.println("city.get(cur_idx).size() : " + city.get(cur_idx).size());

			// current index의 갈수있는 city의 모든 경로들을 탐색
			for (int i = 0; i < city.get(cur_idx).size(); i++) {
				Node next = city.get(cur_idx).get(i);

				// 다음의 갈 경로의 dist에 저장되어 왔던 최소 값과 현재 경로에서 다음으로 갈 경로의 cost와
				// 비교하여서 현재 경로에서 거쳐가는게 더 적은 cost면 update하고 다음 경로를 pq에 넣어 줌.
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