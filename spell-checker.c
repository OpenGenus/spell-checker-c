#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

int main()
{
    char str[100];
    printf("\nEnter the string to be checked (Enter characters only): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    if (!loadDictionary())
    {
        printf("\nError while loading dictionary");
        return 1;
    }

    printf("\nThe sentence after checking: ");

    int index = 0;
    char word[MAX_LENGTH + 1];

    for (int i = 0, l = strlen(str); i < l; i++)
    {
        char c = str[i];
        if (isalpha(c))
        {
            word[index] = c;
            index++;
        }
        else if (isdigit(c))
        {
            printf("\n Error no numbers...!");
            return 0;
        }
        else if (index > 0)
        {
            word[index] = '\0';
            index = 0;
            if (!check(word))
            {
                printf("\033[1;31m%s\033[0m ", word);
                printf("%s", " ");
            }
            else
            {
                printf("\033[1;32m%s\033[0m ", word);
                printf("%s", " ");
            }
        }
    }
    if (index > 0)
    {
        word[index] = '\0';
        if (!check(word))
        {
            printf("\033[1;31m%s\033[0m ", word);
        }
        else
        {
            printf("\033[1;32m%s\033[0m ", word);
        }
    }

    unload();

    return 0;
}