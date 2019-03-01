import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

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
        this.init();
        int size_Of_Triangle = this.nextInt(); // 삼각형의 크기
        int[] triangle = new int[size_Of_Triangle + 1]; // 정수 삼각형에서 한 줄씩 값을 받기 위한 배열
        int[] dp = new int[size_Of_Triangle + 1]; // 해당 칸에 오기까지 최대합을 저장할 배열
        int max_Sum = 0; // 각 최대합들 중에서 가장 큰 수

        for (int i = 1; i <= size_Of_Triangle; ++i) {
            // 한 줄 씩 값을 입력받음
            for (int j = 1; j <= i; j++)
                triangle[j] = this.nextInt();

            /* 정수 삼각형에서 각 줄의 k번째는 그 윗줄의 k - 1번째와 k 번째에서 올 수 있으므로 둘 중
             * 큰 수를 선택하고, 현재 해당 줄의 해당칸에 대한 값에 더해주면 여지껏의 최대합만을 저장할 수 있으므로
             * 이러한 점을 이용하여 1차원 배열로 구현 가능
             */
            for (int k = i; k >= 1; --k) {
                dp[k] = Math.max(dp[k - 1], dp[k]) + triangle[k];
                if (max_Sum < dp[k])
                    max_Sum = dp[k];
            }
        }

        System.out.println(max_Sum); // 최대값 출력
    }

    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
}
