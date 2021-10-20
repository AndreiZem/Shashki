#include "main.h"
#include "memory.h"
#include <fstream>
#include <iostream>
#include <set>


bool operator<(const miniDoska& lhs, const miniDoska& rhs)
{
    int i = 0;
    while ((lhs.pole[i] == rhs.pole[i]) && (i < 12)) i++;
    return (lhs.pole[i] < rhs.pole[i]);
}

extern unsigned int naChstep;
extern unsigned int endstep;
extern char saska;
extern  vector<stek> poradok;
extern int ProvRR;
extern int boolProv;
extern char Rezultat[30];


set <miniDoska> Mem1;
set <miniDoska> Mem2;
set <miniDoska> Mem1_;
set <miniDoska> Mem2_;

void LoadMem(string sss)
{
    char ww[2];
    std::fstream vmdelet_in; //создаем поток
    vmdelet_in.open("tresh"+sss, std::ios::in| std::ios_base::binary);
    vmdelet_in.seekg( 0, std::ios::end );
    unsigned int razm = vmdelet_in.tellg()/14;
    vmdelet_in.seekg( 0, std::ios::beg );

    cout << "razm=" <<razm << endl;
    miniDoska Aa;
    for (; razm>0; razm -- ){
 //       cout << "!";
    vmdelet_in.read(Aa.pole,13);
    vmdelet_in.read(ww,1);
    saska = Aa.pole[12];
    putFile(convMiniDoska(Aa));

    }
    vmdelet_in.close();
 return;
}

void SaveMem(string sss)
{





std::ofstream vmdelet_out; //создаем поток


vmdelet_out.open("tresh"+sss, std::ios::app| std::ios_base::binary);  // открываем файл для записи в конец
for (auto elem: Mem2)
{
for (int i = 0; i < 13 ; ++i) vmdelet_out << elem.pole[i];
vmdelet_out << endl;
}
Mem2.clear();

for (auto elem: Mem2_)
{
for (int i = 0; i < 13 ; ++i) vmdelet_out << elem.pole[i];
vmdelet_out << endl;
}
Mem2_.clear();


vmdelet_out.close();



vmdelet_out.open("all"+sss, std::ios::app| std::ios_base::binary);  // открываем файл для записи в конец
for (auto elem: Mem1)
{
for (int i = 0; i < 13 ; ++i) vmdelet_out << elem.pole[i];
vmdelet_out << endl;
}
Mem1.clear();


for (auto elem: Mem1_)
{
for (int i = 0; i < 13 ; ++i) vmdelet_out << elem.pole[i];
vmdelet_out << endl;
}
Mem1_.clear();


vmdelet_out.close();





}


void analiz()
{


    Doska Ss = GetPole("analiz.txt");
    miniDoska Aa = transMiniDoska(Ss);

    PrintDoska(Ss);

    int be=0;
    int ce=0;
    for (int i=0;i<32;i++)
    if ((Ss.pole[i]==1)||(Ss.pole[i]==3)) ce++;
    else if ((Ss.pole[i]==2)||(Ss.pole[i]==4)) be++;
    string fil;
    fil=ff_[int(saska)]+fff[be]+fff[ce]+".txt";

    // проверка не сеществует ли такая же комбинация
    std::fstream vmdelet_in;
    vmdelet_in.open(fil, std::ios::in| std::ios_base::binary);  // открываем файл для записи в конец
vmdelet_in.seekg( 0, std::ios::end );
    unsigned int razm = vmdelet_in.tellg()/13;


    miniDoska Bb;
     for(unsigned int vbv=0;vbv<razm;vbv++)
     {
         vmdelet_in.seekp(vbv*13,ios::beg);
         vmdelet_in.read(Bb.pole,12);


         int g;
         for(g=0;g<12;g++) if (Aa.pole[g]!=Bb.pole[g]) g=40;
         if (g==12)
         {
         cout << "odinak ";
         char zz[1];
         vmdelet_in.read(zz,1);
         vmdelet_in.close();
         cout << zz[0];
         return;

         }

     }

 cout << "no ";

    return;
}


Doska convMiniDoska(miniDoska Aa)
{
    Doska Ff;

    union
    {
        int tt;
        char t[4];
    };


    for (int n=0, nn= 0; n<32; n+=8, nn+=3 )
    {

        t[0]=Aa.pole[nn];
        t[1]=Aa.pole[nn+1];
        t[2]=Aa.pole[nn+2];




        Ff.pole[n]=   (tt>>21)&7;
        Ff.pole[n+1]= (tt>>18)&7;
        Ff.pole[n+2]= (tt>>15)&7;
        Ff.pole[n+3]= (tt>>12)&7;
        Ff.pole[n+4]= (tt>>9)&7;
        Ff.pole[n+5]= (tt>>6)&7;
        Ff.pole[n+6]= (tt>>3)&7;
        Ff.pole[n+7]= tt&7;


    }


    return Ff;

}


miniDoska transMiniDoska(Doska Aa)
{

    union
    {
        int tt;
        char t[4];
    };

    miniDoska Ff;

    for (int n=0, nn= 0; n<32; n+=8, nn+=3 )
    {
    tt=(Aa.pole[n]<<21)|(Aa.pole[n+1]<<18)|(Aa.pole[n+2]<<15)|(Aa.pole[n+3]<<12)|
                            (Aa.pole[n+4]<<9)|(Aa.pole[n+5]<<6)|(Aa.pole[n+6]<<3)|
                           (Aa.pole[n+7]);

    Ff.pole[nn]=t[0];
    Ff.pole[nn+1]=t[1];
    Ff.pole[nn+2]=t[2];


    }


    return Ff;
}



