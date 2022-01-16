class Solution
{
public:
    int addDigits(int num)
    {
        if (num < 10)
            return num;
        stack<int> stk;
        while (num)
        {
            stk.push(num % 10);
            num /= 10;
        }
        int temp;
        while (1)
        {
            while (!stk.empty())
            {
                temp += stk.top();
                stk.pop();
            }
            if (temp < 10)
                break;
            else
            {
                while (temp)
                {
                    stk.push(temp % 10);
                    temp /= 10;
                }
            }
        }
        return temp;
    }
};

