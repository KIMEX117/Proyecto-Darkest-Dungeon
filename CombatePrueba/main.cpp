#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "Enemigo.h"
#include "Heroe.h"
#include "Ataque.h"

using namespace std;

/*Creacion de objetos*/
void crearCrusader(Heroe*);
void crearHighwayman(Heroe*);
void crearVestal(Heroe*);
void crearDoctor(Heroe*);
void crearSoldier(int,Enemigo*);
/*-------------------*/
/*Escribir habilidades*/
void crusaderSkills(int,Heroe*,Enemigo*);
void highwaymanSkills(int,Heroe*,Enemigo*);
void vestalSkills(int,Heroe*,Enemigo*);
void doctorSkills(int,Heroe*,Enemigo*);
void soldierSkills(int,Heroe*,Enemigo*);
/*--------------------*/
/*Utilidad del programa*/
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
/*---------------------*/
int main(){
    /*Este main simulara una pelea (Estado: incompleto / funcional)*/
    Enemigo enemigos[4];
    Heroe heroes[4];
    int heroesvivos = 4;
    int enemigosvivos = 4;
    /*Crear a prueba crusader*/
    crearCrusader(heroes);
    /*Crear a prueba highwayman*/
    crearHighwayman(heroes);
    /*Crear a prueba vestal*/
    crearVestal(heroes);
    /*Crear a prueba plague doctor*/
    crearDoctor(heroes);
    /*Crear a prueba 4 soldados esqueleto*/
    for(int i=0;i<4;i++){
        crearSoldier(i,enemigos);
    }
    while(enemigosvivos>0&&heroesvivos>0){
        enemigosvivos = 4;
        heroesvivos = 4;
        int turno = 0;
        if(heroes[turno].getHealth()>0){
            if(turno==0&&enemigosvivos>0){
                crusaderSkills(turno,heroes,enemigos);
                turno++;
                Sleep(3500);
                system("cls");
            }
        }
        if(heroes[turno].getHealth()>0){
            if(turno==1&&enemigosvivos>0){
                highwaymanSkills(turno,heroes,enemigos);
                turno++;
                Sleep(3500);
                system("cls");
            }
        }
        if(heroes[turno].getHealth()>0){
            if(turno==2&&enemigosvivos>0){
                vestalSkills(turno,heroes,enemigos);
                turno++;
                Sleep(3500);
                system("cls");
            }
        }
        if(heroes[turno].getHealth()>0){
            if(turno==3&&enemigosvivos>0){
                doctorSkills(turno,heroes,enemigos);
                turno++;
                Sleep(3500);
                system("cls");
            }
        }
        for(int i=0;i<4;i++){
            if(enemigos[i].getHealth()>0){
                soldierSkills(i,heroes,enemigos);
                Sleep(3500);
                system("cls");
            }
        }
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
    return 0;
}
void crearCrusader(Heroe heroes[4]){
    heroes[0].setName("Crusader");
    heroes[0].setMaxHealth(33);
    heroes[0].setHealth(33);
    heroes[0].setAccuracy(0);
    heroes[0].setDamage(9);
    heroes[0].setCritic(0);
    heroes[0].setDodge(5);
    heroes[0].setProtection(10);
    heroes[0].setPosition(0);
    heroes[0].setChanceBleed(30);
    heroes[0].setChancePoison(30);
    heroes[0].setChanceStun(40);
    heroes[0].setChanceDie(70);
    heroes[0].setBleed(0);
    heroes[0].setPoison(0);
    heroes[0].setStun(0);
}
void crearHighwayman(Heroe heroes[4]){
    heroes[1].setName("Highwayman");
    heroes[1].setMaxHealth(23);
    heroes[1].setHealth(23);
    heroes[1].setAccuracy(0);
    heroes[1].setDamage(8);
    heroes[1].setCritic(0);
    heroes[1].setDodge(10);
    heroes[1].setProtection(0);
    heroes[1].setPosition(1);
    heroes[1].setChanceBleed(30);
    heroes[1].setChancePoison(30);
    heroes[1].setChanceStun(30);
    heroes[1].setChanceDie(70);
    heroes[1].setBleed(0);
    heroes[1].setPoison(0);
    heroes[1].setStun(0);
}
void crearVestal(Heroe heroes[4]){
    heroes[2].setName("Vestal");
    heroes[2].setMaxHealth(24);
    heroes[2].setHealth(24);
    heroes[2].setAccuracy(0);
    heroes[2].setDamage(6);
    heroes[2].setCritic(0);
    heroes[2].setDodge(0);
    heroes[2].setProtection(0);
    heroes[2].setPosition(2);
    heroes[2].setChanceBleed(40);
    heroes[2].setChancePoison(30);
    heroes[2].setChanceStun(30);
    heroes[2].setChanceDie(70);
    heroes[2].setBleed(0);
    heroes[2].setPoison(0);
    heroes[2].setStun(0);
}
void crearDoctor(Heroe heroes[4]){
    heroes[3].setName("Plague Doctor");
    heroes[3].setMaxHealth(22);
    heroes[3].setHealth(22);
    heroes[3].setAccuracy(0);
    heroes[3].setDamage(5);
    heroes[3].setCritic(0);
    heroes[3].setDodge(10);
    heroes[3].setProtection(0);
    heroes[3].setPosition(3);
    heroes[3].setChanceBleed(20);
    heroes[3].setChancePoison(60);
    heroes[3].setChanceStun(20);
    heroes[3].setChanceDie(70);
    heroes[3].setBleed(0);
    heroes[3].setPoison(0);
    heroes[3].setStun(0);
}
void crearSoldier(int creacion, Enemigo enemigos[4]){
    enemigos[creacion].setName("Soldier");
    enemigos[creacion].setHealth(35);
    enemigos[creacion].setAccuracy(0);
    enemigos[creacion].setDamage(5);
    enemigos[creacion].setCritic(0);
    enemigos[creacion].setDodge(10);
    enemigos[creacion].setProtection(15);
    enemigos[creacion].setPosition(creacion);
    enemigos[creacion].setChanceBleed(0);
    enemigos[creacion].setChancePoison(80);
    enemigos[creacion].setChanceStun(75);
    enemigos[creacion].setBleed(0);
    enemigos[creacion].setPoison(0);
    enemigos[creacion].setStun(0);
}
void crusaderSkills(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int habilidad;
    bool accion = false;
    bool mostrar = false;
    cout << "Turno: " << turno << endl;
    cout << "Heroe: " << heroes[turno].getName() << endl;
    cout << "Salud: " << heroes[turno].getHealth() << " / " << heroes[turno].getMaxHealth() << endl;
    cout << "DMG: " << heroes[turno].getDamage() << endl;
    cout << "Esquivo: " << heroes[turno].getDodge() << endl;
    cout << "Posicion: " << heroes[turno].getPosition() << endl;
    cout << "Ingrese la habilidad a usar:" << endl;
    do{
        if(heroes[turno].getPosition()<2){
            for(int i=0;i<2;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                cout << "1.- Smite" << endl;
                cout << "2.- Stunning Blow" << endl;
                cout << "3.- Zealous Accusation" << endl;
                mostrar = false;
            }
        }
        for(int i=0;i<4;i++){
            if(heroes[i].getHealth()<heroes[i].getMaxHealth()){
                mostrar = true;
            }
        }
        if(mostrar==true){
            cout << "4.- Battle Heal" << endl;
            mostrar = false;
        }
        cout << "5.- Cambiar posicion" << endl;
        cout << "6.- Saltar turno" << endl;
        cout << "Opcion: ";
        cin >> habilidad;
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
    cout << "Turno: " << turno << endl;
    cout << "Heroe: " << heroes[turno].getName() << endl;
    cout << "Salud: " << heroes[turno].getHealth() << " / " << heroes[turno].getMaxHealth() << endl;
    cout << "DMG: " << heroes[turno].getDamage() << endl;
    cout << "Esquivo: " << heroes[turno].getDodge() << endl;
    cout << "Posicion: " << heroes[turno].getPosition() << endl;
    cout << "Ingrese la habilidad a usar:" << endl;
    do{
        if(heroes[turno].getPosition()<3){
            for(int i=0;i<2;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                cout << "1.- Slice" << endl;
                cout << "2.- Open Vein" << endl;
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
                cout << "3.- Pistol shot" << endl;
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
                cout << "4.- Grapeshot" << endl;
                mostrar = false;
            }
        }
        cout << "5.- Cambiar posicion" << endl;
        cout << "6.- Saltar turno" << endl;
        cout << "Opcion: ";
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
    cout << "Turno: " << turno << endl;
    cout << "Heroe: " << heroes[turno].getName() << endl;
    cout << "Salud: " << heroes[turno].getHealth() << " / " << heroes[turno].getMaxHealth() << endl;
    cout << "DMG: " << heroes[turno].getDamage() << endl;
    cout << "Esquivo: " << heroes[turno].getDodge() << endl;
    cout << "Posicion: " << heroes[turno].getPosition() << endl;
    cout << "Ingrese la habilidad a usar:" << endl;
    do{
        if(heroes[turno].getPosition()<2){
            for(int i=0;i<2;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                cout << "1.- Mace Bash" << endl;
                mostrar = false;
            }
        }
        if(heroes[turno].getPosition()>0){
            for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                cout << "2.- Dazzling Light" << endl;
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
                cout << "3.- Divine Grace" << endl;
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
                cout << "4.- Divine Comfort" << endl;
                mostrar = false;
            }
        }
        cout << "5.- Cambiar posicion" << endl;
        cout << "6.- Saltar turno" << endl;
        cout << "Opcion: ";
        cin >> habilidad;
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
            Ataque().VestalSkill_MaceBash(turno,heroes,enemigos);
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
    cout << "Turno: " << turno << endl;
    cout << "Heroe: " << heroes[turno].getName() << endl;
    cout << "Salud: " << heroes[turno].getHealth() << " / " << heroes[turno].getMaxHealth() << endl;
    cout << "DMG: " << heroes[turno].getDamage() << endl;
    cout << "Esquivo: " << heroes[turno].getDodge() << endl;
    cout << "Posicion: " << heroes[turno].getPosition() << endl;
    cout << "Ingrese la habilidad a usar:" << endl;
    do{
        if(heroes[turno].getPosition()>0){
            for(int i=0;i<2;i++){
                if(enemigos[i].getHealth()>0){
                    mostrar = true;
                }
            }
            if(mostrar==true){
                cout << "1.- Noxious Blast" << endl;
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
                cout << "2.- Plague Grenade" << endl;
                cout << "3.- Blinding Gas" << endl;
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
                cout << "4.- Battlefield Medicine" << endl;
                mostrar = false;
            }
        }
        cout << "5.- Cambiar posicion" << endl;
        cout << "6.- Saltar turno" << endl;
        cout << "Opcion: ";
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
void soldierSkills(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int habilidad;
    cout << "Turno: " << turno << endl;
    cout << "Heroe: " << enemigos[turno].getName() << endl;
    cout << "Posicion: " << enemigos[turno].getPosition() << endl;
    if(enemigos[turno].getPosition()!=3){
        habilidad = 1;
    }else{
        habilidad = 2;
    }
    switch(habilidad){
        case 1:
            Ataque().SoldierSkill_GraveyardSlash(turno,heroes,enemigos);
            break;
        case 2:
            Ataque().SoldierSkill_GraveyardStumble(turno,heroes,enemigos);
            break;
    }
}
