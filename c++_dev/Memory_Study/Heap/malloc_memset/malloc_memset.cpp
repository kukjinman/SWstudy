#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* ptr;

    ptr = (char*)malloc(10);

    printf("%s\n", ptr);

    ptr = NULL;

    memset(ptr, 0, 8);

    ptr[9] = '\0'; // 맨 마지막 요소에 NULL 대입

    // 처음부터 NULL전까지 'f'로 채우고 리턴된 포인터로 출력
    printf("%s\n", (char*)memset(ptr, 'f', 9));

    // ptr로 다시 출력
    printf("%s\n", ptr);

    free(ptr);

    return 0;
}