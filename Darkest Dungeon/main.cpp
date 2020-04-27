#include <iostream>
#include <windows.h>
#include <stdio.h>

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
void pintarMarco();
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
void pintarMenu(int p){
    string Menu[4] = {"Iniciar juego", "Instrucciones", "Creditos", "Salir"};
    int puntero = p;
    gotoxy(86,1);
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
                puntero -= 1;
                if (puntero == -1)
                {
                    puntero = 3;
                }
                break;
            }
            if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                puntero += 1;
                if (puntero == 4)
                {
                    puntero = 0;
                }
                break;
            }
            if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch (puntero)
                {
                    case 0:
                        system("cls");
                        pintarMarco();
                        pintarJugar();
                        pintarMenu(puntero);
                        gotoxy(2,10);
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
                        pintarMarco();
                        pintarSalir();
                        pintarMenu(puntero);
                        gotoxy(2,10);
                        cout << "El juego se cerrara en breve.";
                        Sleep(5000);
                        return 0;
                        break;
                }
                break;
            }
        }
        Sleep(125);
    }
}
