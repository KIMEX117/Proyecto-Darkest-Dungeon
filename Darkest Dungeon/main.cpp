#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <mmsystem.h>

using namespace std;

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}
void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwpos;
    dwpos.X = x;
    dwpos.Y = y;
    SetConsoleCursorPosition(hcon, dwpos);
}
void pintarMarcoJugar();
void pintarMarco();
void pintarescenario();
void plaguedoctor();
void vestal();
void highwayman();
void crusader();
void escudo();
void esqueleto();
void arquero();
void arquero_2();
void pintarTitulo();
void pintarMenu(int p);
void pintarInstruc();
void pintarJugar();
void pintarCreditos();
void pintarSalir();
int inicio(); //int para poder cerrar la aplicacion
//Para visualizar mejor la funcionalidad de este programa, cerrar los void de pintar

int main()
{
    inicio();
}

void pintarescenario()
{
    //JUEGO CONTINUO
    bool on=true;
    //VARIABLES MATRIZ        #1              #10                 #15                 #20                 #25                 #30                 #35                 #40                 #45                 #50                 #30                 #55                 #60                 #65                 #70                 #75                 #80                 #85                 #90
    char matrizJuego[20][90]={' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',
                              '_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_',
                              ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                              '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_',
                              ' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',
                              '_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_',
                              ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                              '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_',
                              ' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',
                              '_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_',
                              ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                              '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_',
                              ' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',
                              '_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_',
                              '_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_',
                              '_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_',
                              '_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_',
                              '_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_',
                              '_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_',
                              '_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_'};
    while(on)
    {
        //TECLA PRESIONADA
        if(kbhit())
        {
            for(int i=0;i<20;i++){
                for(int j=0;j<90;j++){
                        gotoxy(j+1,i+1);
                    cout<<matrizJuego[i][j];
                }
                cout<<endl;
            }

            char tecla = getch();
            if(tecla == 'd'){

            }
            if(tecla == 'a'){

            }
            if(tecla == 'w'){
                break;
            }
        }
    }
}

void plaguedoctor()
{
    gotoxy(3,10);
    cout<<"   _.~~	"<<endl;
    gotoxy(3,11);
    cout<<"  (__)  "<<endl;
    gotoxy(3,12);
    cout<<"  <  >  "<<endl;
    gotoxy(3,13);
    cout<<"   )(   "<<endl;
    gotoxy(3,14);
    cout<<"  /~~"<<char(92)<<"  "<<endl;
    gotoxy(3,15);
    cout<<" /~~~~"<<char(92)<<" "<<endl;
    gotoxy(3,16);
    cout<<"(______)"<<endl;
}

void vestal()
{
    gotoxy(16,10);
    cout<<"  ___  "<<endl;
    gotoxy(16,11);
    cout<<"<|"<<char(34)<<"^"<<char(34)<<"|>"<<endl;
    gotoxy(16,12);
    cout<<"<|^"<<char(34)<<"^|>"<<endl;
    gotoxy(16,13);
    cout<<"<|"<<char(34)<<"^"<<char(34)<<"|>"<<endl;
    gotoxy(16,14);
    cout<<"  "<<char(92)<<" /"<<endl;
    gotoxy(16,15);
    cout<<"  | |"<<endl;
    gotoxy(16,16);
    cout<<"  |_|"<<endl;
}

void highwayman()
{
    gotoxy(27,11);
    cout<<"  __,____ "<<endl;
    gotoxy(27,12);
    cout<<" /__.==--"<<char(34)<<endl;
    gotoxy(27,13);
    cout<<"/#(-'     "<<endl;
    gotoxy(27,14);
    cout<<"`-'		 "<<endl;
}

void crusader()
{
    gotoxy(40,10);
    cout<<"  /|"<<char(92)<<" "<<endl;
    gotoxy(40,11);
    cout<<" | | | "<<endl;
    gotoxy(40,12);
    cout<<" | | | "<<endl;
    gotoxy(40,13);
    cout<<" | | | "<<endl;
    gotoxy(40,14);
    cout<<"[/////]"<<endl;
    gotoxy(40,15);
    cout<<"  |_|  "<<endl;
    gotoxy(40,16);
    cout<<" (~~~) "<<endl;
}

