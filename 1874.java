import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

// 1874번
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
        Stack<Integer> stack = new Stack();
        int number = this.nextInt();
        int push_Count;
        int print_Count = 1;
        String[] print = new String[2 * number + 1];
        boolean check_imPossible = false;
        int a = this.nextInt();
        push_Count = a;

        // while문 진입 전에 수열의 첫 번 재에 해당하는 수까지 push
        for (int k = 1; k <= a; ++k) {
            stack.push(k);
            print[print_Count] = new String();
            print[print_Count++] = "+";
        }

        // pop실행시 첫 번 째에 해당하는 수가 pop됌
        stack.pop();
        print[print_Count] = new String();
        print[print_Count++] = "-";

        /*
         * 수열을 이룰 수 있을 시 while문이 끝까지 돌지만 수열을 이루지 못하는
         * 경우에는 반복문에서 break를 사용하여 반복문을 종료함
         */
        while (print_Count <= 2 * number) {
            int sequence = this.nextInt(); // 이번 반복문에서 pop되어야 하는 숫자
            if (stack.isEmpty()) {
                // Stack이 비어있을시 push를 여기서 행함. cf) stack.peek()은 stack이 비어있으면 오류 발생
                while (push_Count + 1 <= sequence) {
                    stack.push(++push_Count);
                    print[print_Count] = new String();
                    print[print_Count++] = "+";
                }
            }

            if (stack.peek() == sequence) {
                // stack의 top값이 pop해야 할 값과 같은 경우 pop을 실행
                stack.pop();
                print[print_Count] = new String();
                print[print_Count++] = "-";
            } else if (stack.peek() < sequence) {
                // stack의 top값이 pop해야할 값 보다 작은 경우
                while (stack.peek() < sequence) {
                    stack.push(++push_Count);
                    print[print_Count] = new String();
                    print[print_Count++] = "+";
                }
                stack.pop();
                print[print_Count] = new String();
                print[print_Count++] = "-";
            } else {
                // stack의 top값이 pop해야할 값 보다 작은 경우 수열을 이루어 낼 수 없으므로 반복문 종료처리
                check_imPossible = true;
                break;
            }
        }


        if (check_imPossible) // 수열을 이룰 수 없는 경우
            System.out.println("NO");
        else { // 수열을 이룰 수 있는 경우
            for (int i = 1; i < print_Count; ++i)
                System.out.println(print[i]);
        }

    }

    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
}