void goProverka(Doska Ss)
{

int be=0;
int ce=0;
for (int i=0;i<32;i++)
if ((Ss.pole[i]==1)||(Ss.pole[i]==3)) ce++;
else if ((Ss.pole[i]==2)||(Ss.pole[i]==4)) be++;
string fil;
fil=ff_[int(saska)]+fff[be]+fff[ce]+".txt";

// проверка не сеществует ли такая же комбинация
std::fstream vmdelet_in;
vmdelet_in.open(fil, std::ios::in| std::ios_base::binary);  // открываем файл для записи в конец
vmdelet_in.seekg( 0, std::ios::end );
unsigned int razm = vmdelet_in.tellg()/13;

miniDoska Aa = transMiniDoska(Ss);
miniDoska Bb;



 for(unsigned int vbv=0;vbv<razm;vbv++)
 {
     vmdelet_in.seekp(vbv*13,ios::beg);
     vmdelet_in.read(Bb.pole,12);


     int g;
     for(g=0;g<12;g++) if (Aa.pole[g]!=Bb.pole[g]) g=40;
     if (g==12)
     {
//     cout << "odinak ";
     char zz[1];
     vmdelet_in.read(zz,1);
     vmdelet_in.close();
     Rezultat[boolProv] = zz[0];
     boolProv++;
     return;

     }

 }

   cout << "no!";


}

void putFile(Doska Aa)
{


    miniDoska mD;

    mD = transMiniDoska(Aa);
    mD.pole[12] = saska;
/*
    if (ProvRR == 1)
    {
        goProverka(Aa);
        return;
}
*/

    int m=0;
    for (int t=0;t<32;t++)
        if (Aa.pole[t]>0) m++;

    if (m<18){

        if(saska==2)
        Mem2_.insert(mD);
        else
        Mem2.insert(mD);
        return;
    }


    unsigned int memSizB,memSizE;

    if (saska == 2)
    {
        memSizB = Mem1_.size();
        Mem1_.insert(mD);
        memSizE = Mem1_.size();
   }else
    {
        memSizB = Mem1.size();
        Mem1.insert(mD);
        memSizE = Mem1.size();
    }

      // проверка не сеществует ли такая же комбинация
    if (memSizB == memSizE)       return;

    int be=0;
    int ce=0;
    for (int i=0;i<32;i++)
    if ((Aa.pole[i]==1)||(Aa.pole[i]==3)) ce++;
    else if ((Aa.pole[i]==2)||(Aa.pole[i]==4)) be++;
    string fil;
    fil=ff_[int(saska)]+fff[be]+fff[ce]+".txt";


    std::fstream vmdelet_in;
    vmdelet_in.open(fil, std::ios::in| std::ios_base::binary);  // открываем файл для записи в конец
    vmdelet_in.seekg( 0, std::ios::end );
    unsigned int razm = vmdelet_in.tellg()/13;

    unsigned int bbuub = ((be*13+ce)<<24)+razm;

    vmdelet_in.close();


    std::ofstream vmdelet_out; //создаем поток


    vmdelet_out.open(fil, std::ios::app| std::ios_base::binary);  // открываем файл для записи в конец

    for (int i=0;i<12;i++) vmdelet_out << mD.pole[i];                        // сама запись

    vmdelet_out << '=';

                       // сама запись
    vmdelet_out.close();

    stek buffer;
    buffer.igrok = saska;
    buffer.pole = bbuub;
    buffer.rezultat=0;



    poradok.push_back(buffer);
  naChstep++;


}


void setRes(unsigned int Der, char res, int sas)
{

    unsigned int Nn = (Der>>24)&0xff;
    unsigned int Num = Der&0xfffff;
    string fil;
    fil=ff_[sas]+fff[Nn/13]+fff[Nn%13]+".txt";


   std::ofstream out (fil,ios_base::in|ios_base::binary);
   out.seekp (Num*13+12, std::ios::beg);
   out.put (res);
   out.close ();


}



miniDoska  GetMem(unsigned int Der, int sas )
{

    unsigned int Nn = (Der>>24)&0xff;
    unsigned int Num = Der&0xfffff;
    string fil;
    fil=ff_[sas]+fff[Nn/13]+fff[Nn%13]+".txt";

    std::fstream vmdelet_in; //создаем поток
    vmdelet_in.open(fil, std::ios::in| std::ios_base::binary);
    vmdelet_in.seekp(Num*13,ios::beg);
    miniDoska Aa;

    vmdelet_in.read(Aa.pole,12);
    vmdelet_in.close();


return (Aa);
}

Doska GetPole(string imia)
{

    Doska Aa;

    ifstream file_in(imia, ios::in);
    if (!file_in) {
        cout << "Error when try to open file " << endl;
    }

    char Ch[2];
   for (int i = 0; i < 32; i++)
     {
             do
             {
                 file_in.read(Ch, 1);
             } while ((Ch[0] == ' ') || (Ch[0] == 0xd) || (Ch[0] == 0xa));

       if (Ch[0] == '.') Aa.pole[i]=0;
       if (Ch[0] == '1') Aa.pole[i]=1;
       if (Ch[0] == '2') Aa.pole[i]=2;
       if (Ch[0] == '!') Aa.pole[i]=3;
       if (Ch[0] == '@') Aa.pole[i]=4;

     }
  file_in.close();

   return Aa;

}
