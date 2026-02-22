#include <stdio.h>
#include <string.h>

void mirror(char str[], int index)
{
    if (index < 0)
        return; // Base case

    printf("%c", str[index]);
    mirror(str, index - 1); // Recursive call
}

int main()
{
    char str[100];

    printf("Enter code name: ");
    scanf("%s", str); // No spaces as given in question

    int length = strlen(str);

    mirror(str, length - 1);

    return 0;
}