import java.util.*;


public class Main {
    Scanner sc = new Scanner(System.in);
    Queue<Integer> queue = new LinkedList<Integer>();
    int number_Of_Vertices;
    int number_Of_Edges;
    int first_Search_Point;
    int[][] connect;
    int[] visited;

    private void add(int vertices_1, int vertices_2) {
        try {
            // (1 == 연결, 0 == 미연결)
            connect[vertices_1 - 1][vertices_2 - 1] = 1;
            connect[vertices_2 - 1][vertices_1 - 1] = 1;
        } catch (ArrayIndexOutOfBoundsException array_Out_Exception) {
            System.out.println("[Error] 배열 범위를 벗어났습니다.");
        }
    }

    private void search_BFS() {
        visited = new int[number_Of_Vertices]; // visited(방문 확인)배열 초기화
        visited[first_Search_Point - 1] = 1; // 최초 정점 방문 체크
        queue.add(first_Search_Point); // 최초 방문 정점 Queue에 삽입
        System.out.print(first_Search_Point + " ");

        while (queue.peek() != null) {
            int search_Point = queue.poll();

            for (int vertex = 1; vertex <= number_Of_Vertices; ++vertex) {
                if (connect[search_Point - 1][vertex - 1] == 1 && visited[vertex - 1] != 1) {
                    visited[vertex - 1] = 1;
                    queue.add(vertex);
                    System.out.print(vertex + " ");
                }
            }
        }

        System.out.println("");
    }

    private void recu_Search_DFS(int search_Point) {

        visited[search_Point - 1] = 1;
        System.out.print(search_Point + " ");
        for (int vertex = 1; vertex <= number_Of_Vertices; ++vertex) {
            if (connect[search_Point - 1][vertex - 1] == 1 && visited[vertex - 1] != 1)
                this.recu_Search_DFS(vertex);
        }
    }

    private void iter_Search_DFS(int search_Point) {
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(search_Point);

        while (!stack.isEmpty()) {
            int search_Vertex = stack.pop();

            if (visited[search_Vertex - 1] != 1) {
                visited[search_Vertex - 1] = 1;

                System.out.print(+search_Vertex + " ");

                for (int vertex = number_Of_Vertices; vertex > 0; --vertex) {
                    if (connect[search_Vertex - 1][vertex - 1] == 1 && visited[vertex - 1] != 1)
                        stack.push(vertex);
                }
            }
        }
    }


    private void visited_Initialization() {
        visited = new int[number_Of_Vertices];
    }

    public void solve() {
        try {
            number_Of_Vertices = sc.nextInt();
            number_Of_Edges = sc.nextInt();
            first_Search_Point = sc.nextInt();

            connect = new int[number_Of_Vertices][number_Of_Vertices];

            // 정점이 하나도 없는 경우 또는 검색 시작지점이 정점의 개수보다 더 큰 수인 경우 종료
            if (number_Of_Vertices < 1 || first_Search_Point > number_Of_Vertices) {
                return;
            }
            // 정점 간의 연결 부분
            for (int count = 0; count < number_Of_Edges; ++count) {
                int first_Vertice = sc.nextInt();
                int second_Vertice = sc.nextInt();
                this.add(first_Vertice, second_Vertice);
            }

            this.visited_Initialization(); // 배열 초기화
            this.recu_Search_DFS(first_Search_Point); // 재귀 DFS
            //this.iter_Search_DFS(first_Search_Point); // Stack이용 DFS
            System.out.println(""); // 줄바꿈

            this.visited_Initialization(); // 배열 초기화
            this.search_BFS(); // BFS

        } catch (NullPointerException null_Exception) {
            System.out.println("[Error] 예외처리(NULL Point");
        } catch (InputMismatchException input_Exception) {
            System.out.println("[Error] 잘못된 형태의 입력입니다.");
        }
    }


    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
}
