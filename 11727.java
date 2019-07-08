import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 11727번 (2XN 타일링2)
public class Main {
    private StringTokenizer _st;
    private BufferedReader _br;

    private String readLine() {
        try {
            return this._br.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    private String next() {
        while (!this._st.hasMoreTokens()) {
            this._st = new StringTokenizer(this.readLine());
        }
        return this._st.nextToken();
    }

    private int nextInt() {
        return Integer.parseInt(this.next());
    }

    private void init() {
        this._st = new StringTokenizer("");
        this._br = new BufferedReader(new InputStreamReader(System.in));
    }

    private void solve() {
        this.init();// StringTokenizer
        int tileLength = this.nextInt();
        int[] tile = new int[tileLength + 2]; // 런타임에러 방지
        tile[1] = 1;
        tile[2] = 3;

        for(int index = 3; index <= tileLength; ++index) {
            tile[index] = tile[index - 1] + tile[index - 2] * 2; // 점화식
            tile[index] %= 10007; // 10007로 나눈 나머지 출력을 위함과 오버플로우 방지
        }
        System.out.println(tile[tileLength]);
    }

    public static void main(String[] args) {
        Main newMain = new Main();
        newMain.solve();
    }
}
