#ifndef ATAQUE_H
#define ATAQUE_H
#include "Heroe.h"
#include "Enemigo.h"

class Ataque
{
    private:
    public:
        Ataque();
        /*Habilidades De Combate compartidas*/
        void SharedHeroSkill_Move(int,Heroe*);
        void SharedEnemySkill_Move(int,Enemigo*);
        /*Cruzado*/
        void CrusaderSkill_Smite(int,Heroe*,Enemigo*);
        void CrusaderSkill_StunningBlow(int,Heroe*,Enemigo*);
        void CrusaderSkill_ZealousAccusation(int,Heroe*,Enemigo*);
        void CrusaderSkill_BattleHeal(int,Heroe*,Enemigo*);
        /*Pistolero*/
        void HighwaymanSkill_Slice(int,Heroe*,Enemigo*);
        void HighwaymanSkill_OpenVein(int,Heroe*,Enemigo*);
        void HighwaymanSkill_PistolShot(int,Heroe*,Enemigo*);
        void HighwaymanSkill_Grapeshot(int,Heroe*,Enemigo*);
        /*Vestal*/
        void VestalSkill_MaceBash(int,Heroe*,Enemigo*);
        void VestalSkill_DazzlingLight(int,Heroe*,Enemigo*);
        void VestalSkill_DivineGrace(int,Heroe*,Enemigo*);
        void VestalSkill_DivineComfort(int,Heroe*,Enemigo*);
        /*Doctor de Plaga*/
        void PlagueDoctorSkill_NoxiousBlast(int,Heroe*,Enemigo*);
        void PlagueDoctorSkill_PlagueGrenade(int,Heroe*,Enemigo*);
        void PlagueDoctorSkill_BlindingGas(int,Heroe*,Enemigo*);
        void PlagueDoctorSkill_BattlefieldMedicine(int,Heroe*,Enemigo*);
        /*Soldado esqueleto*/
        void SoldierSkill_GraveyardSlash(int,Heroe*,Enemigo*);
        void SoldierSkill_GraveyardStumble(int,Heroe*,Enemigo*);
};

#endif // ATAQUE_H
