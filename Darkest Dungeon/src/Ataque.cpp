#include "Ataque.h"
#include "Heroe.h"
#include "Enemigo.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

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
    int cbleed;
    int cpoison;
    int cstun;
    int cdie;
    int bleed;
    int poison;
    int stun;
    /*Variables de cambio-*/
    if(heroes[turno].getPosition()==0 && realizado==0){
        do{
            cout << "Ingresa la posicion a cambiar" << endl;
            cout << "Espacios disponibles:" << endl;
            for(int i=heroes[turno].getPosition();i<=(heroes[turno].getPosition()+1);i++){
                if(i!=heroes[turno].getPosition()&&heroes[i].getHealth()>0){
                    cout << "Posicion " << i << endl;
                }
            }
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
        cbleed = heroes[space].getChanceBleed();
        cpoison = heroes[space].getChancePoison();
        cstun = heroes[space].getChanceStun();
        cdie = heroes[space].getChanceDie();
        bleed = heroes[space].getBleed();
        poison = heroes[space].getPoison();
        stun = heroes[space].getStun();
        //Cambiar los datos del heroe a la posicion deseada
        heroes[space].setMaxHealth(heroes[turno].getMaxHealth());
        heroes[space].setHealth(heroes[turno].getHealth());
        heroes[space].setAccuracy(heroes[turno].getAccuracy());
        heroes[space].setDamage(heroes[turno].getDamage());
        heroes[space].setCritic(heroes[turno].getCritic());
        heroes[space].setDodge(heroes[turno].getDodge());
        heroes[space].setProtection(heroes[turno].getProtection());
        heroes[space].setPosition(heroes[turno].getPosition());
        heroes[space].setChanceBleed(heroes[turno].getChanceBleed());
        heroes[space].setChancePoison(heroes[turno].getChancePoison());
        heroes[space].setChanceStun(heroes[turno].getChanceStun());
        heroes[space].setChanceDie(heroes[turno].getChanceDie());
        heroes[space].setBleed(heroes[turno].getBleed());
        heroes[space].setPoison(heroes[turno].getPoison());
        heroes[space].setStun(heroes[turno].getStun());
        //Cambiar los datos del heroe que fue reemplazado a la posicion del que realizo el cambio
        heroes[turno].setMaxHealth(hpMax);
        heroes[turno].setHealth(hp);
        heroes[turno].setAccuracy(acc);
        heroes[turno].setDamage(dmg);
        heroes[turno].setCritic(crit);
        heroes[turno].setDodge(dodge);
        heroes[turno].setProtection(prot);
        heroes[turno].setPosition(pos);
        heroes[turno].setChanceBleed(cbleed);
        heroes[turno].setChancePoison(cpoison);
        heroes[turno].setChanceStun(cstun);
        heroes[turno].setChanceDie(cdie);
        heroes[turno].setBleed(bleed);
        heroes[turno].setPoison(poison);
        heroes[turno].setStun(stun);
        realizado = 1;
    }
    if(heroes[turno].getPosition()>0&&heroes[turno].getPosition()<3&&realizado==0){
        do{
            cout << "Ingresa la posicion a cambiar" << endl;
            cout << "Espacios disponibles:" << endl;
            for(int i=heroes[turno].getPosition()-1;i<=(heroes[turno].getPosition()+1);i++){
                if(i!=heroes[turno].getPosition()){
                    cout << "Posicion " << i << endl;
                }
            }
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
        cbleed = heroes[space].getChanceBleed();
        cpoison = heroes[space].getChancePoison();
        cstun = heroes[space].getChanceStun();
        cdie = heroes[space].getChanceDie();
        bleed = heroes[space].getBleed();
        poison = heroes[space].getPoison();
        stun = heroes[space].getStun();
        //Cambiar los datos del heroe a la posicion deseada
        heroes[space].setMaxHealth(heroes[turno].getMaxHealth());
        heroes[space].setHealth(heroes[turno].getHealth());
        heroes[space].setAccuracy(heroes[turno].getAccuracy());
        heroes[space].setDamage(heroes[turno].getDamage());
        heroes[space].setCritic(heroes[turno].getCritic());
        heroes[space].setDodge(heroes[turno].getDodge());
        heroes[space].setProtection(heroes[turno].getProtection());
        heroes[space].setPosition(heroes[turno].getPosition());
        heroes[space].setChanceBleed(heroes[turno].getChanceBleed());
        heroes[space].setChancePoison(heroes[turno].getChancePoison());
        heroes[space].setChanceStun(heroes[turno].getChanceStun());
        heroes[space].setChanceDie(heroes[turno].getChanceDie());
        heroes[space].setBleed(heroes[turno].getBleed());
        heroes[space].setPoison(heroes[turno].getPoison());
        heroes[space].setStun(heroes[turno].getStun());
        //Cambiar los datos del heroe que fue reemplazado a la posicion del que realizo el cambio
        heroes[turno].setMaxHealth(hpMax);
        heroes[turno].setHealth(hp);
        heroes[turno].setAccuracy(acc);
        heroes[turno].setDamage(dmg);
        heroes[turno].setCritic(crit);
        heroes[turno].setDodge(dodge);
        heroes[turno].setProtection(prot);
        heroes[turno].setPosition(pos);
        heroes[turno].setChanceBleed(cbleed);
        heroes[turno].setChancePoison(cpoison);
        heroes[turno].setChanceStun(cstun);
        heroes[turno].setChanceDie(cdie);
        heroes[turno].setBleed(bleed);
        heroes[turno].setPoison(poison);
        heroes[turno].setStun(stun);
        realizado = 1;
    }
    if(heroes[turno].getPosition()==3&&realizado==0){
        do{
            cout << "Ingresa la posicion a cambiar" << endl;
            cout << "Espacios disponibles:" << endl;
            for(int i=(heroes[turno].getPosition()-1);i<=heroes[turno].getPosition();i++){
                if(i!=heroes[turno].getPosition()){
                    cout << "Posicion " << i << endl;
                }
            }
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
        cbleed = heroes[space].getChanceBleed();
        cpoison = heroes[space].getChancePoison();
        cstun = heroes[space].getChanceStun();
        cdie = heroes[space].getChanceDie();
        bleed = heroes[space].getBleed();
        poison = heroes[space].getPoison();
        stun = heroes[space].getStun();
        //Cambiar los datos del heroe a la posicion deseada
        heroes[space].setMaxHealth(heroes[turno].getMaxHealth());
        heroes[space].setHealth(heroes[turno].getHealth());
        heroes[space].setAccuracy(heroes[turno].getAccuracy());
        heroes[space].setDamage(heroes[turno].getDamage());
        heroes[space].setCritic(heroes[turno].getCritic());
        heroes[space].setDodge(heroes[turno].getDodge());
        heroes[space].setProtection(heroes[turno].getProtection());
        heroes[space].setPosition(heroes[turno].getPosition());
        heroes[space].setChanceBleed(heroes[turno].getChanceBleed());
        heroes[space].setChancePoison(heroes[turno].getChancePoison());
        heroes[space].setChanceStun(heroes[turno].getChanceStun());
        heroes[space].setChanceDie(heroes[turno].getChanceDie());
        heroes[space].setBleed(heroes[turno].getBleed());
        heroes[space].setPoison(heroes[turno].getPoison());
        heroes[space].setStun(heroes[turno].getStun());
        //Cambiar los datos del heroe que fue reemplazado a la posicion del que realizo el cambio
        heroes[turno].setMaxHealth(hpMax);
        heroes[turno].setHealth(hp);
        heroes[turno].setAccuracy(acc);
        heroes[turno].setDamage(dmg);
        heroes[turno].setCritic(crit);
        heroes[turno].setDodge(dodge);
        heroes[turno].setProtection(prot);
        heroes[turno].setPosition(pos);
        heroes[turno].setChanceBleed(cbleed);
        heroes[turno].setChancePoison(cpoison);
        heroes[turno].setChanceStun(cstun);
        heroes[turno].setChanceDie(cdie);
        heroes[turno].setBleed(bleed);
        heroes[turno].setPoison(poison);
        heroes[turno].setStun(stun);
        realizado = 1;
    }
    cout << "Posicion actual del heroe: " << heroes[1].getPosition() << endl;
}
void Ataque::SharedHeroDeath(int turno, Heroe heroes[4]){
    //Recorrer de posicion a los heroes una vez muera alguno
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
            heroes[turno].setCritic(3);
            heroes[turno].setAccuracy(85);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((((heroes[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El objetivo ha sido derribado" << endl;
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
//Inflige aturdimiento
void Ataque::CrusaderSkill_StunningBlow(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int hitstun;
    int target;
    float skillDamage = 0.5;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
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
            heroes[turno].setCritic(3);
            heroes[turno].setAccuracy(90);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((((heroes[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El objetivo ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                    /*hitstun = rand()%100;
                    if(hitstun<enemigos[target].getChanceStun()){
                        enemigos[target].setStun(1);
                        cout << "El enemigo ha sido aturdido" << endl;
                    }*/
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
void Ataque::CrusaderSkill_ZealousAccusation(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int random;
    int target;
    float skillDamage = 0.6;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
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
                        if(hitcritical<heroes[turno].getCritic()){
                            enemigos[i].setHealth(enemigos[i].getHealth()-((heroes[turno].getDamage()*skillDamage)*1.5));
                            gotoxyAtaque(41,24);cout << "El enemigo ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                        }else{
                            enemigos[i].setHealth(enemigos[i].getHealth()-(heroes[turno].getDamage()*skillDamage));
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                        }
                        if(enemigos[i].getHealth()<=0){
                            gotoxyAtaque(41,24);cout << "El objetivo ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << i << ": " << enemigos[i].getHealth() << endl;
                        }
                    }else{
                        gotoxyAtaque(41,24);cout << "Fallaste el ataque" << endl;
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
                gotoxyAtaque(41,24);cout << "El heroe ha sido sanado perfectamente!" << endl;
                gotoxyAtaque(41,25);cout << "Sanacion de la habilidad: " << (curacion*1.5) << endl;
            }else{
                heroes[target].setHealth(heroes[target].getHealth()+curacion);
                gotoxyAtaque(41,24);cout << "Sanacion de la habilidad: " << curacion << endl;
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
            heroes[turno].setAccuracy(85);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((((heroes[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El objetivo ha sido derribado" << endl;
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
//Inflige sangrado
void Ataque::HighwaymanSkill_OpenVein(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int hitbleed;
    int target;
    float skillDamage = 0.85;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
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
            heroes[turno].setCritic(5);
            heroes[turno].setAccuracy(95);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((heroes[turno].getDamage()*skillDamage)*1.5));
                    gotoxyAtaque(41,24);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;

                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El objetivo ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                    /*hitbleed = rand()%100;
                    if(hitbleed<enemigos[target].getChanceBleed()){
                        enemigos[target].setBleed(3);
                        cout << "El enemigo ha sido herido con un sangrado nivel " << enemigos[target].getBleed() << endl;
                    }*/
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
    float skillDamage = 0.85;
    int rangeMin = 1;
    int rangeMax = 3;
    int objetivos = 3;
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
            heroes[turno].setCritic(13);
            heroes[turno].setAccuracy(85);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((heroes[turno].getDamage()*skillDamage)*1.5));
                    gotoxyAtaque(41,24);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;

                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El objetivo ha sido derribado" << endl;
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
void Ataque::HighwaymanSkill_Grapeshot(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int random;
    int target;
    float skillDamage = 0.5;
    int rangeMin = 0;
    int rangeMax = 2;
    int objetivos = 3;
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
                        if(hitcritical<heroes[turno].getCritic()){
                            enemigos[i].setHealth(enemigos[i].getHealth()-((heroes[turno].getDamage()*skillDamage)*1.5));
                            gotoxyAtaque(41,24);cout << "El enemigo ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                        }else{
                            enemigos[i].setHealth(enemigos[i].getHealth()-(heroes[turno].getDamage()*skillDamage));
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                        }
                        if(enemigos[i].getHealth()<=0){
                            gotoxyAtaque(41,24);cout << "El objetivo ha sido derribado" << endl;
                        }/*else{
                            gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << i << ": " << enemigos[i].getHealth() << endl;
                        }*/
                    }else{
                        gotoxyAtaque(41,24);gotoxyAtaque(41,24);cout << "Fallaste el ataque" << endl;
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
    float skillDamage = 0.75;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
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
            heroes[turno].setAccuracy(85);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((((heroes[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El objetivo ha sido derribado" << endl;
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
//Inflige aturdimiento
void Ataque::VestalSkill_DazzlingLight(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int hitstun;
    int target;
    float skillDamage = 0.25;
    int rangeMin = 0;
    int rangeMax = 2;
    int objetivos = 3;
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
            heroes[turno].setCritic(6);
            heroes[turno].setAccuracy(90);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((((heroes[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El objetivo ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                    /*hitstun = rand()%100;
                    if(hitstun<enemigos[target].getChanceStun()){
                        enemigos[target].setStun(1);
                        cout << "El enemigo ha sido aturdido" << endl;
                    }*/
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
//Quitara sangrado, veneno y paralisis
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
                gotoxyAtaque(41,24);cout << "El heroe ha sido sanado perfectamente!" << endl;
                gotoxyAtaque(41,25);cout << "Sanacion de la habilidad: " << (curacion*1.5) << endl;
            }else{
                heroes[target].setHealth(heroes[target].getHealth()+curacion);
                gotoxyAtaque(41,24);cout << "Sanacion de la habilidad: " << curacion << endl;
            }
            /*heroes[target].setBleed(0);
            heroes[target].setPoison(0);
            heroes[target].setStun(0);
            cout << "El heroe ha sido curado de efectos de estado" << endl;*/
            if(heroes[target].getHealth()>heroes[target].getMaxHealth()){
                heroes[target].setHealth(heroes[target].getMaxHealth());
            }
            gotoxyAtaque(41,24);cout << "Vida del heroe asistido " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
        }else{
            gotoxyAtaque(41,24);cout << "No es posible desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
//Quitara paralisis
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
                        //cout << "El heroe ha sido sanado perfectamente!" << endl;
                        gotoxyAtaque(41,24);cout << "Sanacion de la habilidad: " << (curacion*1.5) << endl;
                    }else{
                        heroes[i].setHealth(heroes[i].getHealth()+curacion);
                        gotoxyAtaque(41,24);cout << "Sanacion de la habilidad: " << curacion << endl;
                    }
                    /*heroes[i].setStun(0);*/
                    if(heroes[i].getHealth()>heroes[i].getMaxHealth()){
                        heroes[i].setHealth(heroes[i].getMaxHealth());
                    }
                    gotoxyAtaque(41,25+i);cout << "Vida del heroe asistido " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                }
            }
            /*cout << "Los heroes han sido curados del efecto de paralisis" << endl;*/
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }

}
/*Habilidades de doctor*/
//Inflige veneno
void Ataque::PlagueDoctorSkill_NoxiousBlast(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int hitpoison;
    int target;
    float skillDamage = 0.25;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
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
            heroes[turno].setCritic(7);
            heroes[turno].setAccuracy(95);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((((heroes[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El enemigo ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El objetivo ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                    /*hitpoison = rand()%100;
                    if(hitpoison<enemigos[target].getChancePoison()){
                        enemigos[target].setPoison(5);
                        cout << "El enemigo ha sido herido con un envenenamiento nivel " << enemigos[target].getPoison() << endl;
                    }*/
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
//Inflige veneno
void Ataque::PlagueDoctorSkill_PlagueGrenade(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int hitpoison;
    int random;
    int target;
    float skillDamage = 0.15;
    int rangeMin = 2;
    int rangeMax = 3;
    int objetivos = 2;
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
            heroes[turno].setCritic(2);
            heroes[turno].setAccuracy(95);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(enemigos[i].getHealth()>0){
                    if(hit<(heroes[turno].getAccuracy()-enemigos[i].getDodge())){
                        hitcritical = rand()%100;
                        if(hitcritical<heroes[turno].getCritic()){
                            enemigos[i].setHealth(enemigos[i].getHealth()-((heroes[turno].getDamage()*skillDamage)*1.5));
                            gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                        }else{
                            enemigos[i].setHealth(enemigos[i].getHealth()-(heroes[turno].getDamage()*skillDamage));
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                        }
                        if(enemigos[i].getHealth()<=0){
                            gotoxyAtaque(41,24);cout << "El objetivo ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,25+i);cout << "Vida del enemigo impactado " << i << ": " << enemigos[i].getHealth() << endl;
                            /*hitpoison = rand()%100;
                            if(hitpoison<enemigos[i].getChancePoison()){
                                enemigos[i].setPoison(5);
                                cout << "El enemigo ha sido herido con un envenenamiento nivel " << enemigos[i].getPoison() << endl;
                            }*/
                        }
                    }else{
                        gotoxyAtaque(41,24);cout << "Fallaste el ataque" << endl;
                    }
                }
            }
            /*for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                }
            }*/
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
//Inflige aturdimiento
void Ataque::PlagueDoctorSkill_BlindingGas(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int hitstun;
    int random;
    int target;
    float skillDamage = 0.05;
    int rangeMin = 2;
    int rangeMax = 3;
    int objetivos = 2;
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
            heroes[turno].setCritic(2);
            heroes[turno].setAccuracy(95);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(enemigos[i].getHealth()>0){
                    if(hit<(heroes[turno].getAccuracy()-enemigos[i].getDodge())){
                        hitcritical = rand()%100;
                        if(hitcritical<heroes[turno].getCritic()){
                            enemigos[i].setHealth(enemigos[i].getHealth()-((heroes[turno].getDamage()*skillDamage)*1.5));
                            gotoxyAtaque(41,23);cout << "El enemigo ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                        }else{
                            enemigos[i].setHealth(enemigos[i].getHealth()-(heroes[turno].getDamage()*skillDamage));
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                        }
                        if(enemigos[i].getHealth()<=0){
                            gotoxyAtaque(41,24);cout << "El objetivo ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,25+i);cout << "Vida del enemigo impactado " << i << ": " << enemigos[i].getHealth() << endl;
                            /*hitstun = rand()%100;
                            if(hitstun<enemigos[i].getChanceStun()){
                                enemigos[i].setStun(1);
                                cout << "El enemigo ha sido aturdido" << endl;
                            }*/
                        }
                    }else{
                        gotoxyAtaque(41,24);cout << "Fallaste el ataque" << endl;
                    }
                }
            }
            /*for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                }
            }*/
        }else{
            gotoxyAtaque(41,24);cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
//Quitara sangrado, veneno y paralisis
void Ataque::PlagueDoctorSkill_BattlefieldMedicine(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hitcritical;
    int target;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    int curacion = 2;
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
                gotoxyAtaque(41,24);cout << "El heroe ha sido sanado perfectamente!" << endl;
                gotoxyAtaque(41,25);cout << "Sanacion de la habilidad: " << (curacion*1.5) << endl;
            }else{
                heroes[target].setHealth(heroes[target].getHealth()+curacion);
                gotoxyAtaque(41,24);cout << "Sanacion de la habilidad: " << curacion << endl;
            }
            /*heroes[target].setBleed(0);
            heroes[target].setPoison(0);
            heroes[target].setStun(0);
            cout << "El heroe ha sido curado de efectos de estado" << endl;*/
            if(heroes[target].getHealth()>heroes[target].getMaxHealth()){
                heroes[target].setHealth(heroes[target].getMaxHealth());
            }
            gotoxyAtaque(41,26);cout << "Vida del heroe asistido " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
            /*for(int i=0;i<4;i++){
                if(heroes[i].getHealth()>0){
                    cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                }
            }*/
        }else{
            gotoxyAtaque(41,24);cout << "No es posible desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
/*Habilidades de soldado esqueleto*/
//Inflige sangrado
void Ataque::SoldierSkill_GraveyardSlash(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int hitbleed;
    int target;
    float skillDamage = 1;
    int rangeMin = 0;
    int rangeMax = 2;
    int objetivos = 3;
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
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-((((enemigos[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((enemigos[turno].getDamage())*1.5) << endl;
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-(enemigos[turno].getDamage()));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (enemigos[turno].getDamage()) << endl;
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                    /*hitbleed = rand()%100;
                    if(hitbleed<heroes[target].getChanceBleed()){
                        heroes[target].setBleed(3);
                        cout << "El heroe ha sido herido con un sangrado nivel " << heroes[target].getBleed() << endl;
                    }*/
                }
                /*for(int i=0;i<4;i++){
                    if(heroes[i].getHealth()>0){
                        gotoxyAtaque(41,25+i);cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                    }
                }*/
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
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
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-((((enemigos[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((enemigos[turno].getDamage())*1.5) << endl;
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-(enemigos[turno].getDamage()));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (enemigos[turno].getDamage()) << endl;
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth()<< endl;
                }
                /*for(int i=0;i<4;i++){
                    if(heroes[i].getHealth()>0){
                        cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth()<< endl;
                    }
                }*/
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
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
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-((((enemigos[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((enemigos[turno].getDamage())*1.5) << endl;
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-(enemigos[turno].getDamage()));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (enemigos[turno].getDamage()) << endl;
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
                /*for(int i=0;i<4;i++){
                    if(heroes[i].getHealth()>0){
                        cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                    }
                }*/
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
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
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-((((enemigos[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((enemigos[turno].getDamage())*1.5) << endl;
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-(enemigos[turno].getDamage()));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (enemigos[turno].getDamage()) << endl;
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
                /*for(int i=0;i<4;i++){
                    if(heroes[i].getHealth()>0){
                        cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                    }
                }*/
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }
}
/*Habilidades de defensor esqueleto*/
//Inflige sangrado
void Ataque::DefenderSkill_AxeBlade(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int hitbleed;
    int target;
    float skillDamage = 0.8;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
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
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-((((enemigos[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((enemigos[turno].getDamage())*1.5) << endl;
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-(enemigos[turno].getDamage()));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (enemigos[turno].getDamage()) << endl;
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                    /*hitbleed = rand()%100;
                    if(hitbleed<heroes[target].getChanceBleed()){
                        heroes[target].setBleed(3);
                        cout << "El heroe ha sido herido con un sangrado nivel " << heroes[target].getBleed() << endl;
                    }*/
                }
                /*for(int i=0;i<4;i++){
                    if(heroes[i].getHealth()>0){
                        cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                    }
                }*/
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
            }
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }
}
//Inflige aturdimiento
void Ataque::DefenderSkill_DeadWeight(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int hitstun;
    int target;
    float skillDamage = 0.6;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
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
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-((((enemigos[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((enemigos[turno].getDamage())*1.5) << endl;
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-(enemigos[turno].getDamage()));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (enemigos[turno].getDamage()) << endl;
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
                /*for(int i=0;i<4;i++){
                    if(heroes[i].getHealth()>0){
                        cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                        *//*hitstun = rand()%100;
                        if(hitstun<heroes[target].getChanceStun()){
                            heroes[target].setStun(1);
                            cout << "El heroe ha sido aturdido" << endl;
                        }*/
                    /*}
                }*/
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
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-((((enemigos[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((enemigos[turno].getDamage())*1.5) << endl;
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-(enemigos[turno].getDamage()));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (enemigos[turno].getDamage()) << endl;
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
                /*for(int i=0;i<4;i++){
                    if(heroes[i].getHealth()>0){
                        cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                    }
                }*/
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
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-((((enemigos[turno].getDamage()*skillDamage)*1.5))));
                    gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                    gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((enemigos[turno].getDamage())*1.5) << endl;
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-(enemigos[turno].getDamage()));
                    gotoxyAtaque(41,24);cout << "DMG del ataque: " << (enemigos[turno].getDamage()) << endl;
                }
                if(heroes[target].getHealth()<=0){
                    gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                }else{
                    gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
                /*for(int i=0;i<4;i++){
                    if(heroes[i].getHealth()>0){
                        cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                    }
                }*/
            }else{
                gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
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
    float skillDamage = 0.8;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
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
                        if(hitcritical<enemigos[turno].getCritic()){
                            heroes[i].setHealth(heroes[i].getHealth()-((enemigos[turno].getDamage()*skillDamage)*1.5));
                            gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((enemigos[turno].getDamage()*skillDamage)*1.5) << endl;
                        }else{
                            heroes[i].setHealth(heroes[i].getHealth()-(enemigos[turno].getDamage()*skillDamage));
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << (enemigos[turno].getDamage()*skillDamage) << endl;
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
            /*for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << endl;
                }
            }*/
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
//Habilidades del jefe crearan 1 soldado
/*Habilidades de jefe necromancer*/
//Inflige veneno
void Ataque::NecromancerSkill_WillingFlesh(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int hitpoison;
    int random;
    float skillDamage = 1.2;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
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
            enemigos[turno].setAccuracy(100);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(heroes[i].getHealth()>0){
                    if(hit<(enemigos[turno].getAccuracy()-heroes[i].getDodge())){
                        hitcritical = rand()%100;
                        if(hitcritical<enemigos[turno].getCritic()){
                            heroes[i].setHealth(heroes[i].getHealth()-((enemigos[turno].getDamage()*skillDamage)*1.5));
                            gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((enemigos[turno].getDamage()*skillDamage)*1.5) << endl;
                        }else{
                            heroes[i].setHealth(heroes[i].getHealth()-(enemigos[turno].getDamage()*skillDamage));
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << (enemigos[turno].getDamage()*skillDamage) << endl;
                        }
                        if(heroes[i].getHealth()<=0){
                            gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << i << ": " << heroes[i].getHealth() << endl;
                            /*hitpoison = rand()%100;
                            if(hitpoison<heroes[i].getChancePoison()){
                                heroes[i].setPoison(2);
                                cout << "El heroe ha sido herido con un envenenamiento nivel " << heroes[i].getPoison() << endl;
                            }*/
                        }
                    }else{
                        gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
                    }
                }
            }
            /*for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << endl;
                }
            }*/
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
//Inflige sangrado
void Ataque::NecromancerSkill_CrawlingDead(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int hitbleed;
    int random;
    float skillDamage = 0.8;
    int rangeMin = 0;
    int rangeMax = 1;
    int objetivos = 2;
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
            enemigos[turno].setAccuracy(100);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(heroes[i].getHealth()>0){
                    if(hit<(enemigos[turno].getAccuracy()-heroes[i].getDodge())){
                        hitcritical = rand()%100;
                        if(hitcritical<enemigos[turno].getCritic()){
                            heroes[i].setHealth(heroes[i].getHealth()-((enemigos[turno].getDamage()*skillDamage)*1.5));
                            gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((enemigos[turno].getDamage()*skillDamage)*1.5) << endl;
                        }else{
                            heroes[i].setHealth(heroes[i].getHealth()-(enemigos[turno].getDamage()*skillDamage));
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << (enemigos[turno].getDamage()*skillDamage) << endl;
                        }
                        if(heroes[i].getHealth()<=0){
                            gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << i << ": " << heroes[i].getHealth() << endl;
                            /*hitbleed = rand()%100;
                            if(hitbleed<heroes[i].getChanceBleed()){
                                heroes[i].setBleed(3);
                                cout << "El heroe ha sido herido con un sangrado nivel " << heroes[i].getBleed() << endl;
                            }*/
                        }
                    }else{
                        gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
                    }
                }
            }
            /*for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << endl;
                }
            }*/
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
//Inflige paralisis
void Ataque::NecromancerSkill_SixFeetUnder(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int hitstun;
    int random;
    float skillDamage = 0.2;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
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
            enemigos[turno].setCritic(1);
            enemigos[turno].setAccuracy(100);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(heroes[i].getHealth()>0){
                    if(hit<(enemigos[turno].getAccuracy()-heroes[i].getDodge())){
                        hitcritical = rand()%100;
                        if(hitcritical<enemigos[turno].getCritic()){
                            heroes[i].setHealth(heroes[i].getHealth()-((enemigos[turno].getDamage()*skillDamage)*1.5));
                            gotoxyAtaque(41,24);cout << "El heroe ha recibido un golpe critico!" << endl;
                            gotoxyAtaque(41,25);cout << "DMG del ataque: " << ((enemigos[turno].getDamage()*skillDamage)*1.5) << endl;
                        }else{
                            heroes[i].setHealth(heroes[i].getHealth()-(enemigos[turno].getDamage()*skillDamage));
                            gotoxyAtaque(41,24);cout << "DMG del ataque: " << (enemigos[turno].getDamage()*skillDamage) << endl;
                        }
                        if(heroes[i].getHealth()<=0){
                            gotoxyAtaque(41,24);cout << "El heroe ha sido derribado" << endl;
                        }else{
                            gotoxyAtaque(41,26);cout << "Vida del heroe impactado " << i << ": " << heroes[i].getHealth() << endl;
                            /*hitstun = rand()%100;
                            if(hitstun<(heroes[i].getChanceStun()-10)){
                                heroes[i].setStun(1);
                                cout << "El heroe ha sido aturdido " << endl;
                            }*/
                        }
                    }else{
                        gotoxyAtaque(41,24);cout << "El enemigo fallo el ataque" << endl;
                    }
                }
            }
            /*for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << endl;
                }
            }*/
        }else{
            gotoxyAtaque(41,24);cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }else{
        gotoxyAtaque(41,24);cout << "No hay objetivos" << endl;
    }
}
