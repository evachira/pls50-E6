#include <stdio.h>
#include <math.h>
#define PI 3.14

//dilwseis sinartisewn

float per_tetrag(float plevra);
float per_paralilog(float mik, float plat);
float per_trigon(float plev1, float plev2);
float per_circle(float aktin);

int main()
{
  int epil;
  float plevra,mik,plat,plev1,plev2,aktin;

  while(1)
  {
//menu epilogwn
  printf("0.Exit");
  printf("\n1.Tetragono");
  printf("\n2.Paralilogrammo");
  printf("\n3.Orth trigono");
  printf("\n4.Circle");
  printf("\n\nDwse mia epilogi:");
  scanf("%d", &epil);

//Use 0 for exit apo programma
  if (epil == 0)
     {
       printf("EXIT\n");
       return;
     }
   else if(epil == 1)
     {
       // Perimetros tetragonou
       printf("Dwse to mikos ths plevras tou tetragonou\n");
       scanf("%f", &plevra);

       printf("\nPerimetros tou tetragonou isi me %.2f\n\n",
       per_tetrag(plevra));
     }
   else if(epil == 2)
     {
       // Perimetros paralilogrammou
       printf("Dwse to mikos tou paralilogramou\n");
       scanf("%f", &mik);
       printf("Dwse to platos tou paralilogramou\n");
       scanf("%f", &plat);

       printf("\nPerimetros tou orthogoniou parallilogrammou isi me %.2f\n\n",
       per_paralilog(mik,plat));
     }
   else if(epil == 3)
     {
        //Perimetros trigonou
        printf("Dwse thn first plevra tou trigonoy\n");
        scanf("%f", &plev1);
        printf("Dwse thn second plevra tou trigonoy\n");
        scanf("%f", &plev2);

        printf("\nH perimetros tou orthogoniou trigonou isi me %.2f\n\n",
        per_trigon(plev1,plev2));
     }
   else if(epil == 4)
     {
        //Perimetros cilcle
        printf("Dwse thn aktina tou circle\n");
        scanf("%f", &aktin);
        printf("\nH perimetros tou circle isi me %.2f\n\n",
        per_circle(aktin));
     }
   else
     {
        printf("\n Exit\n");
     }
  }
  return 0;
}



//sinartisi gia thn perimetro tetragonou
float per_tetrag(float plevra)
{
   return 4.0 * plevra;
}


//sinartisi gia thn perimetro paralilogrammou
float per_paralilog(float mik, float plat)
{
   return 2 * mik + 2 * plat;
}


//sinartisi gia thn perimetro trigonou
float per_trigon(float plev1, float plev2)
{
  float ypot;
  ypot = sqrt(pow(plev1,2)+pow(plev2, 2));
  return ypot + plev1 + plev2;
}


//sinartisi gia thn perimetro tou circle
float per_circle(float aktin)
{
  return 2 * PI * aktin;
}


