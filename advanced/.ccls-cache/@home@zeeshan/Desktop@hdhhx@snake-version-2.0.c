
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/ioctl.h>
#include<time.h>
#include<signal.h>
#include<curses.h>

long long int  speedSnake=44444;
long int _time_=0;
#define  SIZE_INITIALLY   15 
#define  SNAKE_BIT        '0'
#define  BLANK_SPACE      ' '
#define  TARGET           'T'
#define  SCORE_PER_TARGET 20
#define  SCORE_PER_STEP   2
#define  COLLISION_SELF   1
#define  COLLISION_BOX    2
#define  USER_LEFT_ROOM   1
#define  START_PLAYING    1
#define  true 1
#define  false 0
static   int  CurrentSize=10;
static   int level=0;
static  long long int  CurrentScore=0;
bool flag=true;
int  CurrentDirection=KEY_RIGHT;
int  windowCol;
int  windowRow;
struct coordinates
{
	int x;
	int y;
	struct coordinates *next;
};

typedef struct coordinates coordinates_of_snake_bit;
coordinates_of_snake_bit *SnakeBit;
void SetTimer(void);
void SetSignalHandler(void);
void SignalHandler(int signo);
void InitialiseSnake(void);
void DeleteWindow(void);
void TurnSnakesHead(int direction);
void MoveOneStepForward(void);
void IgnoreThisStroke(void);
void IgnoreThisSignal(int signo);
void PlaceTargetOnField(void);
void GetWindowSize(void);
void FreeSnakeBitMemory(void);
int autoPlay();

int which_if_else=-1;
int which_case=-1;

