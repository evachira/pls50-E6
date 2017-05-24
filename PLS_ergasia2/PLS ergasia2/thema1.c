#include <stdio.h>
#include <string.h>


struct seat
{
   char name[40];
   unsigned short tel[10];
   unsigned short arithm_seat;
};


struct seatNode
{
   struct seat st;
   struct seatNode * next;
};

struct seat * seats;
char * pin;


int seats_number;
struct seatNode *phead;
struct seat * seatstem;

struct seatNode * insert(struct seatNode *p, struct seat t);

void writeTofile()
{
   FILE *fp2;
   int i,k;
   int flag = 0, counter = 0, j;
   char onomat[40];
   unsigned short teltem[10];
   unsigned short temarithm_seat;
   char tem[40];
   counter = 0;

   for(i = 0; i < seats_number; i++)
      {
	 if ((seats[i].name[0]) != '\0')
	    {
		counter++;
	    }
      }

   seatstem = (struct seat *)malloc(counter * sizeof(struct seat));
   j = 0;

   for(i = 0; i < seats_number; i++)
      {
	 if ((seats[i].name[0]) != '\0')
	    {
		strcpy(seatstem[j].name,seats[i].name);
		for (k = 0; k < 10; k++)
		    {
			seatstem[j].tel[k] = seats[i].tel[k];
		    }
		seatstem[k].arithm_seat = seats[i].arithm_seat;
		j++;
	     }
       }

   for (i = 0; i < counter; i++)
      {
        for (k = 0; k < counter - 1; k++)
	   {
	      if (strcmp(seatstem[k].name, seatstem[k+1].name) > 0)
		 {
		    strcpy(tem, seatstem[k].name);
		    strcpy(seatstem[k].name, seatstem[k+1].name);
		    strcpy(seatstem[k+1].name, tem);


	for (j = 0; j < 10; j++)
	   {
	       teltem[j] = seatstem[k].tel[k];
	       seatstem[k].tel[j] = seatstem[k+1].tel[k];
	       seatstem[k+1].tel[j] = teltem[j];
	   }

	temarithm_seat = seatstem[k].arithm_seat;
	seatstem[k].arithm_seat = seatstem[k+1].arithm_seat;
	seatstem[k+1].arithm_seat = temarithm_seat;
	        }
	   }
       }


	for(i = 0; i < counter; i++)
	    {
		if ((seatstem[i].name[0]) != '\0')
		   {
			phead = insert(phead, seatstem[i]);
		   }
	    }


	printf("Write into file bus.txt\n");
	fp2 = fopen ("bus.txt","w");
	if (fp2 == NULL)
	   {
		printf("the file can't open.Please exit.\n");
		return;
	    }

	fprintf (fp2,"%s ",pin);
	fprintf (fp2,"%d\n",seats_number);
	while(phead != NULL)
	{
	    fprintf (fp2,"%s ",phead->st.name);
	    fprintf (fp2,"%d ",phead->st.arithm_seat);
	    for (k = 0; k < 10; k++)
	       {
		    fprintf (fp2,"%d",phead->st.tel[k]);
	       }
	    fprintf (fp2,"\n");
	    phead = phead->next;
	}

	fclose(fp2);
}

struct seatNode * insert(struct seatNode *p, struct seat t)
  {
     int k;
     struct seat *tem;

     if(p==NULL)
        {
            p = (struct thesi *)malloc(sizeof(struct seat));
            if(p==NULL)
                {
                    printf("Error\n");
                    exit(0);
                }
                strcpy(p->st.name, t.name);
                for (k = 0; k < 10; k++)
	           {
			(p->st).tel[k] = t.tel[k];
		   }
		p->st.arithm_seat = t.arithm_seat;
                p->next = NULL;
          }
     else
            p->next = insert(p->next,t);/* the while loop replaced by recursive call */
   return (p);
}


void readFromfile()
{
  FILE *fp1;
  char ch[55],c;

  fp1 = fopen("bus.txt","r");
  if (fp1 == NULL)
     {
	printf("The file can't open. Please exit.\n");
	exit(1);
     }

	if(fgets(ch, 55, fp1) != NULL)
	  {

           pin=strtok(ch,"");
		   seats_number = atoi(strtok(NULL, " "));
		}

   fclose(fp1);

   fp1=fopen("bus.txt","r");
   if(fp1==NULL)
   {
        print("The file can't open. Please exit.\n");
        exit(1);
   }
    //emfanisi ths pinakidas tou leoforiou kai tou arithmou twn thesewn

    while(!feof(fp1))
    {
        c=fscanf(fp1,"%s",ch);
        printf("%s\n",ch);
    }
   /*close file*/
   fclose(fp1);

}

