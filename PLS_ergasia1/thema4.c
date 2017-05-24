#include <stdio.h>
#define S 53
int main()
{
  FILE *fp1, *fp2; /*dhlwnoume diktes se files*/
  char pin[8],ch; /*h  lexi pou ta xrisimopoiei to file*/
  int seats[S] = {};
  int epil,i,k,empty_seats_counter=0,pos, flag = 0;
  fp1 = fopen("bus.txt","r"); /*open file gia diavasma*/
  ch = fscanf(fp1,"%s",pin);

  while (ch != EOF) /* repeat until EOF */
   {
    /* get one word from the file */
    printf("%s\n",pin);
    ch = fscanf(fp1,"%s",pin);
   }
    /* close the file*/
    fclose(fp1);
  while(1)
   {
    // MENU
    printf("\n EPILOGES \n");
    printf("0.Exit");
    printf("\n1.Emfanisi tou plithous twn kenwn thesewn kai twn arithmwn tous");
    printf("\n2.Kratisi thesi me sigekrimeno arithmo");
    printf("\n3.Kratisi protis empty thesis sto parathiro");
    printf("\n4.Akirosi kratisis thesis me arithmo sigekrimeno");
    printf("\n5.Anazitisi gia kratimeni thesi me sigekrimeno arithmo");
    printf("\n6.Lista kratimenwn thesewn kata arithmo thesis taximomimemes");
    printf("\n7.Emfanisi bus pinakidas kai diagrammatos");
    printf("\n8.Save pinakida kai diagrammatos se arxeio");
    printf("\n\nDwse epilogi:");
    scanf("%d", &epil);

    // exit
    if (epil == 0)
       {
          printf("EXIT \n");
          return;
       }
    //Emfanisi tou plithous twn kenwn thesewn kai twn arithmwn tous
    else if(epil == 1)
       {
         printf("\nArithmoi kenon theseon\n");
         empty_seats_counter = 0;

         for(i = 0; i < S; i++)
           {
             if (seats[i] == 0)
               {
                  empty_seats_counter++;
                  printf("%3d", i+1);
               }
            }
           printf("\n\nSynolo kenow thesewn %d\n",empty_seats_counter);
        }

     //Kratisi thesi me sigekrimeno arithmo
    else if(epil == 2)
{
  do
   {
     flag = 0;
     do
       {
         printf("\nDwse thesi gia na kratithei\n");
         scanf("%d", &pos);

         if(pos < 1 || pos > 53)
            printf("\nEktos twn dethentwn oriwn! Doste alli thesi\n");
        }while(pos < 1 || pos> 53);
       for(i = 0; i < S; i++)
         {
           if (seats[pos - 1] == 1)
             {
               flag = 1;
               printf("\nThesi kratimeni! Eisagete xana thesi\n");
               break;
             }
          }
    }while(flag == 1);
    if (seats[pos-1] == 0)
         seats[pos-1] = 1;
   }
    //Kratisi protis empty thesis sto parathiro
  else if(epil == 3)
       {
         flag = 0;
         for(i = 0; i < S && flag == 0; i++)
            {
              if (seats[i] != 1)
                {
                   if (i % 4 == 0 || i % 4 == 3)
                     {
                        seats[i] = 1;
                        flag = 1;
                     }
                }
             }
        }
    //Akirosi kratisis thesis me arithmo sigekrimeno
    else if(epil == 4)
     {
     do
       {
          flag = 0;
          do
            {
              printf("\nDoste thesi gia na akirothei\n");
              scanf("%d", &pos);

              if(pos< 1 || pos > 53)
                 printf("\nEktos twn dethentwn oriwn! Doste alli thesi\n");
             }while(pos < 1 || pos > 53);

              for(i = 0; i < S; i++)
               {
                 if (seats[pos - 1] == 0)
                    {
                       flag = 1;
                       printf("\nThesi oxi kratimeni! Dwse alli thesi\n");
                       break;
                    }
                }
        }while(flag == 1);
        if (seats[pos-1] == 1)
           seats[pos-1] = 0;
     }

     //Anazitisi gia kratimeni thesi me sigekrimeno arithmo
     else if(epil == 5)
       {
         do
           {
              printf("\nDwste thesi gia anazitisi\n");
              scanf("%d", &pos);

              if(pos < 1 || pos> 53)
                 printf("\nEktos twn dethentwn oriwn! Doste alli thesi\n");
           }while(pos < 1 || pos > 53);
           flag = 0;
           for(i = 0; i < S && flag == 0; i++)
               {
                  if (seats[pos - 1] == 1)
                     {
                          printf("\nKratimeni thesi!\n");
                          flag = 1;
                     }
                  else
                     {
                         printf("\nOxi kratimeni!\n");
                         flag = 1;
                      }
                }
       }

     //Lista kratimenwn thesewn kata arithmo thesis taximomimemes
     else if(epil == 6)
       {
          printf("\nKratimenes Theseis!\n");
          for(i = 0; i < S; i++)
               {
                  if (seats[i] == 1)
                      {
                         printf("%3d", i+1);
                      }
                }
        }

     //Emfanisi bus pinakidas kai diagrammatos
     else if(epil == 7)
        {
            fp1 = fopen("bus.txt","r");
            ch = fscanf(fp1,"%s",pin);
            printf("%s\n",pin);
            fclose(fp1);

            for(i = 0; i < S-5; i = i+4)
              {
                for (k = i; k < i+2; k++)
                   {
                      if (seats[k] == 1)
                         {
                            printf("*");
                         }
                       else
                         {
                            printf("_");
                         }
                    }
                    printf(" ");
                    for (k = i+2; k < i+4; k++)
                       {
                         if (seats[k] == 1)
                            {
                              printf("*");
                            }
                         else
                            {
                               printf("_");
                            }

                        }
                     printf("\n");
                  }
               for (k = S-5; k < S; k++)
                  {
                     if (seats[k] == 1)
                        {
                            printf("*");
                        }
                     else
                        {
                            printf("_");
                        }
                   }
                   printf("\n");
             }

    //Save pinakida kai diagrammatos se arxeio
    else if(epil == 8)
       {
          fp2 = fopen ("layout.txt","w");
          for(i = 0; i < S-5; i = i+4)
            {
               for (k = i; k < i+2; k++)
                  {
                     if (seats[k] == 1)
                        {
                           fprintf (fp2,"%s","*");
                        }
                     else
                        {
                           fprintf (fp2,"%s","_");
                        }
                   }
                   fprintf (fp2,"%s"," ");
                   for (k = i+2; k < i+4; k++)
                      {
                         if (seats[k] == 1)
                            {
                               fprintf (fp2,"%s","*");
                            }
                         else
                            {
                               fprintf (fp2,"%s","_");
                            }
                      }
                      fprintf (fp2,"%s","\n");
             }
            for (k = S-5; k < S; k++)
               {
                  if (seats[k] == 1)
                     {
                        fprintf (fp2,"%s","*");
                     }
                  else
                     {
                        fprintf (fp2,"%s","_");
                     }
               }
               fclose(fp2);
             }
      else
       {
            printf("\n Parakalw kante sosti eisido \n");
       }
   }
}
