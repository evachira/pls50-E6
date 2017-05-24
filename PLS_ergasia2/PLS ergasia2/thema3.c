#include <stdio.h>
#include <time.h>

struct player
{
	char playername[17];
	int bathmos;
	char id;
};

struct card
{
	char color;
	char shape;
	char numb;
	char ifi;
};

struct card storecards[12];
struct card storetwocards[3][4];

struct player gameplayers[3] = {{"Marina Andreou",0,'a'},{"Kostas Grammenos",0,'g'},{"Maria Perdika",0,'p'}};

//pinakas me olous tous dinatous sindiasmous os pros to sxima to xroma ton arithmo kai tin yfi.
struct card cards[81] = {
{'g','c','1','b'}, {'g','c','1','h'}, {'g','c','1','e'},
{'g','c','2','b'}, {'g','c','2','h'}, {'g','c','2','e'},
{'g','c','3','b'}, {'g','c','3','h'}, {'g','c','3','e'},
{'g','t','1','b'}, {'g','t','1','h'}, {'g','t','1','e'},
{'g','t','2','b'}, {'g','t','2','h'}, {'g','t','2','e'},
{'g','t','3','b'}, {'g','t','3','h'}, {'g','t','3','e'},
{'g','r','1','b'}, {'g','r','1','h'}, {'g','r','1','e'},
{'g','r','2','b'}, {'g','r','2','h'}, {'g','r','2','e'},
{'g','r','3','b'}, {'g','r','3','h'}, {'g','r','3','e'},

{'b','c','1','b'}, {'b','c','1','h'}, {'b','c','1','e'},
{'b','c','2','b'}, {'b','c','2','h'}, {'b','c','2','e'},
{'b','c','3','b'}, {'b','c','3','h'}, {'b','c','3','e'},
{'b','t','1','b'}, {'b','t','1','h'}, {'b','t','1','e'},
{'b','t','2','b'}, {'b','t','2','h'}, {'b','t','2','e'},
{'b','t','3','b'}, {'b','t','3','h'}, {'b','t','3','e'},
{'b','r','1','b'}, {'b','r','1','h'}, {'b','r','1','e'},
{'b','r','2','b'}, {'b','r','2','h'}, {'b','r','2','e'},
{'b','r','3','b'}, {'b','r','3','h'}, {'b','r','3','e'},

{'r','c','1','b'}, {'r','c','1','h'}, {'r','c','1','e'},
{'r','c','2','b'}, {'r','c','2','h'}, {'r','c','2','e'},
{'r','c','3','b'}, {'r','c','3','h'}, {'r','c','3','e'},
{'r','t','1','b'}, {'r','t','1','h'}, {'r','t','1','e'},
{'r','t','2','b'}, {'r','t','2','h'}, {'r','t','2','e'},
{'r','t','3','b'}, {'r','t','3','h'}, {'r','t','3','e'},
{'r','r','1','b'}, {'r','r','1','h'}, {'r','r','1','e'},
{'r','r','2','b'}, {'r','r','2','h'}, {'r','r','2','e'},
{'r','r','3','b'}, {'r','r','3','h'}, {'r','r','3','e'},
};


void arxikop()
{
   int i,j,p,flag,store;

   time_t t;
   /* Arxikopoiisi genitrias tixewn arithmwn */
   srand((unsigned) time(&t));

   for( i = 0 ; i < 12 ; i++ )
   {
   	 do
   	  {
	   flag = 0;
	   store = rand() % 81;//Dimiourgite enas tixaios arithmos
	   storecards[i] = cards[store];//metavliti apothikefsis twn kartwn

           /* oi 12 kartes prepei na einai diaforetikes metaxi tous*/
	    for (j = 0; j < i; j++)
	      	{
	      	   if(storecards[j].color == storecards[i].color && storecards[j].numb == storecards[i].numb &&
		       storecards[j].shape == storecards[i].shape && storecards[j].ifi == storecards[i].ifi)
			{
			   flag = 1;
			   break;
			}
			}
		}while(flag == 1);
   }

   //Edw ginete metafora twn kartwn pinaka 3X4
   p = 0;
   for(i = 0; i < 3; i++)
     {
   	for(j = 0; j < 4; j++)
   	  {
	    storetwocards[i][j] = storecards[p];
	    p++;
	  }
     }

   //Print twn kartwn se disthiastato pinaka 3 X 4
   for( i = 0 ; i < 3 ; i++ )
     {
       for(j = 0; j < 4; j++)
   	  {
	      printf("[%c,%c,%c,%c]\t",storetwocards[i][j].color,storetwocards[i][j].numb,storetwocards[i][j].shape,
              storetwocards[i][j].ifi);
          }
   	  printf("\n");
      }
}


