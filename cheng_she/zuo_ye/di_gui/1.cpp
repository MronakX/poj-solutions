#include <iostream>
#include <iomanip>
using namespace std;
bool factor_value();
bool term_value();
bool expression_value();

bool factor_value()
{
    bool result;
    char c = cin.peek();
    while(c == ' ')
    {
        cin.ignore();
        c = cin.peek();
    }
    if(c == '(')
    {
        cin.get();
        result = expression_value();
        cin.get();
    }
    else if(c == 'V')
    {
        cin.get();
        result = true;
    }
    else if(c == 'F')
    {
        cin.get();
        result = false;
    }
    else if(c == '!')//!在因子外作用，视为项
    {
        cin.get();
        result = term_value();
    }
    return result;
}   

bool term_value()
{
    bool result;
    char op = cin.peek();
    while(op == ' ')
    {
        cin.ignore();
        op = cin.peek();
    }
    if(op == '!')
    {
        result = !factor_value();
    }
    else
    {
        result = factor_value();
    }
    return result;
    
}

bool expression_value()
{
    bool result = term_value();
    bool more = true;
    while(more)
    {
        char op = cin.peek();
        if(op == ' ')//忽略空格继续读
        {
            cin.ignore();
            continue;
        }
        if(op == '&' || op == '|')
        {
            cin.get();
            int value = term_value();
            if(op == '&')
            {
                result = result & value;
            }
            if(op == '|')
            {
                result = result | value;
            }
        }
        else
            more = false;
    }
    if(cin.peek() == '\n')//每一行输入到结尾，return到main函数
    {
        cin.ignore();
    }
    return result;
}

int main()
{
    int t = 1;
    while(cin.peek() != EOF)//ctrl+z = EOF
    {
        cout << "Expression " << t << ": " ;
        if(expression_value())
        {
            cout << "V" << endl;
        }
        else
        {
            cout << "F" << endl;
        }
        t++;
    }
    system("pause");
    return 0;
}