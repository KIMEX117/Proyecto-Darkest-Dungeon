#include "Ataque.h"
#include "Heroe.h"
#include "Enemigo.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Ataque::Ataque(){}
/*Habilidades de combate compartidas*/
void Ataque::SharedHeroSkill_Move(int turno, Heroe heroes[4]){
    int space;
    int realizado = 0;
    if(heroes[turno].getPosition()==0 && realizado==0){
        do{
            cout << "Ingresa la posicion a cambiar" << endl;
            cout << "Espacios disponibles:" << endl;
            for(int i=heroes[turno].getPosition();i<=(heroes[turno].getPosition()+1);i++){
                if(i!=heroes[turno].getPosition()){
                    cout << "Posicion " << i << endl;
                }
            }
            cin >> space;
        }while(space==heroes[turno].getPosition()||space>1||space<0);
        heroes[turno].setPosition(space);
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
        heroes[turno].setPosition(space);
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
        heroes[turno].setPosition(space);
        realizado = 1;
    }
    cout << "Posicion actual del heroe: " << heroes[1].getPosition() << endl;
}
void Ataque::SharedEnemySkill_Move(int turno, Enemigo enemigos[4]){
    /*Algoritmo de busqueda si puede atacar o no*/
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
            cout << "Objetivos disponibles:" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            cout << "Ingresa el objetivo: ";
            cin >> target;
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(3);
            heroes[turno].setAccuracy(85);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((((heroes[turno].getDamage()*skillDamage)*1.5))));
                    cout << "El enemigo ha recibido un golpe critico!" << endl;
                    cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    cout << "El objetivo ha sido derribado" << endl;
                }else{
                    cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
                for(int i=0;i<4;i++){
                    if(enemigos[i].getHealth()>0){
                        cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                    }
                }
            }else{
                cout << "Fallaste el ataque" << endl;
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
    }
}
void Ataque::CrusaderSkill_StunningBlow(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
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
            cout << "Objetivos disponibles:" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            cout << "Ingresa el objetivo: ";
            cin >> target;
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(3);
            heroes[turno].setAccuracy(90);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((((heroes[turno].getDamage()*skillDamage)*1.5))));
                    cout << "El enemigo ha recibido un golpe critico!" << endl;
                    cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    cout << "El objetivo ha sido derribado" << endl;
                }else{
                    cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
                for(int i=0;i<4;i++){
                    if(enemigos[i].getHealth()>0){
                        cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                    }
                }
            }else{
                cout << "Fallaste el ataque" << endl;
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
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
            heroes[turno].setCritic(1);
            heroes[turno].setAccuracy(85);
            for(int i=rangeMin;i<=rangeMax;i++){
                hit = rand()%100;
                if(enemigos[i].getHealth()>0){
                    if(hit<(heroes[turno].getAccuracy()-enemigos[i].getDodge())){
                        hitcritical = rand()%100;
                        if(hitcritical<heroes[turno].getCritic()){
                            enemigos[i].setHealth(enemigos[i].getHealth()-((heroes[turno].getDamage()*skillDamage)*1.5));
                            cout << "El enemigo ha recibido un golpe critico!" << endl;
                            cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                        }else{
                            enemigos[i].setHealth(enemigos[i].getHealth()-(heroes[turno].getDamage()*skillDamage));
                            cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                        }
                        if(enemigos[i].getHealth()<=0){
                            cout << "El objetivo ha sido derribado" << endl;
                        }else{
                            cout << "Vida del enemigo impactado " << i << ": " << enemigos[i].getHealth() << endl;
                        }
                    }else{
                        cout << "Fallaste el ataque" << endl;
                    }
                }
            }
            for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                }
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
    }
}
void Ataque::CrusaderSkill_BattleHeal(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hitcritical;
    int target;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0&&heroes[i].getHealth()==heroes[i].getMaxHealth()){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()>=0&&heroes[turno].getPosition()<=3){
            do{
                cout << "Objetivos disponibles:" << endl;
                for(int i=rangeMin;i<=rangeMax;i++){
                    if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                    cout << i << ".- " << heroes[i].getName() << endl;
                    }
                }
                cout << "Ingresa el objetivo: ";
                cin >> target;
            }while((target<rangeMin||target>rangeMax)||heroes[target].getHealth()<=0||heroes[target].getHealth()==heroes[target].getMaxHealth());
            heroes[turno].setCritic(12);
            hitcritical = rand()%100;
            if(hitcritical<heroes[turno].getCritic()){
                heroes[target].setHealth(heroes[target].getHealth()+(3*1.5));
                cout << "El heroe ha sido sanado perfectamente!" << endl;
                cout << "Sanacion de la habilidad: " << (3*1.5) << endl;
            }else{
                heroes[target].setHealth(heroes[target].getHealth()+3);
                cout << "Sanacion de la habilidad: " << 3 << endl;
            }
            if(heroes[target].getHealth()>heroes[target].getMaxHealth()){
                heroes[target].setHealth(heroes[target].getMaxHealth());
            }
            cout << "Vida del heroe asistido " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
            for(int i=0;i<4;i++){
                if(heroes[i].getHealth()>0){
                    cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                }
            }
        }else{
            cout << "No es posible desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
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
            cout << "Objetivos disponibles:" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            cout << "Ingresa el objetivo: ";
            cin >> target;
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(10);
            heroes[turno].setAccuracy(85);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((((heroes[turno].getDamage()*skillDamage)*1.5))));
                    cout << "El enemigo ha recibido un golpe critico!" << endl;
                    cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    cout << "El objetivo ha sido derribado" << endl;
                }else{
                    cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
                for(int i=0;i<4;i++){
                    if(enemigos[i].getHealth()>0){
                        cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                    }
                }
            }else{
                cout << "Fallaste el ataque" << endl;
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
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
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(enemigos[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()<3){
            do{
            cout << "Objetivos disponibles:" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            cout << "Ingresa el objetivo: ";
            cin >> target;
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(5);
            heroes[turno].setAccuracy(95);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((heroes[turno].getDamage()*skillDamage)*1.5));
                    cout << "El enemigo ha recibido un golpe critico!" << endl;
                    cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;

                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    cout << "El objetivo ha sido derribado" << endl;
                }else{
                    cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
                for(int i=0;i<4;i++){
                    if(enemigos[i].getHealth()>0){
                        cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                    }
                }
            }else{
                cout << "Fallaste el ataque" << endl;
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
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
            cout << "Objetivos disponibles:" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            cout << "Ingresa el objetivo: ";
            cin >> target;
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(13);
            heroes[turno].setAccuracy(85);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((heroes[turno].getDamage()*skillDamage)*1.5));
                    cout << "El enemigo ha recibido un golpe critico!" << endl;
                    cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;

                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    cout << "El objetivo ha sido derribado" << endl;
                }else{
                    cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
                for(int i=0;i<4;i++){
                    if(enemigos[i].getHealth()>0){
                        cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                    }
                }
            }else{
                cout << "Fallaste el ataque" << endl;
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
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
                            cout << "El enemigo ha recibido un golpe critico!" << endl;
                            cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                        }else{
                            enemigos[i].setHealth(enemigos[i].getHealth()-(heroes[turno].getDamage()*skillDamage));
                            cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                        }
                        if(enemigos[i].getHealth()<=0){
                            cout << "El objetivo ha sido derribado" << endl;
                        }else{
                            cout << "Vida del enemigo impactado " << i << ": " << enemigos[i].getHealth() << endl;
                        }
                    }else{
                        cout << "Fallaste el ataque" << endl;
                    }
                }
            }
            for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                }
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
    }
}
/*Habilidades de vestal*/
void Ataque::VestalSkill_MaceBash(int turno, Heroe heroes[4], Enemigo enemigos[4]){
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
            cout << "Objetivos disponibles:" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            cout << "Ingresa el objetivo: ";
            cin >> target;
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(1);
            heroes[turno].setAccuracy(85);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((((heroes[turno].getDamage()*skillDamage)*1.5))));
                    cout << "El enemigo ha recibido un golpe critico!" << endl;
                    cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    cout << "El objetivo ha sido derribado" << endl;
                }else{
                    cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
                for(int i=0;i<4;i++){
                    if(enemigos[i].getHealth()>0){
                        cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                    }
                }
            }else{
                cout << "Fallaste el ataque" << endl;
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
    }
}
void Ataque::VestalSkill_DazzlingLight(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
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
            cout << "Objetivos disponibles:" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            cout << "Ingresa el objetivo: ";
            cin >> target;
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(6);
            heroes[turno].setAccuracy(90);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((((heroes[turno].getDamage()*skillDamage)*1.5))));
                    cout << "El enemigo ha recibido un golpe critico!" << endl;
                    cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    cout << "El objetivo ha sido derribado" << endl;
                }else{
                    cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
                for(int i=0;i<4;i++){
                    if(enemigos[i].getHealth()>0){
                        cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                    }
                }
            }else{
                cout << "Fallaste el ataque" << endl;
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
    }
}
void Ataque::VestalSkill_DivineGrace(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hitcritical;
    int target;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0&&heroes[i].getHealth()==heroes[i].getMaxHealth()){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()>1){
            do{
                cout << "Objetivos disponibles:" << endl;
                for(int i=rangeMin;i<=rangeMax;i++){
                    if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                    cout << i << ".- " << heroes[i].getName() << endl;
                    }
                }
                cout << "Ingresa el objetivo: ";
                cin >> target;
            }while((target<rangeMin||target>rangeMax)||heroes[target].getHealth()<=0||heroes[target].getHealth()==heroes[target].getMaxHealth());
            heroes[turno].setCritic(12);
            hitcritical = rand()%100;
            if(hitcritical<heroes[turno].getCritic()){
                heroes[target].setHealth(heroes[target].getHealth()+(5*1.5));
                cout << "El heroe ha sido sanado perfectamente!" << endl;
                cout << "Sanacion de la habilidad: " << (5*1.5) << endl;
            }else{
                heroes[target].setHealth(heroes[target].getHealth()+5);
                cout << "Sanacion de la habilidad: " << 5 << endl;
            }
            if(heroes[target].getHealth()>heroes[target].getMaxHealth()){
                heroes[target].setHealth(heroes[target].getMaxHealth());
            }
            cout << "Vida del heroe asistido " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
            for(int i=0;i<4;i++){
                if(heroes[i].getHealth()>0){
                    cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                }
            }
        }else{
            cout << "No es posible desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
    }
}
void Ataque::VestalSkill_DivineComfort(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
    int random;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0&&heroes[i].getHealth()==heroes[i].getMaxHealth()){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()>0){
            heroes[turno].setCritic(1);
            for(int i=rangeMin;i<=rangeMax;i++){
                if(heroes[i].getHealth()>0){
                    hitcritical = rand()%100;
                    if(hitcritical<heroes[turno].getCritic()){
                        heroes[i].setHealth(heroes[i].getHealth()+(3*1.5));
                        cout << "El heroe ha sido sanado perfectamente!" << endl;
                        cout << "Sanacion de la habilidad: " << (3*1.5) << endl;
                    }else{
                        heroes[i].setHealth(heroes[i].getHealth()+3);
                        cout << "Sanacion de la habilidad: " << 3 << endl;
                    }
                    if(heroes[i].getHealth()>heroes[i].getMaxHealth()){
                        heroes[i].setHealth(heroes[i].getMaxHealth());
                    }
                    cout << "Vida del heroe asistido " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                }
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
    }

}
/*Habilidades de doctor*/
void Ataque::PlagueDoctorSkill_NoxiousBlast(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
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
            cout << "Objetivos disponibles:" << endl;
            for(int i=rangeMin;i<=rangeMax;i++){
                if(enemigos[i].getHealth()>0){
                cout << i << ".- " << enemigos[i].getName() << endl;
                }
            }
            cout << "Ingresa el objetivo: ";
            cin >> target;
            }while((target<rangeMin||target>rangeMax)||enemigos[target].getHealth()<=0);
            hit = rand()%100;
            heroes[turno].setCritic(7);
            heroes[turno].setAccuracy(95);
            if(hit<(heroes[turno].getAccuracy()-enemigos[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<heroes[turno].getCritic()){
                    enemigos[target].setHealth(enemigos[target].getHealth()-((((heroes[turno].getDamage()*skillDamage)*1.5))));
                    cout << "El enemigo ha recibido un golpe critico!" << endl;
                    cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                }else{
                    enemigos[target].setHealth(enemigos[target].getHealth()-(heroes[turno].getDamage()*skillDamage));
                    cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                }
                if(enemigos[target].getHealth()<=0){
                    cout << "El objetivo ha sido derribado" << endl;
                }else{
                    cout << "Vida del enemigo impactado " << target << ": " << enemigos[target].getHealth() << endl;
                }
                for(int i=0;i<4;i++){
                    if(enemigos[i].getHealth()>0){
                        cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                    }
                }
            }else{
                cout << "Fallaste el ataque" << endl;
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
    }
}
void Ataque::PlagueDoctorSkill_PlagueGrenade(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
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
                            cout << "El enemigo ha recibido un golpe critico!" << endl;
                            cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                        }else{
                            enemigos[i].setHealth(enemigos[i].getHealth()-(heroes[turno].getDamage()*skillDamage));
                            cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                        }
                        if(enemigos[i].getHealth()<=0){
                            cout << "El objetivo ha sido derribado" << endl;
                        }else{
                            cout << "Vida del enemigo impactado " << i << ": " << enemigos[i].getHealth() << endl;
                        }
                    }else{
                        cout << "Fallaste el ataque" << endl;
                    }
                }
            }
            for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                }
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
    }
}
void Ataque::PlagueDoctorSkill_BlindingGas(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hit;
    int hitcritical;
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
                            cout << "El enemigo ha recibido un golpe critico!" << endl;
                            cout << "DMG del ataque: " << ((heroes[turno].getDamage()*skillDamage)*1.5) << endl;
                        }else{
                            enemigos[i].setHealth(enemigos[i].getHealth()-(heroes[turno].getDamage()*skillDamage));
                            cout << "DMG del ataque: " << (heroes[turno].getDamage()*skillDamage) << endl;
                        }
                        if(enemigos[i].getHealth()<=0){
                            cout << "El objetivo ha sido derribado" << endl;
                        }else{
                            cout << "Vida del enemigo impactado " << i << ": " << enemigos[i].getHealth() << endl;
                        }
                    }else{
                        cout << "Fallaste el ataque" << endl;
                    }
                }
            }
            for(int i=0;i<4;i++){
                if(enemigos[i].getHealth()>0){
                    cout << "Vida del enemigo " << i << ": " << enemigos[i].getHealth() << endl;
                }
            }
        }else{
            cout << "No es posible atacar desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
    }
}
/*Actualmente roto para compensar que no cura debuffs*/
void Ataque::PlagueDoctorSkill_BattlefieldMedicine(int turno, Heroe heroes[4], Enemigo enemigos[4]){
    int hitcritical;
    int target;
    int rangeMin = 0;
    int rangeMax = 3;
    int objetivos = 4;
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0&&heroes[i].getHealth()==heroes[i].getMaxHealth()){
            objetivos--;
        }
    }
    if(objetivos>0){
        if(heroes[turno].getPosition()>1){
            do{
                cout << "Objetivos disponibles:" << endl;
                for(int i=rangeMin;i<=rangeMax;i++){
                    if(heroes[i].getHealth()>0&&heroes[i].getHealth()<heroes[i].getMaxHealth()){
                    cout << i << ".- " << heroes[i].getName() << endl;
                    }
                }
                cout << "Ingresa el objetivo: ";
                cin >> target;
            }while((target<rangeMin||target>rangeMax)||heroes[target].getHealth()<=0||heroes[target].getHealth()==heroes[target].getMaxHealth());
            heroes[turno].setCritic(12);
            hitcritical = rand()%100;
            if(hitcritical<heroes[turno].getCritic()){
                heroes[target].setHealth(heroes[target].getHealth()+(9*1.5));
                cout << "El heroe ha sido sanado perfectamente!" << endl;
                cout << "Sanacion de la habilidad: " << (9*1.5) << endl;
            }else{
                heroes[target].setHealth(heroes[target].getHealth()+9);
                cout << "Sanacion de la habilidad: " << 9 << endl;
            }
            if(heroes[target].getHealth()>heroes[target].getMaxHealth()){
                heroes[target].setHealth(heroes[target].getMaxHealth());
            }
            cout << "Vida del heroe asistido " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
            for(int i=0;i<4;i++){
                if(heroes[i].getHealth()>0){
                    cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                }
            }
        }else{
            cout << "No es posible desde esta posicion" << endl;
        }
    }else{
        cout << "No hay objetivos" << endl;
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
    srand(time(NULL));
    for(int i=rangeMin;i<=rangeMax;i++){
        if(heroes[i].getHealth()<=0){
            objetivos--;
        }
    }
    if(objetivos>0){
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
                    cout << "El heroe ha recibido un golpe critico!" << endl;
                    cout << "DMG del ataque: " << ((enemigos[turno].getDamage())*1.5) << endl;
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-(enemigos[turno].getDamage()));
                    cout << "DMG del ataque: " << (enemigos[turno].getDamage()) << endl;
                }
                if(heroes[target].getHealth()<=0){
                    cout << "El heroe ha sido derribado" << endl;
                }else{
                    cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth() << endl;
                }
                for(int i=0;i<4;i++){
                    if(heroes[i].getHealth()>0){
                        cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth() << endl;
                    }
                }
            }else{
                cout << "El enemigo fallo el ataque" << endl;
            }
        }else{
            cout << "El enemigo no puede atacar desde esta posicion" << endl;
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
        if(enemigos[turno].getPosition()==3){
            hit = rand()%100;
            target = 3;
            enemigos[turno].setCritic(1);
            enemigos[turno].setAccuracy(50);
            if(hit<(enemigos[turno].getAccuracy()-heroes[target].getDodge())){
                hitcritical = rand()%100;
                if(hitcritical<enemigos[turno].getCritic()){
                    heroes[target].setHealth(heroes[target].getHealth()-((((enemigos[turno].getDamage()*skillDamage)*1.5))));
                    cout << "El heroe ha recibido un golpe critico!" << endl;
                    cout << "DMG del ataque: " << ((enemigos[turno].getDamage())*1.5) << endl;
                }else{
                    heroes[target].setHealth(heroes[target].getHealth()-(enemigos[turno].getDamage()));
                    cout << "DMG del ataque: " << (enemigos[turno].getDamage()) << endl;
                }
                if(heroes[target].getHealth()<=0){
                    cout << "El heroe ha sido derribado" << endl;
                }else{
                    cout << "Vida del heroe impactado " << target << ": " << heroes[target].getHealth() << " / " << heroes[target].getMaxHealth()<< endl;
                }
                for(int i=0;i<4;i++){
                    if(heroes[i].getHealth()>0){
                        cout << "Vida del heroe " << i << ": " << heroes[i].getHealth() << " / " << heroes[i].getMaxHealth()<< endl;
                    }
                }
            }else{
                cout << "El enemigo fallo el ataque" << endl;
            }
        }else{
            cout << "El enemigo no puede atacar desde esta posicion" << endl;
        }
    }
}
