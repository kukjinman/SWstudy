import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	void solve() throws IOException {

		// Input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());

		int cnt = 0;
		Stack<Integer>[] stack = new Stack[7];

		for (int i = 1; i <= 6; i++) {
			stack[i] = new Stack<Integer>();
		}

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());

			int line = Integer.parseInt(st.nextToken());
			int plat = Integer.parseInt(st.nextToken());

			if (stack[line].isEmpty()) {
				cnt++;
				stack[line].add(plat);
			} else {

				if (stack[line].peek() == plat) {

				} else if (stack[line].peek() > plat) {

					boolean add_flag = true;
					while (!stack[line].isEmpty()) {
						if (stack[line].peek() < plat) {
							break;
						} else if (stack[line].peek() == plat) {
							add_flag = false;
							break;
						}
						cnt++;
						stack[line].pop();
					}

					if (add_flag == false) {

					} else {
						cnt++;
						stack[line].add(plat);
					}

				} else {

//					System.out.println("plat : " + plat + " cnt : " + cnt);

					cnt++;
					stack[line].add(plat);

				}

			}

		}

		System.out.println(cnt);

	}

	public static void main(String[] args) throws IOException {

		new Main().solve();

	}
}