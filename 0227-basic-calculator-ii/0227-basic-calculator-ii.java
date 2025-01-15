class Solution {
    public int calculate(String s) {
        
    if (s == null || s.length() == 0) {
            return 0;
        }

        s = s.replaceAll(" ", "");

        int n = s.length();
        int currentNumber = 0;
        char operation = '+';
        java.util.Stack<Integer> stack = new java.util.Stack<>();

        for (int i = 0; i < n; i++) {
            char currentChar = s.charAt(i);

            if (Character.isDigit(currentChar)) {
                currentNumber = currentNumber * 10 + (currentChar - '0');
            }

            if (!Character.isDigit(currentChar) || i == n - 1) {
                if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '*') {
                    stack.push(stack.pop() * currentNumber);
                } else if (operation == '/') {
                    stack.push(stack.pop() / currentNumber); 
                }

                operation = currentChar;
                currentNumber = 0;
            }
        }

        int result = 0;
        while (!stack.isEmpty()) {
            result += stack.pop();
        }

        return result;
}}