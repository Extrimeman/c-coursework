#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void pokazi_one(int **tab, int razmer)
{
	
	int i,j;
		for(j=0;j<razmer+1;j++)
		{
				if(j==0)printf("   ");
				else
				{
					if(j<=9)
					printf("\033[1m%d \033[0m ",j);
					else
					printf("\033[1m%d\033[0m ",j);
				}
		}
				printf("\n");
	for(i =0; i < razmer;i++)
		{
			for(j=0;j<razmer;j++)
			{

					if(j==0)
					{
						if(i<9)printf("\033[1m%d \033[0m ",i+1);
						else
						printf("\033[1m%d\033[0m ",i+1);
					}
					if(tab[i][j]==0)
						printf("'  ");
					else printf("S  ");

			}
		printf("\n");
		}
}

void show_two(int **tab, int **bat, int razmer)
{
	
	int i,j;
		for(j=0;j<razmer+1;j++)
		{
				if(j==0)printf("   ");
				else
				{
					if(j<=9)
					printf("\033[1m%d \033[0m ",j);
					else
					printf("\033[1m%d\033[0m ",j);
				}
		}
		printf("\t");
		for(j=0;j<razmer+1;j++)
		{
				if(j==0)printf("   ");
				else
				{
					if(j<=9)
					printf("\033[1m%d \033[0m ",j);
					else
					printf("\033[1m%d\033[0m ",j);
				}
		}

				printf("\n");


	for(i =0; i < razmer;i++)
		{
			for(j=0;j<razmer;j++)
			{

					if(j==0)
					{
						if(i<9)
						{
							printf("\033[1m%d \033[0m ",i+1);
						}
						else
						{
							printf("\033[1m%d\033[0m ",i+1);
						}
					}
					switch(tab[i][j])
					{
						case 0: printf("'  "); break;
						case 1: printf("S  "); break;
						case 2: printf("P  "); break;
						case 8: printf("X  "); break;
					}

			}
					printf("\t");
				for(j=0;j<razmer;j++)
				{
					if(j==0)
					{
						if(i<9)
						{
							printf("\033[1m%d \033[0m ",i+1);
						}
						else
						{
							printf("\033[1m%d\033[0m ",i+1);
						}
					}
					switch(bat[i][j])
					{
						case 0: printf("'  "); break;
						case 1: printf("S  "); break;
						case 2: printf("P  "); break;
						case 8: printf("X  "); break;
					}

				}

		printf("\n");
		}
}


int place_ship(int **tab,int razmer)
{

	int err=0;
	int x,y,k,length;
	int i,j, iferror=0;
	int loaded=4;
	char dummy;

	do
	{
		pokazi_one(tab,razmer);
		iferror=0;
		if(err==1) printf("Wrong size, coordinates or direction.\n");
			printf("Get coordinates of the start of the ship, it's direction(1 to the side 0 down) and length(1-5)\nIn form of:(x y k d):");
		if(loaded<4)scanf("%c",&dummy);
		loaded=scanf("%d %d %d %d",&y,&x,&k, &length);
		if(x>0 && y>0 && (k==0 || k==1) && (length>0 && length<6) && loaded==4)
		{

			if((k==0 && x<razmer-length+2)||(k==1 && y<razmer-length+2))
			{

				if(k==0)
					{
						for(i=x-1;i<x+length-1;i++)
							if(tab[i][y-1]==1) iferror=1;
						for(i=x-1;i<x+length-1;i++)
						{

							if(iferror==0)
								tab[i][y-1]=1;
							else err=1;
						}
						if(iferror==0)err=0;
					}
				else
				{
					for(j=y-1;j<y+length-1;j++)
					{
						if(tab[x-1][j]==1) iferror=1;
					}
					for(j=y-1;j<y+length-1;j++)
					{
						if(iferror==0)
						tab[x-1][j]=1;
						else err=1;
					}
					if(iferror==0)err=0;
				}
			}
			else err=1;
		}
		else err=1;
		system("clear");
	}
	while(err);
			return length;
}


void draw_ship(int **tab, int length,int razmer)
{

	int err=0;
	do
	{
	int i,j, iferror=0;
		int x,y,k;
		x=1+rand()%razmer;
		y=1+rand()%razmer;
		k=rand()%2;

			if((k==0 && x<razmer-length+2)||(k==1 && y<razmer-length+2))
			{

		if(k==0)
			{
				for(i=x-1;i<x+length-1;i++)
					if(tab[i][y-1]==1) iferror=1;
				for(i=x-1;i<x+length-1;i++)
				{

					if(iferror==0)
					tab[i][y-1]=1;
					else err=1;
				}
				if(iferror==0)err=0;
			}
				else
				{
					for(j=y-1;j<y+length-1;j++)
					{
						if(tab[x-1][j]==1) iferror=1;
					}
					for(j=y-1;j<y+length-1;j++)
					{
						if(iferror==0)
						tab[x-1][j]=1;
						else err=1;
					}
					if(iferror==0)err=0;
				}
			}else err=1;
		}while(err);
}

void shoot(int **enemy,int **shots,int razmer)
{
		int x,y,loaded;
		char dummy;
		printf("\nEnter coordinates of the firing points:");
		loaded=scanf("%d %d",&x,&y);
		while(x<=0 || x>razmer || y<=0 || y>razmer || loaded<2 )
		{
			if(loaded<2)scanf("%c",&dummy);
			printf("Wrong coordinates!");
			printf("\nEnter coordinates of the firing points:");
			loaded=scanf("%d %d",&x,&y);
		}
		x--;
		y--;
		if(enemy[y][x]==1)
		{
			shots[y][x]=8;
		}else shots[y][x]=2;
}

