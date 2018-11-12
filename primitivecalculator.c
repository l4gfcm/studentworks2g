#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
printf("argc = %d\n", argc);

for(int ndx = 0; ndx != argc; ++ndx)
printf("argv[%d] --> %s\n", ndx,argv[ndx]);
printf("argv[argc] = %p\n", (void*)argv[argc]);
int a_flag=0;
if ( (argc == 2) && strcmp( argv[1], "x" ) == 0 )
{
a_flag=1;
}
float num1;
float num2;
char op;

printf("Первое число: ");
scanf("%f",&num1);
printf("Второе число: ");
scanf("%f",&num2);
printf("Оператор ( + - * / ): ");
char buff[3];
scanf("%s", buff);
while (buff[0] != EOF)
{
op=buff[0];
if (op == '+'){
        if (a_flag == 1){
                printf("%6.2f + %6.2f=%6.2f \n",num1,num2,num1 + num2);
                        }
        else
        {
        printf("%6.2f\n",num1 + num2);
        }
        }
else if(op == '-'){
                if (a_flag == 1)
                {
                printf("%6.2f - %6.2f=%6.2f \n",num1,num2,num1 - num2);
        }
        else
        {
        printf("%6.2f\n",num1 - num2);
        }
}
else if(op == '*')
{
                if (a_flag == 1)
                {
                printf("%6.2f * %6.2f=%6.2f \n",num1,num2,num1 * num2);
                }
        else
        {
        printf("%6.2f\n",num1 * num2);
        }
}
else if(op == '/')
                {
                if(num2 == 0)
                {
                printf("Ошибка: деление на ноль!\n");
                }
                else
                        {
                        if (a_flag == 1)
                        printf("%6.2f / %6.2f=%6.2f \n",num1,num2,num1 / num2);
                        else
                        printf("%6.2f\n",num1 / num2);
                        }

}
else
{
printf("Ошибка: неверное действие!\n");
printf("%d", op);
}
scanf("%s", buff);
}
return 0;
}
