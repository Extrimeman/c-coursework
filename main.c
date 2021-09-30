#include <ncurses.h>
#include <stdlib.h>
int size=1;



void newgame()
{
	endwin();
	switch(size)
	{
		case 1:
		{
			system("./engine 1");
			break;
		}
		case 2:
		{
			system("./engine 2");
			break;
		}
		case 3:
		{
			system("./engine 3");
			break;
		}
		case 4:
		{
			system("./engine 4");
			break;
		}
	}
}



void options()
{
	int columns,rows;
	const short int min_choice = 1;
   	const short int max_choice = 5;
	int kotory = 1;
    	int symbol;
   	 const char txt1[] = "10x10";
   	 const char txt2[] = "15x15";
   	 const char txt3[] = "20x20";
  	 const char txt4[] = "25x25";
 	 const char txt5[] = "BACK";


        init_pair( 1, COLOR_WHITE, COLOR_BLACK );
	init_pair( 2,COLOR_GREEN,COLOR_BLACK);
        attron( COLOR_PAIR( 1 ) );

    do
    {
getmaxyx(stdscr,columns,rows);
mvprintw(columns/2-1, rows/2-5, "Board size:");
mvprintw(columns-1, 0, "W,S - to move; ENTER - choose square");
        
        switch( kotory )
        {
        case 1:

            mvprintw( columns/2+4 ,rows/2, txt5 );

			if(size==2) attron( COLOR_PAIR( 2 ) );
            mvprintw( columns/2+1, rows/2, txt2 );
			if(size==2) attroff( COLOR_PAIR( 2 ) );

			if(size==3) attron( COLOR_PAIR( 2 ) );
            mvprintw( columns/2+2, rows/2, txt3 );
			if(size==3) attroff( COLOR_PAIR( 2 ) );

			if(size==4) attron( COLOR_PAIR( 2 ) );
			mvprintw( columns/2+3, rows/2, txt4 );
			if(size==4) attroff( COLOR_PAIR( 2 ) );

            attron( A_REVERSE );
			if(size==1) attron( COLOR_PAIR( 2 ) );
			mvprintw( columns/2, rows/2, txt1 );
			if(size==1) attroff( COLOR_PAIR( 2 ) );
            break;

        case 2:
			if(size==1) attron( COLOR_PAIR( 2 ) );
            mvprintw( columns/2  , rows/2, txt1 );
			if(size==1) attroff( COLOR_PAIR( 2 ) );

            mvprintw( columns/2+4, rows/2, txt5 );

			if(size==3) attron( COLOR_PAIR( 2 ) );
            mvprintw( columns/2+2, rows/2, txt3 );
			if(size==3) attroff( COLOR_PAIR( 2 ) );

			if(size==4) attron( COLOR_PAIR( 2 ) );
			mvprintw( columns/2+3, rows/2, txt4 );
			if(size==4) attroff( COLOR_PAIR( 2 ) );

            attron( A_REVERSE );
			if(size==2) attron( COLOR_PAIR( 2 ) );
			mvprintw( columns/2+1, rows/2, txt2 );
			if(size==2) attroff( COLOR_PAIR( 2 ) );
            break;

        case 3:
			if(size==1) attron( COLOR_PAIR( 2 ) );
            mvprintw( columns/2  , rows/2, txt1 );
			if(size==1) attroff( COLOR_PAIR( 2 ) );

			if(size==2) attron( COLOR_PAIR( 2 ) );
            mvprintw( columns/2+1, rows/2, txt2 );
			if(size==2) attroff( COLOR_PAIR( 2 ) );

            mvprintw( columns/2+4, rows/2, txt5 );

			if(size==4) attron( COLOR_PAIR( 2 ) );
			mvprintw( columns/2+3, rows/2, txt4 );
			if(size==4) attroff( COLOR_PAIR( 2 ) );

            attron( A_REVERSE );
			if(size==3) attron( COLOR_PAIR( 2 ) );
			mvprintw( columns/2+2, rows/2, txt3 );
			if(size==3) attroff( COLOR_PAIR( 2 ) );
            break;
	case 4:
			if(size==1) attron( COLOR_PAIR( 2 ) );
            mvprintw( columns/2  , rows/2, txt1 );
			if(size==1) attroff( COLOR_PAIR( 2 ) );

			if(size==2) attron( COLOR_PAIR( 2 ) );
            mvprintw( columns/2+1, rows/2, txt2 );
			if(size==2) attroff( COLOR_PAIR( 2 ) );

			if(size==3) attron( COLOR_PAIR( 2 ) );
            mvprintw( columns/2+2, rows/2, txt3 );
			if(size==3) attroff( COLOR_PAIR( 2 ) );

			mvprintw( columns/2+4, rows/2, txt5 );

            attron( A_REVERSE );
			if(size==4) attron( COLOR_PAIR( 2 ) );
			mvprintw( columns/2+3, rows/2, txt4 );
			if(size==4) attroff( COLOR_PAIR( 2 ) );
            break;
	case 5:
			if(size==1) attron( COLOR_PAIR( 2 ) );
            mvprintw( columns/2  , rows/2, txt1 );
			if(size==1) attroff( COLOR_PAIR( 2 ) );

			if(size==2) attron( COLOR_PAIR( 2 ) );
            mvprintw( columns/2+1, rows/2, txt2 );
			if(size==2) attroff( COLOR_PAIR( 2 ) );

			if(size==3) attron( COLOR_PAIR( 2 ) );
            mvprintw( columns/2+2, rows/2, txt3 );
			if(size==3) attroff( COLOR_PAIR( 2 ) );

			if(size==4) attron( COLOR_PAIR( 2 ) );
			mvprintw( columns/2+3, rows/2, txt4 );
			if(size==4) attroff( COLOR_PAIR( 2 ) );

            attron( A_REVERSE );
			mvprintw( columns/2+4, rows/2, txt5 );
            break;
        }
        attroff( A_REVERSE );
       
        symbol = getch();
        clear();
        if( symbol == 'w' && kotory != min_choice )
        {
            kotory--;
        }
        else if( symbol == 's' && kotory != max_choice )
        {
            kotory++;
        }
        //reakcja
        if( symbol == 10 )
        {
            switch( kotory )
            {
            case 1:
		size=1;
                break;
            case 2:
		size=2;
                break;
	    case 3:
		size=3;
                break;
	    case 4:
		size=4;
                break;
            }
        }

    } while( kotory != 5 || symbol != 10 );

}

