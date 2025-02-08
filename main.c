#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

void	start_ncurses(void);
void	display_menu(int selected);


int main() 
{
    int choice = 0;
    int ch;

    start_ncurses();
    
    while (1) 
    {
        display_menu(choice);
        ch = getch();
        
        if (ch == KEY_UP) 
		if (choice > 0)
			choice -= 1;
        if (ch == KEY_DOWN) 
		if (choice < 2)
			choice += 1;
        if (ch == '\n') 
		break;
    }

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

void display_menu(int selected) 
{
    clear();
    mvprintw(5, 10, "Quelle activite commencez-vous ?");
    
    if (selected == 0)
        attron(A_REVERSE);
    mvprintw(7, 12, "Programmation");
    attroff(A_REVERSE);
    
    if (selected == 1)
        attron(A_REVERSE);
    mvprintw(8, 12, "Japonais");
    attroff(A_REVERSE);

    if (selected == 2)
        attron(A_REVERSE);
    mvprintw(9, 12, "Youtube");
    attroff(A_REVERSE);
    
    refresh();
}