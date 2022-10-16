class Solution {

    public int check(String s_, int L, int R)
    {
        int res = 0;

        while (L >= 0 && R < s_.length() && s_.charAt(L) == s_.charAt(R))
        {

            L--;
            R++;

        }


        System.out.print("len " + (R - L - 1) + "\n");



        return R - L - 1;
    }

    public String longestPalindrome(String s) {

        String res = "";

        int max = 0;

        int res_start_index = 0;

        for (int i = 0; i < s.length(); i++)
        {
            // odd match case
            int odd_max = check(s, i, i);

            // even match case
            int even_max = check(s, i, i + 1);

            int cur_max = Math.max(odd_max, even_max);

            if (cur_max > max)
            {
                max = cur_max;
                res_start_index = i - (max - 1) / 2;
            }

        }

        return s.substring(res_start_index, res_start_index + max);
    }
}