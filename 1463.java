import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//1463번
    
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
        this.init(); // StringTokenizer
        int number = 0; // 정수 N
        number = this.nextInt();
        int[] dp = new int[number + 1]; // index사용시 편의를 위해 number+1만큼
        dp[0] = dp[1] = 0; // 0은 입력시 없으므로 0, 1은 연산이 필요없으므로 0

        /* 정수 N에 대하여 1을 만드는 최소 횟수에 대한 값은 N - 1의 횟수 + 1 또는, N / 2의 횟수 + 1
         * 또는 N / 3의 횟수 + 1이 될 수 있다. 그런 점을 이용해서 첫 수부터 시작해서 차례대로 값을 채워나가며
         * 계산을 거듭하다보면 다시 값이 계산되는 경우에 원래 값과 비교하여 작은 경우 최소값을 갱신하며
         * 해당 수에 대한 최소 값을 계산해낼 수 있다.
         */
        for (int index = 2; index <= number; ++index) {
            dp[index] = dp[index - 1] + 1;
            if (index % 3 == 0)
                dp[index] = Math.min(dp[index], dp[index / 3] + 1);
            if (index % 2 == 0)
                dp[index] = Math.min(dp[index], dp[index / 2] + 1);
        }

        System.out.println(dp[number]);

    }

    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
}
