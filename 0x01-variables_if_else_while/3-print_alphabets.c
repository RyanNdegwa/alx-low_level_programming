#include <stdio.h>

/**
 * main - alphabets
 *
 * Return: 0
*/
int main(void)
{
char ch = 'a';
while (ch <= 'z')
{
printf("%c", ch);
ch++;
} 
char ch = 'A';
while (ch <= 'Z')
{
printf("%c", ch);
ch++;
}
printf("\n");
return (0);
}

