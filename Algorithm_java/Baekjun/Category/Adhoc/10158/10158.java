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

		// p + t �� w�� �������µ�
		// p�� t��ŭ�������� w�� ��Ȯ�� �������� ����
		// ���� ���� ����̴�.

		if (((int) (p + t) / w) % 2 == 0) {
			// ������
			p = (p + t) % w;
		} else {
			// ������ �ƴ�
			p = w - (p + t) % w;
		}

		if (((int) (q + t) / h) % 2 == 0) {
			// ������
			q = (q + t) % h;
		} else {
			// ������ �ƴ�
			q = h - (q + t) % h;
		}
		System.out.println(p + " " + q);

	}

	public static void main(String[] args) throws IOException {

		new Main().solve();

	}
}