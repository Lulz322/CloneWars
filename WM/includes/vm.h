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
# define SET_L(ex) {if (ex == 3){ST.flag_l = true;}ST.log = a;}
# define SET_DUMP_D(ex) {if (ex == 2){ST.flag_d = true;}ST.flag_dump_d = a;}
# define SET_DUMP(ex) {if (ex == 1){ST.flag_dump = true;}ST.flag_dump_d = a;}
# define SET_DUMPS(ex) {SET_DUMP(ex);SET_DUMP_D(ex);SET_L(ex);}
# define DIE ST.cycles_to_die
# define AM_I_DIE DIE == ST.cycles_after_check || ST.cycles_to_die <= 0
# define FD ST.flag_d
# define READING(ex, ex2) if(ex) {ERROR(ex2);}
# define SET_OOP(ex) ex = ST.field[kareta->pos];
# define CWAIT(ex) ex = g_op[kareta->code - 1].cycles;
# define POOP ST.field[kareta->pos] >= 0x01 && ST.field[kareta->pos] <= 0x10
# define VS {if (ST.flag_visual){vs_update_stats(&ST.v);vs_update_main(&ST.v);}}
# define FDUMP ST.flag_dump
# define RAVNO ST.flag_dump_d == ST.cycles
# define PBF if (_RAVNO && (_FD || FDUMP)){_PRINT_B}
# define CHECK_VISUALISATION {if (ST.flag_visual == true){vs_main();}VS;}
# define CHECK_WAIT kareta->code >= 0x01 && kareta->code <= 0x10
# define LOG(ex, ex1) {if (ST.log == 2){logs(ex, ex1, 1);}}
# define PREPARE(ex) {ST.cycles++;ST.cycles_after_check++;ex = ST.kareta;}
# define PRINT_B2 {if (ST.flag_dump)print_field(32);exit(13);}
# define PRINT_B {if (ST.flag_d){print_field(64);}PRINT_B2;}
# define CHECKSSS ST.check_in == MAX_CHECKS || ST.live_in >= NBR_LIVE
# define CYCLE_D {ST.cycles_to_die -= CYCLE_DELTA;ST.check_in = 0;}
# define IS_CYCLE if  (CHECKSSS){CYCLE_D}
# define ZERO {	ST.live_in = 0;	ST.cycles_after_check = 0;}
# define REGO reg = ST.field[adress(pos + step)];
# define PREP_ARGC {i = 0;step = (1 + (oop->args_types_code ? 1 : 0));}
# define LIVE {id = what_opp(kareta, 1, 0);ST.live_in++;champ = NULL;}
# define LIVE2 {champ = &ST.champ[id - 1];champ->last_alive = ST.cycles;}
# define LIVE3 {champ->live++;ST.last_alive = id - 1;}
# define LD {value = what_opp(kareta, 1, 1);kareta->carry = !value;}
# define LD2 {kareta->reg[reg - 1] = value;kareta->step += REG_LEN;}
# define STBLYAT {i = kareta->reg[reg - 1];kareta->step += REG_LEN;}
# define ST1 {kareta->reg[addr - 1] = i;kareta->step += REG_LEN;}
# define SSST {addr = ST.field[adress(kareta->pos + kareta->step)];ST1;}
# define AD1 kareta->step += REG_LEN;
# define ADD(ex) {ex = ST.field[adress(kareta->pos + kareta->step)];AD1}
# define REPLACE {new->next = ST.kareta;ST.kareta = new;ST.am_karet++;}
# define ST g_gen

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
void		set_death(void);
void		set_music(void);
void		kill_sounds(void);
int32_t		bytecode_to_int32(uint8_t *bytecode, int size);
#endif
