import java.util.ArrayList;
import java.util.List;

class recursive_backtracking1 {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> outer_list = new ArrayList<>();
        List<Integer> current_list = new ArrayList<>();
        recursiveBacktrack(nums, current_list, outer_list);
        return outer_list;
    }

    static void recursiveBacktrack(int[] nums, List<Integer> current_list, List<List<Integer>> outer_list) {
        if (current_list.size() == nums.length) {
            System.out.println(current_list);
            outer_list.add(new ArrayList<>(current_list));
            return;
        }
        for (int num : nums) {
            if (current_list.contains(num)) continue;
            current_list.add(num);
            recursiveBacktrack(nums, current_list, outer_list);
            current_list.remove(current_list.size() - 1);
        }
    }
}