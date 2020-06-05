#include "Heroe.h"
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <strings.h>

using namespace std;

/*Constructores*/
Heroe::Heroe(char name[], int maxHealth,int health, int accuracy, int damage, int critic, int dodge, int protection, int position){
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
Heroe::Heroe(){}
/*Metodos Set*/
void Heroe::setName(char name[]){
    strcpy(this->name,name);
}
void Heroe::setMaxHealth(int maxHealth){
    this->maxHealth = maxHealth;
}
void Heroe::setHealth(int health){
    this->health = health;
}
void Heroe::setAccuracy(int accuracy){
    this->accuracy = accuracy;
}
void Heroe::setDamage(int damage){
    this->damage = damage;
}
void Heroe::setCritic(int critic){
    this->critic = critic;
}
void Heroe::setDodge(int dodge){
    this->dodge = dodge;
}
void Heroe::setProtection(int protection){
    this->protection = protection;
}
void Heroe::setPosition(int position){
    this->position = position;
}
/*Metodos Get*/
char * Heroe::getName(){
    return this->name;
}
int Heroe::getMaxHealth(){
    return this->maxHealth;
}
int Heroe::getHealth(){
    return this->health;
}
int Heroe::getAccuracy(){
    return this->accuracy;
}
int Heroe::getDamage(){
    return this->damage;
}
int Heroe::getCritic(){
    return this->critic;
}
int Heroe::getDodge(){
    return this->dodge;
}
int Heroe::getProtection(){
    return this->protection;
}
int Heroe::getPosition(){
    return this->position;
}
