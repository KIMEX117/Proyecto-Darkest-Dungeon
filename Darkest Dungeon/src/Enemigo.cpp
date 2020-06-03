#include "Enemigo.h"
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <strings.h>

using namespace std;

Enemigo::Enemigo(char name[100], int maxHealth, int health, int accuracy, int damage, int critic, int dodge, int protection, int position,
int chanceBleed, int chancePoison, int chanceStun, int bleed, int poison, int stun){
    strcpy(this->name,name);
    this->maxHealth = maxHealth;
    this->health = health;
    this->accuracy = accuracy;
    this->damage = damage;
    this->critic = critic;
    this->dodge = dodge;
    this->protection = protection;
    this->position = position;
    this->chanceBleed = chanceBleed;
    this->chancePoison = chancePoison;
    this->chanceStun = chanceStun;
    this->bleed = bleed;
    this->poison = poison;
    this->stun = stun;
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
void Enemigo::setChanceBleed(int chanceBleed){
    this->chanceBleed = chanceBleed;
}
void Enemigo::setChancePoison(int chancePoison){
    this->chancePoison = chancePoison;
}
void Enemigo::setChanceStun(int chanceStun){
    this->chanceStun = chanceStun;
}
void Enemigo::setBleed(int chanceBleed){
    this->chanceBleed = chanceBleed;
}
void Enemigo::setPoison(int chancePoison){
    this->chancePoison = chancePoison;
}
void Enemigo::setStun(int chanceStun){
    this->chanceStun = chanceStun;
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
int Enemigo::getChanceBleed(){
    return this->chanceBleed;
}
int Enemigo::getChancePoison(){
    return this->chancePoison;
}
int Enemigo::getChanceStun(){
    return this->chanceStun;
}
int Enemigo::getBleed(){
    return this->bleed;
}
int Enemigo::getPoison(){
    return this->poison;
}
int Enemigo::getStun(){
    return this->stun;
}
