/*	I write a blog for this problem.
 *	http://blog.csdn.net/timberwolf_2012/article/details/38487239
 *
 * */
#include <iostream> 
#include <regex>

using namespace std;

//Solution 1:
//Use RegEx to solve the problem, 
//	but g++4.8.2 seem doesn't support regex.
class Solution
{
public:
	bool isNumber(const char *s)
	{
/*		regex re("( *)[+-]?(\\d+|\\d+\\.\\d*|\\d*\\.\\d+)([eE][+-]?\\d+)?");

		if (regex_match(s, re))
			return true;
		else
			return false;
*/
	}

};

//Solution 2:
//Use DFA to solve the problem.
class Solution2_1
{
public:
	bool isNumber(const char *s)
	{
		int state = 0;

		while (1)
		{
			switch (state)
			{
				case 0:
					if (*s == ' ')
						state = 0;
					else if (*s == '+' || *s == '-')
						state = 1;
					else if (isdigit(*s))
						state = 2;
					else if (*s == '.')
						state = 9;
					else 
						state = 8;
					break;

				case 1:
					if (isdigit(*s))
						state = 2;
					else if (*s == '.')
						state = 9;
					else
						state = 8;
					break;

				case 2:
					if (isdigit(*s))
						state = 2;
					else if (*s == '.')
						state = 3;
					else if (*s == '\0')
						state = 7;
					else if (*s == ' ')
						state = 10;
					else if (*s == 'e' || *s == 'E')
						state = 5;
					else
						state = 8;
					break;
					
				case 3:
					if (isdigit(*s))
						state = 4;
					else if (*s == '\0')
						state = 7;
					else if (*s == ' ')
						state = 10;
					else if (*s == 'e' || *s == 'E')
						state = 5;
					else
						state = 8;
					break;

				case 4:
					if (isdigit(*s))
						state = 4;
					else if (*s == 'e' || *s == 'E')
						state = 5;
					else if (*s == '\0')
						state = 7;
					else if (*s == ' ')
						state = 10;
					else
						state = 8;
					break;

				case 5:
					if (isdigit(*s))
						state = 6;
					else if (*s == '+' || *s == '-')
						state = 11;
					else
						state = 8;
					break;

				case 6:
					if (isdigit(*s))
						state = 6;
					else if (*s == ' ')
						state = 6;
					else if (*s == '\0')
						state = 7;
					else if (*s == ' ')
						state = 10;
					else
						state = 8;
					break;

				case 7:
					return true;

				case 8:
					return false;

				case 9:
					if (isdigit(*s))
						state = 4;
					else
						state = 8;
					break;

				case 10:
					if (*s == '\0')
						state = 7;
					else if (*s == ' ')
						state = 10;
					else
						state = 8;
					break;
				case 11:
					if (isdigit(*s))
						state = 6;
					else 
						state = 8;
					break;
			}
			s++;
		}
	}
};

//Solution 2.2:
//Improve solution 2.1 code.
class Solution2_2
{
public:
	bool isNumber(const char *s)
	{
		int state = 0;
		int translate[][7] =
		{
			0, 1, 2, 8, 9, 8, 8,	//0
			8, 8, 2, 8, 9, 8, 8,	//1
			10, 8, 2, 5, 3, 7, 8,	//2
			10, 8, 4, 5, 8, 7, 8,	//3
			10, 8, 4, 5, 8, 7, 8, 	//4
			8, 11, 6, 8, 8, 8, 8,	//5
			10, 8, 6, 8, 8, 7, 8,	//6
			7, 7, 7, 7, 7, 7, 7,	//7
			8, 8, 8, 8, 8, 8, 8,	//8
			8, 8, 4, 8, 8, 8, 8,	//9
			10, 8, 8, 8, 8, 7, 8, 	//10
			8, 8, 6, 8, 8, 8, 8		//11
		};

		int type;
		while (1)
		{
			if (*s == ' ')
				type = 0;
			else if (*s == '+' || *s == '-')
				type = 1;
			else if (isdigit(*s))
				type = 2;
			else if (*s == 'e' || *s == 'E')
				type = 3;
			else if (*s == '.')
				type = 4;
			else if (*s == '\0')
				type = 5;
			else 
				type = 6;

			state = translate[state][type];

			if (state == 7)
				return true;
			else if (state == 8)
				return false;

			s++;
		}
	}
};


//Solution3:
//Use many flags to indentify the state.
//Isn't recommended.
class Solution3 {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s == NULL)
             return false;
             
         while(isspace(*s))
             s++;
             
         if (*s == '+' || *s == '-')
             s++;
             
         bool eAppear = false;
         bool dotAppear = false;
         bool firstPart = false;
         bool secondPart = false;
         bool spaceAppear = false;
         while(*s != '\0')
         {
             if (*s == '.')
             {
                 if (dotAppear || eAppear || spaceAppear)
                     return false;
                 else
                     dotAppear = true;
             }
             else if (*s == 'e' || *s == 'E')
             {
                 if (eAppear || !firstPart || spaceAppear)
                     return false;
                 else
                     eAppear = true;
             }
             else if (isdigit(*s))
             {
                 if (spaceAppear)
                     return false;
                     
                 if (!eAppear)
                     firstPart = true;
                 else
                     secondPart = true;
             }
             else if (*s == '+' || *s == '-')   // behind of e/E
             {
                 if (spaceAppear)
                     return false;
                     
                 if (!eAppear || !(*(s-1) == 'e' || *(s-1) == 'E'))
                     return false;
             }
             else if (isspace(*s))
                 spaceAppear = true;
             else
                 return false;
                 
             s++;            
         }
         
         if (!firstPart) {
             return false;
         }  else if (eAppear && !secondPart) {
             return false;
         } 
         return true;  
    }
};


int main()
{
	Solution2_2 s;

	cout << "0  =>"    	<< s.isNumber("0") << endl;;
	cout << " 0.1 =>"	 << s.isNumber(" 0.1") << endl;;
	cout << "abc =>" 	<< s.isNumber("abc") << endl; 
	cout << "1 a =>"	<< s.isNumber("1 a") << endl;
	cout << "1. =>"	<< s.isNumber("1.") << endl;
	cout << ".4 =>"	<< s.isNumber(".4") << endl;
	cout << ". =>"	<< s.isNumber(".") << endl;
	cout << "1  =>"	<< s.isNumber("1 ") << endl;
	cout << "3.  =>"	<< s.isNumber("3. ") << endl;
	cout << "46.e+3 =>"	<< s.isNumber("46.e+3") << endl;
	cout << "2e0  =>"	<< s.isNumber("2e0") << endl;
	cout << ".2e81 =>"	<< s.isNumber(".2e81") << endl;


	return 0;
}
