import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 1149번 문제(RGB거리)
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
        int sizeOfArray = this.nextInt(); // 집의 개수
        int red = 0; // Red
        int green = 1; // Green
        int blue = 2; // Blue
        int index, result; // 배열의 index값을 가리키는 변수 index, 출력값을 결정할 result
        int[][] cost = new int[3][sizeOfArray + 1]; // 계산을 편하게 하기 위해 집의 개수에서 +1만큼의 크기를 할당
        int[] sum = new int[3]; // 첫 시작 RGB에 대한 각각의 sum값 저장
        int tempStoreRed = 0, tempStoreGreen = 0, tempStoreBlue = 0; // side effect를 방지하기 위한 결과값을 임시로 저장하는 변수

        // cost 저장
        for(index = 1; index <= sizeOfArray; ++index) {
            cost[red][index] = this.nextInt();
            cost[green][index] = this.nextInt();
            cost[blue][index] = this.nextInt();
        }

        // Red, Green, Blue를 칠하기 위해 여지껏 색칠해온 최소 cost계산
        for(index = 1; index < sizeOfArray; ++index) {
            tempStoreRed = (sum[green] + cost[green][index] <= sum[blue] + cost[blue][index]) ? sum[green] + cost[green][index] : sum[blue] + cost[blue][index];
            tempStoreGreen = (sum[red] + cost[red][index] <= sum[blue] + cost[blue][index]) ? sum[red] + cost[red][index] : sum[blue] + cost[blue][index];
            tempStoreBlue = (sum[green] + cost[green][index] <= sum[red] + cost[red][index]) ? sum[green] + cost[green][index] : sum[red] + cost[red][index];

            sum[red] = tempStoreRed;
            sum[green] = tempStoreGreen;
            sum[blue] = tempStoreBlue;
        }

        // 마지막 집 색칠 cost 더해줌
        sum[red] += cost[red][sizeOfArray];
        sum[green] += cost[green][sizeOfArray];
        sum[blue] += cost[blue][sizeOfArray];

        result = (sum[red] <= sum[green]) ? sum[red] : sum[green];
        result = (result <= sum[blue]) ? result : sum[blue];

        System.out.println(result);
    }

    public static void main(String[] args) {
        Main newMain = new Main();
        newMain.solve();
    }
}