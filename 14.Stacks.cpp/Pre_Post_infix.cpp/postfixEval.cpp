#include <bits/stdc++.h>
using namespace std;
int calc(int v1, int v2, char op)
{
    if (op == '^')
        return pow(v1, v2);
    else if (op == '+')
        return v1 + v2;
    else if (op == '-')
        return v1 - v2;
    else if (op == '*')
        return v1 * v2;
    else
        return v1 / v2;
}
int evalPostFix(string &str)
{
    stack<int> st;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (isdigit(ch))
            st.push(ch - '0');
        else
        {
            int v1 = st.top(); // v1 and v2 order changed
            st.pop();
            int v2 = st.top();
            st.pop();
            st.push(calc(v1, v2, ch));
        }
    }
    return st.top();
}
int main()
{
    string str = "284/1*+9-";
    cout << evalPostFix(str);
    return 0;
}