#include "main.h"
#include "Proverka.h"
#include "memory.h"
char saska,damka,sopsas,sopdam;

extern  vector<stek> poradok;

Doska nDoska(Doska Aa, int a, int b, int c)
{
    int f = Aa.pole[a];
    for (int i= 0; i<32; i++)
        if((Aa.pole[i]==saska)||(Aa.pole[i]==damka)) Aa.pole[i]=Aa.pole[i]+100;
    Aa.pole[a]=0;
    Aa.pole[b]=100; // отмечаем сбитую фигуру

    if ((saska == 2)&&(c<4)) Aa.pole[c]=4;         // белая шашка превращается в дамку
    else if ((saska == 1)&&(c>27)) Aa.pole[c]=3;   // черная шашка превращается в дамку
    else Aa.pole[c]=f;

    return (Aa);

}


Doska sDoska(Doska Aa)
{
    for (int i= 0; i<32; i++)
        if(Aa.pole[i]>100) Aa.pole[i]=Aa.pole[i]-100;
    else if(Aa.pole[i]==100) Aa.pole[i]=0;

    return (Aa);

}



int ProverkaBelyh(Doska Zz)
{
    saska = 2;
    damka = 4;
    sopsas =1;
    sopdam =3;
    return Proverka(Zz, 0);
}

int ProverkaChernyh(Doska Zz)
{
    saska = 1;
    damka = 3;
    sopsas =2;
    sopdam =4;
    return Proverka(Zz, 0);
}

void Hod(Doska Aa, int a, int b)
{

    int f = Aa.pole[a];
    Aa.pole[a] = 0;
    if (b<4) Aa.pole[b]=4;         // белая шашка превращается в дамку
    else if (b>27) Aa.pole[b]=3;   // черная шашка превращается в дамку
    else Aa.pole[b]=f;


 //   cout << "hod " << endl;
  //   PrintDoska(sDoska(Aa));
    putFile(sDoska(Aa));

}

void HodD(Doska Aa, int a, int b)
{
    int f = Aa.pole[a];
    Aa.pole[a] = 0;
    Aa.pole[b]=f;

//    cout << "hod " << endl;
//     PrintDoska(sDoska(Aa));
    putFile(sDoska(Aa));

}




int HodDamki(Doska Zz, int Damka)
{
    int fl=0;
        for (int i= 0; i<32; i++)
        {
            if(Zz.pole[i]==Damka)
            {
                int n=1;
                int z = YyXx[Yy[i]+n][Xx[i]+n];

                while ((((Xx[i]+n)<8)&&((Yy[i]+n)<8))&&(Zz.pole[z]==0))
                {
                   fl=1;
                   HodD(Zz,i,z);
                   n++;
                   z = YyXx[Yy[i]+n][Xx[i]+n];
                }

                n=1;
                z = YyXx[Yy[i]-n][Xx[i]-n];
                while ((((Xx[i]-n)>=0)&&((Yy[i]-n)>=0))&&(Zz.pole[z]==0))
                {
                  fl=1;
                  HodD(Zz,i,z);
                  n++;
                  z = YyXx[Yy[i]-n][Xx[i]-n];
                }

               n=1;
               z = YyXx[Yy[i]+n][Xx[i]-n];
               while ((((Xx[i]-n)>=0)&&((Yy[i]+n)<8))&&(Zz.pole[z]==0))
               {
                  fl=1;
                  HodD(Zz,i,z);
                  n++;
                  z = YyXx[Yy[i]+n][Xx[i]-n];
               }
               n=1;
               z = YyXx[Yy[i]-n][Xx[i]+n];
               while ((((Xx[i]+n)<8)&&((Yy[i]-n)>=0))&&(Zz.pole[z]==0))
               {
                 fl=1;
                 HodD(Zz,i,z);
                 n++;
                 z = YyXx[Yy[i]-n][Xx[i]+n];
               }
            }
        }
   return fl;

}

int HodBelyh(Doska Zz)
{
int fl=0;
    for (int i= 4; i<32; i++)
    {
        if(Zz.pole[i]==2)
        {
            if (Xx[i]<7)
            {
                fl=1;
                int z = YyXx[Yy[i]+1][Xx[i]+1];
                if(Zz.pole[z]==0) Hod(Zz,i,z);
            }
            if (Xx[i]>0)
            {
                fl=1;
                int z = YyXx[Yy[i]+1][Xx[i]-1];
                if(Zz.pole[z]==0) Hod(Zz,i,z);
            }

        }

    }
    return (fl|HodDamki(Zz,4));
}

int  HodChernyh(Doska Zz)
{
int fl=0;
    for (int i= 0; i<28; i++)
    {
        if(Zz.pole[i]==1)
        {
            if (Xx[i]<7)
            {
                int z = YyXx[Yy[i]-1][Xx[i]+1];
                if(Zz.pole[z]==0)
                {
                    Hod(Zz,i,z);
                    fl=1;
                }
            }
            if (Xx[i]>0)
            {
                int z = YyXx[Yy[i]-1][Xx[i]-1];
                if(Zz.pole[z]==0)
                {
                    Hod(Zz,i,z);
                    fl=1;
                }
            }

        }

    }
    return (fl|HodDamki(Zz,3));
}



