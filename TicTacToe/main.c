#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

typedef struct player
{
char name[20],symbol;
}pl;


int main()
{
    int row=0, column=0,i=0,choice=7;
    char arr[3][3], winner[20]={'N'};
    char start_player[20];
    pl first_player,second_player,current_player;

    fflush(stdin);
    printf("enter name of first player: \n") ;
    gets(first_player.name);
    fflush(stdin);

    printf("enter name of second player: \n");
    gets(second_player.name);

    first_player.symbol='O';
    second_player.symbol='X';
    printf("\nenter the name of player who play  first: \n") ;

    do
    {
        gotoxy(0,7);
        printf("                    ");
         gotoxy(0,7);
        gets(start_player) ;
        fflush(stdin);
        if(strcmp(start_player,first_player.name)!=0 && strcmp(start_player,second_player.name)!=0)
        {
             MessageBeep(1);
            MessageBoxA(NULL,"the given position is already occupied","ERROR!!!",MB_ICONERROR);
        }
    }
    while(strcmp(start_player,first_player.name)!=0 && strcmp(start_player,second_player.name)!=0);

    //setting the player who play first
    if(strcmp(start_player,first_player.name)==0)
    {
        current_player=first_player;
    }
    else
    {
        current_player=second_player;
    }

    printf("\n symbol for %s    : %c\n", first_player.name,first_player.symbol) ;
    printf(" symbol for %s      : %c", second_player.name,second_player.symbol) ;


    gotoxy(40,13) ;
     printf("_    _    _         11   12   13") ;
    gotoxy(40,15) ;
     printf("_    _    _         21   22   23") ;
    gotoxy(40,17) ;
     printf("_    _    _         31   32   33\n\n\n") ;

     do
     {
        for(i=0;i<9;i++)
        {
            gotoxy(0,20);
            printf(" turn of current  player : %s\n",current_player.name) ;

            printf("enter ur row     :          \n") ;
            printf("enter ur column  :           ") ;

            gotoxy(22,21);
            scanf("%d", &row) ;
            row=row-1;
            gotoxy(22,22);
            scanf("%d", &column) ;
            column=column-1;
            if(arr[row][column]=='O' || arr[row][column]=='X')
            {
                MessageBeep(1);
                MessageBoxA(NULL,"the given position is already occupied","ERROR!!!",MB_ICONERROR);
                continue;

            }
            gotoxy(35+(column+1)*5,11+(row+1)*2) ;
            printf("%c  ", current_player.symbol) ;
            arr[row][column]=current_player.symbol;

            if(i>3)
            {
                if(Check_Sequence(arr,row,column,winner,current_player)==1)
                {
                     break;
                }

            }

            //swapping the turn for current player
            if(current_player.symbol==first_player.symbol)
            {
                current_player=second_player;
            }
            else
            {
                current_player=first_player;
            }

        }


            gotoxy(25,25);
            if(winner[0]=='N')
            {
                printf("match tied") ;
            }
            else
            {
                printf("winner is %s\n\n", winner) ;
            }

          //  delay(2000);
            choice=MessageBoxA(NULL,"do you want to continue? ","NULL",MB_YESNO);

            if(choice==6)
            {
                gotoxy(40,13) ;
                printf("_    _    _         11   12   13") ;
                gotoxy(40,15) ;
                printf("_    _    _         21   22   23") ;
                gotoxy(40,17) ;
                printf("_    _    _         31   32   33\n\n\n") ;

                gotoxy(0,25) ;
                printf("                                                                  \n\n                                                                           ");
                memset(arr,0,sizeof(arr));
            }
            else
            {
                exit(EXIT_SUCCESS);
            }
     }
    while(choice==6);

    return 0;
}
