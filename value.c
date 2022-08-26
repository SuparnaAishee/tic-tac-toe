#include <stdio.h>

char value[10]={'0','1','2','3','4','5','6','7','8','9'};

void Show_Board();                
void Position_Board(int, char);                       //function prototyping
int Check_win();
int main()
{
    int choice,player=1,i;
    char pos;
    do{
    Show_Board();                               //function call
        player= (player % 2) ? 1: 2;

        printf("Player %d> Enter a Number: ",player);
        scanf("%d",&choice);

        pos = (player==1) ? 'X' : 'O';
     Position_Board(choice,pos);

        i=Check_win();
        player++;

    }while(i == -1);

Show_Board();                                       //function call

    if(i==1)
        printf("Player %d Is The Winner",--player);
    else
        printf("<------Its A Tie------>");


    return 0;
}
void Show_Board()                                    //function defination
{
    printf("\n\nTic Tac Toe\n\n");
    
    
    printf(" %c   | %c   | %c   \n",value[1],value[2],value[3]);
   
    printf("--------------- \n");
    printf(" %c   | %c   | %c   \n",value[4],value[5],value[6]);
    
    printf("--------------- \n");
    printf(" %c   | %c   | %c   \n",value[7],value[8],value[9]);
   
    printf("\n");
  
}
void Position_Board( int choice, char pos)             //function defination
{
    if(choice==1 && value[1]=='1')
        value[1]=pos;
    else if(choice==2 && value[2]=='2')
        value[2]=pos;
    else if(choice==3 && value[3]=='3')
        value[3]=pos;
    else if(choice==4 && value[4]=='4')
        value[4]=pos;
    else if (choice==5 && value[5]=='5')
        value[5]=pos;
    else if (choice==6 && value[6]=='6')
        value[6]=pos;
    else if (choice==7 && value[7]=='7')
        value[7]=pos;
    else if (choice==8 && value[8]=='8')
     value[8]=pos;
    else if (choice==9 && value[9]=='9')
     value[9]=pos;
    else
    {
        printf("Invalid Input");
    }
}

int Check_win()                                      //function defination
{
    if(value[1]==value[2] && value[2]==value[3])
        return 1;
    else if(value[4]==value[5] && value[5]==value[6])
        return 1;                                   // horizontal match
    else if (value[7]==value[8] && value[8]==value[9])
        return 1;

    else if (value[1]==value[4] && value[4]==value[7])
        return 1;
    else if(value[2]==value[5] && value[5]==value[8])           // vertical match
        return 1;
    else if(value[3]==value[6] && value[6]==value[9])
        return 1;


    else if(value[1]==value[5] && value[5]==value[9])
        return 1;
    else if(value[3]==value[5] && value[5]==value[7])           //diagonal match
        return 1;

    else if(value[1]!= '1' && value[2]!= '2' && value[3]!= '3' && value[4]!= '4'&& value[5]!= '5' && value[6]!= '6'&& value[7]!= '7' && value[8]!= '8' && value[9]!='9')  //no match
        return 0;

    else
        return -1;
}