void logo()
{
	int columns,rows;
	getmaxyx(stdscr,columns,rows);
	init_pair( 1, COLOR_YELLOW, COLOR_BLACK );
	attron( A_BOLD | COLOR_PAIR(1));
		mvprintw( 1, rows/2-34, ".______        ___      .___________..___________. __       _______ " );
		mvprintw( 2, rows/2-34, "|   _  \\      /   \\     |           ||           ||  |     |   ____|" );
		mvprintw( 3, rows/2-34, "|  |_)  |    /  ^  \\    `---|  |----``---|  |----`|  |     |  |__   " );
		mvprintw( 4, rows/2-34, "|   _  <    /  /_\\  \\       |  |         |  |     |  |     |   __|  " );
		mvprintw( 5, rows/2-34, "|  |_)  |  /  _____  \\      |  |         |  |     |  `----.|  |____ " );
		mvprintw( 6, rows/2-34, "|______/  /__/     \\__\\     |__|         |__|     |_______||_______|" );
		mvprintw( 7, rows/2-25, "     _______. __    __   __  .______        _______." );
		mvprintw( 8, rows/2-25, "    /       ||  |  |  | |  | |   _  \\      /       |" );
		mvprintw( 9, rows/2-25, "   |   (----`|  |__|  | |  | |  |_)  |    |   (----`" );
		mvprintw( 10, rows/2-25,"    \\   \\    |   __   | |  | |   ___/      \\   \\    " );
		mvprintw( 11, rows/2-25,".----)   |   |  |  |  | |  | |  |      .----)   |   " );
		mvprintw( 12, rows/2-25,"|_______/    |__|  |__| |__| | _|      |_______/    " );
		attroff( A_BOLD | COLOR_PAIR(1));
}

void menu()
{
int columns,rows;
    const char txt1[] = "New Game";
    const char txt2[] = "Options";
    const char txt3[] = "Exit";
    int kotory = 1;
    int symbol;
    const short int min_choice = 1;
    const short int max_choice = 3;


        init_pair( 1, COLOR_WHITE, COLOR_BLACK );
        attron( COLOR_PAIR( 1 ) );

    do
    {
getmaxyx(stdscr,columns,rows);
logo();
mvprintw(columns-1, 0, "W,S - to move; ENTER - choose square");

        switch( kotory )
        {
        case 1:
            mvprintw( columns/2+4, rows/2-2, txt2 );
            mvprintw( columns/2+5, rows/2-3, txt3 );
            attron( A_REVERSE );
            mvprintw( columns/2+3, rows/2-3, txt1 );
            break;

        case 2:
            mvprintw( columns/2+3, rows/2-3, txt1 );
            mvprintw( columns/2+5, rows/2-3, txt3 );
            attron( A_REVERSE );
            mvprintw( columns/2+4, rows/2-2, txt2 );
            break;

        case 3:
            mvprintw( columns/2+3, rows/2-3, txt1 );
            mvprintw( columns/2+4, rows/2-2, txt2 );
            attron( A_REVERSE );
            mvprintw( columns/2+5, rows/2-3, txt3 );
            break;
        }
        attroff( A_REVERSE );
        symbol = getch();
        clear();
        if( symbol == 'w' && kotory != min_choice )
        {
            kotory--;
        }
        else if( symbol == 's' && kotory != max_choice )
        {
            kotory++;
        }
        if( symbol == 10 )
        {
            switch( kotory )
            {
            case 1:
                newgame();
                break;
            case 2:
                options();
                break;
            }
        }

    } while( kotory != 3 || symbol != 10 );

    move( 9, 0 );
    printw( "End of program, press a button..." );
    getch();
}

int main()
{
    initscr();
    noecho();
    start_color();
    menu();
    endwin();
    system("clear");
    return 0;

}
