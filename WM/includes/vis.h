#ifndef VIS_H
#define VIS_H

#define RED_BLACK 1
#define YELLOW_BLACK 2
#define BLUE_BLACK 3
#define GREEN_BLACK 4
#define GRAY_BLACK 5
#define WHITE_BLACK 6
#define BLACK_RED 11
#define BLACK_YELLOW 12
#define BLACK_BLUE 13
#define BLACK_GREEN 14
#define BLACK_GREY 15
#define WHITE_RED 21
#define WHITE_YELLOW 22
#define WHITE_BLUE 23
#define WHITE_GREEN 24
#define WHITE_GREY 25

#define KOLBASKA "[------------------------------------------------------]"

#define WIN1 " __       __  __"
#define WIN2 "/  |  _  /  |/  |"
#define WIN3 "$$ | / \\ $$ |$$/  _______   _______   ______    ______"
#define WIN4 "$$ |/$ \\ $$ |/ | /       \\ /      \\ /       \\  /       \\"
#define WIN5 "$$ /$$$  $$ |$$ |$$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$ |"
#define WIN6 "$$ $$/$$ $$ |$$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$/"
#define WIN7 "$$$$/  $$$$ |$$ |$$ |  $$ |$$ |  $$ |$$$$$$$$/ $$ |"
#define WIN8 "$$$/    $$$ |$$ |$$ |  $$ |$$ |  $$ |$$       |$$ |"
#define WIN9 "$$/      $$/ $$/ $$/   $$/ $$/   $$/  $$$$$$$/ $$/"

#define C1 " ______   __        __            __"
#define C2 "/      \\ /  |      /  |          /  |"
#define C3 "/$$$$$$  |$$ |____  $$/   _______ $$ |   __   ______   _______"
#define C4 "$$ |  $$/ $$     \\  /  | /       |$$ |  /  | /      \\ /       \\ "
#define C5 "$$ |      $$$$$$$  |$$ |/$$$$$$$/ $$ |_/$$/ /$$$$$$  |$$$$$$$  |"
#define C6 "$$ |   __ $$ |  $$ |$$ |$$ |      $$   $$<  $$    $$ |$$ |  $$ |"
#define C7 "$$\\ __/  |$$ |  $$ |$$ |$$\\ _____ $$$$$$ \\  $$$$$$$$/ $$ |  $$ |"
#define C8 "$$    $$/ $$ |  $$ |$$ |$$       |$$ | $$  |$$       |$$ |  $$ |"
#define C9 " $$$$$$/  $$/   $$/ $$/  $$$$$$$/ $$/   $$/  $$$$$$$/ $$/   $$/"

#define D1 " ______   __"
#define D2 "/      \\ /  |"
#define D3 "$$$$$$$  |$$/  _______   _______    ______    ______"
#define D4 "$$ |  $$ |/  |/       \\ /       \\  /       \\ /      \\"
#define D5 "$$ |  $$ |$$ |$$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$  |"
#define D6 "$$ |  $$ |$$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$/"
#define D7 "$$ |__$$ |$$ |$$ |  $$ |$$ |  $$ |$$$$$$$$/ $$ |"
#define D8 "$$    $$/ $$ |$$ |  $$ |$$ |  $$ |$$       |$$ |"
#define D9 "$$$$$$$/  $$/ $$/   $$/ $$/   $$/  $$$$$$$/ $$/"


void	vs_print_42(t_vis *v);
void	vs_check_key_events(t_vis *v);
void	vs_init_color(void);
void	vs_main(void);
void	vs_announce_winner(int i, int j, int o);
void	vs_update_stats(t_vis *v);
void	vs_update_main(t_vis *v);
void	vs_prepare_stat(t_vis *v);
void	vs_print_players(t_vis *v);

#endif