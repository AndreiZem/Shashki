#include "print.h"


void PrintDoska(Doska Zz)
{
    int i=0;
cout << endl;
    for( int x=0;x<8;x++)
{
        cout << 8-x << "  ";
        if (x%2==0) cout << "   ";
        for( int y=0;y<4;y++)
        {
            cout << ".";
            if (Zz.pole[i]==0) cout << ".";
            if (Zz.pole[i]==1) cout << "c";
            if (Zz.pole[i]==2) cout << "b";
            if (Zz.pole[i]==4) cout << "B";
            if (Zz.pole[i]==3) cout << "C";
 if (Zz.pole[i]>100) cout << "^";

            cout << ".   ";
i++;
        }
     cout << endl;
}

 //   cout << endl << "   a  b  c  d  e  f  g  h" <<endl;

}


