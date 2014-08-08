#include <iostream>
#include <cstring>

using namespace std;

//Solution 1: brutal force solution.
class Solution 
{
public:
	char *strStr(char *haystack, char *needle) 
	{
		char *p, *q;
		int i;

		if (haystack==NULL || needle==NULL)
			return NULL;

		int l1 = strlen(haystack);
		int l2 = strlen(needle);

		for (i = 0; i < l1 - l2 + 1; i++)
		{
			for (p=haystack+i, q=needle; *p!='\0' && *q!='\0'; p++, q++)
			{
				if (*p == *q)
					continue;
				else
					break;
			}

			if (*q == '\0')
				return haystack+i;
			else
				continue;
		}

		return NULL;
	}
};

//Solution 2: Another brutal force solution
//reference:
//	http://blog.csdn.net/v_july_v/article/details/7041827
class Solution2
{
public:
     char *strStr(char *haystack, char *needle)
	 {
		 int l1 = strlen(haystack);
		 int l2 = strlen(needle);
		 int i = 0; 
		 int j = 0;

		 if (haystack==NULL || needle==NULL)
		     return NULL;


		 while (i < l1 && j < l2)
		 {
			 if (haystack[i] == needle[j])
			 {
				 i++;
				 j++;
			 }
			 else
			 {
				 i = i - j + 1;
				 j = 0;
			 }
		 }

		 if (j == l2)
		 {
			 return haystack + i - j;
		 }

		 return NULL;
	 }
};

//Solution 3: KMP
//reference:
//	http://blog.csdn.net/v_july_v/article/details/7041827
class Solution3
{
public:
	char *strStr(char *haystack, char *needle)
	{
		int next[50000];

		int l1 = strlen(haystack);
		int l2 = strlen(needle);

		int i = 0;
		int j = 0;
		int k = -1;

		//Calculate next
		next[0] = -1;
		while (j < l2-1)
		{
			if (k == -1 || needle[j] == needle[k])
			{
				j++;
				k++;
				if (needle[j] != needle[k])
					next[j] = k;
				else
					next[j] = next[k];
			}
			else
			{
				k = next[k];
			}
		}

		//KMP Search
		i = 0;
		j = 0;
		while (i < l1 && j < l2)
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				j = next[j];
			}
		}

		if (j == l2)
			return haystack + i - j;

		return NULL;
	}
};

int main()
{
	Solution3 s;
	char str1[100], str2[100];

	strcpy(str1, "abbcdefe");
	strcpy(str2, "cd");

	cout << s.strStr(str1, str2) << endl;

	return 0;
}
