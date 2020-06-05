#include "Enemigo.h"
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <strings.h>

using namespace std;

Enemigo::Enemigo(char name[100], int maxHealth, int health, int accuracy, int damage, int critic, int dodge, int protection, int position){
    strcpy(this->name,name);
    this->maxHealth = maxHealth;
    this->health = health;
    this->accuracy = accuracy;
    this->damage = damage;
    this->critic = critic;
    this->dodge = dodge;
    this->protection = protection;
    this->position = position;
}
Enemigo::Enemigo(){}
/*Metodos Set*/
void Enemigo::setName(char name[]){
    strcpy(this->name,name);
}
void Enemigo::setMaxHealth(int maxHealth){
    this->maxHealth = maxHealth;
}
void Enemigo::setHealth(int health){
    this->health = health;
}
void Enemigo::setAccuracy(int accuracy){
    this->accuracy = accuracy;
}
void Enemigo::setDamage(int damage){
    this->damage = damage;
}
void Enemigo::setCritic(int critic){
    this->critic = critic;
}
void Enemigo::setDodge(int dodge){
    this->dodge = dodge;
}
void Enemigo::setProtection(int protection){
    this->protection = protection;
}
void Enemigo::setPosition(int position){
    this->position = position;
}
/*Metodos Get*/
char * Enemigo::getName(){
    return this->name;
}
int Enemigo::getMaxHealth(){
    return this->maxHealth;
}
int Enemigo::getHealth(){
    return this->health;
}
int Enemigo::getAccuracy(){
    return this->accuracy;
}
int Enemigo::getDamage(){
    return this->damage;
}
int Enemigo::getCritic(){
    return this->critic;
}
int Enemigo::getDodge(){
    return this->dodge;
}
int Enemigo::getProtection(){
    return this->protection;
}
int Enemigo::getPosition(){
    return this->position;
}
