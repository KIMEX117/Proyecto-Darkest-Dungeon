#ifndef HEROE_H
#define HEROE_H

class Heroe
{
    private:
        char name[100];
        int maxHealth;
        int health;
        int accuracy;
        int damage;
        int critic;
        int dodge;
        int protection;
        int position;
    public:
        /*Constructores*/
        Heroe(char[],int,int,int,int,int,int,int,int);
        Heroe();
        /*Metodos Set*/
        void setName(char[]);
        void setMaxHealth(int);
        void setHealth(int);
        void setAccuracy(int);
        void setDamage(int);
        void setCritic(int);
        void setDodge(int);
        void setProtection(int);
        void setPosition(int);
        /*Funciones Get*/
        char * getName();
        int getMaxHealth();
        int getHealth();
        int getAccuracy();
        int getDamage();
        int getCritic();
        int getDodge();
        int getProtection();
        int getPosition();
};
#endif // HEROE_H
