import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//9095번

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
        int number_Of_Case = this.nextInt(); // 테스트케이스의 개수를 받음

        // 테스트 케이스 개수만큼 반복
        for (int case_Num = 1; case_Num <= number_Of_Case; ++case_Num) {
            int number_Of_Integer = this.nextInt(); // 정수 N
            int[] dp = new int[number_Of_Integer + 1];
            dp[0] = 0; // 0은 될 수 있는 조합의 가짓수가 0임을 이용
            dp[1] = 1; // 1은 될 수 있는 조합이 1밖에 없으므로 1

            // 2이상인 경우
            if (number_Of_Integer > 1)
                dp[2] = 2;

            // 3이상인 경우
            if(number_Of_Integer > 2)
                dp[3] = 4;

            // n이 4이상인 경우 n이 조합될 수 있는 가짓 수는 n-1, n-2, n-3에 대한 조합의 가짓수 들의 합임을 이용
            for (int n = 4; n <= number_Of_Integer; ++n)
                dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3];

            System.out.println(dp[number_Of_Integer]); // 조합 수 출력
        }

    }

    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
}
