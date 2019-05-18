/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:28:09 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 12:28:10 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdio.h>
# include <stdlib.h>
# include "op.h"
# include "../libft/includes/libft.h"
# include "operations.h"
# include "vis.h"
# include <locale.h>

# define ER_START	"\033[41m"
# define ER_END		"\033[40m"
# define ERROR_MALLOC(ex) if(!(ex)) {ERROR("ERROR IN ALLOCATION MEMMORY")};
# define ERROR(ex) {printf("%s%s%s\n",ER_START,ex,ER_END);errrorrororo();}
# define SET_CHAMP(ex) {ft_strcat(ex, chmp); return ;}
# define READ_CHAMP(ex, name) {read_champ(ex,name);return ;}
# define ERR_CHAMP(ex) {if (!ex) ERROR("Missing first champ");}
# define SET_L(ex) {if (ex == 3){g_gen.flag_l = true;}g_gen.log = a;}
# define SET_DUMP_D(ex) {if (ex == 2){g_gen.flag_d = true;}g_gen.flag_dump_d = a;}
# define SET_DUMP(ex) {if (ex == 1){g_gen.flag_dump = true;}g_gen.flag_dump_d = a;}
# define SET_DUMPS(ex) {SET_DUMP(ex);SET_DUMP_D(ex);SET_L(ex);}
# define DIE g_gen.cycles_to_die
# define AM_I_DIE DIE == g_gen.cycles_after_check || g_gen.cycles_to_die <= 0
# define FD g_gen.flag_d
# define READING(ex, ex2) if(ex) {ERROR(ex2);}
# define SET_OOP(ex) ex = g_gen.field[kareta->pos];
# define CWAIT(ex) ex = g_op[kareta->code - 1].cycles;
# define POOP g_gen.field[kareta->pos] >= 0x01 && g_gen.field[kareta->pos] <= 0x10
# define VS {if (g_gen.flag_visual){vs_update_stats(&g_gen.v);vs_update_main(&g_gen.v);}}
# define FDUMP g_gen.flag_dump
# define RAVNO g_gen.flag_dump_d == g_gen.cycles
# define PBF if (_RAVNO && (_FD || FDUMP)){_PRINT_B}
# define CHECK_VISUALISATION {if (g_gen.flag_visual == true){vs_main();}VS;}
# define CHECK_WAIT kareta->code >= 0x01 && kareta->code <= 0x10
# define LOG(ex, ex1) {if (g_gen.log == 2){logs(ex, ex1, 1);}}
# define PREPARE(ex) {g_gen.cycles++;g_gen.cycles_after_check++;ex = g_gen.kareta;}
# define PRINT_B2 {if (g_gen.flag_dump)print_field(32);exit(13);}
# define PRINT_B {if (g_gen.flag_d){print_field(64);}PRINT_B2;}
# define CHECKSSS g_gen.check_in == MAX_CHECKS || g_gen.live_in >= NBR_LIVE
# define CYCLE_D {g_gen.cycles_to_die -= CYCLE_DELTA;g_gen.check_in = 0;}
# define IS_CYCLE if  (CHECKSSS){CYCLE_D}
# define ZERO {	g_gen.live_in = 0;	g_gen.cycles_after_check = 0;}
# define REGO reg = g_gen.field[adress(pos + step)];
# define PREP_ARGC {i = 0;step = (1 + (oop->args_types_code ? 1 : 0));}
# define LIVE {id = what_opp(kareta, 1, 0);g_gen.live_in++;champ = NULL;}
# define LIVE2 {champ = &g_gen.champ[id - 1];champ->last_alive = g_gen.cycles;}
# define LIVE3 {champ->live++;g_gen.last_alive = id - 1;}
# define LD {value = what_opp(kareta, 1, 1);kareta->carry = !value;}
# define LD2 {kareta->reg[reg - 1] = value;kareta->step += REG_LEN;}
# define STBLYAT {i = kareta->reg[reg - 1];kareta->step += REG_LEN;}
# define ST1 {kareta->reg[addr - 1] = i;kareta->step += REG_LEN;}
# define SSST {addr = g_gen.field[adress(kareta->pos + kareta->step)];ST1;}
# define AD1 kareta->step += REG_LEN;
# define ADD(ex) {ex = g_gen.field[adress(kareta->pos + kareta->step)];AD1}
# define REPLACE {new->next = g_gen.kareta;g_gen.kareta = new;g_gen.am_karet++;}

int			karettta(int i);
bool		is_dat_is_a_child(int i);
void		errrorrororo(void);
void		check_who_die();
void		next_op(t_kareta *kareta);
void		print_field(int i);
int			adress(int i);
int			what_opp(t_kareta *kareta, uint8_t i, int mod);
void		read_champ(int a, char *file_name);
int32_t		byte_to_int(int32_t addr, int32_t size);
void		int_to_byte(int32_t addr, int32_t value, int32_t size);
void		set_field(int32_t addr, uint8_t i, int32_t size);
void		create_field(void);
int			how_m_steps(uint8_t type, t_operation *oop);
int8_t		count_size(int pos, int step);
bool		check_args(t_kareta *kareta, t_operation *oop);
bool		val_argc(t_kareta *kareta, t_operation *oop);
void		r_arg(t_kareta *kareta, t_operation *oop);
t_kareta	*copy_kareta(t_kareta *kareta, int32_t addr);
void		what_is_a_letter(char c, t_champ a);
void		big_letter(char c, t_champ a);
void		add_elem(t_kareta **list, int pos);
void		print_list(t_kareta *list);
void		set_karetu();
int			g_farewell(t_kareta *kareta, t_operation *operation);
void		logs(int i, int d, int mode);
void		parsing_argc(int argc, char **argv);
int			check_where(char *where);
void		swap(t_champ *first, t_champ *second);
void		print_info_champs();
void		print_last_alive();
void		print_player_code();
void		jason_born(void);
void		set_operation(t_kareta *kareta);
void		do_func(t_kareta *kareta);
void		set_ukr_names(void);
void		set_death(void);
void		set_music(void);
void		kill_sounds(void);
int32_t		bytecode_to_int32(uint8_t *bytecode, int size);
#endif
