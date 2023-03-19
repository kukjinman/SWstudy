import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	int w, h, p, q, t;

	void solve() throws IOException {

		// Input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String temp = br.readLine();
		int w = Integer.parseInt(temp.split(" ")[0]);
		int h = Integer.parseInt(temp.split(" ")[1]);
		temp = br.readLine();
		int p = Integer.parseInt(temp.split(" ")[0]);
		int q = Integer.parseInt(temp.split(" ")[1]);
		int t = Integer.parseInt(br.readLine());

		// p + t 가 w로 나눠지는데
		// p가 t만큼지났을때 w로 정확히 나눠지는 경우는
		// 벽에 만난 경우이다.

		if (((int) (p + t) / w) % 2 == 0) {
			// 정방향
			p = (p + t) % w;
		} else {
			// 정방향 아님
			p = w - (p + t) % w;
		}

		if (((int) (q + t) / h) % 2 == 0) {
			// 정방향
			q = (q + t) % h;
		} else {
			// 정방향 아님
			q = h - (q + t) % h;
		}
		System.out.println(p + " " + q);

	}

	public static void main(String[] args) throws IOException {

		new Main().solve();

	}
}