void escudo()
{
    gotoxy(53,10);
    cout<<" _.-^-._ "<<endl;
    gotoxy(53,11);
    cout<<"|   :   |"<<endl;
    gotoxy(53,12);
    cout<<"|  .:.  |"<<endl;
    gotoxy(53,13);
    cout<<"|.:::::.|"<<endl;
    gotoxy(53,14);
    cout<<"| ::::: |"<<endl;
    gotoxy(53,15);
    cout<<"|  ':'  |"<<endl;
    gotoxy(53,16);
    cout<<char(92)<<"   :   /"<<endl;
    gotoxy(53,17);
    cout<<" `-.:.-` "<<endl;
}

void esqueleto()
{
    gotoxy(64,12);
    cout<<" _____ "<<endl;
    gotoxy(64,13);
    cout<<"/     "<<char(92)<<endl;
    gotoxy(64,14);
    cout<<"|() ()|"<<endl;
    gotoxy(64,15);
    cout<<char(92)<<"  ^  /"<<endl;
    gotoxy(64,16);
    cout<<" ||||| "<<endl;
    gotoxy(64,17);
    cout<<" ''''' "<<endl;
}

void arquero()
{
    gotoxy(72,12);
    cout<<"    /"<<char(92)<<"   "<<endl;
    gotoxy(72,13);
    cout<<"   |--"<<char(92)<<"  "<<endl;
    gotoxy(72,14);
    cout<<"<--+====~"<<endl;
    gotoxy(72,15);
    cout<<"   |--/  "<<endl;
    gotoxy(72,16);
    cout<<"    "<<char(92)<<"/   "<<endl;
}

void arquero_2()
{
    gotoxy(83,12);
    cout<<"    /"<<char(92)<<"   "<<endl;
    gotoxy(83,13);
    cout<<"   |--"<<char(92)<<"  "<<endl;
    gotoxy(83,14);
    cout<<"<--+====~"<<endl;
    gotoxy(83,15);
    cout<<"   |--/  "<<endl;
    gotoxy(83,16);
    cout<<"    "<<char(92)<<"/   "<<endl;
}

void pintarMarcoJugar()
{
    for(int i = 1; i < 100; i++)
    {
        gotoxy(i,0);
        cout<<"";
    }
    //La de la parte derecha
    for(int i = 1; i < 29; i++)
    {
        gotoxy(117,i);
        cout<<"\272";
    }
    //La parte de abajo en medio
    for(int i = 116; i >= 0; i--)
    {
        gotoxy(i,21);
        if(i == 0)
        {
            cout<<"\310";
        }
        if(i == 92)
        {
            cout<<char(202);
        }
        cout<<"\315";
    }
    //La parte de abajo
    for(int i = 116; i >= 0; i--)
    {
        gotoxy(i,29);
        if(i == 0)
        {
            cout<<"\310";
        }
        if(i == 92)
        {
            cout<<char(202);
        }
        cout<<"\315";
    }
    gotoxy(117,29);
    cout<<"\274";
    gotoxy(111,21);

    //la parte de arriba
    for(int i = 116; i >= 0; i--)
    {
        gotoxy(i,0);
        if(i == 0)
        {
            cout<<"\311";
        }
        if(i == 92)
        {
            cout<<char(203);
        }
        cout<<"\315";
    }
    gotoxy(117,0);
    cout<<"\273";
    //Parte de la izquierda
    for(int i = 28; i > 0; i--)
    {
        gotoxy(0,i);
        cout<<"\272";
    }
    //La cosa de en medio
    for(int i=1;i<21;i++)
    {
        gotoxy(92,i);
        cout<<char(186);
    }
    //El palo de la derecha
    for(int i = 22;i < 29; i++)
    {
        gotoxy(92,i);
        cout<<char(186);
    }
    //El palo de la izquierda
    for(int i = 22;i < 29; i++)
    {
        gotoxy(40,i);
        cout<<char(186);
    }

}