int Proverka(Doska Zz, int St)
{

int fl=0;

    for (int i= 0; i<32; i++)
    {
        if(Zz.pole[i]==saska)
        {

              if ((Xx[i]<6)&&(Yy[i]<6))
            {

                int z = YyXx[Yy[i]+1][Xx[i]+1];
                int zz = YyXx[Yy[i]+2][Xx[i]+2];
                if(((Zz.pole[z]==sopsas)||(Zz.pole[z]==sopdam))&&(Zz.pole[zz]==0))
                {
                    fl=1;
                  Proverka(nDoska(Zz,i,z,zz), St+1);
                }
            }
            if ((Xx[i]>1)&&(Yy[i]<6))
            {

                int z = YyXx[Yy[i]+1][Xx[i]-1];
                int zz = YyXx[Yy[i]+2][Xx[i]-2];
                if(((Zz.pole[z]==sopsas)||(Zz.pole[z]==sopdam))&&(Zz.pole[zz]==0))
                {
                    fl=1;
                  Proverka(nDoska(Zz,i,z,zz), St+1);
                }
            }

            if ((Xx[i]>1)&&(Yy[i]>1))
            {

                int z = YyXx[Yy[i]-1][Xx[i]-1];
                int zz = YyXx[Yy[i]-2][Xx[i]-2];
                if(((Zz.pole[z]==sopsas)||(Zz.pole[z]==sopdam))&&(Zz.pole[zz]==0))
                {
                    fl=1;
                  Proverka(nDoska(Zz,i,z,zz), St+1);
                }
            }

            if ((Xx[i]<6)&&(Yy[i]>1))
            {
                int z = YyXx[Yy[i]-1][Xx[i]+1];
                int zz = YyXx[Yy[i]-2][Xx[i]+2];
                if(((Zz.pole[z]==1)||(Zz.pole[z]==sopdam))&&(Zz.pole[zz]==0))
                {
                    fl=1;
                  Proverka(nDoska(Zz,i,z,zz), St+1);
                }
            }


        }


        if(Zz.pole[i]==damka)
        {
          int n=1;
          while (((Xx[i]+n)<7)&&((Yy[i]+n)<7))
          {
              int z = YyXx[Yy[i]+n][Xx[i]+n];
              int zz = YyXx[Yy[i]+n+1][Xx[i]+n+1];
              if(((Zz.pole[z]==sopsas)||(Zz.pole[z]==sopdam))&&(Zz.pole[zz]==0))
              {
                  n++;
                  while ((((Xx[i]+n)<8)&&((Yy[i]+n)<8))&&(Zz.pole[zz]==0))
                  {
                    fl=1;
                    Proverka(nDoska(Zz,i,z,zz), St+1);
                    n++;
                    zz = YyXx[Yy[i]+n][Xx[i]+n];
                  }
              break;
              }else
              if(Zz.pole[z]==0) n++;
              else break;
          }

            n=1;
          while (((Xx[i]-n)>0)&&((Yy[i]-n)>0))
          {
              int z = YyXx[Yy[i]-n][Xx[i]-n];
              int zz = YyXx[Yy[i]-n-1][Xx[i]-n-1];
              if(((Zz.pole[z]==sopsas)||(Zz.pole[z]==sopdam))&&(Zz.pole[zz]==0))
              {
                  n++;
                  while ((((Xx[i]-n)>=0)&&((Yy[i]-n)>=0))&&(Zz.pole[zz]==0))
                  {
                    fl=1;
                    Proverka(nDoska(Zz,i,z,zz), St+1);
                    n++;
                    zz = YyXx[Yy[i]-n][Xx[i]-n];
                  }
              break;
              }else
              if(Zz.pole[z]==0) n++;
              else break;
          }


          n=1;
        while (((Xx[i]-n)>0)&&((Yy[i]+n)<7))
        {
            int z = YyXx[Yy[i]+n][Xx[i]-n];
            int zz = YyXx[Yy[i]+n+1][Xx[i]-n-1];
            if(((Zz.pole[z]==sopsas)||(Zz.pole[z]==sopdam))&&(Zz.pole[zz]==0))
            {
                n++;
                while ((((Xx[i]-n)>=0)&&((Yy[i]+n)<8))&&(Zz.pole[zz]==0))
                {
                  fl=1;
                  Proverka(nDoska(Zz,i,z,zz), St+1);
                  n++;
                  zz = YyXx[Yy[i]+n][Xx[i]-n];
                }
            break;
            }else
            if(Zz.pole[z]==0) n++;
            else break;
        }



        n=1;
      while (((Xx[i]+n)<7)&&((Yy[i]-n)>0))
      {
          int z = YyXx[Yy[i]-n][Xx[i]+n];
          int zz = YyXx[Yy[i]-n-1][Xx[i]+n+1];
          if(((Zz.pole[z]==sopsas)||(Zz.pole[z]==sopdam))&&(Zz.pole[zz]==0))
          {
              n++;
              while ((((Xx[i]+n)<8)&&((Yy[i]-n)>=0))&&(Zz.pole[zz]==0))
              {
                fl=1;
                Proverka(nDoska(Zz,i,z,zz), St+1);
                n++;
                zz = YyXx[Yy[i]-n][Xx[i]+n];
              }
          break;
          }else
          if(Zz.pole[z]==0) n++;
          else break;
      }



  }




    }

if ((St >0)&&(fl==0))
{

    putFile(sDoska(Zz));
    return 1;
}
        return 0;

}
