/****************************************************************/
/*																*/
/*   Name: snake.cpp                                            */
/*   Author: Saad Naveed Ismail (2014-10-0055)                  */
/*   Date: 10th October, 2011                                   */
/*   Purpose: Make the Nokia Snake game                         */
/*                                                              */
/*																*/
/*   Tasks Completed: 4 Tasks                                   */
/*   Extra Features: (i) Long snake (7 charaters)               */
/*                   (ii) Snake dies on hitting itself          */
/*																*/
/****************************************************************/

#include <ncurses.h>
#include <string.h>

void drawSnake(char facing, int row1, int row2, int row3, int row4, int row5, int row6, int row7, int col1, int col2, int col3, int col4, int col5, int col6, int col7);

void updateSnake(int &row1, int &row2, int &row3, int &row4, int &row5, int &row6, int &row7, int &col1, int &col2, int &col3, int &col4, int &col5, int &col6, int &col7);

int main()
{
////INITIALIZING//////////////////////////////////////////////////////////////////

    int rowMax, columnMax, direction, lose;
    char start_Text[]="Press Down Arrow Key to start Snake Game!";	//Make strings for start and end texts
    char lost[]="GAME OVER!";
    char instructions[]="Press \"q\" to exit game!";
    char quit[]="Press any key to exit!";

////INITIALIZING CURSES MODE//////////////////////////////////////////////////////

    initscr();                                                    //Initialize curses screen,
    raw();                                                        //get rid of cursor from screen,
    keypad(stdscr, TRUE);                                         //and initialize colour changing
    noecho();
    curs_set(0);
    start_color();
    assume_default_colors(COLOR_BLUE, COLOR_CYAN);
    init_pair(1, COLOR_BLUE, COLOR_CYAN);

////INITIALIZING SNAKE INITIAL POSITION AND START MENU/////////////////////////////

    getmaxyx(stdscr, rowMax, columnMax);                                            //Get max values of rows and columns
    int row1=6, row2=5, row3=4, row4=3, row5=2, row6=1, row7=0; char a;             //and thus have boundaries
    int col1=columnMax/2, col2=columnMax/2, col3=columnMax/2, col4=columnMax/2, col5=columnMax/2, col6=columnMax/2, col7=columnMax/2;

/////row1 and col1 are y and x of 1st part (head), row2 and col2 are y and x of 2nd part and so on/////

    attron(COLOR_PAIR(1));															                   //Turning color feature on and
    drawSnake('d', row1, row2, row3, row4, row5, row6, row7, col1, col2, col3, col4, col5, col6, col7);//drawing snake at start point

    attron(A_BOLD);
    mvprintw(rowMax/2-1, (columnMax-strlen(start_Text))/2, "%s", start_Text);      //Print start menu texts
    mvprintw(rowMax/2, (columnMax-strlen(instructions))/2, "%s", instructions);    //in the center of screen

    do{
    	direction=getch();
    }while(direction!=KEY_DOWN);

    attroff(A_BOLD);
    wtimeout(stdscr, 100);
    erase();

////PLAYING SNAKE/ MOVING SNAKE///////////////////////////////////////////////////////////////////////////

    while( (row1<rowMax) && (row1>=0) && (col1>=0) && (col1<columnMax) )
    {

////////GOING DOWN//////////////////////////////////////////////////////////////////

    	if(direction == KEY_DOWN)
    	{
    		while( (row1<rowMax) && (row1>=0) && (col1>=0) && (col1<columnMax) )
    		{
    			drawSnake('d', row1, row2, row3, row4, row5, row6, row7, col1, col2, col3, col4, col5, col6, col7);
																					                             //Print the snake on screen and
                updateSnake(row1, row2, row3, row4, row5, row6, row7, col1, col2, col3, col4, col5, col6, col7); //update values. Updating is
    			row1++; 																							 //done by making last character
    				                                                                                             //take values of next, 2nd last
				a=mvinch(row1, col1);																			 //by taking off 3rd last and so on.
				if(a=='*')																						 //Head updates according to respective
				{																								 //direction.
					lose=1;
					break;																//Detecting collision with
				}																		//itself by using mvinch.
    			direction=getch();
                                                                                      	//We have getch() running to check
    			if( (direction==KEY_RIGHT)||(direction==KEY_LEFT)||(direction=='q') )	//if its right, left or q pressed
    				break;                                                              //then break and go check next if
    		}                                                                           //condition to move or exit(cause of q)
    	}
        if(lose==1)
        	break;
////////GOING UP//////////////////////////////////////////////////////////////////////

    	if(direction == KEY_UP)
    	{
    		while( (row1>=0) && (row1<rowMax) && (col1>=0) && (col1<columnMax) )
    		{
    			drawSnake('u', row1, row2, row3, row4, row5, row6, row7, col1, col2, col3, col4, col5, col6, col7);  //Prints, updates and detects
    																			    								 //collision of snake just as
    			updateSnake(row1, row2, row3, row4, row5, row6, row7, col1, col2, col3, col4, col5, col6, col7);     //written above for going down.
    			row1--;
																					 //We have getch() running to check
				a=mvinch(row1, col1);												 //if its right, left or q pressed
				if(a=='*')															 //then break and go check next if
				{																	 //condition to move (right or left)
					lose=1;															 //or exit(cause of q)
					break;
				}

    			direction=getch();
    			if( (direction==KEY_RIGHT)||(direction==KEY_LEFT)||(direction=='q') )
    				 break;
    		}
    	}
    	if(lose==1)
    		break;

////////GOING LEFT///////////////////////////////////////////////////////////////////

    	if(direction == KEY_LEFT)
    	{
    		while( (col1>=0) && (col1<columnMax) && (row1<rowMax) && (row1>=0) )
    		{
    			drawSnake('l', row1, row2, row3, row4, row5, row6, row7, col1, col2, col3, col4, col5, col6, col7);	  //Prints and updates and detects
																													  //collision of snake just as
    			updateSnake(row1, row2, row3, row4, row5, row6, row7, col1, col2, col3, col4, col5, col6, col7);      //written above for going down.
    			col1--;
																					//We have getch() running to check
				a=mvinch(row1, col1);												//if its right, left or q pressed
				if(a=='*')															//then break and go check next if
				{																	//condition to move (right or left)
					lose=1;														//or exit(cause of q)
					break;
				}

    			direction=getch();
				if( (direction==KEY_UP)||(direction==KEY_DOWN)||(direction=='q') )
    				break;
    		}
    	}
    	if(lose==1)
    		break;

////////GOING RIGHT/////////////////////////////////////////////////////////////////

    	if(direction == KEY_RIGHT)
    	{
    		while( (col1<columnMax) && (col1>=0) && (row1<rowMax) && (row1>=0) )
    		{
    			drawSnake('r', row1, row2, row3, row4, row5, row6, row7, col1, col2, col3, col4, col5, col6, col7);   //Prints and updates and detects
                                                                                                                      //collision of snake just as
    			updateSnake(row1, row2, row3, row4, row5, row6, row7, col1, col2, col3, col4, col5, col6, col7);      //written above for going down.
    			col1++;
																				    //We have getch() running to check
    			a=mvinch(row1, col1);                                               //if its right, left or q pressed
    			if(a=='*')                                                          //then break and go check next if
    			{                                                                   //condition to move (right or left)
    			    lose=1;                                                        //or exit(cause of q)
    			    break;
    			}

    			direction=getch();
    			if( (direction==KEY_UP)||(direction==KEY_DOWN)||(direction=='q') )
    				break;
    		}
    	}
    	if(lose==1)
    		break;

    	if(direction=='q')						//Functionality that if 'q' is pressed
    		break;								//then stop the game

    }

////GAME LOST, NOW WAITING TO END/////////////////////////////////////////////////////////////////////

	attron(A_BOLD);													//Turning BOLD feature on 
	mvprintw(rowMax/2, (columnMax-strlen(lost))/2, "%s", lost);		//writing and then turning
	mvprintw(rowMax/2+1, (columnMax-strlen(quit))/2, "%s", quit);
	wtimeout(stdscr, 100000);										//it off.
    getch();
    attroff(A_BOLD);
    attroff(COLOR_PAIR(1));										//And finally turning off the color feature.
    endwin();

    return 0;

}

