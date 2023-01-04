class Solution {
public:


    stack<int> st;
    int left_max = 0;
    int right_max = 0;


    int trap(vector<int>& height) {

        int ans = 0;
        int prev = height[0];
        int index = 0;
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i] >= prev)
            {
                prev = height[i];
                index = i;
            }
            else
            {
                break;
            }
        }
        left_max = height[index];

        for (int i = index; i < height.size(); i++)
        {


            if (height[i] >= left_max)
            {

                right_max = height[i];
                while (!st.empty())
                {
                    cout << " height : " << height[i] << " st.top : " << st.top() << endl;
                    cout << " left max : " << left_max << " right max : " << right_max << endl;

                    if (right_max > left_max)
                    {

                        cout << " left max : " << left_max << " st. top : " << st.top() << endl;
                        if (left_max > st.top()) {
                            ans += left_max - st.top();
                            // cout << " ans : " << ans << endl;
                        }

                    }
                    else
                    {
                        cout << " right max : " << right_max << " st. top : " << st.top() << endl;
                        if (right_max > st.top()) {
                            ans += right_max - st.top();
                            // cout << " ans : " << ans << endl;
                        }

                    }
                    st.pop();
                }

                left_max = right_max;
                st.push(left_max);

            }
            else {

                st.push(height[i]);

            }

        }

        right_max = 0;

        while (!st.empty())
        {

            if (right_max < st.top())
            {
                right_max = st.top();
            }

            if (right_max > left_max)
            {
                cout << "[Last] left max : " << left_max << " st. top : " << st.top() << endl;
                if (left_max > st.top()) {
                    ans += left_max - st.top();
                    // cout << " ans : " << ans << endl;
                }

            }
            else
            {
                cout << "[Last] right max : " << right_max << " st. top : " << st.top() << endl;
                if (right_max > st.top()) {
                    ans += right_max - st.top();
                    // cout << " ans : " << ans << endl;
                }

            }
            st.pop();

        }



        return ans;
    }



};