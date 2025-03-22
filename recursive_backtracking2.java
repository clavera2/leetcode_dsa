import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

/* Question: GENERATE VALID PARENTHESIS */
class recursive_backtracking2 {
    public List<String> generateParenthesis(int n) {
        List<String> valid_parenthesis = new ArrayList<>();
        recursiveBacktrack("", new String[] {"(", ")"}, n*2, new HashSet<>(), valid_parenthesis);
        return valid_parenthesis;
    }

    static void recursiveBacktrack(String current_bracket, String[] bracket_choice, int max_count, HashSet<String> seen_brackets, List<String> valid_brackets) {
        if (seen_brackets.contains(current_bracket)) return;
        if (current_bracket.length() == max_count) {
            if (isValidParenthesis(current_bracket)) {
                seen_brackets.add(current_bracket);
                //System.out.println(current_bracket);
                valid_brackets.add(current_bracket);
            }
            return; //print the bracket then backtrack
        }
        for (String bracket : bracket_choice) {
            recursiveBacktrack(current_bracket+bracket, bracket_choice, max_count, seen_brackets, valid_brackets);
        }
    }

    static boolean isValidParenthesis(String s) {
        Stack<Character> stack = new Stack<>();
        for (char bracket : s.toCharArray()) {
            if (bracket == '(') {
                stack.push(bracket);
            } else {
                if (stack.isEmpty()) return false;
                stack.pop();
            }
        }
        if (stack.isEmpty()) return true;
        return false;
    }
}