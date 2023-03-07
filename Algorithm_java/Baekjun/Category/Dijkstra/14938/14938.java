import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	int[] item;

	// r개의 길을 담아둘 ArrayList : loc.get(from)에 from의 연결된 길 수 만큼 추가
	// from에 붙을 길은 동적으로 변할 수 있어서 ArrayList를 사용.
	ArrayList<ArrayList<Node>> loc = new ArrayList<>();

	// 각각의 n개의 지역에서 출발하여 각 지역에 걸리는 dist 저장
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
		// 자기지역의 거리는 0으로 세팅
		dist[start][start] = 0;

		while (!pq.isEmpty()) {
			Node cur = pq.poll();
//			System.out.println("cur : " + cur.idx);

			// while의 탈출조건을 만드는 부분
			// dist[start][cur.idx]가 만약 모든 route를 다 거쳐서 최소값이 되면
			// 이후에 pq.add를 하지 못하도록 이 부분에서 continue해준다.
			// 길이 무한으로 이어져서 while을 탈출하지 못함을 막음.
			if (dist[start][cur.idx] < cur.cost) {
				continue;
			}
//			System.out.println("cdist : " + loc.get(cur.idx).size());

			// cur 지역에서 연결된 길마다 계산을 위한 for loop
			for (int i = 0; i < loc.get(cur.idx).size(); i++) {
				int next = loc.get(cur.idx).get(i).idx;
				int ncost = loc.get(cur.idx).get(i).cost;

//				System.out.println("next : " + next);

				if (dist[start][next] > (ncost + dist[start][cur.idx])) {
					dist[start][next] = ncost + dist[start][cur.idx];

					// 이 if문은 왔던길로 되돌아가는 것을 방지해준다.
					// 만약 pq.add가 if문 밖에 있으면. 왔던 길도 pq에 넣어 무한 반복을 일으킨다.
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

		// loc 초기화
		// 0이 없어서 n까지 돌려줘서 overflow를 막아야한다.
		for (int i = 0; i <= n; i++) {
			loc.add(new ArrayList<Node>());
		}

		// n개의 시작점에서 n개의 지역이 들어갈 수 있음으로 [n][n]
		dist = new int[n + 1][n + 1];

		// 최소값을 update하기 위해 dist를 모두 int Max로 세팅
		for (int i = 1; i <= n; i++) {
			Arrays.fill(dist[i], Integer.MAX_VALUE);
		}

		for (int i = 0; i < r; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());

			// loc의 ArrayList 안의 ArrayList에 Node추가
			// loc.get(from)에 from의 연결된 길 수 만큼 추가
			loc.get(from).add(new Node(to, cost));
			// 양쪽으로 가는 값은 동일하다.
			// 추가하는 이유는 출발지역이 달라질 수 있기 때문이다.
			loc.get(to).add(new Node(from, cost));
//			System.out.println("f size : " + loc.get(from).size());

		}

		// 0 ~ n-1의 지역을 시작으로 dijkstra 사용하여 dist update

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