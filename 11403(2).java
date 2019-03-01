import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private StringTokenizer _st;
    private BufferedReader _br;
    private int number_Of_Vertex;
    private int point_Of_Search_Start = 1;
    private int[][] connected; // 연결 상태를 나타내는 배열
    private int[][] visit; // 도달 가능한지 여부를 나타내는 배열

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
        number_Of_Vertex = this.nextInt(); // 정점의 개수
        this.input_Connect(number_Of_Vertex);
        for (int index = 1; index <= number_Of_Vertex; ++index) {
            this.search_DFS(index);
            ++point_Of_Search_Start;
        }

        this.print_Result();
    }

    private void input_Connect(int number_Of_Vertex) {
        // 입력된 수들을 방향 그래프의 정점 연결상태로 저장
        connected = new int[number_Of_Vertex + 1][number_Of_Vertex + 1];
        visit = new int[number_Of_Vertex + 1][number_Of_Vertex + 1];

        for (int index_Column = 1; index_Column <= number_Of_Vertex; ++index_Column)
            for (int index_Row = 1; index_Row <= number_Of_Vertex; ++index_Row)
                connected[index_Column][index_Row] = this.nextInt();
    }


    private void search_DFS(int next) {
        for (int index = 1; index <= number_Of_Vertex; ++index)
            if(connected[next][index] == 1 && visit[point_Of_Search_Start][index] != 1) {
                visit[point_Of_Search_Start][index] = 1;
                this.search_DFS(index);
            }
    }

    private void print_Result() {
        for(int index_Column = 1; index_Column <= number_Of_Vertex; ++index_Column) {
            for (int index_Row = 1; index_Row <= number_Of_Vertex; ++index_Row)
                System.out.print(visit[index_Column][index_Row] + " ");

            System.out.println("");
        }
    }
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
}
