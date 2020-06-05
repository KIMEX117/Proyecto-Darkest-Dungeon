#ifndef ATAQUE_H
#define ATAQUE_H
#include "Heroe.h"
#include "Enemigo.h"

class Ataque
{
    private:
    public:
        Ataque();
        void gotoxyAtaque(int,int);
        void limpiarHabilidades();
        /*Habilidades compartidas*/
        void SharedHeroSkill_Move(int,Heroe*);
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
        void VestalSkill_Judgement(int,Heroe*,Enemigo*);
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
        /*Ballestero esqueleto*/
        void ArbalistSkill_Quarrel(int,Heroe*,Enemigo*);
        void ArbalistSkill_BayonetJab(int,Heroe*,Enemigo*);
        /*Defensor esqueleto*/
        void DefenderSkill_AxeBlade(int,Heroe*,Enemigo*);
        void DefenderSkill_DeadWeight(int,Heroe*,Enemigo*);
        void DefenderSkill_ClumsyAxeBlade(int,Heroe*,Enemigo*);
        /*Capitan esqueleto*/
        void CaptainSkill_CrushingBlow(int,Heroe*,Enemigo*);
        void CaptainSkill_GroundPound(int,Heroe*,Enemigo*);
        /*Necromancer*/
        void NecromancerSkill_WillingFlesh(int,Heroe*,Enemigo*);
        void NecromancerSkill_CrawlingDead(int,Heroe*,Enemigo*);
        void NecromancerSkill_SixFeetUnder(int,Heroe*,Enemigo*);
};

#endif // ATAQUE_H
