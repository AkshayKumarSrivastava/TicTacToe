#include<stdio.h>
typedef struct player
{
char name[20],symbol;
}pl;

int Check_Sequence(char arr[][3],int row,int column,char winner[20],pl current_player)
{

    if(arr[row][column]==arr[(row+1)%3][column]  &&  arr[(row+1)%3][column]==arr[(row+2)%3][column] )
    {
        strcpy(winner,current_player.name);
        SetColor(2);

        gotoxy(35+(column+1)*5,11+(row+1)*2) ;
        printf("%c  ", current_player.symbol) ;
        gotoxy(35+(column+1)*5,11+((row+1)%3+1)*2) ;
        printf("%c  ", current_player.symbol) ;
        gotoxy(35+(column+1)*5,11+((row+2)%3+1)*2) ;
        printf("%c  ", current_player.symbol) ;

        SetColor(7);
        return(1);
    }
    else if(  arr[row][column]==arr[row][(column+1)%3]  &&  arr[row][(column+1)%3]==arr[row][(column+2)%3])
    {
        strcpy(winner,current_player.name);
        SetColor(2);
        //printf("%c",arr[row][(column+2)%3]);

        gotoxy(35+(column+1)*5,11+(row+1)*2) ;
        printf("%c  ", current_player.symbol) ;
        gotoxy(35+((column+1)%3+1)*5,11+(row+1)*2) ;
        printf("%c  ", current_player.symbol) ;
        gotoxy(35+((column+2)%3+1)*5,11+(row+1)*2) ;
        printf("%c  ", current_player.symbol) ;

        SetColor(7);
        return(1);
    }
    if((row+column)%2==0)
    {
        if (  (arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])    )
        {
            strcpy(winner, current_player.name);
            SetColor(2);

            gotoxy(35+(1)*5,11+(1)*2) ;
            printf("%c  ", current_player.symbol) ;
            gotoxy(35+(2)*5,11+(2)*2) ;
            printf("%c  ", current_player.symbol) ;
            gotoxy(35+(3)*5,11+(3)*2) ;
            printf("%c  ", current_player.symbol) ;

            SetColor(7);
            return(1);
        }
        else if(  (arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]))
        {
            strcpy(winner, current_player.name);
            SetColor(2);

            gotoxy(35+(2+1)*5,11+(0+1)*2) ;
            printf("%c  ", current_player.symbol) ;
            gotoxy(35+(1+1)*5,11+(1+1)*2) ;
            printf("%c  ", current_player.symbol) ;
            gotoxy(35+(1)*5,11+(2+1)*2) ;
            printf("%c  ", current_player.symbol) ;

            SetColor(7);
            return(1);
        }
    }
        return(0);
}
