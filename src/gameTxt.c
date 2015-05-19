#include "gameTxt.h"

void ncursAff( WINDOW* win, const Map *map)
{
	int x,y;
	char c = '#';
	wclear(win);
	//affichage terrain
	for(x=0;x<map->dimX;++x)
	{
		for(y=0;y<map->dimY;++y)
		{
			if (map->grid[x][y]->path) 
			{
				c = '=';
			} else if(map->grid[x][y]->build)
			{
				c = ' ';
			}
			mvwprintw(win, x, y, "%c ",c);
		}
	}
	//affichage tower
	for(x=0;x<map->getEnsTowerNb(towers);++x)
	{
		mvwprintw(win, map->towers->tab[x]->position.y, map->towers->tab[x]->position.x, "%c",getTowerType(map->towers->tab[x]));
	}
	//affichage des ennemies
	for(x=0;x<map->getEnsEnemyNb(enemys);++x)
	{
		mvwprintw(win, map->enemys->tab[x]->position.y, map->enemys->tab[x]->position.x, "%c",getEnemyType (map->enemys->tab[x]));
	}

	mvwprintw(win, 0, 16, "Life: %d",map->life);
	mvwprintw(win, 1, 16, "Gold: %d",map->gold);
	mvwprintw(win, 16, 0, "Wave: %d",map->wave);
	mvwprintw(win, 17, 0, "Nb ennemis: %d",getEnsEnemyNb(map->enemys));
}

void ncursBoucle(Map *map)
{
	WINDOW *win;
	int c,x,y;
	int continue_boucle;

	/* Horloges (en secondes) */
	float horloge_courante, horloge_precedente;

	/* Intervalle de temps (en secondes) entre deux Èvolutions du jeu */
	/* Changer la valeur pour ralentir ou accÈlÈrer le dÈplacement des fantomes */
	float intervalle_horloge = 0.1;

	initscr();		/* passe l'Ècran texte en mode NCurses */
	clear();		/* efface l'Ècran */
	noecho();  	/* Lorsqu'une touche est prÈssÈe au clavier, elle n'apparait pasa ‡ l'Ècran */
	cbreak();		/* un caractËre est directement affichÈ, il ne passe pas dans un buffer */

	/* Creation d'une nouvelle fenetre en mode texte */
	/* => fenetre de dimension et position ( WIDTH, HEIGHT, STARTX,STARTY) */
	win = newwin(map->dimX+20,map->dimY*2+20, 10, 5);
	keypad(win, TRUE);		/* pour que les flËches soient traitÈes (il faut le faire aprËs crÈation de la fenÍtre) */

	/* notimeout(win,true); */
	/* wtimeout( win, 500 ); */
	nodelay(win,true); /* Pour que l'appel ‡ wgetch soit non-bloquant */

	continue_boucle = 1;
	/* RÈcupËre l'horloge actuelle et la convertit en secondes */
	/* clock() retourne le nombre de tops horloge depuis le lancement du programme */
	horloge_precedente = (float)clock()/(float)CLOCKS_PER_SEC;
	srand(time(NULL));

	ncursAff(win, map);

	do
	{
		/* RÈcupËre l'horloge actuelle et la convertit en secondes */
		/* clock() retourne le nombre de tops horloge depuis le lancement du programme */
		horloge_courante = (float)clock()/(float)CLOCKS_PER_SEC;
		if ((horloge_courante - horloge_precedente) >= intervalle_horloge)
		{
			updateMap(map);
			if (map->life <= 0) 
			{
				continue_boucle = 0;
			}
			ncursAff(win, map);
			horloge_precedente = horloge_courante;
		}
		if (isWaveEnd(map)) 
		{
			mvwprintw(win, 16, 8, "No current Wave");
		} else 
		{
			mvwprintw(win, 18, 0, "Life 1st enemy: %d",getEnemyMaxHp (map->enemys->tab[0]));
			mvwprintw(win, 21, 0, "Move Timer 1st Ennemie: %d",getEnemyMoveTimer (map->enemys->tab[0]));
			if(map->towers->nb)
			{
				mvwprintw(win, 19, 0, "Target 1st Tower: %d",getTowerId (map->towers->tab[0]));
				mvwprintw(win, 20, 0, "AttackTimer 1st Tower: %d",getTowerTimer (map->towers->tab[0]));
			}
		}
		c = wgetch(win);
		switch (c) 
		{
		case KEY_RIGHT:
			if(isWaveEnd(map))
			{
				newWave(map);
				mvwprintw(win, 0, 0, "NewWave");
			}
			break;
		case 27: //echap
			freeMap(map);
			continue_boucle = 0;
			break;
		case 't':
			x= -1;
			y= -1;
			do 
			{
				do
				{
					x = rand()%(map->dimX - 0)-0;
					y = rand()%(map->dimY - 0)-0;
				} while (x<0 || x>map->dimX || y<0 || y>map->dimY);
			} while (!isCellBuildable(getCellFromXY(map, y, x)));

			buyTower(&(map->towers), 'A', x, y,&(map->gold));
			map->grid[x][y]->build = 0;
		default:
			break;
		}

	} while (continue_boucle==1);

	assert(delwin(win)!=ERR);

	endwin();
}