void check_maximum_score()
{
	int last_score;
	
	FILE *fp=fopen("maximum_score.txt","r");
	fscanf(fp,"%d",&last_score);
	fclose(fp);
	
	if( CurrentScore > last_score)
	{
		printf("\n\n\t\t#############################################\n");
		printf("\n\t\tCongratulation! ");
		printf("\n\t\tYou broke the highest recorded score till now.\n");
		printf("\t\tThe recored score was %d, ",last_score);
		printf("and your score is %d.\n",CurrentScore);
		printf("\n\t\t#############################################\n\n\n\n");
		
		FILE *fp=fopen("maximum_score.txt","w");
		fprintf(fp,"%d",CurrentScore);
		fclose(fp);
	}
	return;
}
WINDOW *mainwin;
int main(void)
{
	
	char player;
	printf("Do you want to play yourself? (y/n) ");
	scanf("%c", &player);

	// the next four lines, cannot be placed above the 'above two lines'. since they are signal handlers
	time_t tm;
	srand(time(&tm));
	SetTimer();
	SetSignalHandler();
	
	if((mainwin=initscr())==NULL)
	{
		fprintf(stderr,"initscr failure\n");
		exit(EXIT_FAILURE);
	}
	noecho();
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	init_pair(2,COLOR_RED,COLOR_BLACK);
	init_pair(3,COLOR_GREEN,COLOR_BLACK);
	init_pair(4,COLOR_BLUE,COLOR_BLACK);
	init_pair(5,COLOR_YELLOW,COLOR_BLACK);
	init_pair(6,COLOR_WHITE,COLOR_RED);
	init_pair(7,COLOR_RED,COLOR_WHITE);
	init_pair(8,COLOR_GREEN,COLOR_YELLOW);
	init_pair(9,COLOR_BLUE,COLOR_RED);
	init_pair(10,COLOR_YELLOW,COLOR_BLUE);

//	color_set(1,NULL);
	box(mainwin,0,0);
	keypad(mainwin,TRUE);
	curs_set(0);
	GetWindowSize();
	InitialiseSnake();
	int playerKeyStroke;
	int playerKeyStroke_check;
	while(START_PLAYING)
	{
		playerKeyStroke_check=getch(); // this wont wait fot input 
		if(player != 'y')
			playerKeyStroke=autoPlay();
		else
			playerKeyStroke=playerKeyStroke_check;

		switch(playerKeyStroke)
		{
			case KEY_RIGHT:
				TurnSnakesHead(KEY_RIGHT);
				break;
			case KEY_LEFT:
				TurnSnakesHead(KEY_LEFT);
				break;
			case KEY_UP:
				TurnSnakesHead(KEY_UP);
				break;
			case KEY_DOWN:
				TurnSnakesHead(KEY_DOWN);
				break;
			default:
				IgnoreThisStroke();
		}
		switch (playerKeyStroke_check)
		{
			case 'i':
			case 'I':
				if(speedSnake-1000>0)
				{
					speedSnake-=1000;
					SetTimer();
					SetSignalHandler();
				}
				break;
			case 'd':
			case 'D':
				speedSnake+=1000;
				SetTimer();
				SetSignalHandler();
				break;
			case 'y':
			case 'n':
				player = playerKeyStroke_check;
				break;
			case 'q':
			case 'Q':
				DeleteWindow();
				fprintf(stdout,"You score is %lld\n",CurrentScore);
				check_maximum_score();
				exit(EXIT_SUCCESS);
			default:
				IgnoreThisStroke();
		}
	}
} 
void InitialiseSnake(void)
{
	int i,x=1,y=1;
	SnakeBit=(struct coordinates*)malloc(sizeof(struct coordinates));
	SnakeBit->next=NULL;
	coordinates_of_snake_bit *Tmp,*temp;
	Tmp=SnakeBit;
	for(i=1;i<SIZE_INITIALLY;i++)
	{
		Tmp->x=x++;
		Tmp->y=y;
		Tmp->next=(struct coordinates*)malloc(sizeof(struct coordinates));	
		Tmp=Tmp->next;
	}
	Tmp->x=x;
	Tmp->y=y;
	Tmp->next=NULL;
	Tmp=SnakeBit;
	while(Tmp)
	{
		mvaddch(Tmp->y,Tmp->x,SNAKE_BIT);
		refresh();
		Tmp=Tmp->next;
	}
	PlaceTargetOnField();
	return;
}
void TurnSnakesHead(int directionIndicated)
{
	switch(directionIndicated)
	{
		case KEY_UP:
			if(CurrentDirection==KEY_DOWN)
				return;
			break;
		case KEY_DOWN:
			if(CurrentDirection==KEY_UP)
				return;
			break;
		case KEY_LEFT:
			if(CurrentDirection==KEY_RIGHT)
				return;
			break;
		case KEY_RIGHT:
			if(CurrentDirection==KEY_LEFT)
				return;
			break;
	}
	CurrentDirection=directionIndicated;
	return;
}
void MoveOneStepForward(void)
{
	coordinates_of_snake_bit *Tmp;
	Tmp=SnakeBit;
	int y,x;
	while(Tmp->next!=NULL)
		Tmp=Tmp->next;
	switch(CurrentDirection)
	{
		case KEY_UP:
			x=Tmp->x;
			y=Tmp->y-1;
			break;
		case KEY_DOWN:
			x=Tmp->x;
			y=Tmp->y+1;
			break;
		case KEY_LEFT:
			x=Tmp->x-1;
			y=Tmp->y;
			break;
		case KEY_RIGHT:
			x=Tmp->x+1;
			y=Tmp->y;
	}
	Tmp->next=(struct coordinates*)malloc(sizeof(struct coordinates));
	Tmp->next->x=x;
	Tmp->next->y=y;
	Tmp->next->next=NULL;
	move(y,x);
	refresh();
	int ch;
	switch((ch=inch()))
	{
		case  BLANK_SPACE :
			addch(SNAKE_BIT);
			refresh();
			mvaddch(SnakeBit->y,SnakeBit->x,BLANK_SPACE);
			refresh();
			Tmp=SnakeBit;
			SnakeBit=SnakeBit->next;
			free(Tmp);
			return;
		case    TARGET   :
			CurrentScore+=SCORE_PER_TARGET;
			addch(SNAKE_BIT);
			refresh();	
			PlaceTargetOnField();
			return;
		case  SNAKE_BIT   :
			//sleep(5);
			DeleteWindow();
			fprintf(stdout,"\n\t\t\tSnake hits itself\n\t\t\tYour score is %lld, which_if_else : %d, which_case: %d\n\n",CurrentScore,which_if_else,which_case);
			switch(CurrentDirection)
			{
				case KEY_UP:
					fprintf(stdout, "up\n");
					break;
				case KEY_DOWN:
					fprintf(stdout, "down\n");
					break;
				case KEY_LEFT:
					fprintf(stdout, "left\n");
					break;
				case KEY_RIGHT:
					fprintf(stdout, "right\n");
					break;
			}	
			check_maximum_score();
			exit(EXIT_SUCCESS);
		default:
			DeleteWindow();
			fprintf(stdout,"\n\t\t\tSnake hits the wall\n\t\t\tYour score is %lld, which_if_else : %d,which_case=: %d\n\n",CurrentScore,which_if_else,which_case);	
			check_maximum_score();
			exit(EXIT_SUCCESS);
	}	
}

int target_x,target_y;

