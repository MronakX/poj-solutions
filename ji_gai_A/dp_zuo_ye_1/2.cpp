#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110;
class CHugeInt {
	// 初始化，h+h, h+num, num+h, +=, ++i, i++, ostream
	int n;
	char num[210] = {};
	int len;

public:
	CHugeInt(int n)
	{
		//int i = 0;
		int len1 = 0;
		char tmp[210] = {};
		while (n > 0)
		{
			tmp[len1++] = n % 10 + '0';
			n /= 10;
		}
		len = len1;
		len1--;
		for (int i = 0; i < len; i++)
		{
			num[i] = tmp[len1--];
		}
	}

	CHugeInt(const char* s)
	{
		len = strlen(s);
		strcpy(num, s);
	}

	CHugeInt operator + (CHugeInt& s)
	{
		int q = 209;
		while (num[q] == 0 || num[q] == '0')
		{
			num[q] = 0;
			q--;
		}
		q = 209;
		while (s.num[q] == 0 || s.num[q] == '0')
		{
			s.num[q] = 0;
			q--;
		}
		int num1[210] = {};
		int num2[210] = {};
		int len1 = strlen(num);
		int len2 = strlen(s.num);
		int i, j = 0;
		for (int i = len1 - 1; i >= 0; i--)
		{
			num1[j++] = num[i] - '0';
		}
		j = 0;
		for (int i = len2 - 1; i >= 0; i--)
		{
			num2[j++] = s.num[i] - '0';
		}
		CHugeInt sum(0);
		int sum1[210] = {};
		for (int i = 0; i < 210; i++)
		{
			sum1[i] += num1[i] + num2[i];
			if (sum1[i] >= 10)
			{
				sum1[i] -= 10;
				sum1[i + 1] ++;
			}
		}
		for (int i = 0; i < 210; i++)
		{
			sum.num[i] = sum1[i] + '0';
		}
		CHugeInt sum2(0);
		i = 209, j = 0;
		while (sum.num[i] == 0 || sum.num[i] == '0')
			i--;
		for (; i >= 0; i--)
		{
			sum2.num[j++] = sum.num[i];
		}
		return sum2;
	}

	friend CHugeInt operator + (CHugeInt s, int n)//de
	{
		//CHugeInt temp(n);
		//return s + n;
		CHugeInt temp(n);
		s = temp + s;
		return s;
	}

	friend CHugeInt operator + (int n, CHugeInt s)
	{
		//CHugeInt temp(n);
		//return s + n;
		CHugeInt temp(n);
		s = temp + s;
		return s;
	}


	//+=,++在整数范围内
	CHugeInt& operator += (int n)
	{
		CHugeInt temp(n);
		*this = *this + temp;
		return *this;
	}
	CHugeInt& operator ++ ()//前置
	{
		CHugeInt temp(1);
		*this = *this + temp;
		return *this;
	}
	CHugeInt operator ++ (int k)//后置
	{
		CHugeInt tmp(*this);
		*this += 1;
		return tmp;
	}

	friend ostream& operator <<(ostream& o, const CHugeInt& s)
	{
		cout << s.num;
		return o;
	}
};
int  main()
{
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout << ++b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	system("PAUSE");
	return 0;
}