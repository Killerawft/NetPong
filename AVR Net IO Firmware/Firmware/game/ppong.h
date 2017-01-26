/*
   Gamebox
    Copyright (C) 2004-2006  by Malte Marwedel
    m.marwedel AT onlinehome dot de

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef PPONG_H
 #define PPONG_H


#define BALL_SIZE           3                                       //Radius des Balls
#define PLAYER_SIZE         10                                      //Breite des Spielerbalkens, muss durch 2 teilbar sein
#define FIELD_SIZE          64                                      //Feldgr��e -> Feld ist immer rechteckig
#define FIELD_SPACE         32                                      //Bereich neben dem Feld

#define PLAYER_1_RANGE      FIELD_SPACE + 2                         //Bereich f�r Linken Spielerbalken auf X Achse
#define PLAYER_2_RANGE      FIELD_SPACE + FIELD_SIZE - 2            //Bereich f�r Rechten Spielerbalken auf X Achse
#define PLAYER_LINE_START   (FIELD_SIZE / 2) - (PLAYER_SIZE / 2)    //Startpunkt des Spielerbalkens auf Y Achse
#define FIELD_CENTER_X      FIELD_SPACE + (FIELD_SIZE / 2)          //X Mittelpunkt des Feldes
#define FIELD_CENTER_Y      (FIELD_SIZE / 2)                        //Y Mittelpunkt des Feldes


#include "../config.h"
#include "glcd.h"


struct pong_ballstruct{
    s08 speedx;
    s08 speedy;
    u08 posx;
    u08 posy;
};

struct pong_playerstruct{
    u08 posy;
    u08 posyo;
};

struct pong_ballstruct ball = {0, 0, FIELD_CENTER_X, FIELD_CENTER_Y};
struct pong_playerstruct player[2] = {{PLAYER_LINE_START, 0},{PLAYER_LINE_START, 0}};

void pong_init();
void draw_start_screen();


#endif
