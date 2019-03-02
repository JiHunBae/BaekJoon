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
        int number_Of_Commander = this.nextInt();
        Stack stack = new Stack(number_Of_Commander);
        while (number_Of_Commander > 0) {
            --number_Of_Commander;
            String command = this.next();

            switch (command) {
                case "push":
                    int push_Number = this.nextInt();
                    stack.push(push_Number);
                    break;
                case "pop":
                    stack.pop();
                    break;
                case "size":
                    stack.size();
                    break;
                case "empty":
                    stack.empty();
                    break;
                case "top":
                    stack.top();
                    break;
                default:
                    break;
            }
        }
    }

    private class Stack {
        int[] array; // 배열
        int size = 0; // Stack 사이즈

        public int getSize() {
            return size;
        }

        public void setSize(int size) {
            this.size = size;
        }

        public Stack() {
        }

        public Stack(int number) {
            array = new int[number + 1];
        }

        private void push(int x) {
            // Stack의 size값을 1 늘리고, size에 해당하는 Index에 x값 저장
            this.setSize(this.getSize() + 1);
            this.array[this.getSize()] = x;
        }

        private void pop() {
            if (this.getSize() == 0)
                System.out.println(-1);
            else {
                // size값에 해당하는 배열 값 출력 후 size값을 -1해줌
                System.out.println(this.array[this.getSize()]);
                this.setSize(this.getSize() - 1);
            }
        }

        private void size() {
            // 현재 Stack의 size값 출력
            System.out.println(this.getSize());
        }

        private void empty() {
            // Stack이 비어있는지 아닌지 확인
            if (this.getSize() == 0)
                System.out.println(1);
            else
                System.out.println(0);
        }

        private void top() {
            // 현재 Stack의 top 출력
            if (this.getSize() == 0)
                System.out.println(-1);
            else
                System.out.println(this.array[this.getSize()]);
        }
    }

    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
}