/////Function to draw the snake//////////////////////////////////////////

void drawSnake(char facing, int row1, int row2, int row3, int row4, int row5, int row6, int row7, int col1, int col2, int col3, int col4, int col5, int col6, int col7)
{
	erase();
	mvprintw(row7, col7, "*");					//Printing the body and then
	mvprintw(row6, col6, "*");					//checking which direction snake
	mvprintw(row5, col5, "*");					//is facing and making the appropriate face.
	mvprintw(row4, col4, "*");
	mvprintw(row3, col3, "*");
	mvprintw(row2, col2, "*");

	if(facing=='d')								//d=down
		mvprintw(row1, col1, "^");
	if(facing=='u')								//u=up
		mvprintw(row1, col1, "v");
	if(facing=='l')								//l=left
		mvprintw(row1, col1, ">");
	if(facing=='r')								//r=right
		mvprintw(row1, col1, "<");
}

/////Function to update the row and column values of the snake part/////////

void updateSnake(int &row1, int &row2, int &row3, int &row4, int &row5, int &row6, int &row7, int &col1, int &col2, int &col3, int &col4, int &col5, int &col6, int &col7)
{
	row7=row6; row6=row5; row5=row4; row4=row3; row3=row2; row2=row1;	//Making 7th star take row and column values of 6th, 6th
	col7=col6; col6=col5; col5=col4; col4=col3; col3=col2; col2=col1;	//take that of 5th and so on till 2nd taking that of 1st
}
