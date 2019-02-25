import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 2178번 문제(미로찾기)
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
        this.init(); // StringToken 생성
        int number_Of_Column = this.nextInt(); // 행의 개수
        int number_Of_Row = this.nextInt(); // 열의 개수
        int[][] maze = new int[number_Of_Column + 2][number_Of_Row + 2]; // 크기를 +2를 해준 이유는 맨 끝의 인덱스 처리를 위함
        int[][] minimum_Arrive = new int[number_Of_Column + 2][number_Of_Row + 2]; // 크기를 +2를 해준 이유는 위와 동일

        // 미로 정보를 배열에 저장
        for (int index_Of_Column = 1; index_Of_Column <= number_Of_Column; ++index_Of_Column) {
            String str = this.next();
            for (int index_Of_Row = 1; index_Of_Row <= number_Of_Row; ++index_Of_Row)
                maze[index_Of_Column][index_Of_Row] = Integer.parseInt(Character.toString(str.charAt(index_Of_Row - 1)));
        }

        // 행, 열의 인덱스를 담을 Queue들을 생성
        Queue<Integer> queue_1 = new LinkedList<Integer>();
        Queue<Integer> queue_2 = new LinkedList<Integer>();
        queue_1.add(1);
        queue_2.add(1);
        minimum_Arrive[queue_1.peek()][queue_2.peek()] = 1;

        while (queue_1.peek() != null) {
            int a = queue_1.poll();
            int b = queue_2.poll();
            if (maze[a - 1][b] == 1) { // 위쪽으로 연결 가능한 경우
                if (minimum_Arrive[a][b] + 1 < minimum_Arrive[a - 1][b] || minimum_Arrive[a - 1][b] == 0) {
                    // 최소거리 갱신이 필요한 경우
                    // 최소거리 값 갱신 후 해당 인덱스를 Queue에 삽입
                    minimum_Arrive[a - 1][b] = minimum_Arrive[a][b] + 1;
                    queue_1.add(a - 1);
                    queue_2.add(b);
                }
            }
            if (maze[a][b - 1] == 1) {
                // 왼쪽으로 연결 가능한 경우
                if (minimum_Arrive[a][b] + 1 < minimum_Arrive[a][b - 1] || minimum_Arrive[a][b - 1] == 0) {
                    // 최소거리 갱신이 필요한 경우
                    // 최소거리 값 갱신 후 해당 인덱스를 Queue에 삽입
                    minimum_Arrive[a][b - 1] = minimum_Arrive[a][b] + 1;
                    queue_1.add(a);
                    queue_2.add(b - 1);
                }
            }
            if (maze[a + 1][b] == 1) {
                // 아래로 연결 가능한 경우
                if (minimum_Arrive[a][b] + 1 < minimum_Arrive[a + 1][b] || minimum_Arrive[a + 1][b] == 0) {
                    // 최소거리 갱신이 필요한 경우
                    // 최소거리 값 갱신 후 해당 인덱스를 Queue에 삽입
                    minimum_Arrive[a + 1][b] = minimum_Arrive[a][b] + 1;
                    queue_1.add(a + 1);
                    queue_2.add(b);
                }
            }
            if (maze[a][b + 1] == 1) {
                // 오른쪽으로 연결 가능한 경우
                if (minimum_Arrive[a][b] + 1 < minimum_Arrive[a][b + 1] || minimum_Arrive[a][b + 1] == 0) {
                    // 최소거리 갱신이 필요한 경우
                    // 최소거리 값 갱신 후 해당 인덱스를 Queue에 삽입
                    minimum_Arrive[a][b + 1] = minimum_Arrive[a][b] + 1;
                    queue_1.add(a);
                    queue_2.add(b + 1);
                }
            }
        }

        System.out.println(minimum_Arrive[number_Of_Column][number_Of_Row]); // N * M에 대한 최소거리 출력
    }



    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
}
