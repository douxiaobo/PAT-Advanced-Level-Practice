#include <stdio.h>
#include <stdlib.h>
//有链表和静态数组两种方式，我比较习惯用链表，链表对于需要不定改变长度的操作很便捷
//静态数组也可以使用，不过需要计算转换后的整个字符串长度
//设数字长度为count_num,正负号长度为(0或1)
//所需要的逗号数目为count_char;
//len = count_num + 0或1 + count_char; 
//所以可以设定char *num = (char *)malloc(sizeof(char)*len);然后进行计算
typedef struct line{
    char data;
    struct line *next;
}line;
int main( void ){
    line *head = (line *)malloc(sizeof(line));
    head->next = NULL;
    int num_1, num_2, sum;
    if(scanf("%d %d",&num_1, &num_2)){};
    sum = num_1 + num_2;
    int num = (sum>=0?(sum):(-sum));
    if( num == 0 )  printf("0");
    int count_num=0;
    while( num )
    {
        int a = num%10;
        line * p = (line*)malloc(sizeof(line));
        p->next = head->next;
        p->data = a + '0';
        head->next = p;
        count_num++;
        if( count_num % 3 == 0 && num/10!=0)
        {
            line * p = (line*)malloc(sizeof(line));
            p->next = NULL;
            p->data = ',';
            p->next = head->next;
            head->next = p;
        }
        num = num/10;
    }
    if( sum < 0 )
        head->data = '-';
    line * p = head;
    if( sum > 0 )
        p = p->next;
    while( p!=NULL )
    {
        printf("%c", p->data );
        p = p->next;
    }
    return 0;
}