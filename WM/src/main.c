#include "../includes/vm.h"

void			errrorrororo(void)
{
	ft_printf("MGRN(Usage: ./corewar [-d N] [-dump N] [-v] [-l N] [-n N{1 - 4}] {champ_name.cor , ...})\n");
	ft_printf("\tMRED(-d)\tMRED(Print Battlefield in 64 octets in a row)\n");
	ft_printf("\tMRED(-dump)\tMBLU(Print Battlefield in 32 octets in row)\n");
	ft_printf("\tMRED(-v)\tMYLW(Turn on a Visualisation\n");
	ft_printf("\tMRED(-l)\tMCYN(Verbosity levels)\n");
	ft_printf("\tMRED(-n)\tMPRP(Set player Number  N)\n");
	exit(0);
}

int main(int argc, char **argv)
{
	st.aff = 1;
	parsing_argc(argc, argv);
	_ERR_CHAMP(g_gen.champ[0].length);
	create_field();
	set_karetu();
	print_last_alive();
	system("leaks corewar");
}
