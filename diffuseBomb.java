class Solution {
    public int[] decrypt(int[] code, int k) {
                if (k == 0) return new int[code.length];
        HashMap<Integer, Integer> map = new HashMap<>();
        int i = 0;
        if (k > 0) {
            while (i < code.length) {
                int startIndex = i+1;
                int count = 0;
                int total = 0;
                while (count < k) {
                    if (startIndex >= code.length) {
                        total += code[startIndex%code.length];
                    } else {
                        total += code[startIndex];
                    }
                    startIndex++;
                    count++;
                }
                map.put(i, total);
                i++;
            }
        } else {
            while (i < code.length) {
            int startIndex = i-1;
            int count = 0;
            int total = 0;
            while (count < Math.abs(k)) {
                if (startIndex < 0) {
                    total += code[startIndex+code.length];
                } else {
                    total += code[startIndex];
                }
                startIndex--;
                count++;
            }
            map.put(i, total);
            i++;
        }    
        }
        int[] ans = new int[code.length];
        for (int j = 0; j < ans.length;j++) {
            ans[j] = map.get(j);
        }
        return ans;
    }
}