void arxikop()
{
  int i,k;
  seats = (struct seat *)malloc(seats_number * sizeof(struct seat));


  for(i = 0; i < seats_number; i++)
     {
	  seats[i].name[0] = '\0';
	  for (k = 0; k < 10; k++)
	      {
		  seats[i].tel[k] = 0;
	      }
	  seats[i].arithm_seat = 0;
      }
}


void ep1()
{
    int i,empty_seats_counter = 0;
    printf("\nArithmoi kenwn thesewn\n");
    empty_seats_counter = 0;
    for(i = 0; i < seats_number; i++)
	{
	   if (seats[i].name[0] == '\0')
	      {
		  empty_seats_counter++;
		  printf("%3d", i+1);
	      }
        }
	printf("\n\n To Synolo kenwn thesewn %d\n", empty_seats_counter);

}

void ep2()
{

   int epil,i,k,empty_seats_counter = 0,pos, flag = 0, found = 0;
   char onomat[40];
   unsigned short telephon[10];
	do
	  {
	  flag = 0;
	    do
	       {
		   printf("\nDwse thesi gia na kratithei\n");
		   scanf("%d", &pos);
		   if(pos< 1 || pos > 53)
			printf("\nThesi ektos orion! Eisagete xana arithmo thesis\n");
		}while(pos < 1 || pos> 53);

		if (seats[pos-1].name[0] != '\0')
		     {
			flag = 1;
			printf("\nThe seat is kept. Give another one\n");
		     }
		}
		while(flag == 1);

		fflush(stdin);
		printf("\nDwse to onomateponimo tou xristi gia thn kratisi tis thesis\n");
		gets(seats[pos-1].name);
		fflush(stdin);

		printf("\nDwse to tilefono tou xristi gia thn kratisi tis thesis\n");
		for(k = 0; k < 10; k++)
		{
			scanf("%d", &seats[pos-1].tel[k]);
		}

		seats[pos-1].arithm_seat = pos;
}

void ep3()
{
    int epil,i,k,empty_seats_counter = 0,pos, flag = 0, found = 0;
    char onomat[40];
    unsigned short telephon[10];
    while(1)
     {

     //EPILOGES
     printf("0.ExIT");
     printf("\n1.Search an thesi kratimeni me onomateponimo i tilefono");
     printf("\n2.Search an thesi einai kratimeni me sigekrimeno tilefono");
     printf("\n\nDwse mia epilogi:");
     scanf("%d", &epil);
     if(epil == 1)
	{
	   printf("\nDwse onomateponimo for search\n");
	   fflush(stdin);
	   gets(onomat);
	   flag = 0;
	   for(i = 0; i < seats_number; i++)
	      {
		if (strcmp(seats[i].name,onomat) == 0)
		   {
			printf("\nThe seat is kept!\n");
			flag = 1;
		   }
	      }

		if (flag == 0)
		   {
			printf("\nThe seat isn't kept!\n");
					}
		   }
		else if (epil == 2)
		   {
			printf("\nFDwse tilefono for search\n");
			for(k = 0; k < 10; k++)
			   {
			      scanf("%d", &telephon[k]);
			   }

			for(i = 0; i < seats_number; i++)
			   {
				found = 0;
				for(k = 0; k < 10; k++)
				   {
				   //Telephono search
				   if (seats[i].tel[k] == telephon[k])
					{
					   found++;
					}
					}
				   if (found == 10)
					break;
				   }
				if (found == 10)
				    printf("Telephone is found, the seat is kept\n");
				else
				    printf("Telephone isn't found, the seat is not kept\n");

			   }
			else if (epil == 0)
			{
				break;
			}
		}
}

void ep4()
 {
    int epil,i,k,empty_seats_counter = 0,pos, flag = 0, found = 0;
    char onomat[40];
    unsigned short telephon[10];
    do
     {
	printf("\nDwse seat gia akirosi\n");
	scanf("%d", &pos);
	if(pos < 1 || pos > 53)
	    printf("\nThesi ektos orion! Eisagete xana arithmo thesis\n");
     }while(pos < 1 || pos> 53);


    if(seats[pos-1].name[0] != '\0')
      {
	  seats[pos-1].name[0] = '\0';
	  for (k = 0; k < 10; k++)
	     {
		seats[pos-1].tel[k] = 0;
	     }
	  seats[pos-1].arithm_seat = 0;

	  printf("\nSeat akirothike\n");
       }
     else
	{
	   printf("\nThe seat is idi keni,den akirinete\n");
	}
 }

