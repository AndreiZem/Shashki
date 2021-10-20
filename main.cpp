#include "main.h"
#include "Proverka.h"
#include "memory.h"
#include <fstream>
#include <iostream>
#include <ctime>

Doska Glavn;
unsigned int naChstep;
unsigned int endstep;
vector<stek> poradok;
extern char saska;


int ProvRR;
int boolProv;
char Rezultat[30];

int main()
{

    cout << "Start" << endl;
 time_t now = time(0);
ProvRR = 0;

//analiz();
//return 1;


   naChstep = 0;
   /*
   saska = 1;
putFile(GetPole("shashki.txt"));
*/

   LoadMem("19");



   unsigned int nnn;
   unsigned int dcd = 0;



   Glavn =convMiniDoska( GetMem(poradok[0].pole, saska));
   PrintDoska(Glavn);

unsigned int razm = poradok.size();
while (razm>0)
  {

    razm = poradok.size()-1;
    nnn = poradok[razm].pole;

      Glavn =convMiniDoska( GetMem(nnn, poradok[razm].igrok));
if(dcd%100000==0)
  {
      PrintDoska(Glavn);
      cout << naChstep << endl;
      cout << razm << endl;

   }
dcd++;
    int igt = poradok[razm].igrok;
    poradok.pop_back();



      if ( igt==2) {
          if (!ProverkaChernyh(Glavn)) if(!HodChernyh(Glavn)) {
          setRes(nnn,'>',2);
 //             poradok[naChstep].rezultat = 2;
          }
      }else
      {
          if (!ProverkaBelyh(Glavn)) if(!HodBelyh(Glavn)) {
              setRes(nnn,'<',1);
//              poradok[naChstep].rezultat = 1;
          }

      }
      razm = poradok.size();
}

cout << "end" << endl;
time_t now1 = time(0);

cout << "time: " << now1 - now << endl;

SaveMem("18");

cout << "aaaend" << endl;

/*


cout << "obratka" << endl;

unsigned int obrBeg = naChstep-2;
ProvRR = 1;


int isprar = 1;

while (isprar>0)
{
isprar = 0;

    for (unsigned int obr = obrBeg; obr >0; obr --)
{



    if (obr%10000==0) cout << obr << endl;

    if ( poradok[obr].rezultat==0){

     Glavn =convMiniDoska( GetMem(poradok[obr].pole, poradok[obr].igrok));
//cout << "doska:";
//PrintDoska(Glavn);
boolProv = 0;
     if ( poradok[obr].igrok==2) {
         if (!ProverkaChernyh(Glavn)) HodChernyh(Glavn);
         }
     else
     {
         if (!ProverkaBelyh(Glavn)) HodBelyh(Glavn);

         }

//     cout << "zes:";
    int b=0;
    int c=0;
    int z=0;

     for(int t = 0; t<boolProv; t++)
         if (Rezultat[t]=='>') b++;
         else if (Rezultat[t]=='<') c++;
            else z++;

     if ( poradok[obr].igrok==2) {
         if (c>0){
             setRes( poradok[obr].pole,'<',2);
             poradok[obr].rezultat = 2;
             isprar++;
         }else if (z>0){ }else
         {
            setRes( poradok[obr].pole,'>',2);
            poradok[obr].rezultat = 1;
            isprar++;
         }

         }
     else
     {
         if (b>0){
             setRes( poradok[obr].pole,'>',1);
             poradok[obr].rezultat = 1;
             isprar++;
         }else if (z>0){ }else
         {
            setRes( poradok[obr].pole,'<',1);
            poradok[obr].rezultat = 2;
            isprar++;
         }

      }

}

 }

cout << "isp:" <<isprar << endl;
}


time_t now2 = time(0);
cout << endl;
cout << "time: " << now2 - now1 << endl;



for (unsigned int obr = 0 ; obr <= obrBeg; obr ++)
{
    Glavn =convMiniDoska( GetMem(poradok[obr].pole, poradok[obr].igrok));
PrintDoska(Glavn);
cout << "rez:" << int(poradok[obr].rezultat) ;


}
*/


    return 0;
}


