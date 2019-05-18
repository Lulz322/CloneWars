/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:44:14 by amatveie          #+#    #+#             */
/*   Updated: 2019/05/17 12:44:16 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIS_H
# define VIS_H

typedef struct	s_print
{
	int			y;
	int			x;
	int			i;
	int			color;
	int			k;
}				t_print;

# define RED_BLACK 1
# define YELLOW_BLACK 2
# define BLUE_BLACK 3
# define GREEN_BLACK 4
# define GRAY_BLACK 5
# define WHITE_BLACK 6
# define BLACK_RED 11
# define BLACK_YELLOW 12
# define BLACK_BLUE 13
# define BLACK_GREEN 14
# define BLACK_GREY 15
# define WHITE_RED 21
# define WHITE_YELLOW 22
# define WHITE_BLUE 23
# define WHITE_GREEN 24
# define WHITE_GREY 25

# define KOLBASKA "[------------------------------------------------------]"

# define WIN1 " __       __  __"
# define WIN2 "/  |  _  /  |/  |"
# define WIN3 "$$ | / \\ $$ |$$/  _______   _______   ______    ______"
# define WIN4 "$$ |/$ \\ $$ |/ | /       \\ /      \\ /       \\  /       \\"
# define WIN5 "$$ /$$$  $$ |$$ |$$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$ |"
# define WIN6 "$$ $$/$$ $$ |$$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$/"
# define WIN7 "$$$$/  $$$$ |$$ |$$ |  $$ |$$ |  $$ |$$$$$$$$/ $$ |"
# define WIN8 "$$$/    $$$ |$$ |$$ |  $$ |$$ |  $$ |$$       |$$ |"
# define WIN9 "$$/      $$/ $$/ $$/   $$/ $$/   $$/  $$$$$$$/ $$/"

# define C1 " ______   __        __            __"
# define C2 "/      \\ /  |      /  |          /  |"
# define C3 "/$$$$$$  |$$ |____  $$/   _______ $$ |   __   ______   _______"
# define Y "$$ |  $$/ $$     \\  /  | /       |$$ |  /  | /      \\ /       \\ "
# define C5 "$$ |      $$$$$$$  |$$ |/$$$$$$$/ $$ |_/$$/ /$$$$$$  |$$$$$$$  |"
# define C6 "$$ |   __ $$ |  $$ |$$ |$$ |      $$   $$<  $$    $$ |$$ |  $$ |"
# define L "$$\\ __/  |$$ |  $$ |$$ |$$\\ _____ $$$$$$ \\  $$$$$$$$/ $$ |  $$ |"
# define C8 "$$    $$/ $$ |  $$ |$$ |$$       |$$ | $$  |$$       |$$ |  $$ |"
# define C9 " $$$$$$/  $$/   $$/ $$/  $$$$$$$/ $$/   $$/  $$$$$$$/ $$/   $$/"

# define D1 " ______   __"
# define D2 "/      \\ /  |"
# define D3 "$$$$$$$  |$$/  _______   _______    ______    ______"
# define D4 "$$ |  $$ |/  |/       \\ /       \\  /       \\ /      \\"
# define D5 "$$ |  $$ |$$ |$$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$  |"
# define D6 "$$ |  $$ |$$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$/"
# define D7 "$$ |__$$ |$$ |$$ |  $$ |$$ |  $$ |$$$$$$$$/ $$ |"
# define D8 "$$    $$/ $$ |$$ |  $$ |$$ |  $$ |$$       |$$ |"
# define D9 "$$$$$$$/  $$/ $$/   $$/ $$/   $$/  $$$$$$$/ $$/"

# define Z "#######  ######  ######   ######  ##     ##   #####   ######   ####"
# define O "##   ##  ##      ##   ##  ##      ###   ###  ##   ##  ##      ## ##"
# define P "##   ##  ##      ##   ##  ##      ## # # ##  ##   ##  ##     ##  ##"
# define X "##   ##  #####   ######   #####   ##  V  ##  ##   ##  ##    ##   ##"
# define B "##   ##  ##      ##       ##      ##     ##  ##   ##  ##    #######"
# define K "##   ##  ##      ##       ##      ##     ##  ##   ##  ##    ##   ##"
# define J "##   ##  ######  ##       ######  ##     ##   #####   ##    ##   ##"

# define G3 "#*                   "
# define G4 "                  *##*                  "
# define G5 "     ##           ####           ##     "
# define G6 "     ####         ####         ####     "
# define G7 "     #####*       ####       ######     "
# define G8 "     ##* ###      ###*      ### ###     "
# define G9 "     ##*  ##*     *##*     *##  ###     "
# define G10 "     ##*  *##     *##*     ##*  ###     "
# define G11 "     ##*   ##     *##*     ##   ###     "
# define G12 "     ##*   ##*    *##*    *##   ###     "
# define G13 "     ##*   ###    ####    ###   ###     "
# define G14 "     ##*   *##    ####    ##*   ###     "
# define G15 "     ##*  ####   #####*   ####  ###     "
# define G16 "     ##* ###    *##  ##     ### ###     "
# define G17 "     ##* ##     ##*  *##     ## ###     "
# define G18 "     ##* *###  ##     *##  ###* ###     "
# define G19 "     ##*      ## *#  # *##      ###     "
# define G20 "     ##*     ###  ####  ##*     ###     "
# define G21 "     ###********* *##  *********###     "
# define G22 "     ############ *## *############     "
# define G23 "              ### *##  ###              "
# define G24 "               #########*               "
# define G25 "                 ######                 "

# define EN1 "*** STATISTICS ***"
# define UA1 "*** СЛАВА УКРАЇНІ! ***"
# define EN2 "Execution status:"
# define UA2 "Статус виконання:"
# define UA3 "Живі каретки:"
# define EN3 "Carries alive:"
# define UA4 "Цикли померти: %d"
# define EN4 "Cycles to die: %d"
# define UA5 "ДЕЛЬТА ЦИКЛ: "
# define EN5 "CYCLE_DELTA: "
# define EN6 "Player %d: "
# define UA6 "Гравець %d: "
# define EN7 "Last cycle alive: "
# define UA7 "Останній живий цикл: "
# define EN8 "Cycles reported alive: "
# define UA8 "Цикли повідомл. живими: "

# define TRD "\xF0\x9F\x94\xB1"

void			vs_print_42(t_vis *v, int mod);
void			vs_check_key_events(t_vis *v);
void			vs_init_color(void);
void			vs_main(void);
void			vs_announce_winner(int i, int j, int o);
void			vs_update_stats(t_vis *v);
void			vs_update_main(t_vis *v);
void			vs_prepare_stat(t_vis *v);
void			vs_print_players(t_vis *v);

#endif
