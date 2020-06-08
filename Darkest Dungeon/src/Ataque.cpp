#include "Ataque.h"
#include "Heroe.h"
#include "Enemigo.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

Ataque::Ataque(){}
/*Habilidades de combate compartidas*/
void Ataque::SharedHeroSkill_Move(int turno, Heroe heroes[4]){
    int space;
    int realizado = 0;
    /*-Variables de cambio*/
    int hpMax;
    int hp;
    int acc;
    int dmg;
    int crit;
    int dodge;
    int prot;
    int pos;
    /*Variables de cambio-*/
    if(heroes[turno].getPosition()==0 && realizado==0){
        do{
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout<<"CAMBIO DE POSICION         (Ingresar # de posicion)"<<endl;
            gotoxyAtaque(41,23);cout << "Espacios disponibles:" << endl;
            for(int i=heroes[turno].getPosition();i<=(heroes[turno].getPosition()+1);i++){
                if(i!=heroes[turno].getPosition()){
                    gotoxyAtaque(41,24+i);cout << "Posicion " << i << endl;
                }
            }
            gotoxyAtaque(70,24);cout << "Posicion: ";
            cin >> space;
        }while(space==heroes[turno].getPosition()||space>1||space<0);
        heroes[space].setPosition(heroes[turno].getPosition());
        heroes[heroes[turno].getPosition()].setPosition(space);
        //Guardar variables del heroe objetivo a cambiar posicion
        hpMax = heroes[space].getMaxHealth();
        hp = heroes[space].getHealth();
        acc = heroes[space].getAccuracy();
        dmg = heroes[space].getDamage();
        crit = heroes[space].getCritic();
        dodge = heroes[space].getDodge();
        prot = heroes[space].getProtection();
        pos = heroes[space].getPosition();
        //Cambiar los datos del heroe a la posicion deseada
        heroes[space].setMaxHealth(heroes[turno].getMaxHealth());
        heroes[space].setHealth(heroes[turno].getHealth());
        heroes[space].setAccuracy(heroes[turno].getAccuracy());
        heroes[space].setDamage(heroes[turno].getDamage());
        heroes[space].setCritic(heroes[turno].getCritic());
        heroes[space].setDodge(heroes[turno].getDodge());
        heroes[space].setProtection(heroes[turno].getProtection());
        heroes[space].setPosition(heroes[turno].getPosition());
        //Cambiar los datos del heroe que fue reemplazado a la posicion del que realizo el cambio
        heroes[turno].setMaxHealth(hpMax);
        heroes[turno].setHealth(hp);
        heroes[turno].setAccuracy(acc);
        heroes[turno].setDamage(dmg);
        heroes[turno].setCritic(crit);
        heroes[turno].setDodge(dodge);
        heroes[turno].setProtection(prot);
        heroes[turno].setPosition(pos);
        realizado = 1;
    }
    if(heroes[turno].getPosition()>0&&heroes[turno].getPosition()<3&&realizado==0){
        do{
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout<<"CAMBIO DE POSICION         (Ingresar # de posicion)"<<endl;
            gotoxyAtaque(41,23);cout << "Espacios disponibles:" << endl;
            for(int i=heroes[turno].getPosition()-1;i<=(heroes[turno].getPosition()+1);i++){
                if(i!=heroes[turno].getPosition()){
                    gotoxyAtaque(41,24+i);cout << "Posicion " << i << endl;
                }
            }
            gotoxyAtaque(70,24);cout << "Posicion: ";
            cin >> space;
        }while(space==heroes[turno].getPosition()||space>3||space>heroes[turno].getPosition()+1||space<heroes[turno].getPosition()-1);
        heroes[space].setPosition(heroes[turno].getPosition());
        heroes[heroes[turno].getPosition()].setPosition(space);
        //Guardar variables del heroe objetivo a cambiar posicion
        hpMax = heroes[space].getMaxHealth();
        hp = heroes[space].getHealth();
        acc = heroes[space].getAccuracy();
        dmg = heroes[space].getDamage();
        crit = heroes[space].getCritic();
        dodge = heroes[space].getDodge();
        prot = heroes[space].getProtection();
        pos = heroes[space].getPosition();
        //Cambiar los datos del heroe a la posicion deseada
        heroes[space].setMaxHealth(heroes[turno].getMaxHealth());
        heroes[space].setHealth(heroes[turno].getHealth());
        heroes[space].setAccuracy(heroes[turno].getAccuracy());
        heroes[space].setDamage(heroes[turno].getDamage());
        heroes[space].setCritic(heroes[turno].getCritic());
        heroes[space].setDodge(heroes[turno].getDodge());
        heroes[space].setProtection(heroes[turno].getProtection());
        heroes[space].setPosition(heroes[turno].getPosition());
        //Cambiar los datos del heroe que fue reemplazado a la posicion del que realizo el cambio
        heroes[turno].setMaxHealth(hpMax);
        heroes[turno].setHealth(hp);
        heroes[turno].setAccuracy(acc);
        heroes[turno].setDamage(dmg);
        heroes[turno].setCritic(crit);
        heroes[turno].setDodge(dodge);
        heroes[turno].setProtection(prot);
        heroes[turno].setPosition(pos);
        realizado = 1;
    }
    if(heroes[turno].getPosition()==3&&realizado==0){
        do{
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout<<"CAMBIO DE POSICION         (Ingresar # de posicion)"<<endl;
            gotoxyAtaque(41,23);cout << "Espacios disponibles:" << endl;
            for(int i=(heroes[turno].getPosition()-1);i<=heroes[turno].getPosition();i++){
                if(i!=heroes[turno].getPosition()){
                    gotoxyAtaque(41,24+i);cout << "Posicion " << i << endl;
                }
            }
            gotoxyAtaque(70,24);cout << "Posicion: ";
            cin >> space;
        }while(space==heroes[turno].getPosition()||space>3||space<heroes[turno].getPosition()-1);
        heroes[space].setPosition(heroes[turno].getPosition());
        heroes[heroes[turno].getPosition()].setPosition(space);
        //Guardar variables del heroe objetivo a cambiar posicion
        hpMax = heroes[space].getMaxHealth();
        hp = heroes[space].getHealth();
        acc = heroes[space].getAccuracy();
        dmg = heroes[space].getDamage();
        crit = heroes[space].getCritic();
        dodge = heroes[space].getDodge();
        prot = heroes[space].getProtection();
        pos = heroes[space].getPosition();
        //Cambiar los datos del heroe a la posicion deseada
        heroes[space].setMaxHealth(heroes[turno].getMaxHealth());
        heroes[space].setHealth(heroes[turno].getHealth());
        heroes[space].setAccuracy(heroes[turno].getAccuracy());
        heroes[space].setDamage(heroes[turno].getDamage());
        heroes[space].setCritic(heroes[turno].getCritic());
        heroes[space].setDodge(heroes[turno].getDodge());
        heroes[space].setProtection(heroes[turno].getProtection());
        heroes[space].setPosition(heroes[turno].getPosition());
        //Cambiar los datos del heroe que fue reemplazado a la posicion del que realizo el cambio
        heroes[turno].setMaxHealth(hpMax);
        heroes[turno].setHealth(hp);
        heroes[turno].setAccuracy(acc);
        heroes[turno].setDamage(dmg);
        heroes[turno].setCritic(crit);
        heroes[turno].setDodge(dodge);
        heroes[turno].setProtection(prot);
        heroes[turno].setPosition(pos);
        realizado = 1;
    }
    //cout << "Posicion actual del heroe: " << heroes[1].getPosition() << endl;
}
//FUNCION GOTOXY PARA PODER USARLA DENTRO DE LA CLASE
void Ataque::gotoxyAtaque(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwpos;
    dwpos.X = x;
    dwpos.Y = y;
    SetConsoleCursorPosition(hcon, dwpos);
}
//LIMPIAR RECUADRO DE HABILIDADES EN COMBATE
void Ataque::limpiarHabilidades(){
    for(int i=22;i<29;i++){
        for(int j=41;j<92;j++){
            gotoxyAtaque(j,i);
            cout<<" ";
        }
        cout<<endl;
    }
}
/*Habilidades de cruzado*/
void Ataque::CrusaderSkill_Smite(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 1;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
    float protect;
    int damageReceive;
    //bool pos_0=false, pos_1=false, pos_2=false, pos_3=false;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()<2){
            do{
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout << "Objetivos disponibles:     (Ingresar # de objetivo)" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                gotoxyAtaque(41,24+i);cout << i << ".- " << enemigos[i].getName() << endl;
                    /*switch(i){
                        case 0: pos_0=true; break;
                        case 1: pos_1=true; break;
                        case 2: pos_2=true; break;
                        case 3: pos_3=true; break;
                    }*/
                }
            }
            gotoxyAtaque(70,24);cout << "Objetivo: ";
            cin >> target;
            /*if(pos_0==true){if (GetAsyncKeyState(0x31)){target=0;}}
            if(pos_1==true){if (GetAsyncKeyState(0x32)){target=1;}}
            if(pos_2==true){if (GetAsyncKeyState(0x33)){target=2;}}
            if(pos_3==true){if (GetAsyncKeyState(0x34)){target=3;}}*/
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(9);
            heroes[turno].setAccuracy(87);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-enemigos[target].getProtection())*0.01);
                damageReceive = (heroes[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_al_cru_smite.wav"),NULL,SND_ASYNC);
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_al_cru_smite.wav"),NULL,SND_ASYNC);
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,25);cout << "El objetivo ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "Fallaste el ataque" << endl;
                PlaySound(TEXT("sounds/char_al_cru_smite_miss.wav"),NULL,SND_ASYNC);
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
//Inflige aturdimiento
void Ataque::CrusaderSkill_StunningBlow(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 0.8;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()<2){
            do{
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout << "Objetivos disponibles:     (Ingresar # de objetivo)" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                gotoxyAtaque(41,24+i);cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            gotoxyAtaque(70,24);cout << "Objetivo: ";
            cin >> target;
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(37);
            heroes[turno].setAccuracy(70);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-enemigos[target].getProtection())*0.01);
                damageReceive = (heroes[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_al_cru_stunningblow.wav"),NULL,SND_ASYNC);
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_al_cru_stunningblow.wav"),NULL,SND_ASYNC);
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,25);cout << "El objetivo ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "Fallaste un ataque" << endl;
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::CrusaderSkill_ZealousAccusation(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int random;
    int target;
    float skillDamage = 0.65;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()<2){
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
            heroes[turno].setCritic(1);
            heroes[turno].setAccuracy(85);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(enemigos[i].getHealth()>0){
                    if(hit<(heroes[turno].getAccuracy()-enemigos[i].getDodge())){
                        hitcritical = rand()%100;
                        protect = ((100-enemigos[i].getProtection())*0.01);
                        damageReceive = (heroes[turno].getDamage()*skillDamage)*protect;
                        if(hitcritical<heroes[turno].getCritic()){
                            enemigos[i].setHealth(enemigos[i].getHealth()-(damageReceive*1.5));
                            gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                            PlaySound(TEXT("sounds/char_al_cru_zealousacc.wav"),NULL,SND_ASYNC);
                        }else{
                            enemigos[i].setHealth(enemigos[i].getHealth()-damageReceive);
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                            PlaySound(TEXT("sounds/char_al_cru_zealousacc.wav"),NULL,SND_ASYNC);
                        }
                        if(enemigos[i].getHealth()<=0){
                            gotoxyAtaque(41,25);cout << "Un objetivo ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,26+1);cout << "Vida del enemigo impactado " << i << ": " << enemigos[i].getHealth() << endl;
                        }
                    }else{
                        gotoxyAtaque(41,26);cout << "Fallaste un ataque" << endl;
                    }
                }
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::CrusaderSkill_BattleHeal(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hitcritical;
    int target;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    int curacion = 3;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0&&heroes[i].getHealth()==heroes[i].getMaxHealth()){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()>=0&&heroes[turno].getPosition()<=3){
            do{
                limpiarHabilidades();
                gotoxyAtaque(41,22);cout << "Objetivos disponibles:     (Ingresar # de objetivo)" << endl;
                for(int i=rangeMin;i<=rangeMax;i++){
                    if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                    gotoxyAtaque(41,24+i);cout << i << ".- " << heroes[i].getName() << endl;
                    }
                }
                gotoxyAtaque(70,24);cout << "Objetivo: ";
                cin >> target;
                limpiarHabilidades();
                gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
            }while((target<rangeMin||target>rangeMax)||heroes[target].getHealth()<=0||heroes[target].getHealth()==heroes[target].getMaxHealth());
            heroes[turno].setCritic(12);
            hitcritical = rand()%100;
            if(hitcritical<heroes[turno].getCritic()){
                heroes[target].setHealth(heroes[target].getHealth()+(curacion*1.5));
                gotoxyAtaque(41,23);cout << "El heroe ha sido sanado perfectamente!" << endl;
                gotoxyAtaque(41,24);cout << "Sanacion de la habilidad: " << (curacion*1.5) << endl;
                PlaySound(TEXT("sounds/char_al_cru_battleheal.wav"),NULL,SND_ASYNC);
            }else{
                heroes[target].setHealth(heroes[target].getHealth()+curacion);
                gotoxyAtaque(41,24);cout << "Sanacion de la habilidad: " << curacion << endl;
                PlaySound(TEXT("sounds/char_al_cru_battleheal.wav"),NULL,SND_ASYNC);
            }
            if(heroes[target].getHealth()>heroes[target].getMaxHealth()){
                heroes[target].setHealth(heroes[target].getMaxHealth());
            }
            gotoxyAtaque(41,26);cout << "Vida del heroe asistido " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
        }else{
            gotoxyAtaque(41,24);cout << "No es posible desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
/*Habilidades de pistolero*/
void Ataque::HighwaymanSkill_Slice(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 1.15;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()<3){
            do{
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout << "Objetivos disponibles:     (Ingresar # de objetivo)" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                gotoxyAtaque(41,24+i);cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            gotoxyAtaque(70,24);cout << "Objetivo: ";
            cin >> target;
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(10);
            heroes[turno].setAccuracy(87);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-enemigos[target].getProtection())*0.01);
                damageReceive = (heroes[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_al_hwy_wickedslice.wav"),NULL,SND_ASYNC);
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_al_hwy_wickedslice.wav"),NULL,SND_ASYNC);
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,25);cout << "El objetivo ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "Fallaste el ataque" << endl;
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::HighwaymanSkill_OpenVein(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 0.85;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()<3){
            do{
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout << "Objetivos disponibles:     (Ingresar # de objetivo)" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                gotoxyAtaque(41,24+i);cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            gotoxyAtaque(70,24);cout << "Objetivo: ";
            cin >> target;
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(36);
            heroes[turno].setAccuracy(70);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-enemigos[target].getProtection())*0.01);
                damageReceive = (heroes[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_al_hwy_openedvein.wav"),NULL,SND_ASYNC);
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_al_hwy_openedvein.wav"),NULL,SND_ASYNC);
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,25);cout << "El objetivo ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "Fallaste el ataque" << endl;
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::HighwaymanSkill_PistolShot(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 0.9;
    int rangeMin = 1;
    int rangeMax = 3;
    int objetivos = 3;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()>0){
            do{
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout << "Objetivos disponibles:     (Ingresar # de objetivo)" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                gotoxyAtaque(41,24+i);cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            gotoxyAtaque(70,24);cout << "Objetivo: ";
            cin >> target;
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(17);
            heroes[turno].setAccuracy(85);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-enemigos[target].getProtection())*0.01);
                damageReceive = (heroes[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_al_hwy_pistolshot.wav"),NULL,SND_ASYNC);
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_al_hwy_pistolshot.wav"),NULL,SND_ASYNC);
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,26);cout << "El objetivo ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "Fallaste el ataque" << endl;
                PlaySound(TEXT("sounds/char_al_hwy_pistolshot_miss.wav"),NULL,SND_ASYNC);
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::HighwaymanSkill_Grapeshot(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int random;
    int target;
    float skillDamage = 0.55;
    int rangeMin = 0;
    int rangeMax = 2;
    int objetivos = 3;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(heroes[turno].getPosition()>0&&heroes[turno].getPosition()<3){
            heroes[turno].setCritic(1);
            heroes[turno].setAccuracy(75);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(enemigos[i].getHealth()>0){
                    if(hit<(heroes[turno].getAccuracy()-enemigos[i].getDodge())){
                        hitcritical = rand()%100;
                        protect = ((100-enemigos[i].getProtection())*0.01);
                        damageReceive = (heroes[turno].getDamage()*skillDamage)*protect;
                        if(hitcritical<heroes[turno].getCritic()){
                            enemigos[i].setHealth(enemigos[i].getHealth()-(damageReceive*1.5));
                            gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                            PlaySound(TEXT("sounds/char_al_hwy_grapeshot.wav"),NULL,SND_ASYNC);
                        }else{
                            enemigos[i].setHealth(enemigos[i].getHealth()-damageReceive);
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                            PlaySound(TEXT("sounds/char_al_hwy_grapeshot.wav"),NULL,SND_ASYNC);
                        }
                        if(enemigos[i].getHealth()<=0){
                            gotoxyAtaque(41,25);cout << "Un objetivo ha sido derribado" << endl;
                        }
                    }else{
                        gotoxyAtaque(41,26);gotoxyAtaque(41,24);cout << "Fallaste un ataque" << endl;
                        PlaySound(TEXT("sounds/char_al_hwy_grapeshot_miss.wav"),NULL,SND_ASYNC);
                    }
                }
            }
            for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    gotoxyAtaque(41,25+i);cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                }
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
/*Habilidades de vestal*/
void Ataque::VestalSkill_Judgement(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 0.9;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()>=0&&heroes[turno].getPosition()<=3){
            do{
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout << "Objetivos disponibles:     (Ingresar # de objetivo)" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                gotoxyAtaque(41,24+i);cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            gotoxyAtaque(70,24);cout << "Objetivo: ";
            cin >> target;
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(5);
            heroes[turno].setAccuracy(87);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-enemigos[target].getProtection())*0.01);
                damageReceive = (heroes[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_al_vst_judgement.wav"),NULL,SND_ASYNC);
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_al_vst_judgement.wav"),NULL,SND_ASYNC);
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,25);cout << "El objetivo ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "Fallaste el ataque" << endl;
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::VestalSkill_DazzlingLight(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 0.85;
    int rangeMin = 0;
    int rangeMax = 2;
    int objetivos = 3;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()>0){
            do{
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout << "Objetivos disponibles:     (Ingresar # de objetivo)" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                gotoxyAtaque(41,24+i);cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            gotoxyAtaque(70,24);cout << "Objetivo: ";
            cin >> target;
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(36);
            heroes[turno].setAccuracy(70);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-enemigos[target].getProtection())*0.01);
                damageReceive = (heroes[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_al_vst_dazzlinglight.wav"),NULL,SND_ASYNC);
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_al_vst_dazzlinglight.wav"),NULL,SND_ASYNC);
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,25);cout << "El objetivo ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "Fallaste el ataque" << endl;
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::VestalSkill_DivineGrace(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hitcritical;
    int target;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    int curacion = 5;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0&&heroes[i].getHealth()==heroes[i].getMaxHealth()){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()>1){
            do{
                limpiarHabilidades();
                gotoxyAtaque(41,22);cout << "Objetivos disponibles:     (Ingresar # de objetivo)" << endl;
                for(int i=rangeMin;i<=rangeMax;i++){
                    if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                    gotoxyAtaque(41,24+i);cout << i << ".- " << heroes[i].getName() << endl;
                    }
                }
                gotoxyAtaque(70,24);cout << "Objetivo: ";
                cin >> target;
                limpiarHabilidades();
                gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
            }while((target<rangeMin||target>rangeMax)||heroes[target].getHealth()<=0||heroes[target].getHealth()==heroes[target].getMaxHealth());
            heroes[turno].setCritic(12);
            hitcritical = rand()%100;
            if(hitcritical<heroes[turno].getCritic()){
                heroes[target].setHealth(heroes[target].getHealth()+(curacion*1.5));
                gotoxyAtaque(41,23);cout << "El heroe ha sido sanado perfectamente!" << endl;
                gotoxyAtaque(41,24);cout << "Sanacion de la habilidad: " << (curacion*1.5) << endl;
                PlaySound(TEXT("sounds/char_al_vst_divinegrace.wav"),NULL,SND_ASYNC);
            }else{
                heroes[target].setHealth(heroes[target].getHealth()+curacion);
                gotoxyAtaque(41,24);cout << "Sanacion de la habilidad: " << curacion << endl;
                PlaySound(TEXT("sounds/char_al_vst_divinegrace.wav"),NULL,SND_ASYNC);
            }
            if(heroes[target].getHealth()>heroes[target].getMaxHealth()){
                heroes[target].setHealth(heroes[target].getMaxHealth());
            }
            gotoxyAtaque(41,26);cout << "Vida del heroe asistido " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
        }else{
            gotoxyAtaque(41,24);cout << "No es posible desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::VestalSkill_DivineComfort(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int random;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    int curacion = 3;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0&&heroes[i].getHealth()==heroes[i].getMaxHealth()){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(heroes[turno].getPosition()>0){
            heroes[turno].setCritic(1);
            for(int i=rangeMin;i<=rangeMax;i++){
                if(heroes[i].getHealth()>0){
                    hitcritical = rand()%100;
                    if(hitcritical<heroes[turno].getCritic()){
                        heroes[i].setHealth(heroes[i].getHealth()+(curacion*1.5));
                        gotoxyAtaque(41,24);cout << "Sanacion de la habilidad: " << (curacion*1.5) << endl;
                        PlaySound(TEXT("sounds/char_al_vst_divinegrace.wav"),NULL,SND_ASYNC);
                    }else{
                        heroes[i].setHealth(heroes[i].getHealth()+curacion);
                        gotoxyAtaque(41,24);cout << "Sanacion de la habilidad: " << curacion << endl;
                        PlaySound(TEXT("sounds/char_al_vst_divinegrace.wav"),NULL,SND_ASYNC);
                    }
                    if(heroes[i].getHealth()>heroes[i].getMaxHealth()){
                        heroes[i].setHealth(heroes[i].getMaxHealth());
                    }
                    gotoxyAtaque(41,25+i);cout << "Vida del heroe asistido " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                }
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }

}
/*Habilidades de doctor*/
void Ataque::PlagueDoctorSkill_NoxiousBlast(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 1.25;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()>0){
            do{
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout << "Objetivos disponibles:     (Ingresar # de objetivo)" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                gotoxyAtaque(41,24+i);cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            gotoxyAtaque(70,24);cout << "Objetivo: ";
            cin >> target;
            limpiarHabilidades();
            gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(9);
            heroes[turno].setAccuracy(95);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-enemigos[target].getProtection())*0.01);
                damageReceive = (heroes[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_al_plg_noxiousblast.wav"),NULL,SND_ASYNC);
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_al_plg_noxiousblast.wav"),NULL,SND_ASYNC);
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,25);cout << "Un objetivo ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "Fallaste el ataque" << endl;
                PlaySound(TEXT("sounds/char_al_plg_noxiousblast_miss.wav"),NULL,SND_ASYNC);
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::PlagueDoctorSkill_PlagueGrenade(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int random;
    int target;
    float skillDamage = 0.85;
    int rangeMin = 2;
    int rangeMax = 3;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(heroes[turno].getPosition()>1){
            heroes[turno].setCritic(7);
            heroes[turno].setAccuracy(95);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(enemigos[i].getHealth()>0){
                    if(hit<(heroes[turno].getAccuracy()-enemigos[i].getDodge())){
                        hitcritical = rand()%100;
                        protect = ((100-enemigos[i].getProtection())*0.01);
                        damageReceive = (heroes[turno].getDamage()*skillDamage)*protect;
                        if(hitcritical<heroes[turno].getCritic()){
                            enemigos[i].setHealth(enemigos[i].getHealth()-(damageReceive*1.5));
                            gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                            PlaySound(TEXT("sounds/char_al_plg_plaguegrenade.wav"),NULL,SND_ASYNC);
                        }else{
                            enemigos[i].setHealth(enemigos[i].getHealth()-damageReceive);
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                            PlaySound(TEXT("sounds/char_al_plg_plaguegrenade.wav"),NULL,SND_ASYNC);
                        }
                        if(enemigos[i].getHealth()<=0){
                            gotoxyAtaque(41,25);cout << "Un objetivo ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,25+i);cout << "Vida del enemigo impactado " << i << ": " << enemigos[i].getHealth() << endl;
                        }
                    }else{
                        gotoxyAtaque(41,26);cout << "Fallaste un ataque" << endl;
                        PlaySound(TEXT("sounds/char_al_plg_plaguegrenade_miss.wav"),NULL,SND_ASYNC);
                    }
                }
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::PlagueDoctorSkill_BlindingGas(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int random;
    int target;
    float skillDamage = 0.55;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(heroes[turno].getPosition()>1){
            heroes[turno].setCritic(4);
            heroes[turno].setAccuracy(95);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(enemigos[i].getHealth()>0){
                    if(hit<(heroes[turno].getAccuracy()-enemigos[i].getDodge())){
                        hitcritical = rand()%100;
                        protect = ((100-enemigos[i].getProtection())*0.01);
                        damageReceive = (heroes[turno].getDamage()*skillDamage)*protect;
                        if(hitcritical<heroes[turno].getCritic()){
                            enemigos[i].setHealth(enemigos[i].getHealth()-(damageReceive*1.5));
                            gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                            PlaySound(TEXT("sounds/char_al_plg_blindinggas.wav"),NULL,SND_ASYNC);
                        }else{
                            enemigos[i].setHealth(enemigos[i].getHealth()-damageReceive);
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                            PlaySound(TEXT("sounds/char_al_plg_blindinggas.wav"),NULL,SND_ASYNC);
                        }
                        if(enemigos[i].getHealth()<=0){
                            gotoxyAtaque(41,25);cout << "Un objetivo ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,25+i);cout << "Vida del enemigo impactado " << i << ": " << enemigos[i].getHealth() << endl;
                        }
                    }else{
                        gotoxyAtaque(41,25);cout << "Fallaste un ataque" << endl;
                        PlaySound(TEXT("sounds/char_al_plg_blindinggas_miss.wav"),NULL,SND_ASYNC);
                    }
                }
            }
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::PlagueDoctorSkill_BattlefieldMedicine(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hitcritical;
    int target;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    int curacion = 5;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0&&heroes[i].getHealth()==heroes[i].getMaxHealth()){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()>1){
            do{
                limpiarHabilidades();
                gotoxyAtaque(41,22);cout << "Objetivos disponibles:     (Ingresar # de objetivo)" << endl;
                for(int i=rangeMin;i<=rangeMax;i++){
                    if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                    gotoxyAtaque(41,24+i);cout << i << ".- " << heroes[i].getName() << endl;
                    }
                }
                gotoxyAtaque(70,24);cout << "Objetivo: ";
                cin >> target;
                limpiarHabilidades();
                gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
            }while((target<rangeMin||target>rangeMax)||heroes[target].getHealth()<=0||heroes[target].getHealth()==heroes[target].getMaxHealth());
            heroes[turno].setCritic(12);
            hitcritical = rand()%100;
            if(hitcritical<heroes[turno].getCritic()){
                heroes[target].setHealth(heroes[target].getHealth()+(curacion*1.5));
                gotoxyAtaque(41,23);cout << "El heroe ha sido sanado perfectamente!" << endl;
                gotoxyAtaque(41,25);cout << "Sanacion de la habilidad: " << (curacion*1.5) << endl;
                PlaySound(TEXT("sounds/char_al_plg_battlemed.wav"),NULL,SND_ASYNC);
            }else{
                heroes[target].setHealth(heroes[target].getHealth()+curacion);
                gotoxyAtaque(41,24);cout << "Sanacion de la habilidad: " << curacion << endl;
                PlaySound(TEXT("sounds/char_al_plg_battlemed.wav"),NULL,SND_ASYNC);
            }
            if(heroes[target].getHealth()>heroes[target].getMaxHealth()){
                heroes[target].setHealth(heroes[target].getMaxHealth());
            }
            gotoxyAtaque(41,26);cout << "Vida del heroe asistido " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
        }else{
            gotoxyAtaque(41,24);cout << "No es posible desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
/*Habilidades de soldado esqueleto*/
void Ataque::SoldierSkill_GraveyardSlash(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 1;
    int rangeMin = 0;
    int rangeMax = 2;
    int objetivos = 3;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(enemigos[turno].getPosition()<3){
            hit = rand()%100;
            do{
                target = rand()%3;
            }while(heroes[target].getHealth()<=0);
            enemigos[turno].setCritic(11);
            enemigos[turno].setAccuracy(90);
            if(hit<(enemigos[turno].getAccuracy()-heroes[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-heroes[target].getProtection())*0.01);
                damageReceive = (enemigos[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_en_sklmi_swordstrike.wav"),NULL,SND_ASYNC);
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_en_sklmi_swordstrike.wav"),NULL,SND_ASYNC);
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
                PlaySound(TEXT("sounds/char_en_sklsp_spearthrust.wav"),NULL,SND_ASYNC);
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }
}
void Ataque::SoldierSkill_GraveyardStumble(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 0.5;
    int rangeMin = 3;
    int rangeMax = 3;
    int objetivos = 1;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(enemigos[turno].getPosition()==3){
            hit = rand()%100;
            target = 3;
            enemigos[turno].setCritic(1);
            enemigos[turno].setAccuracy(50);
            if(hit<(enemigos[turno].getAccuracy()-heroes[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-heroes[target].getProtection())*0.01);
                damageReceive = (enemigos[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_en_sklmi_swordstrike.wav"),NULL,SND_ASYNC);
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_en_sklmi_swordstrike.wav"),NULL,SND_ASYNC);
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth()<< endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
                PlaySound(TEXT("sounds/char_en_sklsp_spearthrust.wav"),NULL,SND_ASYNC);
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }
}
/*Habilidades de ballestero esqueleto*/
void Ataque::ArbalistSkill_Quarrel(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 1;
    int rangeMin = 1;
    int rangeMax = 3;
    int objetivos = 3;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(enemigos[turno].getPosition()>1){
            hit = rand()%100;
            do{
                target = rand()%4;
            }while(heroes[target].getHealth()<=0);
            enemigos[turno].setCritic(12);
            enemigos[turno].setAccuracy(83);
            if(hit<(enemigos[turno].getAccuracy()-heroes[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-heroes[target].getProtection())*0.01);
                damageReceive = (enemigos[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_en_sklar_crossbowshot.wav"),NULL,SND_ASYNC);
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_en_sklar_crossbowshot.wav"),NULL,SND_ASYNC);
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
                PlaySound(TEXT("sounds/char_en_sklar_crossbowshot_miss.wav"),NULL,SND_ASYNC);
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }
}
void Ataque::ArbalistSkill_BayonetJab(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 0.5;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(enemigos[turno].getPosition()<2){
            hit = rand()%100;
            do{
                target = rand()%2;
            }while(heroes[target].getHealth()<=0);
            enemigos[turno].setCritic(2);
            enemigos[turno].setAccuracy(73);
            if(hit<(enemigos[turno].getAccuracy()-heroes[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-heroes[target].getProtection())*0.01);
                damageReceive = (enemigos[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_en_sklar_bayonet_jab.wav"),NULL,SND_ASYNC);
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_en_sklar_bayonet_jab.wav"),NULL,SND_ASYNC);
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }
}
/*Habilidades de defensor esqueleto*/
void Ataque::DefenderSkill_AxeBlade(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 0.8;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(enemigos[turno].getPosition()<2){
            hit = rand()%100;
            do{
                target = rand()%2;
            }while(heroes[target].getHealth()<=0);
            enemigos[turno].setCritic(6);
            enemigos[turno].setAccuracy(73);
            if(hit<(enemigos[turno].getAccuracy()-heroes[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-heroes[target].getProtection())*0.01);
                damageReceive = (enemigos[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_en_sklde_axestrike.wav"),NULL,SND_ASYNC);
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_en_sklde_axestrike.wav"),NULL,SND_ASYNC);
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }
}
void Ataque::DefenderSkill_DeadWeight(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 0.6;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(enemigos[turno].getPosition()<2){
            hit = rand()%100;
            do{
                target = rand()%2;
            }while(heroes[target].getHealth()<=0);
            enemigos[turno].setCritic(6);
            enemigos[turno].setAccuracy(83);
            if(hit<(enemigos[turno].getAccuracy()-heroes[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-heroes[target].getProtection())*0.01);
                damageReceive = (enemigos[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_en_sklde_shieldbash.wav"),NULL,SND_ASYNC);
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_en_sklde_shieldbash.wav"),NULL,SND_ASYNC);
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }
}
void Ataque::DefenderSkill_ClumsyAxeBlade(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 0.6;
    int rangeMin = 2;
    int rangeMax = 3;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(enemigos[turno].getPosition()>1){
            hit = rand()%100;
            do{
                target = rand()%2+2;
            }while(heroes[target].getHealth()<=0);
            enemigos[turno].setCritic(6);
            enemigos[turno].setAccuracy(73);
            if(hit<(enemigos[turno].getAccuracy()-heroes[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-heroes[target].getProtection())*0.01);
                damageReceive = (enemigos[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_en_sklde_axestrike.wav"),NULL,SND_ASYNC);
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_en_sklde_axestrike.wav"),NULL,SND_ASYNC);
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }
}
/*Habilidades de capitan esqueleto*/
void Ataque::CaptainSkill_CrushingBlow(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int target;
    float skillDamage = 1.2;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(enemigos[turno].getPosition()>=0&&enemigos[turno].getPosition()<=1){
            hit = rand()%100;
            do{
                target = rand()%2;
            }while(heroes[target].getHealth()<=0);
            enemigos[turno].setCritic(8);
            enemigos[turno].setAccuracy(89);
            if(hit<(enemigos[turno].getAccuracy()-heroes[target].getDodge())){
                hitcritical = rand()%100;
                protect = ((100-heroes[target].getProtection())*0.01);
                damageReceive = (enemigos[turno].getDamage()*skillDamage)*protect;
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-(damageReceive*1.5));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                    PlaySound(TEXT("sounds/char_en_sklcap_crushingblow.wav"),NULL,SND_ASYNC);
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-damageReceive);
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                    PlaySound(TEXT("sounds/char_en_sklcap_crushingblow.wav"),NULL,SND_ASYNC);
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
                PlaySound(TEXT("sounds/char_en_sklcap_crushingblow_miss.wav"),NULL,SND_ASYNC);
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }
}
void Ataque::CaptainSkill_GroundPound(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int random;
    float skillDamage = 0.7;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(enemigos[turno].getPosition()>=0&&enemigos[turno].getPosition()<=3){
            enemigos[turno].setCritic(6);
            enemigos[turno].setAccuracy(89);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(heroes[i].getHealth()>0){
                    if(hit<(enemigos[turno].getAccuracy()-heroes[i].getDodge())){
                        hitcritical = rand()%100;
                        protect = ((100-heroes[i].getProtection())*0.01);
                        damageReceive = (enemigos[turno].getDamage()*skillDamage)*protect;
                        if(hitcritical<enemigos[turno].getCritic()){
                            heroes[i].setHealth(heroes[i].getHealth()-(damageReceive*1.5));
                            gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,25);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                            PlaySound(TEXT("sounds/char_en_sklcap_groundpound.wav"),NULL,SND_ASYNC);
                        }else{
                            heroes[i].setHealth(heroes[i].getHealth()-damageReceive);
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                            PlaySound(TEXT("sounds/char_en_sklcap_groundpound.wav"),NULL,SND_ASYNC);
                        }
                        if(heroes[i].getHealth()<=0){
                            gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << i << ": " << heroes[i].getHealth() << endl;
                        }
                    }else{
                        gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
                        PlaySound(TEXT("sounds/char_en_sklcap_groundpound_miss.wav"),NULL,SND_ASYNC);
                    }
                }
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
/*Habilidades de jefe necromancer*/
void Ataque::NecromancerSkill_WillingFlesh(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int random;
    float skillDamage = 0.95;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(enemigos[turno].getPosition()>=0&&enemigos[turno].getPosition()<=3){
            enemigos[turno].setCritic(5);
            enemigos[turno].setAccuracy(92);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(heroes[i].getHealth()>0){
                    if(hit<(enemigos[turno].getAccuracy()-heroes[i].getDodge())){
                        hitcritical = rand()%100;
                        protect = ((100-heroes[i].getProtection())*0.01);
                        damageReceive = (enemigos[turno].getDamage()*skillDamage)*protect;
                        if(hitcritical<enemigos[turno].getCritic()){
                            heroes[i].setHealth(heroes[i].getHealth()-(damageReceive*1.5));
                            gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,25);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                            PlaySound(TEXT("sounds/char_en_nec_flesh.wav"),NULL,SND_ASYNC);

                        }else{
                            heroes[i].setHealth(heroes[i].getHealth()-damageReceive);
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                            PlaySound(TEXT("sounds/char_en_nec_flesh.wav"),NULL,SND_ASYNC);
                        }
                        if(heroes[i].getHealth()<=0){
                            gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << i << ": " << heroes[i].getHealth() << endl;
                        }
                    }else{
                        gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
                    }
                }
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::NecromancerSkill_CrawlingDead(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int random;
    float skillDamage = 0.8;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(enemigos[turno].getPosition()>=0&&enemigos[turno].getPosition()<=3){
            enemigos[turno].setCritic(5);
            enemigos[turno].setAccuracy(93);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(heroes[i].getHealth()>0){
                    if(hit<(enemigos[turno].getAccuracy()-heroes[i].getDodge())){
                        hitcritical = rand()%100;
                        protect = ((100-heroes[i].getProtection())*0.01);
                        damageReceive = (enemigos[turno].getDamage()*skillDamage)*protect;
                        if(hitcritical<enemigos[turno].getCritic()){
                            heroes[i].setHealth(heroes[i].getHealth()-(damageReceive*1.5));
                            gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,25);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                            PlaySound(TEXT("sounds/char_en_nec_clawingdead_hit.wav"),NULL,SND_ASYNC);
                        }else{
                            heroes[i].setHealth(heroes[i].getHealth()-damageReceive);
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                            PlaySound(TEXT("sounds/char_en_nec_clawingdead.wav"),NULL,SND_ASYNC);
                        }
                        if(heroes[i].getHealth()<=0){
                            gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << i << ": " << heroes[i].getHealth() << endl;
                        }
                    }else{
                        gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
                    }
                }
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
void Ataque::NecromancerSkill_SixFeetUnder(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int random;
    float skillDamage = 0.5;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    float protect;
    int damageReceive;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        limpiarHabilidades();
        gotoxyAtaque(41,22);cout<<"ESTADO DEL ATAQUE:";
        if(enemigos[turno].getPosition()>=0&&enemigos[turno].getPosition()<=3){
            enemigos[turno].setCritic(2);
            enemigos[turno].setAccuracy(93);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(heroes[i].getHealth()>0){
                    if(hit<(enemigos[turno].getAccuracy()-heroes[i].getDodge())){
                        hitcritical = rand()%100;
                        protect = ((100-heroes[turno].getProtection())*0.01);
                        damageReceive = (enemigos[turno].getDamage()*skillDamage)*protect;
                        if(hitcritical<enemigos[turno].getCritic()){
                            heroes[i].setHealth(heroes[i].getHealth()-(damageReceive*1.5));
                            gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,25);cout << "DMG del ataque: " << (damageReceive*1.5) << endl;
                            PlaySound(TEXT("sounds/char_en_nec_sixfeetunder_hit.wav"),NULL,SND_ASYNC);
                        }else{
                            heroes[i].setHealth(heroes[i].getHealth()-damageReceive);
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << damageReceive << endl;
                            PlaySound(TEXT("sounds/char_en_nec_sixfeetunder.wav"),NULL,SND_ASYNC);
                        }
                        if(heroes[i].getHealth()<=0){
                            gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << i << ": " << heroes[i].getHealth() << endl;
                        }
                    }else{
                        gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
                    }
                }
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
