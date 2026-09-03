class Solution {
    static String[] key = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    public void helper(String digit, StringBuilder s, List<String> list){
        if(digit.length()==0){
            list.add(s.toString());
            return;
        }
        int idx = digit.charAt(0)-'0';
        for(int i=0;i<key[idx].length();i++){
            s.append(key[idx].charAt(i));
            helper(digit.substring(1), s, list);
            s.deleteCharAt(s.length()-1);
        }
    }

    public List<String> letterCombinations(String digits) {

        List<String> list = new ArrayList<>();
        if(digits.length() == 0)return list;
        helper(digits, new StringBuilder(),list);
        return list;

    }
}