int count_player_ships(int **tab,int razmer)
{
	int summa =0;
	int i,j;

	for(i=0;i<razmer;i++)
		for(j=0;j<razmer;j++)
		if(tab[i][j]==1)summa++;

	return summa;
}

int count_enemy_ships(int **ships,int **hits, int razmer)
{
	
	int i,j,summa=0,shot=0;
	for(i=0;i<razmer;i++)
		for(j=0;j<razmer;j++)
		if(ships[i][j]==1)summa++;
	for(i=0;i<razmer;i++)
		for(j=0;j<razmer;j++)
		if(hits[i][j]==8)shot++;

	return summa-shot;

}

void AI_shoot(int **tab,int razmer)
{
	
		int x,y;
		static int ost_x,ost_y;
		static int ifhit=0;
		static int offset=1;
		static int verticalguesses=0;

		switch(ifhit)
		{
			case 0:
			{

				x=rand()%razmer;
				y=rand()%razmer;

				while(tab[y][x]==2 || tab[y][x]==8)
				{
					x=rand()%razmer;
					y=rand()%razmer;
				}

				if(tab[y][x]==1)
				{
					tab[y][x]=8;
					ifhit=4;
					ost_x=x;
					ost_y=y;
				}else tab[y][x]=2;
					break;
			}
			case 4:
			{
				if(ost_x+offset<=razmer-1)
				{
					if(tab[ost_y][ost_x+offset]==1)
					{
						tab[ost_y][ost_x+offset]=8;
						offset++;
					}
					else
					{
						tab[ost_y][ost_x+offset]=2;
						if(offset==1)
							verticalguesses=1;
						ifhit=3;
						offset=1;
					}
				}
				else
				{
					if(offset==1)
							verticalguesses=1;
						ifhit=3;
						offset=1;
				}
				break;
			}
			case 3:
			{
				if(ost_x-offset>=0)
				{
					if(tab[ost_y][ost_x-offset]==1)
					{
						tab[ost_y][ost_x-offset]=8;
						offset++;
					}
					else
					{
						tab[ost_y][ost_x-offset]=2;
						if(offset==1 && verticalguesses==1)
							ifhit=2;
							else
							ifhit=0;
						offset=1;
					}
				}
				else
				{
					if(offset==1 && verticalguesses==1)
							ifhit=2;
							else
							ifhit=0;
						offset=1;
				}
				break;
			}
			case 2:
			{
				if(ost_y+offset<=razmer-1)
				{
					if(tab[ost_y+offset][ost_x]==1)
					{
						tab[ost_y+offset][ost_x]=8;
						offset++;
					}
					else
					{
						tab[ost_y+offset][ost_x]=2;
							ifhit=1;
							offset=1;
					}
				}
				else
				{
					ifhit=1;
					offset=1;
				}
					break;
			}
			case 1:
			{
				if(ost_y-offset>=0)
				{
					if(tab[ost_y-offset][ost_x]==1)
					{
						tab[ost_y-offset][ost_x]=8;
						offset++;
					}
					else
					{
						tab[ost_y-offset][ost_x]=2;
						ifhit=0;
						offset=1;
						verticalguesses=0;
					}
				}
				else
				{
						ifhit=0;
						offset=1;
						verticalguesses=0;
				}
				break;
			}
		}

}


int main(int argc, char* argv[])
{
	srand(time(NULL));
	int i,j,shipcount;
	int **player; 
	int **enemy;
	int **firing; 
	int ships[5]={0};
	int razmer=atoi(argv[1])*5+5;
	int loaded;
	char dummy;

	player=(int**)malloc(razmer*sizeof(int*));
	enemy=(int**)malloc(razmer*sizeof(int*));
	firing=(int**)malloc(razmer*sizeof(int*));
	for (i=0;i<razmer;i++)
	{
		player[i]=(int*)malloc(razmer*sizeof(int));
		enemy[i]=(int*)malloc(razmer*sizeof(int));
		firing[i]=(int*)malloc(razmer*sizeof(int));
	}
	system("clear");

			printf("Number of ships(1-20):");
			loaded=scanf("%d",&shipcount);
			if(loaded<1)scanf("%c",&dummy);
			while(shipcount<1 || shipcount>20)
			{
				system("clear");
				printf("Incorrect info!\n");
				printf("Number of ships(1-20):");
				loaded=scanf("%d",&shipcount);
				if(loaded<1)scanf("%c",&dummy);
			}

			system("clear");
			for(i=0;i<shipcount;i++)
			switch(place_ship(player,razmer))
		{
			case 1:
			ships[0]++;
			break;

			case 2:
			ships[1]++;
			break;

			case 3:
			ships[2]++;
			break;

			case 4:
			ships[3]++;
			break;

			case 5:
			ships[4]++;
			break;
		}


		for(i=0; i<5;i++)
		{
			for(j=0;j<ships[i];j++)
			draw_ship(enemy,i+1,razmer);
		}

		system("clear");
		while(count_player_ships(player,razmer)>0 && count_enemy_ships(enemy,firing,razmer)>0)
		{
			show_two(player,firing,razmer);
			printf("Player ship slots: %d\n",count_player_ships(player,razmer));
			printf("Enemy ship slots: %d",count_enemy_ships(enemy,firing,razmer));
			shoot(enemy,firing,razmer);
			AI_shoot(player,razmer);
			system("clear");

		}
		if(count_player_ships(player,razmer)!=0)
		printf("You won!\nEnter something to continue");
		else
		printf("You lost!\nEnter something to continue");
		char symbol;
			scanf("%s",&symbol);

	for (i=0;i<razmer;i++)
	{
		free(player[i]);
		free(enemy[i]);
		free(firing[i]);
	}
	free(player);
	free(enemy);
	free(firing);

	return 0;
}