int ITISTHESET(struct card car1,struct card car2, struct card car3)
{
	//Den einai SET an einai ana 2 idia kai oxi ola idia- gia xrwma.

	if ((car1.color == car2.color || car1.color == car3.color || car2.color == car3.color) &&
	!(car1.color == car2.color && car1.color == car3.color && car2.color == car3.color))
	   {
		return 0;
	   }

	//Den einai SET an einai ana 2 idia kai oxi ola idia - gia arithmo.

	if ((car1.numb == car2.numb || car1.numb == car3.numb || car2.numb == car3.numb) &&
	!(car1.numb == car2.numb && car1.numb == car3.numb && car2.numb == car3.numb))
	   {
		return 0;
	   }

        //Den einai SET an einai ana 2 idia kai oxi ola idia - gia sxima.

	if ((car1.shape == car2.shape || car1.shape == car3.shape || car2.shape == car3.shape) &&
	!(car1.shape == car2.shape && car1.shape == car3.shape && car2.shape == car3.shape) )
	   {
		return 0;
	   }
	//Den einai SET an einai ana 2 idia kai oxi ola idia - gia ifi.

	if ( (car1.ifi == car2.ifi || car1.ifi == car3.ifi || car2.ifi == car3.ifi) &&
	!(car1.ifi == car2.ifi && car1.ifi == car3.ifi && car2.ifi == car3.ifi) )
	{
		return 0;
	}

	return 1;
}

void GAMESET(char id)
{
    int i,max,x1,x2,x3,y1, y2,y3,apotelesma;
    struct card car1,car2,car3;
    do
	{

	  printf("START THE GAME SET\n");
	  arxikop();

	  //Ginete i eisagogi twn sidetagmenon ths 1 kartas
	   do
	     {
		printf("\nDose sidetagmeni x 1hs kartas\n");
		scanf("%d", &x1);
	     }
	   while(x1 < 0 || x1 > 2);

	  //eisagogi sidetagmenon kartas
	   do
	     {
		printf("Dose sidetagmeni y 1hs kartas\n");
		scanf("%d", &y1);
	     }
	   while(y1 < 0 || y1 > 3);
	   car1 = storetwocards[x1][y1];

	  //Ginete i eisagogi twn sidetagmenon ths 2 kartas
	   do
	     {
		printf("Dose sidetagmeni x 2hs kartas\n");
		scanf("%d", &x2);
	     }
	   while(x2 < 0 || x2 > 2);

	  //eisagogi sidetagmenon kartas
	   do
	    {
		printf("Dose sidetagmeni y 2hs kartas\n");
		scanf("%d", &y2);
	    }
	   while(y2 < 0 || y2 > 3);
	   car2 = storetwocards[x2][y2];

	 //Ginete i eisagogi twn sidetagmenon ths 3 kartas
	   do
	    {
	        printf("Dose sidetagmeni x 3hs kartas\n");
		scanf("%d", &x3);
	    }
	   while(x3 < 0 || x3 > 2);

         //eisagogi sidetagmenon kartas
	   do
	    {
		printf("Dose sidetagmeni y 3hs kartas\n");
		scanf("%d", &y3);
	    }
	   while(y3 < 0 || y3 > 3);
	   car3 = storetwocards[x3][y3];

	//Elegxos apotelesmatwn tou SET
	  apotelesma = ITISTHESET(car1,car2,car3);

	//Ypologismos ths vathologias twn players
	  if (apotelesma == 1)
	     {
		printf("IS SET!!!\n");
		if (id == 'a')
                    gameplayers[0].bathmos += 2;
		else if (id == 'g')
		    gameplayers[1].bathmos += 2;
		else if (id == 'p')
		    gameplayers[2].bathmos += 2;
	      }
	   else
	      {
		 printf("IS NOT SET!!!\n");
		 if (id == 'a' && gameplayers[0].bathmos > 0)
		     gameplayers[0].bathmos -= 1;
		 else if (id == 'g' && gameplayers[1].bathmos > 0)
		     gameplayers[1].bathmos -= 1;
		 else if (id == 'p' && gameplayers[2].bathmos > 0)
		     gameplayers[2].bathmos -= 1;
	      }

	  if(gameplayers[0].bathmos == 10 || gameplayers[1].bathmos == 10 || gameplayers[2].bathmos == 10 )
	      {
		 printf("PLARER WITH 10 MARKS\n");
		   return;
	       }
	}
	while(result == 1);
}


int main()
{
   char opt;
   char WinnerName[17];
   int i,max;
   struct card c1,c2,c3;
   while(1)
   {
		//menu epilogis tou xristi
		printf("\n\n@@@@@@@@@@@@@@@@@@@ MENU EPILOGON @@@@@@@@@@@@@@@@@@@@@@@\n");
		printf("Dose kodiko tou xristi a OR g OR p\n");
		printf("0 gia exodo\n");
		fflush(stdin);
		scanf("%c", &opt);
		if(opt == 'a')
		{
			PLAYGAME(opt);
		}
		else if(opt == 'g')
		{
			PLAYGAME(opt);
		}
		else if(opt == 'p')
		{
			PLAYGAME(opt);
		}
		else if (opt == '0')
		{
			printf("Telos programmatos\n");
			break;
		}
		else
		{
			printf("lathos eisodos - Arxikopoiisi programmatos\n");
			initialize();
		}

	}

	for (i = 0 ; i < 3; i++)
	{
		printf("Onoma = %s Vathmologia = %d ID = %c\n", players[i].name, players[i].vathologia, players[i].id);
	}
   //ypologismos nikiti
   max = players[0].vathologia;
   strcpy(WinnerName,players[0].name);

   if (players[1].vathologia > max)
   {
   		max = players[1].vathologia;
   		strcpy(WinnerName,players[1].name);
   }
   if (players[2].vathologia > max)
   {
   		max = players[2].vathologia;
   		strcpy(WinnerName,players[2].name);
   }
   if(max > 0)
   	   printf("o nikhths einai o %s me %d vathous\n", WinnerName, max);
   else
	   printf("DEN YPARXEI NIKITIS\n");


   return(0);


}
