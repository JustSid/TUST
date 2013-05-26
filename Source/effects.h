#ifndef _EFFECTS_H_
#define _EFFECTS_H_

VECTOR vecEffectsTemp;

BMAP* bmapStar = "..\\Ressources\\Graphics\\star.bmp";
BMAP* bmapFlame = "..\\Ressources\\Graphics\\flame.bmp";
BMAP* bmapSmoke = "..\\Ressources\\Graphics\\smoke.tga";

void pFountain(PARTICLE *p);
void pDenseSmoke(PARTICLE *p);
void pStars(PARTICLE *p);
void pFlame(PARTICLE *p);
void pSmokeFlames(PARTICLE *p);

// Rain and snow effects can be found in weather.h/.c
void pElectro(PARTICLE *p);
void pLeaves(PARTICLE *p);
void pFlies(PARTICLE *p);
void pBubbles(PARTICLE *p);
void pWaterfall(PARTICLE *p);
void pExplosionFire(PARTICLE *p);
void pExplosionDust(PARTICLE *p);
void pExplosionScatter(PARTICLE *p);

// Internal

void pAlphaFade(PARTICLE *p);
void pAlphaFadeFlame(PARTICLE *p);

#include "effects.c"

#endif