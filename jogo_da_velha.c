/***************************************************************************
 *   jogo_da_velha.c                           Version 20220316.213500     *
 *                                                                         *
 *   Jogo da velha feito totalmente em C                                   *
 *   Copyright (C) 2016-2021    by Fernando Laguzza                        *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 3 of the License                *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Fernando Laguzza                                                      *
 *   Email: laguzzafernando@gmail.com                                      *
 *   Phone: +55 (87) 99150-3087                                            *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc. */

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    jogo();

    return 0;
}

void tabuleiro(char casas[3][3])
{
    system("cls");
    printf("\t %c | %c | %c\n", casas[0][0], casas[0][1], casas[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c\n", casas[1][0], casas[1][1], casas[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c\n", casas[2][0], casas[2][1], casas[2][2]);
}

void jogo(void)
{
    char casas[3][3]; /* casas do tabuleiro*/
    int vez = 0; /*Variavel que determina se a vez é do X ou do O*/
    int jogadas = 1; /* numero de jogadas*/
    int l, c = 0; /* numero da coordenada de linhas e colunas */
    int i, j = 0; /* General index*/
    char resposta = ' '; /* variável que armazena a resposta se o jogador deseja ou não jogar novamente*/
    do
    {
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                casas[i][j] = ' ';
            }
        }
        do
        {
            tabuleiro(casas);
            printf("Digite a linha: ");
            scanf("%i", &l);
            printf("Digite a coluna: ");
            scanf("%i", &c);
            if(l < 1 || c < 1 || l > 3 || c > 3) /* Se o numero da linha ou coluna for menor que 1 ou maior que 3, caracteriza como jogada invalida*/
            {
                l = 0;
                c = 0;
            }
            else if(casas[l-1][c-1] != ' ') /* Se a casa não estiver vazia, caractecteriza uma jogada invalida */
            {
                l = 0;
                c = 0;
            }
            else
            {
                if(vez % 2 == 0)
                {
                    casas[l-1][c-1] = 'X';
                }
                else
                {
                    casas[l-1][c-1] = 'O';
                }
                
                vez++;
                jogadas++;
            }

        }while(jogadas <= 9);

        printf("Deseja jogar novamente?(s/n)");
        scanf("%c", &resposta);
    } while(resposta == 's');
}
