// Check if a substring can be Palindromic by replacing K characters

import java.util.*;
public class CanMakePalindrome {
   
    public static void main(String args[]) {
        String input = "cdecd";
        int result = Test.makePalindrome(input, 0, 3, 0); //string, start index, end index, substitutions
        System.out.println(result);
    }

    public static int makePalindrome(String s, int start, int end, int sub) {
        boolean result;
        
        Set<Character> set = new HashSet<>();
        for (int i = start; i <= end; i++) {
            if (!set.add(s.charAt(i)))
                set.remove(s.charAt(i));
        }
        
        result = sub >= set.size() / 2;
        return result ? 1 : 0;
    }
}