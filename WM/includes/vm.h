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
# define SET_DUMP_D(ex) {if(ex == 2){FD = true;}g_gen.flag_dump_d = a;}
# define SET_DUMP(ex) {if(ex == 1){FDUMP = true;}g_gen.flag_dump_d = a;}
# define SET_DUMPS(ex) {SET_DUMP(ex);SET_DUMP_D(ex);SET_L(ex);}
# define DIE g_gen.cycles_to_die
# define AM_I_DIE DIE == g_gen.cycles_after_check || g_gen.cycles_to_die <= 0
# define READING(ex, ex2) if(ex) {ERROR(ex2);}
# define POOP g_gen.field[kareta->pos] >= 0x01&&g_gen.field[kareta->pos] <= 0x10
# define FD g_gen.flag_d
# define FDUMP g_gen.flag_dump
# define RAVNO g_gen.flag_dump_d == g_gen.cycles
# define CHECKSSS g_gen.check_in == MAX_CHECKS || g_gen.live_in >= NBR_LIVE
# define PREP_ARGC {step = (1 + (oop->args_types_code ? 1 : 0));}

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
void		set_wait_time(t_kareta *kareta);
t_operation	*set_func(t_kareta *kareta);
t_kareta	*u_are_not_prepeare();
void		set_ukr_names(void);
void		set_death(void);
void		set_music(void);
void		kill_sounds(void);
void		gavno(void);
int32_t		set_reg(t_kareta *kareta);
int32_t		bytecode_to_int32(uint8_t *bytecode, int size);
#endif
