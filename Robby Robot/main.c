#include <stdio.h>
#include <ctype.h>
#include <windows.h>

typedef struct{
    int x;
    int y;
    int move;
    char location;
    char choice;
}Menu;

Menu menu;

void printPrompt();
void selectedPrompt();

int main()
{
    menu.x = 0;
    menu.y = 0;

    while(menu.choice != 'd')
    {
        printPrompt();
        selectedPrompt();
    }
    return 0;
}

void printPrompt()
{
        system("cls");
        printf(" ________________________________________\n");
        printf("+                                        +\n");
        printf("|\t Robby Robot Commands Menu       |\n");
        printf("+________________________________________+\n");
        printf("|                                        |\n");
        printf("|\t\ta] Origin                |\n");
        printf("|\t\tb] Location              |\n");
        printf("|\t\tc] Move                  |\n");
        printf("|\t\td] Exit:                 |\n");
        printf("+________________________________________+");
        printf("\n\nEnter a valid choice<a-d>: ");
}

void selectedPrompt()
{
    scanf(" %c", &menu.choice);
        switch(menu.choice){
                case 'c':
                    system("cls");
                    printf("\t\tEnter where to move\n\n");
                    printf("====================================================================\n");
                    printf("||                                                                ||\n");
                    printf("||\t\tE-East    W-West     S-South     N-North          ||\n");
                    printf("||              ------    ------     -------     -------          ||\n");
                    printf("====================================================================\n");
                    scanf(" %c", &menu.location);
                    printf("\n\n\t\tEnter how many points you move:--> ");
                    scanf("%d", &menu.move);
                    if(toupper(menu.location) == 'E')
                    {
                        menu.x -= menu.move;
                        break;
                    }
                    else if(toupper(menu.location) == 'W')
                    {
                        menu.x += menu.move;
                        break;
                    }
                    else if(toupper(menu.location) == 'S')
                    {
                        menu.y -= menu.move;
                        break;
                    }
                    else if(toupper(menu.location) == 'N');
                    {
                        menu.y += menu.move;
                        break;
                    }
                    break;
                case 'b':
                    printf("\n\nRobbys Location:--> %d,%d", menu.x, menu.y);
                    break;
                case 'a':
                    menu.x = 0;
                    menu.y = 0;
                    printf("\n\nRobbys Location:--> %d,%d", menu.x, menu.y);
                    break;
                case 'd':
                    printf("Program Terminated");
                    break;
                default:
                    printf("Enter valid choice");
            }
            printf("\n\nPress any key to continue...");
            getch();
}
