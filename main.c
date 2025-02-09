#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

void	start_ncurses(void);
WINDOW	*create_window(void);
void	display_menu(WINDOW *win, char *title, int nb_choices, char *choices[]);

int	main() 
{
	WINDOW *win;
	char	*title;
	char	*choices[] = 
	{
		"START A TIMER",
		"SEE STATS",
		"EXIT"
	};

	title = "What do you want to do?";

	start_ncurses();
	refresh(); // Met à jour l’écran principal

	win = create_window();
	wrefresh(win); // Met à jour la fenêtre après sa création

	display_menu(win, title, 3, choices);

	getch();
	endwin(); // Quitte ncurses proprement
	return 0;
}

void	start_ncurses(void)
{
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
}

WINDOW	*create_window(void)
{
	int height = 10;
	int width = 40;
	int y = (LINES - height) / 2;
	int x = (COLS - width) / 2;

	WINDOW *win = newwin(height, width, y, x);
	box(win, 0, 0);
	wrefresh(win); // Important pour afficher la boîte

	return win;
}

void	display_menu(WINDOW *win, char *title, int nb_choices, char *choices[])
{
	int	height;
	int	width;
	int	col; 
	
	getmaxyx(win, height, width); // Récupère les dimensions de la fenêtre
	
	col = (width - strlen(title)) / 2; // Centre horizontalement

	mvwprintw(win, 1, col, "%s", title); // Affiche le texte centré

	for (int i = 0, line = i + 3; i < nb_choices; i++, line++)
	{
		col = (width - strlen(choices[i])) / 2;
		mvwprintw(win, line, col, "%s", choices[i]);
	}

	wrefresh(win); // Rafraîchit l'affichage de la fenêtre
}