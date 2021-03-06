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

#ifndef _TEXT_H
 #define _TEXT_H

#if (screenx >= 250)
#warning "Die Funktion scrolltext() erzeugt bei einer Bildschirmbreite von mehr als 249 Pixel Fehler!"
#endif

#define CWDT        6        //Pixel breite eines Zeichens
#define CHGT        7        //Pixel H�he eines Zeichens
#define CTP_X(x)    x*CWDT+1 //X Buchstaben umrechnen in Pixelanzahl auf x achse
#define CTP_Y(x)    x*CHGT   //X Buchstaben umrechnen in Pixelanzahl auf y achse

/* draw_char pr�ft, vor dem schreiben auf das Display ob die Position
innerhalb des g�ltigen Bereiches ist. Daher sind f�r posx und posy auch negative
oder zu gro�e Werte kein Problem. Die Buchstaben sind dann normalerweise nicht
sichtbar.
Im schlimmsten Fall werden sie an die falsche Stelle auf dem Display gezeichnet.
*/
uint8_t draw_char(uint8_t zeichen, uint8_t posx, uint8_t posy, uint8_t color, uint8_t turn); //turn = 0 => Normal; turn = 1 =>90� IUZ; turn = 2 => 90� GUZ; Somit Playernr + 1 => Text f�r den Spieler richtig gedreht

void draw_string(char* c,uint8_t posx, uint8_t posy, uint8_t color, uint8_t turn);

void scrolltext(char* c, uint8_t posy, uint8_t color, uint8_t bcolor, uint8_t waittime);

void draw_tinydigit(uint8_t ziffer, uint8_t posx,uint8_t posy, uint8_t color);

void draw_tinynumber(uint16_t value, uint8_t posx, uint8_t posy, uint8_t color);

#endif
