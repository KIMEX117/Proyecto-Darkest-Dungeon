#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <mmsystem.h>
#include <cstdlib>
#include <stdlib.h>
#include "Enemigo.h"
#include "Heroe.h"
#include "Ataque.h"
#include <time.h>

using namespace std;

void ShowConsoleCursor(bool showFlag){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}
void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwpos;
    dwpos.X = x;
    dwpos.Y = y;
    SetConsoleCursorPosition(hcon, dwpos);
}
//CREAR HEROES
void crearCrusader(Heroe heroes[4]){
    heroes[0].setName("Crusader");
    heroes[0].setMaxHealth(33);
    heroes[0].setHealth(33);//33
    heroes[0].setAccuracy(0);
    heroes[0].setDamage(9);
    heroes[0].setCritic(0);
    heroes[0].setDodge(8);
    heroes[0].setProtection(23);
    heroes[0].setPosition(0);
}
void crearHighwayman(Heroe heroes[4]){
    heroes[1].setName("Highwayman");
    heroes[1].setMaxHealth(26);
    heroes[1].setHealth(26);//26
    heroes[1].setAccuracy(0);
    heroes[1].setDamage(8);
    heroes[1].setCritic(0);
    heroes[1].setDodge(14);
    heroes[1].setProtection(19);
    heroes[1].setPosition(1);
}
void crearVestal(Heroe heroes[4]){
    heroes[2].setName("Vestal");
    heroes[2].setMaxHealth(24);
    heroes[2].setHealth(24);//24
    heroes[2].setAccuracy(0);
    heroes[2].setDamage(6);
    heroes[2].setCritic(0);
    heroes[2].setDodge(10);
    heroes[2].setProtection(15);
    heroes[2].setPosition(2);
}
void crearDoctor(Heroe heroes[4]){
    heroes[3].setName("Plague Doctor");
    heroes[3].setMaxHealth(23);
    heroes[3].setHealth(23);//23
    heroes[3].setAccuracy(0);
    heroes[3].setDamage(7);
    heroes[3].setCritic(0);
    heroes[3].setDodge(12);
    heroes[3].setProtection(13);
    heroes[3].setPosition(3);
}
//CREAR ENEMIGOS
void crearSoldier(int creacion, Enemigo enemigos[4]){
    enemigos[creacion].setName("Skeleton Soldier");
    enemigos[creacion].setMaxHealth(10);
    enemigos[creacion].setHealth(10);//10
    enemigos[creacion].setAccuracy(0);
    enemigos[creacion].setDamage(5);
    enemigos[creacion].setCritic(0);
    enemigos[creacion].setDodge(10);
    enemigos[creacion].setProtection(15);
    enemigos[creacion].setPosition(creacion);
}
void crearArbalist(int creacion, Enemigo enemigos[4]){
    enemigos[creacion].setName("Skeleton Arbalist");
    enemigos[creacion].setMaxHealth(14);
    enemigos[creacion].setHealth(14);//14
    enemigos[creacion].setAccuracy(0);
    enemigos[creacion].setDamage(6);
    enemigos[creacion].setCritic(0);
    enemigos[creacion].setDodge(5);
    enemigos[creacion].setProtection(5);
    enemigos[creacion].setPosition(creacion);
}
void crearDefender(int creacion, Enemigo enemigos[4]){
    enemigos[creacion].setName("Skeleton Defender");
    enemigos[creacion].setMaxHealth(16);
    enemigos[creacion].setHealth(16);//16
    enemigos[creacion].setAccuracy(0);
    enemigos[creacion].setDamage(4);
    enemigos[creacion].setCritic(0);
    enemigos[creacion].setDodge(7);
    enemigos[creacion].setProtection(25);
    enemigos[creacion].setPosition(creacion);
}
void crearCaptain(int creacion, Enemigo enemigos[4]){
    enemigos[creacion].setName("Skeleton Captain");
    enemigos[creacion].setMaxHealth(28);
    enemigos[creacion].setHealth(28);//28
    enemigos[creacion].setAccuracy(0);
    enemigos[creacion].setDamage(6);
    enemigos[creacion].setCritic(0);
    enemigos[creacion].setDodge(1);
    enemigos[creacion].setProtection(33);
    enemigos[creacion].setPosition(creacion);
}
void crearNecromancer(int creacion, Enemigo enemigos[4]){
    enemigos[creacion].setName("Necromancer");
    enemigos[creacion].setMaxHealth(95);
    enemigos[creacion].setHealth(95);//95
    enemigos[creacion].setAccuracy(0);
    enemigos[creacion].setDamage(5);
    enemigos[creacion].setCritic(0);
    enemigos[creacion].setDodge(2);
    enemigos[creacion].setProtection(5);
    enemigos[creacion].setPosition(creacion);
}
//HABILIDADES DE HEROES
void crusaderSkills(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int habilidad;
    bool accion = false;
    bool mostrar = false;
    gotoxy(6,28);cout<<"Turno: "<<turno;
    gotoxy(22,28);cout<<"Heroe: Crusader";
    gotoxy(41,22);cout<<"  HABILIDADES        (Ingresar numero de habilidad)";
    do{
        if(heroes[turno].getPosition()<2){
            for(int i=0;i<2;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                gotoxy(41,23);cout<<"1.- Smite";
                gotoxy(41,24);cout<<"2.- Stunning Blow";
                gotoxy(41,25);cout<<"3.- Zealous Accusation";
                mostrar = false;
            }
        }
        for(int i=0;i<4;i++){
            if(heroes[i].getHealth()<heroes[i].getMaxHealth()){
                mostrar = true;
            }
        }
        if(mostrar==true){
            gotoxy(41,26);cout<<"4.- Battle Heal";
            mostrar = false;
        }
        gotoxy(41,27);cout<<"5.- Cambiar posicion";
        gotoxy(41,28);cout<<"6.- Saltar turno";
        gotoxy(70,24);cout<<"Opcion: ";
        cin>>habilidad;
        //HABILIDAD 1
        /*
        if (GetAsyncKeyState(0x31)){
            habilidad=1;
            if(heroes[turno].getPosition()<2){
                for(int i=0;i<2;i++){
                    if(enemigos[i].getHealth()>0){
                        accion = true;
                    }
                }
            }
        }
        //HABILIDAD 2
        if (GetAsyncKeyState(0x32)){
            habilidad=2;
            if(heroes[turno].getPosition()<2){
                for(int i=0;i<2;i++){
                    if(enemigos[i].getHealth()>0){
                        accion = true;
                    }
                }
            }
        }
        //HABILIDAD 3
        if (GetAsyncKeyState(0x33)){
            habilidad=3;
            if(heroes[turno].getPosition()<2){
                for(int i=0;i<2;i++){
                    if(enemigos[i].getHealth()>0){
                        accion = true;
                    }
                }
            }
        }
        //HABILIDAD 4
        if (GetAsyncKeyState(0x34)){
            habilidad=4;
            for(int i=0;i<4;i++){
                if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                    accion = true;
                }
            }
        }
        //HABILIDAD 5
        if (GetAsyncKeyState(0x35)){
            habilidad=5;
            accion = true;
        }
        //HABILIDAD 6
        if (GetAsyncKeyState(0x36)){
            habilidad=6;
            accion = true;
        }
        */
        switch(habilidad){
            case 1:
                if(heroes[turno].getPosition()<2){
                    for(int i=0;i<2;i++){
                        if(enemigos[i].getHealth()>0){
                            accion = true;
                        }
                    }
                }
                break;
            case 2:
                if(heroes[turno].getPosition()<2){
                    for(int i=0;i<2;i++){
                        if(enemigos[i].getHealth()>0){
                            accion = true;
                        }
                    }
                }
                break;
            case 3:
                if(heroes[turno].getPosition()<2){
                    for(int i=0;i<2;i++){
                        if(enemigos[i].getHealth()>0){
                            accion = true;
                        }
                    }
                }
                break;
            case 4:
                for(int i=0;i<4;i++){
                    if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                        accion = true;
                    }
                }
                break;
            case 5:
                accion = true;
                break;
            case 6:
                accion = true;
                break;
        }
    }while(accion==false);
    switch(habilidad){
        case 1:
            Ataque().CrusaderSkill_Smite(turno,heroes,enemigos);
            break;
        case 2:
            Ataque().CrusaderSkill_StunningBlow(turno,heroes,enemigos);
            break;
        case 3:
            Ataque().CrusaderSkill_ZealousAccusation(turno,heroes,enemigos);
            break;
        case 4:
            Ataque().CrusaderSkill_BattleHeal(turno,heroes,enemigos);
            break;
        case 5:
            Ataque().SharedHeroSkill_Move(turno,heroes);
            break;
        case 6:
            break;
        default:
            break;
    }
}
void highwaymanSkills(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int habilidad;
    bool accion = false;
    bool mostrar = false;
    gotoxy(4,28);cout<<"Turno: "<<turno;
    gotoxy(20,28);cout<<"Heroe: Highwayman";
    gotoxy(41,22);cout<<"  HABILIDADES        (Ingresar numero de habilidad)";
    do{
        if(heroes[turno].getPosition()<3){
            for(int i=0;i<2;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                gotoxy(41,23);cout << "1.- Slice" << endl;
                gotoxy(41,24);cout << "2.- Open Vein" << endl;
                mostrar = false;
            }
        }
        if(heroes[turno].getPosition()>0){
            for(int i=1;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                gotoxy(41,25);cout << "3.- Pistol shot" << endl;
                mostrar = false;
            }
        }
        if(heroes[turno].getPosition()>0&&heroes[turno].getPosition()<3){
            for(int i=1;i<3;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                gotoxy(41,26);cout << "4.- Grapeshot" << endl;
                mostrar = false;
            }
        }
        gotoxy(41,27);cout << "5.- Cambiar posicion" << endl;
        gotoxy(41,28);cout << "6.- Saltar turno" << endl;
        gotoxy(70,24);cout << "Opcion: ";
        cin >> habilidad;
        switch(habilidad){
            case 1:
                if(heroes[turno].getPosition()<3){
                    for(int i=0;i<2;i++){
                        if(enemigos[i].getHealth()>0){
                            accion = true;
                        }
                    }
                }
                break;
            case 2:
                if(heroes[turno].getPosition()<3){
                    for(int i=0;i<2;i++){
                        if(enemigos[i].getHealth()>0){
                            accion = true;
                        }
                    }
                }
                break;
            case 3:
                if(heroes[turno].getPosition()>0){
                    for(int i=1;i<4;i++){
                        if(enemigos[i].getHealth()>0){
                            accion = true;
                        }
                    }
                }
                break;
            case 4:
                if(heroes[turno].getPosition()>0&&heroes[turno].getPosition()<3){
                    for(int i=0;i<3;i++){
                        if(enemigos[i].getHealth()>0){
                            accion = true;
                        }
                    }
                }
                break;
            case 5:
                accion = true;
                break;
            case 6:
                accion = true;
                break;
        }
    }while(accion==false);
    switch(habilidad){
        case 1:
            Ataque().HighwaymanSkill_Slice(turno,heroes,enemigos);
            break;
        case 2:
            Ataque().HighwaymanSkill_OpenVein(turno,heroes,enemigos);
            break;
        case 3:
            Ataque().HighwaymanSkill_PistolShot(turno,heroes,enemigos);
            break;
        case 4:
            Ataque().HighwaymanSkill_Grapeshot(turno,heroes,enemigos);
            break;
        case 5:
            Ataque().SharedHeroSkill_Move(turno,heroes);
            break;
        case 6:
            break;
        default:
            break;
    }
}
void vestalSkills(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int habilidad;
    bool accion = false;
    bool mostrar = false;
    gotoxy(6,28);cout<<"Turno: "<<turno;
    gotoxy(22,28);cout<<"Heroe: Vestal";
    gotoxy(41,22);cout<<"  HABILIDADES        (Ingresar numero de habilidad)";
    do{
        if(heroes[turno].getPosition()>=0){
            for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                gotoxy(41,23);cout << "1.- Judgement" << endl;
                mostrar = false;
            }
        }
        if(heroes[turno].getPosition()>0){
            for(int i=0;i<3;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                gotoxy(41,24);cout << "2.- Dazzling Light" << endl;
                mostrar = false;
            }
        }
        if(heroes[turno].getPosition()>1){
            for(int i=0;i<4;i++){
                if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                gotoxy(41,25);cout << "3.- Divine Grace" << endl;
                mostrar = false;
            }
        }
        if(heroes[turno].getPosition()>0){
            for(int i=0;i<4;i++){
                if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                gotoxy(41,26);cout << "4.- Divine Comfort" << endl;
                mostrar = false;
            }
        }
        gotoxy(41,27);cout << "5.- Cambiar posicion" << endl;
        gotoxy(41,28);cout << "6.- Saltar turno" << endl;
        gotoxy(70,24);cout << "Opcion: ";
        cin >> habilidad;
        switch(habilidad){
            case 1:
                if(heroes[turno].getPosition()>=0){
                    for(int i=0;i<4;i++){
                        if(enemigos[i].getHealth()>0){
                            accion = true;
                        }
                    }
                }
                break;
            case 2:
                if(heroes[turno].getPosition()>0){
                    for(int i=0;i<3;i++){
                        if(enemigos[i].getHealth()>0){
                            accion = true;
                        }
                    }
                }
                break;
            case 3:
                if(heroes[turno].getPosition()>1){
                    for(int i=0;i<4;i++){
                        if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                            accion = true;
                        }
                    }
                }
                break;
            case 4:
                for(int i=0;i<4;i++){
                    if(heroes[i].getHealth()<heroes[i].getMaxHealth()){
                        accion = true;
                    }
                }
                break;
            case 5:
                accion = true;
                break;
            case 6:
                accion = true;
                break;
        }
    }while(accion==false);
    switch(habilidad){
        case 1:
            Ataque().VestalSkill_Judgement(turno,heroes,enemigos);
            break;
        case 2:
            Ataque().VestalSkill_DazzlingLight(turno,heroes,enemigos);
            break;
        case 3:
            Ataque().VestalSkill_DivineGrace(turno,heroes,enemigos);
            break;
        case 4:
            Ataque().VestalSkill_DivineComfort(turno,heroes,enemigos);
            break;
        case 5:
            Ataque().SharedHeroSkill_Move(turno,heroes);
            break;
        case 6:
            break;
        default:
            break;
    }
}
void doctorSkills(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int habilidad;
    bool accion = false;
    bool mostrar = false;
    gotoxy(6,28);cout<<"Turno: "<<turno;
    gotoxy(22,28);cout<<"Heroe: Doctor";
    gotoxy(41,22);cout<<"  HABILIDADES        (Ingresar numero de habilidad)";
    do{
        if(heroes[turno].getPosition()>0){
            for(int i=0;i<2;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                gotoxy(41,23);cout << "1.- Noxious Blast" << endl;
                mostrar = false;
            }
        }
        if(heroes[turno].getPosition()>1){
            for(int i=2;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                gotoxy(41,24);cout << "2.- Plague Grenade" << endl;
                gotoxy(41,25);cout << "3.- Blinding Gas" << endl;
                mostrar = false;
            }
        }
        if(heroes[turno].getPosition()>1){
            for(int i=0;i<4;i++){
                if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                gotoxy(41,26);cout << "4.- Battlefield Medicine" << endl;
                mostrar = false;
            }
        }
        gotoxy(41,27);cout << "5.- Cambiar posicion" << endl;
        gotoxy(41,28);cout << "6.- Saltar turno" << endl;
        gotoxy(70,24);cout << "Opcion: ";
        cin >> habilidad;
        switch(habilidad){
            case 1:
                if(heroes[turno].getPosition()>0){
                    for(int i=0;i<2;i++){
                        if(enemigos[i].getHealth()>0){
                            accion = true;
                        }
                    }
                }
                break;
            case 2:
                if(heroes[turno].getPosition()>1){
                    for(int i=2;i<4;i++){
                        if(enemigos[i].getHealth()>0){
                            accion = true;
                        }
                    }
                }
                break;
            case 3:
                if(heroes[turno].getPosition()>1){
                    for(int i=2;i<4;i++){
                        if(enemigos[i].getHealth()>0){
                            accion = true;
                        }
                    }
                }
                break;
            case 4:
                if(heroes[turno].getPosition()>1){
                    for(int i=0;i<4;i++){
                        if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                            accion = true;
                        }
                    }
                }
                break;
            case 5:
                accion = true;
                break;
            case 6:
                accion = true;
                break;
        }
    }while(accion==false);
    switch(habilidad){
        case 1:
            Ataque().PlagueDoctorSkill_NoxiousBlast(turno,heroes,enemigos);
            break;
        case 2:
            Ataque().PlagueDoctorSkill_PlagueGrenade(turno,heroes,enemigos);
            break;
        case 3:
            Ataque().PlagueDoctorSkill_BlindingGas(turno,heroes,enemigos);
            break;
        case 4:
            Ataque().PlagueDoctorSkill_BattlefieldMedicine(turno,heroes,enemigos);
            break;
        case 5:
            Ataque().SharedHeroSkill_Move(turno,heroes);
            break;
        case 6:
            break;
        default:
            break;
    }
}
//HABILIDADES DE ENEMIGOS
void soldierSkills(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int habilidad;
    gotoxy(3,28);cout<<"Turno: "<<turno;
    gotoxy(14,28);cout << "Enemigo: Skeleton Soldier" << endl;
    if(enemigos[turno].getPosition()!=3){
        if(heroes[0].getHealth()>0||heroes[1].getHealth()>0||heroes[2].getHealth()>0){
            habilidad = 1;
        }else{
            habilidad = 3;
        }
    }else{
        if(heroes[3].getHealth()>0){
            habilidad = 2;
        }else{
            habilidad = 3;
        }
    }
    switch(habilidad){
        case 1:
            Ataque().SoldierSkill_GraveyardSlash(turno,heroes,enemigos);
            break;
        case 2:
            Ataque().SoldierSkill_GraveyardStumble(turno,heroes,enemigos);
            break;
        default:
            break;
    }
}
void arbalistSkills(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int habilidad;
    gotoxy(3,28);cout << "Turno: " << turno << endl;
    gotoxy(13,28);cout << "Enemigo: Skeleton Arbalist" << endl;
    if(enemigos[turno].getPosition()>1){
        if(heroes[1].getHealth()>0||heroes[2].getHealth()>0||heroes[3].getHealth()>0){
            habilidad = 1;
        }else{
            habilidad = 3;
        }
    }else{
        if(heroes[0].getHealth()>0||heroes[1].getHealth()>0){
            habilidad = 2;
        }else{
            habilidad = 3;
        }
    }
    switch(habilidad){
        case 1:
            Ataque().ArbalistSkill_Quarrel(turno,heroes,enemigos);
            break;
        case 2:
            Ataque().ArbalistSkill_BayonetJab(turno,heroes,enemigos);
            break;
        default:
            break;
    }
}
void defenderSkills(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int habilidad;
    gotoxy(3,28);cout << "Turno: " << turno << endl;
    gotoxy(13,28);cout << "Enemigo: Skeleton Defender" << endl;
    if(enemigos[turno].getPosition()<2){
        if(heroes[0].getHealth()>0||heroes[1].getHealth()>0){
            habilidad = (rand()%2)+1;
        }else{
            habilidad = 4;
        }
    }else{
        if(heroes[2].getHealth()>0||heroes[3].getHealth()>0){
            habilidad = 3;
        }else{
            habilidad = 4;
        }
    }
    switch(habilidad){
        case 1:
            Ataque().DefenderSkill_AxeBlade(turno,heroes,enemigos);
            break;
        case 2:
            Ataque().DefenderSkill_DeadWeight(turno,heroes,enemigos);
            break;
        case 3:
            Ataque().DefenderSkill_ClumsyAxeBlade(turno,heroes,enemigos);
        default:
            break;
    }
}
void captainSkills(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int habilidad;
    gotoxy(3,28);cout << "Turno: " << turno << endl;
    gotoxy(14,28);cout << "Enemigo: Skeleton Captain" << endl;
    if(enemigos[turno].getPosition()<2){
        if(heroes[0].getHealth()>0||heroes[1].getHealth()>0){
            habilidad = (rand()%2)+1;
        }else{
            habilidad = 3;
        }
    }else{
        if(heroes[0].getHealth()>0||heroes[1].getHealth()>0||heroes[2].getHealth()>0||heroes[3].getHealth()>0){
            habilidad = 2;
        }else{
            habilidad = 3;
        }
    }
    switch(habilidad){
        case 1:
            Ataque().CaptainSkill_CrushingBlow(turno,heroes,enemigos);
            break;
        case 2:
            Ataque().CaptainSkill_GroundPound(turno,heroes,enemigos);
            break;
        default:
            break;
    }
}
void necromancerSkills(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int habilidad;
    gotoxy(4,28);cout << "Turno: " << turno << endl;
    gotoxy(16,28);cout << "Enemigo: Necromancer" << endl;
    if(enemigos[turno].getPosition()>=0&&enemigos[turno].getPosition()<=3){
        if(heroes[0].getHealth()>0||heroes[1].getHealth()>0||heroes[2].getHealth()>0||heroes[3].getHealth()>0){
            habilidad = (rand()%3)+1;
        }else{
            habilidad = 4;
        }
    }
    switch(habilidad){
        case 1:
            Ataque().NecromancerSkill_WillingFlesh(turno,heroes,enemigos);
            break;
        case 2:
            Ataque().NecromancerSkill_CrawlingDead(turno,heroes,enemigos);
            break;
        case 3:
            Ataque().NecromancerSkill_SixFeetUnder(turno,heroes,enemigos);
            break;
        default:
            break;
    }
}
//MOVIMIENTO DEL MAPA
void movimientoEscenario();
//PINTAR EN PANTALLA
void pintarMarcoJugar();
void pintarMarco();
void pintarEscenario();
void pintarBatalla();
bool pintarCombate(char matrizJuego[20][185], bool copia);
void repintarPersonajes(Heroe heroes[4],Enemigo enemigos[4]);
void borrarHabilidades();
void borrarEnemigosStats(Heroe heroes[4]);
void vidaPersonajes(Heroe heroes[4],Enemigo enemigos[4]);
void pintarmapa();
void plagueDoctor(int pos_X_Personaje);
void vestal(int pos_X_Personaje);
void highwayman(int pos_X_Personaje);
void crusader(int pos_X_Personaje);
void captain(int pos_X_Personaje);
void defender(int pos_X_Personaje);
void soldier(int pos_X_Personaje);
void arbalist(int pos_X_Personaje);
void necromancer(int pos_X_Personaje);
void pintarCastillo();
void pintarTitulo();
void pintarMenu(int p);
void pintarInstruc();
void pintarJugar();
void pintarCreditos();
void pintarSalir();
int inicio();

