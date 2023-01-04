
// This fails by the Invalid test case.

class Solution {
    public int reverse(int x) {
        int ret  =0;    
        String temp = Integer.toString(x);


        System.out.print("temp " + temp);
        System.out.println();

        LinkedList<Integer> ll = new LinkedList<>();

        boolean negative_flag = false;
        boolean pre_zero_flag = false;

        if(x == 0)
        {
            return 0;
        }
        
        for(int i = temp.length(); i > 0 ; i--)
        {
            if(temp.charAt(i-1) == '-')
            {
                negative_flag = true;
            }
            else if(temp.charAt(i-1) == '0')
            {
                if(pre_zero_flag == true)
                {
                    ll.add(temp.charAt(i-1) - '0');
                }

                continue;

            }
            else{
                pre_zero_flag = true;

                System.out.print(": " + (temp.charAt(i-1) - '0'));

                ll.add(temp.charAt(i-1) - '0');
            }

        }

        String res_tmp = "";
        for(int i =0; i < ll.size();i++)
        {
            res_tmp += ll.get(i);
        }

        ret = Integer.parseInt(res_tmp);

        if(negative_flag == true)
        {
            ret = ret * -1;
        }


        return ret;
    }
}