void ep5()
 {
    int epil,i,k,empty_seats_counter = 0,pos, flag = 0, counter = 0, j;
    struct seat * 	seatstem;
    char onomat[40];
    unsigned short teltem[10];
    unsigned short temarithm_seat;
    char tem[40];

    while(1)
	{
	//EPILOGES
	 printf("0.Exit");
	 printf("\n1.Show list vasi arithmou thesis");
	 printf("\n2.Show list vasi to onomateponimou");
	 printf("\n\nDwse epilogi:");
	 scanf("%d", &epil);
	 if(epil == 1)
	    {
	 	flag = 0;
	        for(i = 0; i < seats_number; i++)
		   {
		      if ((seats[i].name[0]) != '\0')
		         {
			     flag = 1;
			     printf("Thesi %d\n",seats[i].arithm_seat);
			     printf("Onomateponimo: ");
			     printf("%s\n",seats[i].name);
			     printf("Tilefono: ");
			     for (k = 0; k < 10; k++)
				{
				   printf("%d",seats[i].tel[k]);
				}
				printf("\n");
			   }

		     }

		       if(flag == 0)
			   {
				printf("There are no entries\n");
			   }
		     }
          else if (epil ==2)
	     {
		  counter = 0;
		  for(i = 0; i < seats_number; i++)
		     {
			if ((seats[i].name[0]) != '\0')
			   {
				 counter++;
			   }
		      }

		  seatstem = (struct seat *)malloc(counter * sizeof(struct seat));
		  j = 0;
		  for(i = 0; i < seats_number; i++)
		      {
			  if ((seats[i].name[0]) != '\0')
		              {
				 strcpy(seatstem[j].name, seats[i].name);
				 for (k = 0; k < 10; k++)
				     {
					seatstem[j].tel[k] = seats[i].tel[k];
				     }
					seatstem[j].arithm_seat = seats[i].arithm_seat;
				   	j++;
				 }
			}

		  for (i = 0; i < counter; i++)
		      {
			  for (k = 0; k < counter - 1; k++)
			      {
			          if (strcmp(seatstem[k].name, seatstem[k+1].name) > 0)
					{
				            strcpy(tem, seatstem[k].name);
				            strcpy(seatstem[k].name, seatstem[k+1].name);
				            strcpy(seatstem[k+1].name, tem);


				            for (j = 0; j< 10; j++)
					   	{
						    teltem[j] = seatstem[k].tel[k];
						    seatstem[k].tel[j] = seatstem[k+1].tel[j];
						    seatstem[k+1].tel[j] = teltem[j];
						}

						temarithm_seat = seatstem[k].arithm_seat;
						seatstem[k].arithm_seat = seatstem[k+1].arithm_seat;
						seatstem[k+1].arithm_seat = temarithm_seat;
				    	}
				   }
			}


			flag = 0;
			for(i = 0; i < counter; i++)
			    {
			       if ((seatstem[i].name[0]) != '\0')
				   {
				        flag = 1;
				        printf("Thesi %d\n",seatstem[i].arithm_seat);
					printf("Onomateponimo: ");
					printf("%s\n",seatstem[i].name);
					printf("Tilefono: ");
					for (k = 0; k < 10; k++)
					   {
						printf("%d",seatstem[i].tel[k]);
					   }
						printf("\n");
				   }

			     }

			   	if(flag == 0)
				{
				      printf("There are no entries\n");
				}

			     }
			     else if (epil == 0)
			         {
				    break;
			         }
		       }
 }

int main()
{
	int epil,i,k,empty_seats_counter = 0,pos, flag = 0, found = 0;
	char onomat[40];
	unsigned short telephon[10];
	pin = malloc(7*sizeof(char));
	readFromfile();
	arxikop();

   while(1)
   {
   //MENU

	printf("0.Exit");
	printf("\n1.Emfanisi tou plithous twn kenwn thesewn kai twn arithmwn tous");
	printf("\n2.Kratisi thesis me sigekrimeno arithmo. Stoixeia xristi");
	printf("\n3.Anazitisi an thesi kratimeni me onomateponimo or tilefono");
	printf("\n4.Akirosi kratisis thesis me  arithmo sigekrimeno");
	printf("\n5.Lista kratimenwn thesewn kata arithmo taxinomimenes");
	printf("\n\nDwse epilogi:");
	scanf("%d", &epil);

	//epilogi gia exit
	if (epil == 0)
	{
	    printf("EXIT\n");
            break;
	}

	//Emfanisi tou plithous twn kenwn thesewn kai twn arithmwn tous
	else if(epil == 1)
	{
	    ep1();
	}

	//Kratisi thesis me sigekrimeno arithmo
	else if(epil == 2)
	{
	    ep2();
	}

	//Anazitisi an thesi kratimeni me  onomateponimo or tilefono
	else if(epil == 3)
	{
	    ep3();
	}

        //Akirosi kratisis thesis me arithmo sigekrimeno
	else if(epil == 4)
	{
	    ep4();
	}

        //Lista kratimenwn thesewn kata arithmo thesis taxinomimenes
	else if(epil == 5)
	{
	    ep5();
	}
	else
	{
	    printf("\nParakalw kante sosti eisodo\n");
	}
}

writeTofile();

//Save pinakidas tou leoforiou kai diagrammatos leoforiou se arxeio


}