int main()
{
    inicio();
}
//METODO ELECCION DE PASILLO (CANCELADO)
void opcionJuego(int opcion){
    string camino[2]={"Left","Right"};
    gotoxy(35,10);cout<<"0====================0";
    gotoxy(35,11);cout<<"|  Elige un camino:  |";
    gotoxy(35,12);cout<<"|        <->         |";
    gotoxy(35,13);cout<<"0====================0";

    for(int i=0;i<2;i++){
        if(i==opcion){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            gotoxy(38,12);
            cout<< camino[i] << endl;
        }else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            gotoxy(49,12);
            cout << camino[i] << endl;
        }
    }
}
//FUNCION PRINCIPAL PARA EL DESARROLLO DEL GAMEPLAY
void pintarEscenario(){
    //JUEGO CONTINUO
    bool on=true;
    //POSICIONES DEL ESCENARIO
    int pos_x=0;
    int movimiento=1;
    bool desplazamiento=true;
    //POSICION EN EL MAPA Y EVENTOS
    //int randomCaracter = 0;
    //srand (time(NULL));
    int posicion_actual = 0;
    //PUNTOS DE LOS NIVELES
    int puntos_cofre = 0;
    int puntos_enemigos = 0;
    int puntos_obtenidos = 0;
    //VARIABLES NIVEL
    //int opcion=0;
    bool pasillo=false;
    bool nivel_1=true;
    bool nivel_2=false;
    bool nivel_F=false;
    //VARIABLES COMBATE
    bool combate=false;
    bool activo=true;
    bool copia=false;
    Enemigo enemigos[4];
    Heroe heroes[4];
    int heroesvivos = 4;
    int enemigosvivos = 4;
    //CREACION DE HEROES
    crearCrusader(heroes);
    crearHighwayman(heroes);
    crearVestal(heroes);
    crearDoctor(heroes);

    //MAPA           #1              #5          #8          #11         #14         #17         #20         #23
    char mapa[23] = {'O',' ',' ',' ','X',' ',' ','?',' ',' ','?',' ',' ','X',' ',' ','?',' ',' ','?',' ',' ','X'};
    //POSICION X MATRIZ        #1              #5                  #10                 #15                 #20                 #25                 #30                 #35                 #40                 #45                 #50                 #55                 #60                 #65                 #70                 #75                 #80                 #85                 #90                 #95                #100                #105                #110                #115                #120                #125                #130                #135                #140                #145                #150                #155                #160                #165                #170                #175                #180                #185
    char matrizJuego[20][185]={' ',' ',' ',' ',' ','_','_','_','_','_','_','_','_',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','(','o','.','_','_','_','.','o',')',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','(','o','.','_','_','_','.','o',')',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','(','o','.','_','_','_','.','o',')',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','_','_','_','_','_','_','_','_',' ',' ',' ',' ',' ',
                               ' ','_','_','_','[','_','_','_','_','_','_','_','_',']','_','_','_',' ','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','+','+','=','=','=','=','=','=','=','+','+','_','_','_','_','|','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','+','+','=','=','=','=','=','=','=','+','+','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' ','_','_','_','[','_','_','_','_','_','_','_','_',']','_','_','_',' ',
                               '[','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',']',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|',' ',' ',' ',' ',' ',' ',' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','_','_',',','~','~','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','_','_',',','~','~','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ','|','|',' ',' ',' ',' ',' ',' ',' ','|','|',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|','_','_',',','~','~','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ','[','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',']',
                               ',','|','|','.','"','"','"','"','"','"','"','"','"','"','.','|','|',',','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','|',' ',' ',' ',' ',' ',' ',' ','|','|','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','|','|',' ',' ',' ',' ',' ',' ',' ','|','|','_','_','_','_','|','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_',',','|','|','.','"','"','"','"','"','"','"','"','"','"','.','|','|',',',
                               ',','|','|',' ',' ',' ','_',' ','_','_',' ','_',' ',' ',' ','|','|',',',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ','|','|',' ',' ',' ',' ',' ',' ',' ','|','|',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|',' ',' ',' ',' ',' ',' ',' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',',','|','|',' ',' ',' ','_',' ','_','_',' ','_',' ',' ',' ','|','|',',',
                               ',','|','|',' ',' ','|',' ','|',' ',' ','|',' ','|',' ',' ','|','|',',','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','+','+','=','=','=','=','=','=','=','+','+','_','_','_','_','|','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','+','+','=','=','=','=','=','=','=','+','+','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',',','|','|',' ',' ','|',' ','|',' ',' ','|',' ','|',' ',' ','|','|',',',
                               ',','|','|',' ',' ','|',' ','+',' ',' ','+',' ','|',' ',' ','|','|',',',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','_','_',',','~','~','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','_','_',',','~','~','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|','_','_',',','~','~','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',',','|','|',' ',' ','|',' ','+',' ',' ','+',' ','|',' ',' ','|','|',',',
                               ',','|','|',' ',' ','|','_','|','_','_','|','_','|',' ',' ','|','|',',','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_',',','|','|',' ',' ','|','_','|','_','_','|','_','|',' ',' ','|','|',',',
                               ',',':',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',':',':',',',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',',',':',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',':',':',',',
                               ',','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','(',')',' ','|','|',',','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',',','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','(',')',' ','|','|',',',
                               ',','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|',',',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','_','_',',','~','~','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','_','_',',','~','~','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|','_','_',',','~','~','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',',','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|',',',
                               ',','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|',',','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_',',','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|',',',
                               ',','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|',',',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',',','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|',',',
                               '[','_','_',']','=','=','=','=','=','=','=','=','=','=','[','_','_',']','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','(','o','.','_','_','_','.','o',')','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','(','o','.','_','_','_','.','o',')','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','(','o','.','_','_','_','.','o',')','_','_','_','_','_','_','_','_','_','_','_','_','_','_','[','_','_',']','=','=','=','=','=','=','=','=','=','=','[','_','_',']',
                               '_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_',
                               '_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_',
                               '_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_',
                               '_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_',
                               '_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_',
                               '_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_'};

    char matrizSinCofre[20][35];
    for(int i=0;i<20;i++){
        for(int j=132;j<167;j++){
            matrizSinCofre[i][j-132]=matrizJuego[i][j];
        }
    }

    //POSICION X MATRIZ        #1              #5                 #10                 #15                 #20                 #25                 #30                 #35
    char matrizCofre[20][35]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                              '=','+','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
                              '|','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',
                              '|','|','_','_','_','.','=','"','"','_',';','=','.','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_',
                              '|',',','-','"','_',',','=','"','"',' ',' ',' ',' ',' ','`','"','=','.','_',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                              '+','"','=','.','_','o','`','"','-','.','_',' ',' ',' ',' ',' ',' ',' ',' ','`','"','=','.','_','_','_','_','_','_','_','_','_','_','_','_',
                              ' ',' ',' ',' ',' ','`','"','=','.','_','o','`','"','=','.','_',' ',' ',' ',' ',' ',' ','_','`','"','=','.','_',' ',' ',' ',' ',' ',' ',' ',
                              '_','_','_','_','_','_','_','_','_','_',':','=','.','_','o',' ','"','=','.','_','.','"','_','.','-','=','"',' ','"','=','.','_','_','_','_',
                              ' ',' ',' ','_','_','.','-','-','"',' ',',',' ',';',' ','`','"','=','.','_','o','.','"',' ',',','-','"','"','"','-','.','_',' ','"','.',' ',
                              '.','_','"',' ',' ',',','.',' ','.','`',' ','`',' ','`','`',' ',' ',' ',' ','`','"','-','.','_','"','-','.','_',' ',' ',' ','"','.',' ','`',
                              '|','o','`','"','=','.','_','`',' ',',',' ','"','`',' ','`',';',' ','.','"','.',' ',',',' ',' ','"','-','.','_','"','-','.','_',';',' ',';',
                              '|',' ',';','`','-','.','o','`','"','=','.','_',';',' ','.','"',' ','`',' ',' ','`','.','"',' ','`',' ','.',' ','"','-','.','_',' ','/','_',
                              '|','o',';',' ',' ',' ',' ','`','"','-','.','o','`','"','=','.','_','`','`',' ',' ','`','`',' ','"',' ',' ','_','_','.','-','-','o',';',' ',
                              '|',' ',';',' ',' ',' ',' ',' ','(','#',')',' ','`','-','.','o',' ','`','"','=','.',' ','_','.','-','-','"','_','o','.','-',';',' ',';','_',
                              '|','o',';','.','_',' ',' ',' ',' ','"',' ',' ',' ',' ',' ',' ','`','"','.','o','|','o','_','.','-','-','"',' ',' ',' ',' ',';','o',';','_',
                              '_','"','=','.','_','o','-','-','.','_',' ',' ',' ',' ',' ',' ',' ',' ',';',' ','|',' ',';',' ',' ',' ',' ',' ',' ',' ',' ',';',' ',';','/',
                              '_','_','_','/','_','_','"','=','.','_','o','-','-','.','_',' ',' ',' ',';','o','|','o',';',' ',' ',' ',' ',' ','_','.','_',';','o',';','_',
                              '_','_','_','_','_','_','/','_','_','_','_','"','=','.','_','o','.','_',';',' ','|',' ',';','_','.','-','-','"','o','.','-','-','"','_','/',
                              '_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','"','=','.','o','|','o','_','.','-','-','"','"','_','_','_','/','_','_','_',
                              '_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/'};

    while(on)
    {
        //PRINTEAR TODO DEL MISMO COLOR
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        //VIDA DE LOS HEROES FUERA DE COMBATE
        borrarEnemigosStats(heroes);
        //MOVIMIENTO EN EL ESCENARIO
        for(int i=0;i<20;i++){
            for(int j=pos_x;j<91+pos_x;j++){
                gotoxy(movimiento,i+1);
                if(j>131&&j<167&&(pasillo==true&&mapa[posicion_actual+1]=='I')){
                    matrizJuego[i][j]=matrizCofre[i][j-132];
                }
                if(j>131&&j<167&&(pasillo==false&&mapa[posicion_actual+1]!='I')){
                    matrizJuego[i][j]=matrizSinCofre[i][j-132];
                }
                cout<<matrizJuego[i][j];
                movimiento++;
            }
            movimiento=1;
            cout<<endl;
        }
        //SIMBOLOGIA DEL MAPA
        gotoxy(93,1);cout<<"O Posicion actual";
        gotoxy(93,2);cout<<"X Enemigos";
        gotoxy(93,3);cout<<"I Tesoro";
        gotoxy(93,4);cout<<"* Pasillo vacio";
        //PUNTAJE
        gotoxy(93,5);cout<<"Score: "<<puntos_obtenidos<<" puntos"<<endl;
        //MAPA IMPRESO EN PANTALLA
        gotoxy(100,25);cout<<"Nivel 1";
        gotoxy(100,19);cout<<"Nivel 2";
        gotoxy(96,13);cout<<"Nivel Final";
        //IMPRESION DEL MAPA
        int impresion_Y_mapa=28;
        for(int i=0;i<23;i++){
            if((i>=0&&i<=4)||(i>=11&&i<=13)||(i>=20&&i<=22)){
                gotoxy(108,impresion_Y_mapa);
                cout<<"["<<mapa[i]<<"]";
            }
            if((i>=5&&i<=7)||(i>=14&&i<=16)){
                gotoxy(105,impresion_Y_mapa);
                cout<<"["<<mapa[i]<<"]";
            }
            if((i>=8&&i<=10)||(i>=17&&i<=19)){
                if(i==8){
                    impresion_Y_mapa=23;
                }
                if(i==17){
                    impresion_Y_mapa=17;
                }
                gotoxy(111,impresion_Y_mapa);
                cout<<"["<<mapa[i]<<"]";
            }
            impresion_Y_mapa--;
        }

        //IMPRESION DE HEROES EN EL ESCENARIO
        repintarPersonajes(heroes,enemigos);

        //CAPTURA DE TECLA PARA EVITAR QUE ESTE PARPADEANDO DEMASIADO
        char tecla = getch();

        //MOVIMIENTO A LA DERECHA
        if (GetAsyncKeyState(0x44)&&desplazamiento==true)
        {
            if(nivel_1==true){
                if(pos_x<94){
                    pos_x++;
                }
                if(pos_x%22==0){
                    posicion_actual++;
                    mapa[posicion_actual] = 'O';
                    mapa[posicion_actual-1] = ' ';
                }
            }
            if(nivel_2==true){
                if(pos_x<94){
                    pos_x++;
                }
                if(pos_x%45==0){
                    posicion_actual++;
                    mapa[posicion_actual] = 'O';
                    mapa[posicion_actual-1] = ' ';
                }
                if(pasillo==true){
                    if(pos_x==89&&mapa[posicion_actual+1]=='I'){
                        puntos_cofre = rand() % 100+50;
                        puntos_obtenidos += puntos_cofre;
                        PlaySound(TEXT("sounds/ui_dun_loot_take_heirloom.wav"),NULL,SND_ASYNC);
                        PlaySound(TEXT("sounds/ui_dun_loot_take_gold.wav"),NULL,SND_ASYNC);
                        /*for(int i=0;i<4;i++){
                            if(heroes[i].getHealth()>0){
                                heroes[i].setMaxHealth(heroes[i].getMaxHealth()+3);
                                heroes[i].setHealth(heroes[i].getHealth()+3);
                                heroes[i].setDamage(heroes[i].getDamage()+2);
                                heroes[i].setDodge(heroes[i].getDodge()+5);
                                heroes[i].setProtection(heroes[i].getProtection()+8);
                            }
                        }*/
                    }
                    if(pos_x==94){
                        pasillo=false;
                        if(mapa[7]=='O'){
                            posicion_actual+=4;
                            mapa[posicion_actual] = 'O';
                            mapa[posicion_actual-4] = ' ';
                        }else{
                            posicion_actual++;
                            mapa[posicion_actual] = 'O';
                            mapa[posicion_actual-1] = ' ';
                        }
                        pos_x=0;
                    }
                }
                if(mapa[11]=='O'){
                        activo=true;
                }
            }
            if(nivel_F==true){
                if(pos_x<94){
                    pos_x++;
                }
                if(pos_x%45==0){
                    posicion_actual++;
                    mapa[posicion_actual] = 'O';
                    mapa[posicion_actual-1] = ' ';
                }
                if(pasillo==true){
                    if(pos_x==89&&mapa[posicion_actual+1]=='I'){
                        puntos_cofre = rand() % 100+50;
                        puntos_obtenidos += puntos_cofre;
                        PlaySound(TEXT("sounds/ui_dun_loot_take_heirloom.wav"),NULL,SND_ASYNC);
                        PlaySound(TEXT("sounds/ui_dun_loot_take_gold.wav"),NULL,SND_ASYNC);
                        /*for(int i=0;i<4;i++){
                            if(heroes[i].getHealth()>0){
                                heroes[i].setMaxHealth(heroes[i].getMaxHealth()+3);
                                heroes[i].setHealth(heroes[i].getHealth()+3);
                                heroes[i].setDamage(heroes[i].getDamage()+2);
                                heroes[i].setDodge(heroes[i].getDodge()+5);
                                heroes[i].setProtection(heroes[i].getProtection()+8);
                            }
                        }*/
                    }
                    if(pos_x==94){
                        pasillo=false;
                        if(mapa[16]=='O'){
                            posicion_actual+=4;
                            mapa[posicion_actual] = 'O';
                            mapa[posicion_actual-4] = ' ';
                        }else{
                            posicion_actual++;
                            mapa[posicion_actual] = 'O';
                            mapa[posicion_actual-1] = ' ';
                        }
                        pos_x=0;
                    }
                }
                if(mapa[20]=='O'){
                        activo=true;
                }
            }
        }
        //MOVIMIENTO A LA IZQUIERDA
        if (GetAsyncKeyState(0x41)&&desplazamiento==true)
        {
            if(nivel_1==true){
                if(pos_x>0)
                {
                    pos_x--;
                }
                if(pos_x==21||pos_x==43||pos_x==65||pos_x==87){
                    posicion_actual--;
                    mapa[posicion_actual] = 'O';
                    mapa[posicion_actual+1] = ' ';
                }
            }
            if(nivel_2==true||nivel_F==true){
                if(pos_x>0)
                {
                    pos_x--;
                }
                if(pos_x==44||pos_x==89){
                    posicion_actual--;
                    mapa[posicion_actual] = 'O';
                    mapa[posicion_actual+1] = ' ';
                }
            }
        }
/*===========================================================================================================
                                    C O M B A T E S

        TAMAÑO DE RECUADROS DE INFORMACION                          ENEMIGOS POR NIVEL
                                                        NIVEL 1:(DEFENDER,SOLDIER,SOLDIER Y ARBALIST)
    AREA STATS HEROES         AREA DE HABILIDADES       NIVEL 2:(CAPTAIN,DEFENDER,ARBALIST Y ARBALIST)
        7 x 39                       7 x 51             NIVEL F:(NECROMANCER,SOLDIER, SOLDIER Y ARBALIST)
===========================================================================================================*/
        //CODIGO DE COMBATES
        if(pos_x==94&&desplazamiento==true&&pasillo==false&&combate==false){
            desplazamiento=false;
            combate=true;
            //COMBATE DEL PRIMER NIVEL (DEFENDER,SOLDIER,SOLDIER Y ARBALIST)
            if(nivel_1==true&&combate==true){
                //CREACION DE ENEMIGOS
                crearDefender(0,enemigos);
                crearSoldier(1,enemigos);
                crearSoldier(2,enemigos);
                crearArbalist(3,enemigos);
                //CICLO DE TURNOS DEL COMBATE
                while(enemigosvivos>0&&heroesvivos>0&&activo==true){
                    enemigosvivos = 4;
                    heroesvivos = 4;
                    int turno = 0;
                    vidaPersonajes(heroes,enemigos);
                    //REPINTAR MAPA POR SI MUERE ALGUN ENEMIGO O HEROE
                    pintarCombate(matrizJuego,copia);
                    //REPINTADO DE HEROES
                    repintarPersonajes(heroes,enemigos);
                    //TURNOS DEL COMBATE
                    if(heroes[turno].getHealth()>0){
                        if(turno==0&&enemigosvivos>0){
                            if(heroes[turno].getMaxHealth()==33){
                                crusaderSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==26){
                                highwaymanSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==24){
                                vestalSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==23){
                                doctorSkills(turno,heroes,enemigos);
                            }
                            turno++;
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }else{
                        turno++;
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    if(heroes[turno].getHealth()>0){
                        if(turno==1&&enemigosvivos>0){
                            if(heroes[turno].getMaxHealth()==33){
                                crusaderSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==26){
                                highwaymanSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==24){
                                vestalSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==23){
                                doctorSkills(turno,heroes,enemigos);
                            }
                            turno++;
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }else{
                        turno++;
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    if(heroes[turno].getHealth()>0){
                        if(turno==2&&enemigosvivos>0){
                            if(heroes[turno].getMaxHealth()==33){
                                crusaderSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==26){
                                highwaymanSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==24){
                                vestalSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==23){
                                doctorSkills(turno,heroes,enemigos);
                            }
                            turno++;
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }else{
                        turno++;
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    if(heroes[turno].getHealth()>0){
                        if(turno==3&&enemigosvivos>0){
                            if(heroes[turno].getMaxHealth()==33){
                                crusaderSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==26){
                                highwaymanSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==24){
                                vestalSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==23){
                                doctorSkills(turno,heroes,enemigos);
                            }
                            turno++;
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }else{
                        turno++;
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    for(int i=0;i<4;i++){
                        if(enemigos[i].getHealth()>0){
                            if(enemigos[i].getMaxHealth()==10){
                                soldierSkills(i,heroes,enemigos);
                            }else if(enemigos[i].getMaxHealth()==14){
                                arbalistSkills(i,heroes,enemigos);
                            }else if(enemigos[i].getMaxHealth()==16){
                                defenderSkills(i,heroes,enemigos);
                            }else if(enemigos[i].getMaxHealth()==28){
                                captainSkills(i,heroes,enemigos);
                            }else if(enemigos[i].getMaxHealth()==95){
                                necromancerSkills(i,heroes,enemigos);
                            }
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    for(int i=0;i<4;i++){
                        if(enemigos[i].getHealth()<=0){
                            enemigosvivos--;
                        }
                    }
                    for(int i=0;i<4;i++){
                        if(heroes[i].getHealth()<=0){
                            heroesvivos--;
                        }
                    }
                }
                //CONDICION DE VICTORIA
                if(heroesvivos>0&&enemigosvivos<=0){
                    int op_pasillo=0;
                    puntos_enemigos = rand() % 100+50;
                    puntos_obtenidos += puntos_enemigos;
                    gotoxy(57,25);cout << "HAS GANADO EL COMBATE";
                    Sleep(2000);
                    do{
                        borrarHabilidades();
                        gotoxy(60,23);cout << "~ PASILLOS ~";
                        gotoxy(60,24);cout<<"1. Izquierda";
                        gotoxy(60,25);cout<<"2. Derecha";
                        gotoxy(60,26);cout<<"Opcion: ";cin>>op_pasillo;
                    }while(op_pasillo<1||op_pasillo>2);
                    if(op_pasillo==1){
                        posicion_actual++;
                        mapa[posicion_actual] = 'O';
                        mapa[posicion_actual-1] = ' ';
                        if(nivel_1==true){
                            nivel_1=false;
                            nivel_2=true;
                            pasillo=true;
                            mapa[7]='I';
                            mapa[10]='*';
                        }
                        pos_x = 0;
                    }
                    if(op_pasillo==2){
                        posicion_actual+=4;
                        mapa[posicion_actual] = 'O';
                        mapa[posicion_actual-4] = ' ';
                        if(nivel_1==true){
                            nivel_1=false;
                            nivel_2=true;
                            pasillo=true;
                            mapa[7]='I';
                            mapa[10]='*';
                        }
                        pos_x = 0;
                    }
                    Sleep(100);
                    borrarHabilidades();
                    borrarEnemigosStats(heroes);
                    desplazamiento=true;
                    combate=false;
                    activo=false;
                    pintarMarcoJugar();
                }
                if(enemigosvivos>0&&heroesvivos<=0){
                    gotoxy(57,25);cout << "HAS PERDIDO EL COMBATE";
                    PlaySound(TEXT("sounds/gen_title_stygianbutton.wav"),NULL,SND_ASYNC);
                    Sleep(2500);
                    gotoxy(57,25);cout << "EL JUEGO SE REINICIARA";
                    gotoxy(57,26);cout << " DESDE EL PRIMER NIVEL";
                    Sleep(2000);
                    on=false;
                }
            }
            //COMBATE DEL SEGUNDO NIVEL (CAPTAIN,DEFENDER,ARBALIST Y ARBALIST)
            if(nivel_2==true&&combate==true){
                cout<<"Pasillo: FALSO"<<endl;
                //CREACION DE ENEMIGOS
                enemigosvivos = 4;
                crearCaptain(0,enemigos);
                crearSoldier(1,enemigos);
                crearArbalist(2,enemigos);
                crearArbalist(3,enemigos);
                //CICLO DE TURNOS DEL COMBATE
                while(enemigosvivos>0&&heroesvivos>0&&activo==true){
                    enemigosvivos = 4;
                    heroesvivos = 4;
                    int turno = 0;
                    vidaPersonajes(heroes,enemigos);
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    //TURNOS DEL COMBATE
                    if(heroes[turno].getHealth()>0){
                        if(turno==0&&enemigosvivos>0){
                            if(heroes[turno].getMaxHealth()==33){
                                crusaderSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==26){
                                highwaymanSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==24){
                                vestalSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==23){
                                doctorSkills(turno,heroes,enemigos);
                            }
                            turno++;
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    if(heroes[turno].getHealth()>0){
                        if(turno==1&&enemigosvivos>0){
                            if(heroes[turno].getMaxHealth()==33){
                                crusaderSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==26){
                                highwaymanSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==24){
                                vestalSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==23){
                                doctorSkills(turno,heroes,enemigos);
                            }
                            turno++;
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }else{
                        turno++;
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    if(heroes[turno].getHealth()>0){
                        if(turno==2&&enemigosvivos>0){
                            if(heroes[turno].getMaxHealth()==33){
                                crusaderSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==26){
                                highwaymanSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==24){
                                vestalSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==23){
                                doctorSkills(turno,heroes,enemigos);
                            }
                            turno++;
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }else{
                        turno++;
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    if(heroes[turno].getHealth()>0){
                        if(turno==3&&enemigosvivos>0){
                            if(heroes[turno].getMaxHealth()==33){
                                crusaderSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==26){
                                highwaymanSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==24){
                                vestalSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==23){
                                doctorSkills(turno,heroes,enemigos);
                            }
                            turno++;
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }else{
                        turno++;
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    for(int i=0;i<4;i++){
                        if(enemigos[i].getHealth()>0){
                            if(enemigos[i].getMaxHealth()==10){
                                soldierSkills(i,heroes,enemigos);
                            }else if(enemigos[i].getMaxHealth()==14){
                                arbalistSkills(i,heroes,enemigos);
                            }else if(enemigos[i].getMaxHealth()==16){
                                defenderSkills(i,heroes,enemigos);
                            }else if(enemigos[i].getMaxHealth()==28){
                                captainSkills(i,heroes,enemigos);
                            }else if(enemigos[i].getMaxHealth()==95){
                                necromancerSkills(i,heroes,enemigos);
                            }
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    for(int i=0;i<4;i++){
                        if(enemigos[i].getHealth()<=0){
                            enemigosvivos--;
                        }
                    }
                    for(int i=0;i<4;i++){
                        if(heroes[i].getHealth()<=0){
                            heroesvivos--;
                        }
                    }
                }
                //CONDICION DE VICTORIA
                if(heroesvivos>0&&enemigosvivos<=0){
                    int op_pasillo=0;
                    puntos_enemigos = rand() % 100+50;
                    puntos_obtenidos += puntos_enemigos;
                    gotoxy(57,25);cout << "HAS GANADO EL COMBATE";
                    Sleep(2000);
                    do{
                        borrarHabilidades();
                        gotoxy(60,23);cout << "~ PASILLOS ~";
                        gotoxy(60,24);cout<<"1. Izquierda";
                        gotoxy(60,25);cout<<"2. Derecha";
                        gotoxy(60,26);cout<<"Opcion: ";cin>>op_pasillo;
                    }while(op_pasillo<1||op_pasillo>2);
                    if(op_pasillo==1){
                        posicion_actual++;
                        mapa[posicion_actual] = 'O';
                        mapa[posicion_actual-1] = ' ';
                        if(nivel_2==true){
                            nivel_2=false;
                            nivel_F=true;
                            pasillo=true;
                            mapa[16]='*';
                            mapa[19]='I';
                        }
                        pos_x = 0;
                    }
                    if(op_pasillo==2){
                        posicion_actual+=4;
                        mapa[posicion_actual] = 'O';
                        mapa[posicion_actual-4] = ' ';
                        if(nivel_2==true){
                            nivel_2=false;
                            nivel_F=true;
                            pasillo=true;
                            mapa[16]='*';
                            mapa[19]='I';
                        }
                        pos_x = 0;
                    }
                    Sleep(100);
                    borrarHabilidades();
                    borrarEnemigosStats(heroes);
                    desplazamiento=true;
                    combate=false;
                    activo=false;
                    pintarMarcoJugar();
                }
                if(enemigosvivos>0&&heroesvivos<=0){
                    gotoxy(57,25);cout << "HAS PERDIDO EL COMBATE";
                    PlaySound(TEXT("sounds/gen_title_stygianbutton.wav"),NULL,SND_ASYNC);
                    Sleep(2500);
                    gotoxy(57,25);cout << "EL JUEGO SE REINICIARA";
                    gotoxy(57,26);cout << " DESDE EL PRIMER NIVEL";
                    Sleep(2000);
                    on=false;
                }
            }
            //COMBATE DEL TERCER NIVEL (NECROMANCER,SOLDIER, SOLDIER Y ARBALIST)
            if(nivel_F==true&&combate==true){
                //CREACION DE ENEMIGOS
                enemigosvivos = 4;
                crearNecromancer(0,enemigos);
                crearSoldier(1,enemigos);
                crearSoldier(2,enemigos);
                crearArbalist(3,enemigos);
                //CICLO DE TURNOS DEL COMBATE
                while(enemigosvivos>0&&heroesvivos>0&&activo==true){
                    enemigosvivos = 4;
                    heroesvivos = 4;
                    int turno = 0;
                    vidaPersonajes(heroes,enemigos);
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    //TURNOS DEL COMBATE
                    if(heroes[turno].getHealth()>0){
                        if(turno==0&&enemigosvivos>0){
                            if(heroes[turno].getMaxHealth()==33){
                                crusaderSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==26){
                                highwaymanSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==24){
                                vestalSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==23){
                                doctorSkills(turno,heroes,enemigos);
                            }
                            turno++;
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    if(heroes[turno].getHealth()>0){
                        if(turno==1&&enemigosvivos>0){
                            if(heroes[turno].getMaxHealth()==33){
                                crusaderSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==26){
                                highwaymanSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==24){
                                vestalSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==23){
                                doctorSkills(turno,heroes,enemigos);
                            }
                            turno++;
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }else{
                        turno++;
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    if(heroes[turno].getHealth()>0){
                        if(turno==2&&enemigosvivos>0){
                            if(heroes[turno].getMaxHealth()==33){
                                crusaderSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==26){
                                highwaymanSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==24){
                                vestalSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==23){
                                doctorSkills(turno,heroes,enemigos);
                            }
                            turno++;
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }else{
                        turno++;
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    if(heroes[turno].getHealth()>0){
                        if(turno==3&&enemigosvivos>0){
                            if(heroes[turno].getMaxHealth()==33){
                                crusaderSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==26){
                                highwaymanSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==24){
                                vestalSkills(turno,heroes,enemigos);
                            }else if(heroes[turno].getMaxHealth()==23){
                                doctorSkills(turno,heroes,enemigos);
                            }
                            turno++;
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }else{
                        turno++;
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    for(int i=0;i<4;i++){
                        if(enemigos[i].getHealth()>0){
                            if(enemigos[i].getMaxHealth()==10){
                                soldierSkills(i,heroes,enemigos);
                            }else if(enemigos[i].getMaxHealth()==14){
                                arbalistSkills(i,heroes,enemigos);
                            }else if(enemigos[i].getMaxHealth()==16){
                                defenderSkills(i,heroes,enemigos);
                            }else if(enemigos[i].getMaxHealth()==28){
                                captainSkills(i,heroes,enemigos);
                            }else if(enemigos[i].getMaxHealth()==95){
                                necromancerSkills(i,heroes,enemigos);
                            }
                            vidaPersonajes(heroes,enemigos);
                            Sleep(3000);
                            borrarHabilidades();
                            pintarMarcoJugar();
                            gotoxy(1,28);cout<<"                                       ";
                        }
                    }
                    pintarCombate(matrizJuego,copia);
                    repintarPersonajes(heroes,enemigos);
                    for(int i=0;i<4;i++){
                        if(enemigos[i].getHealth()<=0){
                            enemigosvivos--;
                        }
                    }
                    for(int i=0;i<4;i++){
                        if(heroes[i].getHealth()<=0){
                            heroesvivos--;
                        }
                    }
                }
                //CONDICION DE VICTORIA
                if(heroesvivos>0&&enemigosvivos<=0){
                    puntos_enemigos = rand() % 100+50;
                    puntos_obtenidos += puntos_enemigos;
                    gotoxy(57,25);cout<<"HAS GANADO EL COMBATE";
                    Sleep(2000);
                    borrarHabilidades();
                    gotoxy(35,10);cout<<"0====================0";
                    gotoxy(35,11);cout<<"|  HAS TERMINADO EL  |";
                    gotoxy(35,12);cout<<"|        JUEGO.      |";
                    gotoxy(35,13);cout<<"0====================0";
                    gotoxy(60,25);cout<<"FELICIDADES";
                    Sleep(4000);
                }
                if(enemigosvivos>0&&heroesvivos<=0){
                    gotoxy(57,25);cout << "HAS PERDIDO EL COMBATE";
                    PlaySound(TEXT("sounds/gen_title_stygianbutton.wav"),NULL,SND_ASYNC);
                    Sleep(2500);
                    gotoxy(57,25);cout << "EL JUEGO SE REINICIARA";
                    gotoxy(57,26);cout << " DESDE EL PRIMER NIVEL";
                    Sleep(2000);
                    on=false;
                }
            }
        }
    }
}
//PRINTEAR STATS DE VIDA Y BORRAR
void borrarHabilidades(){
    for(int i=22;i<29;i++){
        for(int j=41;j<92;j++){
            gotoxy(j,i);
            cout<<" ";
        }
        cout<<endl;
    }
}
void borrarEnemigosStats(Heroe heroes[4]){
    //BORRAR STATS ENEMIGOS
    for(int i=22;i<27;i++){
        for(int j=23;j<39;j++){
            gotoxy(j,i);
            cout<<" ";
        }
        cout<<endl;
    }
    //MOSTRAR VIDA DE HEROES
    gotoxy(4,22);cout<<"Health HEROES";
    for(int i=0;i<4;i++){
        gotoxy(5,23+i);cout<<i<<" - ";
        //VIDA MENOR A 0
        if(heroes[i].getHealth()<=0){
            cout<<" 0 / "<<heroes[i].getMaxHealth();
        }
        //VIDA MAYOR A 0 PERO MENOR A 10
        if(heroes[i].getHealth()>0&&heroes[i].getHealth()<10){
            cout<<" "<<heroes[i].getHealth()<<" / "<<heroes[i].getMaxHealth();
        }//VIDA MAYOR O IGUAL A 10
        if(heroes[i].getHealth()>=10){
            cout<<heroes[i].getHealth()<<" / "<<heroes[i].getMaxHealth();
        }
    }
}
void vidaPersonajes(Heroe heroes[4],Enemigo enemigos[4]){
    //LIMPIAR ZONA DE STATS DE VIDA
    for(int i=23;i<27;i++){
        for(int j=1;j<39;j++){
            gotoxy(j,i);
            cout<<" ";
        }
        cout<<endl;
    }
    //MOSTRAR VIDA DE HEROES
    gotoxy(4,22);cout<<"Health HEROES";
    for(int i=0;i<4;i++){
        gotoxy(5,23+i);cout<<i<<" - ";
        //VIDA MENOR A 0
        if(heroes[i].getHealth()<=0){
            cout<<" 0 / "<<heroes[i].getMaxHealth();
        }
        //VIDA MAYOR A 0 PERO MENOR A 10
        if(heroes[i].getHealth()>0&&heroes[i].getHealth()<10){
            cout<<" "<<heroes[i].getHealth()<<" / "<<heroes[i].getMaxHealth();
        }//VIDA MAYOR O IGUAL A 10
        if(heroes[i].getHealth()>=10){
            cout<<heroes[i].getHealth()<<" / "<<heroes[i].getMaxHealth();
        }

    }
    //MOSTRAR VIDA ENEMIGOS
    gotoxy(23,22);cout<<"Health ENEMIES";
    for(int i=0;i<4;i++){
        gotoxy(25,23+i);cout<<i<<" - ";
        //VIDA MENOR A 0
        if(enemigos[i].getHealth()<=0){
            cout<<" 0 / "<<enemigos[i].getMaxHealth();
        }
        //VIDA MAYOR A 0 PERO MENOR A 10
        if(enemigos[i].getHealth()>0&&enemigos[i].getHealth()<10){
            cout<<" "<<enemigos[i].getHealth()<<" / "<<enemigos[i].getMaxHealth();
        }//VIDA MAYOR O IGUAL A 10
        if(enemigos[i].getHealth()>=10){
            cout<<enemigos[i].getHealth()<<" / "<<enemigos[i].getMaxHealth();
        }
    }
}
//ESCENARIO DE BATALLA (CANCELADO)
void pintarBatalla(){
    char matrizPelea[20][91]={'(','o','.','_','_','_','.','o',')',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','(','o','.','_','_','_','.','o',')',
                              '_','|',' ',' ',' ',' ',' ','|','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_',
                              ' ','|','_','_',',','~','~','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ','|','_','_',',','~','~','|',' ',
                              '_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','|',' ',' ',' ',' ',' ','|','_',
                              ' ','|',' ',' ',' ',' ',' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',
                              '_','|',' ',' ',' ',' ',' ','|','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_',
                              ' ','|','_','_',',','~','~','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ','|','_','_',',','~','~','|',' ',
                              '_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','|',' ',' ',' ',' ',' ','|','_',
                              ' ','|',' ',' ',' ',' ',' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',
                              '_','|',' ',' ',' ',' ',' ','|','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ','|','_',
                              ' ','|','_','_',',','~','~','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ','|','_','_',',','~','~','|',' ',
                              '_','|',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','|',' ',' ',' ',' ',' ','|','_',
                              ' ','|',' ',' ',' ',' ',' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',
                              '(','o','.','_','_','_','.','o',')','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','(','o','.','_','_','_','.','o',')',
                              '_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_',
                              '_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_',
                              '_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_',
                              '_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_',
                              '_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_',
                              '_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_','_','_','_','_','/','_','_'};
    for(int i=0;i<20;i++){
        for(int j=0;j<91;j++){
            gotoxy(j+1,i+1);
            cout<<matrizPelea[i][j];
        }
        cout<<endl;
    }
}
//ESCENARIO DE MATRIZ PRINCIPAL COMO REPINTADO PARA COMBATES
bool pintarCombate(char matrizJuego[20][185], bool copia){
    char matrizCombate[20][91];
    //COPIADO DE CARACTERES DE UNA MATRIZ A OTRA
    if(copia==false){
        for(int i=0;i<20;i++){
            for(int j=93;j<184;j++){
                matrizCombate[i][j-93]=matrizJuego[i][j];
            }
        }
        copia=true;
    }
    //IMPRESION DE LA MATRIZ DE FONDO PARA LOS COMBATES
    for(int i=0;i<20;i++){
        for(int j=0;j<91;j++){
            gotoxy(j+1,i+1);
            cout<<matrizCombate[i][j];
        }
    }
    return copia;
}
//REPINTADO DE TODOS LOS PERSONAJES EN BATALLA VALIDANDO SU VIDA
void repintarPersonajes(Heroe heroes[4],Enemigo enemigos[4]){
    int pos_X_Personaje=0;
    //HEROES
    for(int i=0;i<4;i++){
        switch(i){
            case 0:
                pos_X_Personaje=37;
                if(heroes[i].getMaxHealth()==33&&heroes[i].getHealth()>0){
                    crusader(pos_X_Personaje);
                }else if(heroes[i].getMaxHealth()==26&&heroes[i].getHealth()>0){
                    highwayman(pos_X_Personaje);
                }else if(heroes[i].getMaxHealth()==24&&heroes[i].getHealth()>0){
                    vestal(pos_X_Personaje);
                }else if(heroes[i].getMaxHealth()==23&&heroes[i].getHealth()>0){
                    plagueDoctor(pos_X_Personaje);
                }
                break;
            case 1:
                pos_X_Personaje=25;
                if(heroes[i].getMaxHealth()==33&&heroes[i].getHealth()>0){
                    crusader(pos_X_Personaje);
                }else if(heroes[i].getMaxHealth()==26&&heroes[i].getHealth()>0){
                    highwayman(pos_X_Personaje);
                }else if(heroes[i].getMaxHealth()==24&&heroes[i].getHealth()>0){
                    vestal(pos_X_Personaje);
                }else if(heroes[i].getMaxHealth()==23&&heroes[i].getHealth()>0){
                    plagueDoctor(pos_X_Personaje);
                }
                break;
            case 2:
                pos_X_Personaje=14;
                if(heroes[i].getMaxHealth()==33&&heroes[i].getHealth()>0){
                    crusader(pos_X_Personaje);
                }else if(heroes[i].getMaxHealth()==26&&heroes[i].getHealth()>0){
                    highwayman(pos_X_Personaje);
                }else if(heroes[i].getMaxHealth()==24&&heroes[i].getHealth()>0){
                    vestal(pos_X_Personaje);
                }else if(heroes[i].getMaxHealth()==23&&heroes[i].getHealth()>0){
                    plagueDoctor(pos_X_Personaje);
                }
                break;
            case 3:
                pos_X_Personaje=2;
                if(heroes[i].getMaxHealth()==33&&heroes[i].getHealth()>0){
                    crusader(pos_X_Personaje);
                }else if(heroes[i].getMaxHealth()==26&&heroes[i].getHealth()>0){
                    highwayman(pos_X_Personaje);
                }else if(heroes[i].getMaxHealth()==24&&heroes[i].getHealth()>0){
                    vestal(pos_X_Personaje);
                }else if(heroes[i].getMaxHealth()==23&&heroes[i].getHealth()>0){
                    plagueDoctor(pos_X_Personaje);
                }
                break;
        }
    }
    //ENEMIGOS
    for(int i=0;i<5;i++){
        switch(i){
            case 0:
                pos_X_Personaje=49;
                if(enemigos[i].getMaxHealth()==10&&enemigos[i].getHealth()>0){
                    soldier(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==14&&enemigos[i].getHealth()>0){
                    arbalist(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==16&&enemigos[i].getHealth()>0){
                    defender(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==28&&enemigos[i].getHealth()>0){
                    captain(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==95&&enemigos[i].getHealth()>0){
                    necromancer(pos_X_Personaje);
                }
                break;
            case 1:
                pos_X_Personaje=61;
                if(enemigos[i].getMaxHealth()==10&&enemigos[i].getHealth()>0){
                    soldier(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==14&&enemigos[i].getHealth()>0){
                    arbalist(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==16&&enemigos[i].getHealth()>0){
                    defender(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==28&&enemigos[i].getHealth()>0){
                    captain(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==95&&enemigos[i].getHealth()>0){
                    necromancer(pos_X_Personaje);
                }
                break;
            case 2:
                pos_X_Personaje=72;
                if(enemigos[i].getMaxHealth()==10&&enemigos[i].getHealth()>0){
                    soldier(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==14&&enemigos[i].getHealth()>0){
                    arbalist(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==16&&enemigos[i].getHealth()>0){
                    defender(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==28&&enemigos[i].getHealth()>0){
                    captain(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==95&&enemigos[i].getHealth()>0){
                    necromancer(pos_X_Personaje);
                }
                break;
            case 3:
                pos_X_Personaje=83;
                if(enemigos[i].getMaxHealth()==10&&enemigos[i].getHealth()>0){
                    soldier(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==14&&enemigos[i].getHealth()>0){
                    arbalist(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==16&&enemigos[i].getHealth()>0){
                    defender(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==28&&enemigos[i].getHealth()>0){
                    captain(pos_X_Personaje);
                }else if(enemigos[i].getMaxHealth()==95&&enemigos[i].getHealth()>0){
                    necromancer(pos_X_Personaje);
                }
                break;
        }
    }
}
//REPRESENTACION GRAFICA DE HEROES Y ENEMIGOS
void plagueDoctor(int pos_X_Personaje){
    //8 x 7
    //POS 3
    gotoxy(pos_X_Personaje,8); cout<<"Doctor"<<endl;
    gotoxy(pos_X_Personaje,10);cout<<"   _.~~	"<<endl;
    gotoxy(pos_X_Personaje,11);cout<<"  (__)  "<<endl;
    gotoxy(pos_X_Personaje,12);cout<<"  <  >  "<<endl;
    gotoxy(pos_X_Personaje,13);cout<<"   )(   "<<endl;
    gotoxy(pos_X_Personaje,14);cout<<"  /~~"<<char(92)<<"  "<<endl;
    gotoxy(pos_X_Personaje,15);cout<<" /~~~~"<<char(92)<<" "<<endl;
    gotoxy(pos_X_Personaje,16); cout<<"(______)"<<endl;
}
void vestal(int pos_X_Personaje){
    //7 x 7
    //POS 16
    gotoxy(pos_X_Personaje,8); cout<<"Vestal"<<endl;
    gotoxy(pos_X_Personaje,10);cout<<"  ___  "<<endl;
    gotoxy(pos_X_Personaje,11);cout<<"<|"<<char(34)<<"^"<<char(34)<<"|>"<<endl;
    gotoxy(pos_X_Personaje,12);cout<<"<|^"<<char(34)<<"^|>"<<endl;
    gotoxy(pos_X_Personaje,13);cout<<"<|"<<char(34)<<"^"<<char(34)<<"|>"<<endl;
    gotoxy(pos_X_Personaje,14);cout<<"  "<<char(92)<<" /  "<<endl;
    gotoxy(pos_X_Personaje,15);cout<<"  | |  "<<endl;
    gotoxy(pos_X_Personaje,16);cout<<"  |_|  "<<endl;
}
void highwayman(int pos_X_Personaje){
    //10 x 4
    //POS 27
    gotoxy(pos_X_Personaje,8); cout<<"Highwayman"<<endl;
    gotoxy(pos_X_Personaje,11);cout<<"  __,____ "<<endl;
    gotoxy(pos_X_Personaje,12);cout<<" /__.==--"<<char(34)<<endl;
    gotoxy(pos_X_Personaje,13);cout<<"/#(-'     "<<endl;
    gotoxy(pos_X_Personaje,14);cout<<"`-'		 "<<endl;
}
void crusader(int pos_X_Personaje){
    //7 x 7
    //40
    gotoxy(pos_X_Personaje,8); cout<<"Crusader"<<endl;
    gotoxy(pos_X_Personaje,10);cout<<"  /|"<<char(92)<<"  "<<endl;
    gotoxy(pos_X_Personaje,11);cout<<" | | | "<<endl;
    gotoxy(pos_X_Personaje,12);cout<<" | | | "<<endl;
    gotoxy(pos_X_Personaje,13);cout<<" | | | "<<endl;
    gotoxy(pos_X_Personaje,14);cout<<"[/////]"<<endl;
    gotoxy(pos_X_Personaje,15);cout<<"  |_|  "<<endl;
    gotoxy(pos_X_Personaje,16);cout<<" (~~~) "<<endl;
}
void captain(int pos_X_Personaje){
    //11 x 9
    //POS 51
    gotoxy(pos_X_Personaje,7); cout<<"Skeleton"<<endl;
    gotoxy(pos_X_Personaje,8); cout<<" Captain"<<endl;
    gotoxy(pos_X_Personaje,9);cout<<"    ___    "<<endl;
    gotoxy(pos_X_Personaje,10);cout<<" .-"<<char(239)<<"^"<<char(34)<<"^`-. "<<endl;
    gotoxy(pos_X_Personaje,11);cout<<"<|"<<char(34)<<"^"<<char(34)<<"^"<<char(34)<<"^"<<char(34)<<"|>"<<endl;
    gotoxy(pos_X_Personaje,12);cout<<"<|^"<<char(34)<<"^"<<char(34)<<"^"<<char(34)<<"^|>"<<endl;
    gotoxy(pos_X_Personaje,13);cout<<"  `-"<<char(34)<<"^"<<char(34)<<"-"<<char(239)<<"  "<<endl;
    gotoxy(pos_X_Personaje,14);cout<<"    "<<char(92)<<" /    "<<endl;
    gotoxy(pos_X_Personaje,15);cout<<"    | |    "<<endl;
    gotoxy(pos_X_Personaje,16);cout<<"    | |    "<<endl;
    gotoxy(pos_X_Personaje,17);cout<<"    |_|    "<<endl;
}
void defender(int pos_X_Personaje){
    //10 x 8
    //POS 63
    gotoxy(pos_X_Personaje,7); cout<<"Skeleton"<<endl;
    gotoxy(pos_X_Personaje,8); cout<<"Defender"<<endl;
    gotoxy(pos_X_Personaje,10);cout<<" _.-^-._ "<<endl;
    gotoxy(pos_X_Personaje,11);cout<<"|   :   |"<<endl;
    gotoxy(pos_X_Personaje,12);cout<<"|  .:.  |"<<endl;
    gotoxy(pos_X_Personaje,13);cout<<"|.:::::.|"<<endl;
    gotoxy(pos_X_Personaje,14);cout<<"| ::::: |"<<endl;
    gotoxy(pos_X_Personaje,15);cout<<"|  ':'  |"<<endl;
    gotoxy(pos_X_Personaje,16);cout<<char(92)<<"   :   /"<<endl;
    gotoxy(pos_X_Personaje,17);cout<<" `-.:.-` "<<endl;
}
void soldier(int pos_X_Personaje){
    //10 x 9
    //POS 73
    gotoxy(pos_X_Personaje,6); cout<<"Skeleton"<<endl;
    gotoxy(pos_X_Personaje,7); cout<<"Soldier"<<endl;
    gotoxy(pos_X_Personaje,8); cout<<"   .-.   "<<endl;
    gotoxy(pos_X_Personaje,9); cout<<"  (o.o)  "<<endl;
    gotoxy(pos_X_Personaje,10);cout<<"   |=|   "<<endl;
    gotoxy(pos_X_Personaje,11);cout<<"  __|__  "<<endl;
    gotoxy(pos_X_Personaje,12);cout<<"// -|- "<<char(92)<<char(92)<<endl;
    gotoxy(pos_X_Personaje,13);cout<<char(92)<<char(92)<<" -|- //"<<endl;
    gotoxy(pos_X_Personaje,14);cout<<"  (.=.)  "<<endl;
    gotoxy(pos_X_Personaje,15);cout<<"  || ||  "<<endl;
    gotoxy(pos_X_Personaje,16);cout<<"  || ||  "<<endl;
    gotoxy(pos_X_Personaje,17);cout<<" =="<<char(39)<<" "<<char(39)<<"== "<<endl;
}
void arbalist(int pos_X_Personaje){
    //9 x 5
    //POS 83
    gotoxy(pos_X_Personaje,7); cout<<"Skeleton"<<endl;
    gotoxy(pos_X_Personaje,8); cout<<"Arbalist"<<endl;
    gotoxy(pos_X_Personaje,12);cout<<"    /"<<char(92)<<"   "<<endl;
    gotoxy(pos_X_Personaje,13);cout<<"   |--"<<char(92)<<"  "<<endl;
    gotoxy(pos_X_Personaje,14);cout<<"<--+====~"<<endl;
    gotoxy(pos_X_Personaje,15);cout<<"   |--/  "<<endl;
    gotoxy(pos_X_Personaje,16);cout<<"    "<<char(92)<<"/   "<<endl;
}
void necromancer(int pos_X_Personaje){
    //11 x 7
    //POS 83
    gotoxy(pos_X_Personaje,8); cout<<"Necromancer"<<endl;
    gotoxy(pos_X_Personaje-1,11); cout<<"    _______ ";
    gotoxy(pos_X_Personaje-1,12); cout<<"   /~~~~~/ "<<char(92);
    gotoxy(pos_X_Personaje-1,13); cout<<"   | .-. |_/";
    gotoxy(pos_X_Personaje-1,14); cout<<"   |(o.o)|  ";
    gotoxy(pos_X_Personaje-1,15); cout<<"   | |=| |  ";
    gotoxy(pos_X_Personaje-1,16); cout<<" __|__~~~|  ";
    gotoxy(pos_X_Personaje-1,17); cout<<" "<<char(92)<<"____"<<char(92)<<"__/  ";
}
//MARCOS, TITULOS Y DECORACIONES
void pintarCastillo(){
gotoxy(3,7);
cout<<"                              _   _   _";
gotoxy(3,8);
cout<<"                    |"<<char(62)<<char(62)<<char(62)<<"     |;| |;| |;|        |"<<char(62)<<char(62)<<char(62)<<" ";
gotoxy(3,9);
cout<<"                _  _|_  _    "<<char(92)<<char(92)<<".    .  /    _  _|_  _                          ";
gotoxy(3,10);
cout<<"               |;|_|;|_|;|    "<<char(92)<<char(92)<<":. ,  /    |;|_|;|_|;|                         ";
gotoxy(3,11);
cout<<"               "<<char(92)<<char(92)<<"..      /    ||;   . |    "<<char(92)<<char(92)<<".    .  /                         ";
gotoxy(3,12);
cout<<"                "<<char(92)<<char(92)<<".  ,  /     ||:  .  |     "<<char(92)<<char(92)<<":  .  /                          ";
gotoxy(3,13);
cout<<"                 ||:   |_   _ ||_ . _ | _   _||:   |                           ";
gotoxy(3,14);
cout<<"                 ||:  .|||_|;|_|;|_|;|_|;|_|;||:.  |                           ";
gotoxy(3,15);
cout<<"                 ||: . || .     . .   .  ,   ||:   |       "<<char(92)<<",/                 ";
gotoxy(3,16);
cout<<"                 ||:   ||:  ,  _______   .   ||: , |            /`"<<char(92)<<"            ";
gotoxy(3,17);
cout<<"                 ||:   || .   /+++++++"<<char(92)<<"    . ||:   |                           ";
gotoxy(3,18);
cout<<"                 ||:   ||.    |+++++++| .    ||: . |                           ";
gotoxy(3,19);
cout<<"     ____--`~----'--~~__|.    |+++++__|----~    ~`---,              ___        ";
gotoxy(3,20);
cout<<"-~--~                   ~---__|,--~'                  ~~----_____-~'   `~----~~";
}
void pintarMarcoJugar(){
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
    for(int i = 91; i >= 0; i--)
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
    gotoxy(92,21);
    cout<<"\274";
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
void pintarMenu(int p){
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
//FUNCION PRINCIPAL DEL PROGRAMA
int inicio(){
    int puntero = 0;
    //bool game=true;
    while(true)
    {
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        pintarMarco();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        pintarTitulo();
        pintarCastillo();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        pintarMenu(puntero);
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                puntero -= 1;
                PlaySound(TEXT("sounds/ui_town_button_embark.wav"),NULL,SND_ASYNC);
                if (puntero == -1)
                {
                    puntero = 3;
                }
                break;
            }
            if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                puntero += 1;
                PlaySound(TEXT("sounds/ui_town_button_embark.wav"),NULL,SND_ASYNC);
                if (puntero == 4)
                {
                    puntero = 0;
                }
                break;
            }
            if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                PlaySound(TEXT("sounds/ui_shr_button_click.wav"),NULL,SND_ASYNC);
                switch (puntero)
                {
                    case 0:
                        system("cls");
                        PlaySound(TEXT("sounds/gen_title_startgame.wav"),NULL,SND_ASYNC);
                        pintarMarcoJugar();
                        pintarEscenario();
                        /*while (true)
                        {
                            //pintarEscenario(game);
                            if (GetAsyncKeyState(VK_RETURN) != 0)
                            {
                                //break;
                            }
                            if (GetAsyncKeyState(VK_UP) != 0){}
                            if (GetAsyncKeyState(VK_DOWN) != 0){}
                        }*/
                        //system("cls");
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
                        cout << "-> Utilizaras teclas para interactuar con el juego, lee las indicaciones";
                        gotoxy(2,13);
                        cout << "-> Para desplazarte por el escenario se usa 'A' (Left) y 'D' (Right)";
                        gotoxy(2,14);
                        cout << "-Presiona enter para regresar-";
                        Sleep(1000);
                        while (true){
                            if (GetAsyncKeyState(VK_RETURN) != 0)
                            {
                                PlaySound(TEXT("sounds/ui_shr_unpause.wav"),NULL,SND_ASYNC);
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
                                PlaySound(TEXT("sounds/ui_shr_unpause.wav"),NULL,SND_ASYNC);
                                break;
                            }
                            if (GetAsyncKeyState(VK_UP) != 0){}
                            if (GetAsyncKeyState(VK_DOWN) != 0){}
                        }
                        system("cls");
                        break;
                    case 3:
                        system("cls");
                        PlaySound(TEXT("sounds/ui_shr_window_popup.wav"),NULL,SND_ASYNC);
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
