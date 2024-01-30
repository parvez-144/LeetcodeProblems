class Solution {
public:
    int eval(int num1,int num2,char op){
        if(op=='+'){
            return num1+num2;
        }
        else if(op=='-'){
            return num2-num1;
        }
        else if(op=='*'){
            return num1*num2;
        }
        return num2/num1;
    }
    int evalRPN(vector<string>& s) {
        stack<int>st;
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!="+"&&s[i]!="-"&&s[i]!="*"&&s[i]!="/"){
                st.push(stoi(s[i]));
            }
            else{
                int num1=st.top();
                st.pop();
                int num2=st.top();st.pop();
                int val=eval(num1,num2,s[i][0]);
                st.push(val);
            }
        }
        return st.top();
    }
};