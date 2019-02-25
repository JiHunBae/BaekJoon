import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
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
        int number = 0; // 정점의 개수
        number = this.nextInt();

        int[][] connected = new int[number][number]; // 연결관계를 나타내는 배열
        int[][] visited = new int[number][number]; // 어떻게든 연결되어 있는지를 나타내는 배열

        for (int index_Of_Start = 0; index_Of_Start < number; ++index_Of_Start) {
            for (int index_Of_Arrive = 0; index_Of_Arrive < number; ++index_Of_Arrive)
                connected[index_Of_Start][index_Of_Arrive] = this.nextInt();
            // 정점 연결관계를 입력받음(방향 그래프)
        }

        // 하나의 정점마다 BFS실행
        for (int index_Of_Start = 0; index_Of_Start < number; ++index_Of_Start)
            this.direct_BFS(connected, visited, index_Of_Start, number);

        // 도달가능한 정점 출력 하는 반복문
        for(int index_Of_Start = 0; index_Of_Start < number; ++index_Of_Start) {
            for(int index_Of_Arrive = 0; index_Of_Arrive < number; ++index_Of_Arrive)
                System.out.print(visited[index_Of_Start][index_Of_Arrive] + " ");

            System.out.println("");
        }
    }

    private void direct_BFS(int[][] connected, int[][] visited, int index_Of_Start, int number) {
        // 하나의 정점에서 넓이 우선 탐색
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(index_Of_Start);

        while (queue.peek() != null) {
            // 큐가 비어있는 상태가 될 때까지 계속해서 동작
            int index_Of_Search_Start = queue.poll();
            for (int index_Of_Arrive = 0; index_Of_Arrive < number; ++index_Of_Arrive) {
                // 현재 Queue에서 poll된 원소가 도착 정점에 대해 연결 된 경우이면서 처음 BFS를 실행한 정점과 도착 정점이 아직 도달가능하지 못한 경우
                if (connected[index_Of_Search_Start][index_Of_Arrive] == 1 && visited[index_Of_Start][index_Of_Arrive] != 1) {
                    visited[index_Of_Start][index_Of_Arrive] = 1;
                    queue.add(index_Of_Arrive);
                }
            }
        }

    }


    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
}
