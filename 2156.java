import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 2156번 문제(포도주 시식)
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
        int numberOfWine = this.nextInt();
        int[] amountOfWine = new int[numberOfWine + 1];
        int[][] calcMaxAmount = new int[3][numberOfWine + 1];
        int index, max1, max2, resultOfCase1, resultOfCase2, tempStoreMaxValue, result;

        for(index = 1; index <= numberOfWine; ++index) {
            amountOfWine[index] = this.nextInt();
        }

        if(numberOfWine == 1) {
            result = amountOfWine[1];
        } else if(numberOfWine == 2) {
            result = amountOfWine[1] + amountOfWine[2];
        } else  {
            // row값이 0이면 연속하지 않은 상태로 포도주를 마시는 경우, 1인 경우에는 연속해서 포도주를 마시는 경우

            // 1번째 포도주를 마시는 경우
            calcMaxAmount[0][1] = amountOfWine[1];
            calcMaxAmount[1][1] = amountOfWine[1];
            calcMaxAmount[2][1] = amountOfWine[1];
            calcMaxAmount[0][2] = amountOfWine[1] + amountOfWine[2];
            calcMaxAmount[1][2] = amountOfWine[2];
            calcMaxAmount[2][2] = amountOfWine[2];

            for(index = 3; index <= numberOfWine; ++index) {
                calcMaxAmount[0][index] = Math.max(calcMaxAmount[1][index - 1], calcMaxAmount[2][index - 1]) + amountOfWine[index];
                tempStoreMaxValue = Math.max(calcMaxAmount[0][index - 2], calcMaxAmount[1][index - 2]);
                calcMaxAmount[1][index] = Math.max(tempStoreMaxValue, calcMaxAmount[2][index -2]) + amountOfWine[index];
                tempStoreMaxValue = Math.max(calcMaxAmount[0][index - 3], calcMaxAmount[1][index - 3]);
                calcMaxAmount[2][index] = Math.max(tempStoreMaxValue, calcMaxAmount[2][index - 3]) + amountOfWine[index];
            }

            max1 = Math.max(calcMaxAmount[0][numberOfWine - 1], calcMaxAmount[1][numberOfWine - 1]);
            max2 = Math.max(calcMaxAmount[2][numberOfWine - 1], calcMaxAmount[0][numberOfWine]);
            tempStoreMaxValue = Math.max(max1, max2);
            max1 = tempStoreMaxValue;
            max2 = Math.max(calcMaxAmount[1][numberOfWine], calcMaxAmount[2][numberOfWine]);
            result = Math.max(max1, max2);
        }

        System.out.println(result);
    }

    public static void main(String[] args) {
        Main newMain = new Main();
        newMain.solve();
    }
}