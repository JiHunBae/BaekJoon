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
        int size_Of_Triangle = this.nextInt(); // 정수 삼각형의 크기
        int[][] triangle = new int[size_Of_Triangle + 1][size_Of_Triangle + 1]; // 삼각형의 정수값 저장
        int[][] dp = new int[size_Of_Triangle + 1][size_Of_Triangle + 1]; // 해당 칸으로 오기까지의 최대합 저장
        int result = 0; // 최대값 저장

        // 삼각형 정수 입력부분
        for (int i = 1; i <= size_Of_Triangle; ++i)
            for (int j = 1; j <= i; ++j)
                triangle[i][j] = this.nextInt();

        // 한 줄 씩 내려가며 해당 칸에 대한 최대합을 계산하여 저장하고 최대값을 계속 갱신
        for (int x = 1; x <= size_Of_Triangle; ++x)
            for (int y = 1; y <= size_Of_Triangle; ++y) {
                /* 위 방향으로 왼쪽 또른 오른쪽 값 중 큰 값을 선택하여 현재 해당 칸에 대한 정수 값과 더해줌
                * 맨 왼쪽과 맨 오른쪽은 윗 줄의 대각선 중 한 쪽이 없는데 배열에 0이 들어있어 무시 할 수 있다
                */
                dp[x][y] = Math.max(dp[x - 1][y - 1], dp[x - 1][y]) + triangle[x][y];

                if (result < dp[x][y]) // 최대값 갱신
                    result = dp[x][y];
            }

        System.out.println(result); // 최대값 출력
    }

    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
}