void pintarMarco(){
    for(int i = 1; i < 100; i++)
    {
        gotoxy(i,0);
        cout<<"";
    }
    //Parte de arriba a abajo derecha
    for(int i = 1; i < 21; i++)
    {
        gotoxy(111,i);
        cout<<"\272";
    }
    //De izquierda a derecha abajo
    for(int i = 110; i >= 0; i--)
    {
        gotoxy(i,21);
        if(i == 0)
        {
            cout<<"\310";
        }
        if(i == 84){
            cout<<char(202);
        }
        cout<<"\315";
    }
    gotoxy(111,21);
    cout<<"\274";
    //la parte de arriba
    for(int i = 110; i >= 0; i--)
    {
        gotoxy(i,0);
        if(i == 0)
        {
            cout<<"\311";
        }
        if(i == 84){
            cout<<char(203);
        }
        cout<<"\315";
    }
    gotoxy(111,0);
    cout<<"\273";
    for(int i = 20; i > 0; i--)
    {
        gotoxy(0,i);
        cout<<"\272";
    }
    for(int i=1;i<21;i++){
        gotoxy(84,i);
        cout<<char(186);
    }
}
void pintarTitulo(){
    gotoxy(1,1);
    cout<<"  _____             _             _     _____      "<<endl;
    gotoxy(1,2);
    cout<<" |  __ "<<char(92)<<"           | |           | |   |  __ "<<char(92)<<"                                    "<<endl;
    gotoxy(1,3);
    cout<<" | |  | | __ _ _ __| | _____  ___| |_  | |  | |_   _ _ __   __ _  ___  ___  _ __  "<<endl;
    gotoxy(1,4);
    cout<<" | |  | |/ _` | '__| |/ / _ "<<char(92)<<"/ __| __| | |  | | | | | '_ "<<char(92)<<" / _` |/ _ "<<char(92)<<"/ _ "<<char(92)<<"| '_ "<<char(92)<<" "<<endl;
    gotoxy(1,5);
    cout<<" | |__| | (_| | |  |   <  __/"<<char(92)<<"__ "<<char(92)<<" |_  | |__| | |_| | | | | (_| |  __/ (_) | | | |"<<endl;
    gotoxy(1,6);
    cout<<" |_____/ "<<char(92)<<"__,_|_|  |_|"<<char(92)<<"_"<<char(92)<<"___||___/"<<char(92)<<"__| |_____/ "<<char(92)<<"__,_|_| |_|"<<char(92)<<"__, |"<<char(92)<<"___|"<<char(92)<<"___/|_| |_|"<<endl;
    gotoxy(1,7);
    cout<<"                                                            __/ |                 "<<endl;
    gotoxy(1,8);
    cout<<"                                                           |___/                  "<<endl;
}
void pintarMenu(int p)
{
    string Menu[4] = {"Iniciar juego", "Instrucciones", "Creditos", "Salir"};
    int puntero = p;
    gotoxy(88,1);
    cout << "Main Menu";
    for (int j = 0; j < 4; j++)
    {
        if (j == puntero)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            gotoxy(86,3+j);
            cout << Menu[j] << endl;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            gotoxy(86,3+j);
            cout << Menu[j] << endl;
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(86,10);
    cout << "Botones del menu:";
    gotoxy(86,12);
    cout << "Flecha arriba:";
    gotoxy(86,13);
    cout << "Ir arriba en las opciones";
    gotoxy(86,15);
    cout << "Flecha abajo:";
    gotoxy(86,16);
    cout << "Ir abajo en las opciones";
    gotoxy(86,18);
    cout << "Enter:";
    gotoxy(86,19);
    cout << "Elegir opcion";
}
void pintarInstruc(){
    gotoxy(1,1);
    cout<<"  _____           _                       _                       "<<endl;
    gotoxy(1,2);
    cout<<" |_   _|         | |                     (_)                      "<<endl;
    gotoxy(1,3);
    cout<<"   | |  _ __  ___| |_ _ __ _   _  ___ ___ _  ___  _ __   ___  ___ "<<endl;
    gotoxy(1,4);
    cout<<"   | | | '_ "<<char(92)<<"/ __| __| '__| | | |/ __/ __| |/ _ "<<char(92)<<"| '_ "<<char(92)<<" / _ "<<char(92)<<"/ __|"<<endl;
    gotoxy(1,5);
    cout<<"  _| |_| | | "<<char(92)<<"__ "<<char(92)<<" |_| |  | |_| | (_| (__| | (_) | | | |  __/"<<char(92)<<"__ "<<char(92)<<""<<endl;
    gotoxy(1,6);
    cout<<" |_____|_| |_|___/"<<char(92)<<"__|_|   "<<char(92)<<"__,_|"<<char(92)<<"___"<<char(92)<<"___|_|"<<char(92)<<"___/|_| |_|"<<char(92)<<"___||___/"<<endl;
}
void pintarJugar(){
    gotoxy(1,1);
    cout<<"       _                        ";
    gotoxy(1,2);
    cout<<"      | |                       ";
    gotoxy(1,3);
    cout<<"      | |_   _  __ _  __ _ _ __ ";
    gotoxy(1,4);
    cout<<"  _   | | | | |/ _` |/ _` | '__|";
    gotoxy(1,5);
    cout<<" | |__| | |_| | (_| | (_| | |   ";
    gotoxy(1,6);
    cout<<"  "<<char(92)<<"____/ "<<char(92)<<"__,_|"<<char(92)<<"__, |"<<char(92)<<"__,_|_|   ";
    gotoxy(1,7);
    cout<<"                __/ |           ";
    gotoxy(1,8);
    cout<<"               |___/            ";
}
void pintarCreditos(){
    gotoxy(1,1);
    cout<<"   _____              _ _ _            ";
    gotoxy(1,2);
    cout<<"  / ____|            | (_) |           ";
    gotoxy(1,3);
    cout<<" | |     _ __ ___  __| |_| |_ ___  ___ ";
    gotoxy(1,4);
    cout<<" | |    | '__/ _ "<<char(92)<<"/ _` | | __/ _ "<<char(92)<<"/ __|";
    gotoxy(1,5);
    cout<<" | |____| | |  __/ (_| | | || (_) "<<char(92)<<"__ "<<char(92);
    gotoxy(1,6);
    cout<<"  "<<char(92)<<"_____|_|  "<<char(92)<<"___|"<<char(92)<<"__,_|_|"<<char(92)<<"__"<<char(92)<<"___/|___/";
}
void pintarSalir(){
    gotoxy(1,1);
    cout<<"   _____       _ _      ";
    gotoxy(1,2);
    cout<<"  / ____|     | (_)     ";
    gotoxy(1,3);
    cout<<" | (___   __ _| |_ _ __ ";
    gotoxy(1,4);
    cout<<"  "<<char(92)<<"___ "<<char(92)<<" / _` | | | '__|";
    gotoxy(1,5);
    cout<<"  ____) | (_| | | | |   ";
    gotoxy(1,6);
    cout<<" |_____/ "<<char(92)<<"__,_|_|_|_|   ";
}

int inicio(){
    int puntero = 0;
    while(true)
    {
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        pintarMarco();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        pintarTitulo();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        pintarMenu(puntero);
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                PlaySound(TEXT("ui_town_button_embark.wav"),NULL,SND_SYNC);
                puntero -= 1;
                if (puntero == -1)
                {
                    puntero = 3;
                }
                break;
            }
            if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                PlaySound(TEXT("ui_town_button_embark.wav"),NULL,SND_SYNC);
                PlaySound(TEXT(""),NULL,SND_ASYNC);
                puntero += 1;
                if (puntero == 4)
                {
                    puntero = 0;
                }
                break;
            }
            if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                PlaySound(TEXT("ui_shr_button_click.wav"),NULL,SND_ASYNC);
                switch (puntero)
                {
                    case 0:
                        system("cls");
                        PlaySound(TEXT("gen_title_startgame.wav"),NULL,SND_ASYNC);
                        pintarMarcoJugar();
                        pintarescenario();
                        plaguedoctor();
                        vestal();
                        highwayman();
                        crusader();
                        escudo();
                        esqueleto();
                        arquero();
                        arquero_2();
                        gotoxy(2,10);
                        Sleep(1000);
                        while (true)
                        {
                            if (GetAsyncKeyState(VK_RETURN) != 0)
                            {
                                break;
                            }
                            if (GetAsyncKeyState(VK_UP) != 0){}
                            if (GetAsyncKeyState(VK_DOWN) != 0){}
                        }
                        system("cls");
                        break;
                    case 1:
                        system("cls");
                        pintarMarco();
                        pintarInstruc();
                        pintarMenu(puntero);
                        gotoxy(2,2);
                        cout << "";
                        gotoxy(2,8);
                        cout << "-> Tendras que atravesar las 3 mazmorras para completar el juego";
                        gotoxy(2,9);
                        cout << "-> Iniciaras unicamente con 4 personajes, dependera de ti su supervivencia";
                        gotoxy(2,10);
                        cout << "-> Tienes que eliminar a todos los enemigos en tu camino";
                        gotoxy(2,11);
                        cout << "-> Perderas unicamente cuando todos tus personajes mueran";
                        gotoxy(2,12);
                        cout << "-> Utilizaras teclas para interactuar con el juego, presta atencion al tutorial";
                        gotoxy(2,13);
                        cout << "-Presiona enter para regresar-";
                        Sleep(1000);
                        while (true){
                            if (GetAsyncKeyState(VK_RETURN) != 0)
                            {
                                break;
                            }
                            if (GetAsyncKeyState(VK_UP) != 0){}
                            if (GetAsyncKeyState(VK_DOWN) != 0){}
                        }
                        system("cls");
                        break;
                    case 2:
                        system("cls");
                        pintarMarco();
                        pintarCreditos();
                        pintarMenu(puntero);
                        gotoxy(2,8);
                        cout << "Instituto: Universidad Aut"<<char(162)<<"noma de Baja California Sur";
                        gotoxy(2,10);
                        cout << "Departamento: Departamento Acad"<<char(130)<<"mico de Sistemas Computacionales - (DASC)";
                        gotoxy(2,12);
                        cout << "Profesor: Ing. Jonathan Giovanni Soto Mu"<<char(164)<<"oz";
                        gotoxy(2,14);
                        cout << "Materia: Programaci"<<char(162)<<"n I";
                        gotoxy(2,16);
                        cout << "Equipo: David Alonso Estrada Buenrostro";
                        gotoxy(10,17);
                        cout << "Enrique Le"<<char(162)<<"n Geraldo";
                        gotoxy(10,18);
                        cout << "Ian Manuel Rodr"<<char(161)<<"guez Jacinto";
                        gotoxy(2,20);
                        cout << "-Presiona enter para regresar-";
                        Sleep(1000);
                        while (true){
                            if (GetAsyncKeyState(VK_RETURN) != 0)
                            {
                                break;
                            }
                            if (GetAsyncKeyState(VK_UP) != 0){}
                            if (GetAsyncKeyState(VK_DOWN) != 0){}
                        }
                        system("cls");
                        break;
                    case 3:
                        system("cls");
                        PlaySound(TEXT("ui_shr_window_popup.wav"),NULL,SND_ASYNC);
                        pintarMarco();
                        pintarSalir();
                        pintarMenu(puntero);
                        gotoxy(2,10);
                        cout << "El juego se cerrara en breve.";
                        Sleep(3000);
                        return 0;
                        break;
                }
                break;
            }
        }
        Sleep(125);
    }
}
