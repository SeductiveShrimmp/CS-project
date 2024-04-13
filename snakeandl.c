#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int pos1=1;
int pos2=1;

int randomNumber()
{
	int rem;
	srand(time(NULL));
	rem=rand()%6 + 1;
	return rem;
}

void board(int cp, int player)
{	
    //W
	if(cp==100)
	{
		printf("*****Congratulations*****\n\n\n%s wins\n",(player==1)?"PLAYER 1":"PLAYER 2");
		scanf("%*s");
		exit(0);
	}
	
	//SNAKES
	if(cp==63){
	    printf("Oops!! That was a nasty bite ");
	    printf("\nSNAKE FROM 63 TO 18\n");
	    cp=18;
	}
	else if(cp==32){
	    printf("Oops!! That was a nasty bite ");
	    printf("\nSNAKE FROM 32 TO 10\n");
	    cp=10;
	}
	else if(cp==48){
	    printf("Oops!! That was a nasty bite ");
	    printf("\nSNAKE FROM 48 TO 26\n");
	    cp=26;
	}
	else if(cp==88){
	    printf("Oops!! That was a nasty bite ");
	    printf("\nSNAKE FROM 88 TO 24\n");
	    cp=24;
	}
	else if(cp==99){
	    printf("DAMN :_)");
	    printf("\nSNAKE FROM 99 TO 1\n");
	    cp=1;
	}
	
	//LADDERS
	else if(cp==4){
	    printf("Weee!! Upp we gooo ");
	    printf("\nLADDER AT 4 TO 18\n");
	    cp=18;
	}
	else if(cp==60){
	    printf("Weee!! Upp we gooo ");
	    printf("\nLADDER AT 60 TO 83\n");
	    cp=83;
	}
	else if(cp==70){
	    printf("Weee!! Upp we gooo ");
	    printf("\nLADDER AT 70 TO 93\n");
	    cp=93;
	}
	else if(cp==28){
	    printf("Weee!! Upp we gooo");
	    printf("\nLADDER AT 28 TO 76\n");
	    cp=76;
	}
	else if(cp==50){
	    printf("Weee!! Upp we gooo ");
	    printf("\nLADDER AT 50 TO 67\n");
	    cp=67;
	}

    //UPDATING POSITIONS
    if(player==1){
        pos1=cp;   
    }
    else{
        pos2=cp;
    }
    
	for(int i=0;i<10;i++)
	{
		for(int j=1; j<=10; j++)
		{
		      int curr=(i*10 + j);
		      
		      if(player ==1 && pos1==curr)
		      {
		          printf("*P1*\t");
		      }
		      else if(player ==2 && pos2==curr)
		      {
		          printf("*P2*\t");
		      }
		      else{
		        printf("%d\t",curr);
		      }
		}
		printf("\n\n");
	}

	

	printf("--------------------------------------------------------------------------\n");
}

void main()
{
	int dice;
	char ch;
	
	while(true)
	{
	    printf("		** SNAKE AND LADDER GAME** \n	    	CODED BY GROUP 33\n");
		printf("Snakes:- 63 to 18,\t 32 to 10,\t 48 to 26,\t 88 to 24,\t 99 to 1.\nLadder:- 4 to 14,\t 60 to 83,\t 70 to 93,\t 28 to 76.\n");
		printf("Choose your option\n");
		printf("1. Player 1 plays\n");
		printf("2. Player 2 plays\n");
		printf("3. Exit\n");
		scanf("%s",&ch);
	
	    int fwd=0;
		switch(ch)
		{
		    
			case '1':
    			dice=randomNumber();
    			system("clear");
				printf("\t\t\t\tDice = %d\n\n",dice);
				fwd+=dice;
				
				if(dice==6)
				{
				    printf("Dice = 6: You have earned a chance to play one more time.\n");
				    dice=randomNumber();
				    printf("\t\t\t\tDice = %d\n\n",dice);
				    fwd+=dice;
				}
				
				if(pos1+ fwd>=101){
				    fwd=0;
				    printf("Overshoot!! Turn Ended...\n\n");
				    board(pos1,1);
				    continue;
				}
				else{
					board(pos1+fwd,1);
				}
				printf("Player 2 position is %d\n\n",pos2);
			
			break;
			
			case '2':
    			dice=randomNumber();
    			system("clear");
				printf("\t\t\t\tDice = %d\n\n",dice);
				fwd+=dice;
				
				if(dice==6)
				{
				    printf("Dice = 6: You have earned a chance to play one more time.\n");
				    dice=randomNumber();
				    printf("\t\t\t\tDice = %d\n\n",dice);
				    fwd+=dice;
				}
				
				if(pos2+ fwd>=101){
				    fwd=0;
				    printf("Overshoot!! Turn Ended...\n\n");
				    board(pos1,1);
				    continue;
				}
				else{
					board(pos2+fwd,2);
				}
				printf("Player 1 position is %d\n\n",pos1);
				
			break;
			
			case '3':
			    exit(0);
			    
			break;
			
			default:
			    printf("Incorrect choice.Try Again\n");
			 
			break;
				
		}
		
	}
	
}
