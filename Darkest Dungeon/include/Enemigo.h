#ifndef ENEMIGO_H
#define ENEMIGO_H

class Enemigo
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
        Enemigo(char[],int,int,int,int,int,int,int,int);
        Enemigo();
        /*Habilidades De Combate*/
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
        /*Metodos Get*/
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

#endif // ENEMIGO_H
