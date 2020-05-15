#include "Heroe.h"
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <strings.h>

using namespace std;

/*Constructores*/
Heroe::Heroe(char name[], int maxHealth,int health, int accuracy, int damage, int critic, int dodge, int protection, int position,
int chanceBleed, int chancePoison, int chanceStun, int chanceDie, int bleed, int poison, int stun){
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
    this->chanceDie = chanceDie;
    this->bleed = bleed;
    this->poison = poison;
    this->stun = stun;
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
void Heroe::setChanceBleed(int chanceBleed){
    this->chanceBleed = chanceBleed;
}
void Heroe::setChancePoison(int chancePoison){
    this->chancePoison = chancePoison;
}
void Heroe::setChanceStun(int chanceStun){
    this->chanceStun = chanceStun;
}
void Heroe::setChanceDie(int chanceDie){
    this->chanceDie = chanceDie;
}
void Heroe::setBleed(int chanceBleed){
    this->chanceBleed = chanceBleed;
}
void Heroe::setPoison(int chancePoison){
    this->chancePoison = chancePoison;
}
void Heroe::setStun(int chanceStun){
    this->chanceStun = chanceStun;
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
int Heroe::getChanceBleed(){
    return this->chanceBleed;
}
int Heroe::getChancePoison(){
    return this->chancePoison;
}
int Heroe::getChanceStun(){
    return this->chanceStun;
}
int Heroe::getChanceDie(){
    return this->chanceDie;
}
int Heroe::getBleed(){
    return this->bleed;
}
int Heroe::getPoison(){
    return this->poison;
}
int Heroe::getStun(){
    return this->stun;
}
