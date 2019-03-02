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
        Queue queue = new Queue();
        int number_Of_Commander = this.nextInt();

        while(number_Of_Commander > 0) {
            --number_Of_Commander;
            String command = this.next();

            switch(command) {
                case "push" :
                    int push_Number = this.nextInt();
                    queue.push(push_Number);
                    break;
                case "pop" :
                    queue.pop();
                    break;
                case "size" :
                    queue.size();
                    break;
                case "empty" :
                    queue.empty();
                    break;
                case "front" :
                    queue.front();
                    break;
                case "back" :
                    queue.back();
                    break;
                default :
                    break;
            }
        }
    }

    private class Queue {
        int value = 0, size = 0;
        Queue next;

        public Queue() {}

        public int getSize() {
            return size;
        }

        public void setSize(int size) {
            this.size = size;
        }

        public int getValue() {
            return value;
        }

        public void setValue(int value) {
            this.value = value;
        }

        public Queue getNext() {
            return next;
        }

        public void setNext(Queue next) {
            this.next = next;
        }

        private void push(int x) {
            Queue temp = this;

            while(temp.getNext() != null) {
                temp = temp.getNext();
            }

            temp.setValue(x);
            temp.setNext(new Queue());
            this.setSize(this.getSize() + 1);
        }

        private void pop() {
            if(this.getSize() == 0)
                System.out.println(-1);
            else {
                int return_Value = this.getValue();
                Queue temp = this;
                temp = temp.getNext();
                this.setValue(temp.getValue());
                this.setNext(temp.getNext());
                this.setSize(this.getSize() - 1);
                System.out.println(return_Value);
            }
        }

        private void size() {
            System.out.println(this.getSize());
        }

        private void empty() {
            if(this.getSize() == 0)
                System.out.println(1);
            else
                System.out.println(0);
        }

        private void front() {
            if(this.getSize()== 0)
                System.out.println(-1);
            else
                System.out.println(this.getValue());
        }

        private void back() {
            if(this.getSize() == 0)
                System.out.println(-1);
            else {
                Queue temp = this;
                int count = 1;
                while(count < this.getSize()) {
                    temp = temp.getNext();
                    ++count;
                }

                System.out.println(temp.getValue());
            }
        }
    }

    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
}
