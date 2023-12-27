#include <bits/stdc++.h>
using namespace std;

int prec(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}

void InfixtoPostfix(string s, string &ans)
{
    stack<char> st;
    for (char ch : s)
    {
        if (isalpha(ch))
        {
            ans = ans + ch;
        }
        else
        {
            if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    ans = ans + st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && prec(ch) <= prec(st.top()))
                {
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
    }
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
}

int main()
{
    string s;
    cout << "Enter the infix expxression : ";
    cin >> s;
    string ans;
    InfixtoPostfix(s, ans);
    cout << "Resultant Postfix Expression is : " << ans << endl;
    return 0;
}