class MyQueue {

public:

    stack<int> input, output;

    MyQueue() {

    }

    void push(int x) {

        // Naya element input stack me dalo

        input.push(x);
    }

    int pop() {

        // Agar output khali hai

        if (output.empty()) {

            // input ke saare elements
            // output me transfer karo

            while (!input.empty()) {

                output.push(input.top());

                input.pop();
            }
        }

        // Ab output ka top hi queue ka front hai

        int ans = output.top();

        output.pop();

        return ans;
    }

    int peek() {

        // Agar output khali hai

        if (output.empty()) {

            // Transfer karo

            while (!input.empty()) {

                output.push(input.top());

                input.pop();
            }
        }

        // Front return karo

        return output.top();
    }

    bool empty() {

        // Dono stacks khali hone chahiye

        return input.empty() && output.empty();
    }
};