int checkValidity(int x ,int y)
{	
	move(y,x);
	refresh();
	int ch;
	switch((ch=inch()))
	{
		case  BLANK_SPACE :
			which_case=1;
			return 1;
		case    TARGET   :
			which_case=2;
			return 1;
		case  SNAKE_BIT   :
			which_case=3;
			return 0;
			//sleep(5);
			DeleteWindow();
			fprintf(stdout,"\n\t\t\tcheckValidity : %c which_if_else : %d\n\n",ch,which_if_else);	
			exit(EXIT_SUCCESS);
		default:
			which_case=4;
			return 0;

	}

}
int autoPlay()
{
	coordinates_of_snake_bit *Tmp;
	Tmp=SnakeBit;
	int y,x;
	while(Tmp->next!=NULL)
		Tmp=Tmp->next;
	if(Tmp->x < target_x)
	{

		if ( CurrentDirection != KEY_LEFT)
		{
			which_if_else=1;
			// checkValidity: its because may be the snake already is moving towards RIGHT, so it might hit wall.
			if(checkValidity(Tmp->x+1,Tmp->y))
				return KEY_RIGHT;	
		}
		if(Tmp->y < target_y)
		{
			which_if_else=2;
			if(checkValidity(Tmp->x,Tmp->y+1))
				return KEY_DOWN;
		}
		if(Tmp->y > target_y)
		{
			which_if_else=3;
			if(checkValidity(Tmp->x,Tmp->y-1))
				return KEY_UP;
		}

		
		// the next  "if when Tmp->y = target_y, that is, target on same line in which snake ALREADY moves, but
		// the snake will have to turn (temporarily), since snake bit IS on the way. May be I am wrong now :-s
		if(checkValidity(Tmp->x,Tmp->y+1)) 
		{
			 which_if_else=1000;	
			 return KEY_DOWN;	
		}
		else if (checkValidity(Tmp->x,Tmp->y-1))
		{
			 which_if_else=2000;	
			 return KEY_UP;
		}
	}
	if(Tmp->x > target_x)
	{
		if ( CurrentDirection != KEY_RIGHT)
		{
			which_if_else=5;
			if(checkValidity(Tmp->x-1,Tmp->y))
				return KEY_LEFT;
		}
		if(Tmp->y < target_y)
		{
			which_if_else=6;
			if(checkValidity(Tmp->x,Tmp->y+1))
				return KEY_DOWN;
		}
		if(Tmp->y > target_y)
		{
			which_if_else=7;
			if(checkValidity(Tmp->x,Tmp->y-1))
				return KEY_UP;
		}
		if(checkValidity(Tmp->x,Tmp->y+1)) 
		{
			 which_if_else=3000;	
			 return KEY_DOWN;	
		}
		else if(checkValidity(Tmp->x,Tmp->y-1))
		{
			 which_if_else=4000;	
			 return KEY_UP;
		}
	}
	if(Tmp->y < target_y)
	{
		if ( CurrentDirection != KEY_UP) 
		{
			which_if_else=9;
			if(checkValidity(Tmp->x,Tmp->y+1))
				return KEY_DOWN;
		}
		if(Tmp->x < target_x)
		{
			which_if_else=10;
			if(checkValidity(Tmp->x+1,Tmp->y))
				return KEY_RIGHT;
		}
		if(Tmp->x > target_x)
		{
			which_if_else=11;
			if(checkValidity(Tmp->x-1,Tmp->y))	
				return KEY_LEFT;
		}
		if(checkValidity(Tmp->x-1,Tmp->y)) 
		{
			 which_if_else=5000;	
			 return KEY_LEFT;	
		}
		else if(checkValidity(Tmp->x+1,Tmp->y))
		{
			 which_if_else=6000;	
			 return KEY_RIGHT;
		}
	}
	if(Tmp->y > target_y)
	{
		if ( CurrentDirection != KEY_DOWN)
		{
			which_if_else=13;
			if(checkValidity(Tmp->x,Tmp->y-1))
				return KEY_UP;
		}
		if(Tmp->x < target_x)
		{
			which_if_else=14;
			if(checkValidity(Tmp->x+1,Tmp->y+1))
				return KEY_RIGHT;
		}
		if(Tmp->x > target_x)
		{
			which_if_else=15;
			if(checkValidity(Tmp->x-1,Tmp->y+1))
				return KEY_LEFT;
		}
		if(checkValidity(Tmp->x-1,Tmp->y)) 
		{
			 which_if_else=7000;	
			 return KEY_LEFT;	
		}
		else if(checkValidity(Tmp->x+1,Tmp->y))
		{
			 which_if_else=8000;	
			 return KEY_RIGHT;
		}
	}
	which_if_else +=-100;
	return CurrentDirection;
}
void PlaceTargetOnField(void)
{
	extern WINDOW *mainwin;
	int x,y;
	int height=windowRow/5;
	int width=windowCol/4;
	int Y=windowRow/3;
	int X=windowCol/3;
	while(1)
	{
		x=rand()%(windowCol-2);
		y=rand()%(windowRow-2);
		move(y,x);
		if(inch()==BLANK_SPACE&&(y<Y||y>(Y+height))&&(x<X||x>(X+width)))
			break;
	}
	target_x=x;
	target_y=y;
	mvaddch(y,x,TARGET);
	wrefresh(mainwin);
	return;
}
void GetWindowSize(void)
{
	struct winsize WinSize;
	if(ioctl(0,TIOCGWINSZ,&WinSize)<0)
	{
		DeleteWindow();
		fprintf(stderr,"ioctl failure\n");
		exit(EXIT_FAILURE);
	}
	windowCol=WinSize.ws_col;
	windowRow=WinSize.ws_row;
	return;
}
void SignalHandler(int signo)
{
	switch(signo)
	{
		case SIGTERM:
		case SIGINT:
			DeleteWindow();
			FreeSnakeBitMemory();
			fprintf(stdout,"Your score till now is %lld\n",CurrentScore);
			exit(EXIT_SUCCESS);
		case SIGALRM:
			MoveOneStepForward();
			break;
		case SIGSEGV:
			DeleteWindow();
			fprintf(stderr,"There is segmentation fault\n");
			exit(EXIT_FAILURE);
		default:
			IgnoreThisSignal(signo);
	}
	extern WINDOW *mainwin;
	WINDOW *subwindow;
	int height=windowRow/4;
	int width=windowCol/4;
	int y=windowRow/3;
	int x=windowCol/3;
	subwindow=subwin(mainwin,height,width,y,x);
	box(subwindow,0,0);
	
	wcolor_set(subwindow,2,NULL);
	wattron(subwindow,A_UNDERLINE);
	mvwaddstr(subwindow, height/8,(width-21)/2, "WELCOME TO SNAKE GAME");
	wattroff(subwindow,A_UNDERLINE);
	
	wattron(subwindow,A_BOLD);
	
	wcolor_set(subwindow,1,NULL);
	if(flag)
		mvwprintw(subwindow, height*2/8,(width-10)/2, "LEVEL : %2d",level);
	else
		mvwaddstr(subwindow, height*2/8,(width-15)/2, "LEVEL : HIGHEST");
	
	wcolor_set(subwindow,5,NULL);

	mvwprintw(subwindow, height*3/8,(width-21)/2, "Score: %lld, Time: %ld",CurrentScore, _time_++);
	
	wcolor_set(subwindow,3,NULL);
	mvwaddstr(subwindow, height*4/8,(width-25)/2,"Press I to Increase speed");
	mvwaddstr(subwindow, height*4/8+1,(width-25)/2,"Press D to Decrease speed");
	wcolor_set(subwindow,1,NULL);
	
	wcolor_set(subwindow,4,NULL);
	mvwaddstr(subwindow, height*6/8,(width-15)/2,"Press Q to QUIT");
	
	wcolor_set(subwindow,2,NULL);
	mvwaddstr(subwindow, height*7/8,(width-26)/2,"Designed by Sarfaraz Nawaz");
	wcolor_set(subwindow,1,NULL);
	wattroff(subwindow,A_BOLD);
	
	wrefresh(subwindow);
	delwin(subwindow);
	wrefresh(mainwin);
	int prev=level;
	int pres;
	pres=CurrentScore/100;
	if(pres-prev)
	{
		if(speedSnake-2000>0)
		{
			speedSnake-=2000;//DONT CONFUSE THIS STEP INCRESES THE SPEED OF SNAKE (not decreases)
			level++;
			SetTimer();
			SetSignalHandler();
		}
		else
			flag=false;
	}
	return;
}
void SetTimer(void)
{
	struct itimerval timer;
	timerclear(&timer.it_interval);
	timerclear(&timer.it_value);
	timer.it_interval.tv_usec=speedSnake;
	timer.it_value.tv_usec=speedSnake;
	setitimer(ITIMER_REAL,&timer,NULL);
	return;
}
void SetSignalHandler(void)
{
  
	struct sigaction action;
	action.sa_handler = SignalHandler;
	action.sa_flags   =0;
	sigemptyset(&action.sa_mask);
	sigaction(SIGTERM, &action, NULL);
	sigaction(SIGINT,  &action, NULL);
	sigaction(SIGALRM, &action, NULL);
	sigaction(SIGSEGV, &action, NULL);
	action.sa_handler = SIG_IGN;
	sigaction(SIGTSTP, &action, NULL);
}
void DeleteWindow(void)
{
	extern WINDOW *mainwin;
	delwin(mainwin);
	endwin();
	refresh();
	return;
}
void FreeSnakeBitMemory(void)
{
	coordinates_of_snake_bit *Tmp;
	while(SnakeBit)
	{
		Tmp=SnakeBit;
		SnakeBit=SnakeBit->next;
		free(Tmp);
	}
	return;
}
void IgnoreThisSignal(int signo)
{
	return;//Do sth here ,using subwindow if possible (OPTIONAL)
}
void IgnoreThisStroke(void)
{
	return;//Do sth here ,using subwindow if possible (OPTIONAL)
}
