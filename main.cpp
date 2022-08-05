#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

float plansza[3][3];
int wy=0, sz=0, pentla=0,pentla2=0, res=0;
int wP=0, sP=0,wR=0, sR=0, wygrana=0, B=0;
int posta=0;


//--------------------------------------------

void W_pla()
{
    system("cls");
    pentla=0;
    wy=0;

    while(pentla<=2)
    {
        while(pentla2<=2)
        {
            if(plansza[wy][sz]==0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            }
            else if(plansza[wy][sz]==1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
            }
            else if(plansza[wy][sz]==8)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
            }
            cout<<plansza[wy][sz]<<" ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
            sz++;
            pentla2++;
        }
        cout<<endl;
        wy++;
        pentla++;
        pentla2=0;
        sz=0;
    }
}

void Podaj()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout<<"Podaj pole: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    cin>>wP>>sP;

    if(plansza[wP][sP] == 1 || plansza[wP][sP] == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cout<<"Nie mozesz tu postawic!  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
        Podaj();
    }
    else if(wP>=3||sP>=3)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cout<<"Za wysoka liczba, tylko 0-2!  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
        Podaj();
    }
    else
    {
        plansza[wP][sP] = 0;
        posta++;
    }

}

/*void Wcz_P()
{
    if(plansza[wP][sP] == 1 || plansza[wP][sP] == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cout<<"Nie mozesz tu postawic!  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
        Podaj();
    }
    else if(wP>=3||sP>=3)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cout<<"Za wysoka liczba, tylko 0-2!  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
        Podaj();
    }
    else
    {
        plansza[wP][sP] = 0;
        posta++;
    }
}*/

void R_rob()
{
    Sleep(100);
    wR = rand()%3;
    sR = rand()%3;
    if(plansza[wR][sR] == 0 || plansza[wR][sR] == 1)
    {
        R_rob();
    }
    else
    {
        plansza[wR][sR] = 1;
        posta++;
    }
}

void S_wygrana()
{
    while(B<=1)
    {
            if(plansza[0][0] == B && plansza[0][1] == B && plansza[0][2] == B)          // POZIOMO
        {
            wygrana=1;
        }
        else if(plansza[1][0] == B && plansza[1][1] == B && plansza[1][2] == B)
        {
            wygrana=1;
        }
        else if(plansza[2][0] == B && plansza[2][1] == B && plansza[2][2] == B)
        {
            wygrana=1;
        }
        else if(plansza[0][0] == B && plansza[1][0] == B && plansza[2][0] == B)     // PIONOWO
        {
            wygrana=1;
        }
        else if(plansza[0][1] == B && plansza[1][1] == B && plansza[2][1] == B)
        {
            wygrana=1;
        }
        else if(plansza[0][2] == B && plansza[1][2] == B && plansza[2][2] == B)
        {
            wygrana=1;
        }
        else if(plansza[0][0] == B && plansza[1][1] == B && plansza[2][2] == B)    //UKOSY
        {
            wygrana=1;
        }
        else if(plansza[0][2] == B && plansza[1][1] == B && plansza[2][0] == B)
        {
            wygrana=1;
        }
        //-------------------------------------------------------------------------------------

        if(wygrana==1 && B==0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout<<"WYGRAL GRACZ"<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
            Sleep(8000);
            wygrana=0;
            res=1;
        }
        else if(wygrana==1 && B==1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout<<"WYGRAL KOMPUTER"<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
            Sleep(8000);
            wygrana=0;
            res=1;
        }
        B++;

    }


}

void Restart()
{
    if(res==1)
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    srand(time(NULL));
    plansza[0][0] = 8;
    plansza[0][1] = 8;
    plansza[0][2] = 8;

    plansza[1][0] = 8;
    plansza[1][1] = 8;
    plansza[1][2] = 8;

    plansza[2][0] = 8;
    plansza[2][1] = 8;
    plansza[2][2] = 8;
    system("cls");
    res=0;
    posta=0;

    }
    else
    {
        Sleep(200);
    }
}

void Remis()
{
    //if(plansza[0][0]==0||plansza[0][0]==1&&plansza[0][1]==0||plansza[0][1]==1&&plansza[0][2]==0||plansza[0][2]==1&&
    //   plansza[1][0]==0||plansza[1][0]==1&&plansza[1][1]==0||plansza[1][1]==1&&plansza[1][2]==0||plansza[1][2]==1&&
    //   plansza[2][0]==0||plansza[2][0]==1&&plansza[2][1]==0||plansza[2][1]==1&&plansza[2][2]==0||plansza[2][2]==1&&wygrana==0)
    if(posta==9&&res!=1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
        cout<<"  !.REMIS.!  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
        Sleep(5000);
        res=1;
    }
}
//----------------------------------------------

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
        srand(time(NULL));
        plansza[0][0] = 8;
        plansza[0][1] = 8;
        plansza[0][2] = 8;
        plansza[1][0] = 8;
        plansza[1][1] = 8;
        plansza[1][2] = 8;
        plansza[2][0] = 8;
        plansza[2][1] = 8;
        plansza[2][2] = 8;


    while(res<=1)
    {
        W_pla(); //pokazuje plansze

        Podaj(); //szczytuje wysokoc i szerokosc pola

        //Wcz_P(); //zaladuj ruch gracza

        W_pla();

        S_wygrana();  //sprawdza czy ktos wygral
        B=0;  //resetuje S_wygrana
        Remis();
        Restart(); //resetuje gre


        W_pla();

        R_rob(); //teraz kolej robota

        W_pla();

        S_wygrana();
        B=0;
        Remis();
        Restart();

    }


    return 0;
}
