class Solution {
    public List<String> validStrings(int n) {
        List<String> list = new ArrayList<>();
        recursiveBacktrack(new String[]{"0", "1"}, "", list, n);
        return list;
    }

    static void recursiveBacktrack(String[] choices, String current_string, List<String> valid_strings, int k) {
        if (current_string.length() == k) {
            if (validString(current_string)) {
                System.out.println(current_string);
                valid_strings.add(current_string);
            }
            return;
        } else if (current_string.length() > k) return;
        for (String choice : choices) {
            recursiveBacktrack(choices, current_string+choice, valid_strings, k);
        }
    }

    static boolean validString(String s) {
        int i = 0, j = 1;
        while (j < s.length()) {
            if (s.charAt(i) == '0' && s.charAt(j) == '0') return false;
            i++;
            j++;
        }
        return true;
    }
}