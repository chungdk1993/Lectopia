#include <stdio.h>
#include <string.h>

int input(char*, char*);
int strcheck(char*, char,int);
void flush();

int main()
{
	char str[100];
	char ch;
	int res, check;
	while (1)
	{
		res = input(str, &ch);
		if (res == 1) // 정상 입력
		{
			check = strcheck(str, ch, - 1);
			if (check != -1)   // 문자열에 찾는 문자가 있는 경우
			{
				printf("\"%s\" 문자열 안에 '%c' 문자는 <%d번> 위치 ", str, ch, check);
				while (check != -1)   // 다중 문자 검색
				{
					check = strcheck(str, ch, check);
					if (check != -1)
						printf("<%d번> 위치 ", check);
					else
						break;
				}
				printf("\b에 존재합니다.\n\n");
			}
			else
				printf("\"%s\" 문자열 안에 '%c' 문자는 존재하지 않습니다.\n\n", str, ch);
		}
		else if (res == 0)
			break;
	}
	return 0;
}

int input(char* string, char *ch)
{
	printf("# 문자열을 입력하시오 : ");
	scanf("%s", string);
	if (strcmp(string, "end") == 0) // end 입력시
		return 0;
	printf("# 문자를 입력하시오 : ");
	if (scanf(" %c", ch) == 1) // 문자열이 end가 아니고 문자하나를 잘 입력한경우
	{
		if (getchar() == '\n')
			return 1;
		else
		{
			printf("<<<<<잘못 입력하셨습니다>>>>>\n");
			flush();
			return -1;
		}
	}
}

int strcheck(char* str, char ch,int check) // 위치 리턴
{
	int i, len;
	len = strlen(str);
	for (i = check+1; i < len; i++)
	{
		if (str[i] == ch)
			return i;
	}
	return -1;
}

void flush()
{
	while (getchar() != '\n') { ; }
}
