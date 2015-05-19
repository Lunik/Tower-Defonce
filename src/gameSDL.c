#include "gameSDL.h"
//salut


void sdlMapInit(sdlMap *sdMap)
{
	Map *map;
	Interface *interface;
	int dimx, dimy;

	map = newMap(15, 15);
	setSdlMap(sdMap,map);

	interface = newInterface();
	setSdlMapInterface(sdMap,interface);

	assert(SDL_Init(SDL_INIT_EVERYTHING)!= -1);

	dimx = 15;
	dimy = 15;

	//met les valeurs max de la position du curseur
	sdMap->interface->cursor->max.x = dimx-1;
	sdMap->interface->cursor->max.y = dimy-1;

	dimx = (dimx+10) * 32;
	dimy = (dimy+5) * 32;

	//Creation de l'ecran
	setSdlMapEcran(sdMap,SDL_SetVideoMode(dimx, dimy, 32, SDL_SWSURFACE));
	assert(getSdlMapEcran(sdMap)!=NULL);
	SDL_WM_SetCaption( "Tower Défonce v0.1", NULL );

	//Chargement des images
	sdMap->Path = newSprite();
	addSprite(sdMap->Path, "data/map/path.png");

	sdMap->Terrain = newSprite();
	addSprite(sdMap->Terrain, "data/map/terrain.png");
	addSprite(sdMap->Terrain, "data/map/terrainI.png");

	sdMap->Grotte = newSprite();
	addSprite(sdMap->Grotte, "data/map/grotte.png");

	sdMap->Castle = newSprite();
	addSprite(sdMap->Castle, "data/map/chateau.png");

	sdMap->Life = newSprite();
	addSprite(sdMap->Life, "data/enemies/life/0.png");
	addSprite(sdMap->Life, "data/enemies/life/20.png");
	addSprite(sdMap->Life, "data/enemies/life/40.png");
	addSprite(sdMap->Life, "data/enemies/life/60.png");
	addSprite(sdMap->Life, "data/enemies/life/80.png");
	addSprite(sdMap->Life, "data/enemies/life/100.png");

	sdMap->Projectile = newSprite();
    addSprite(sdMap->Projectile, "data/towers/projectile/0.png"); //mage
    addSprite(sdMap->Projectile, "data/towers/projectile/1.png"); //archer
    addSprite(sdMap->Projectile, "data/towers/projectile/2.png"); //canon

	sdMap->EnemyClassic = newSprite();
	addSprite(sdMap->EnemyClassic, "data/enemies/classic/0.png");
	addSprite(sdMap->EnemyClassic, "data/enemies/classic/1.png");
	addSprite(sdMap->EnemyClassic, "data/enemies/classic/2.png");
	addSprite(sdMap->EnemyClassic, "data/enemies/classic/3.png");

	sdMap->EnemyFly = newSprite();
	addSprite(sdMap->EnemyFly, "data/enemies/fly/0.png");
	addSprite(sdMap->EnemyFly, "data/enemies/fly/1.png");

	sdMap->EnemyBoss = newSprite();
	addSprite(sdMap->EnemyBoss, "data/enemies/boss/0.png");

	sdMap->TowerAura = newSprite();
	addSprite(sdMap->TowerAura, "data/towers/aura/0.png");
	addSprite(sdMap->TowerAura, "data/towers/aura/1.png");
	addSprite(sdMap->TowerAura, "data/towers/aura/2.png");
	addSprite(sdMap->TowerAura, "data/towers/aura/3.png");
	addSprite(sdMap->TowerAura, "data/towers/aura/4.png");

	sdMap->TowerArcher = newSprite();
	addSprite(sdMap->TowerArcher, "data/towers/archer/0.png");
	addSprite(sdMap->TowerArcher, "data/towers/archer/1.png");
	addSprite(sdMap->TowerArcher, "data/towers/archer/2.png");

	sdMap->TowerCannon = newSprite();
	addSprite(sdMap->TowerCannon, "data/towers/cannon/0.png");
	addSprite(sdMap->TowerCannon, "data/towers/cannon/2.png");
	addSprite(sdMap->TowerCannon, "data/towers/cannon/1.png");

	sdMap->TowerKnight = newSprite();
	addSprite(sdMap->TowerKnight, "data/towers/knight/0.png");
	addSprite(sdMap->TowerKnight, "data/towers/knight/2.png");
	addSprite(sdMap->TowerKnight, "data/towers/knight/1.png");

	sdMap->TowerMage = newSprite();
	addSprite(sdMap->TowerMage, "data/towers/mage/0.png");
	addSprite(sdMap->TowerMage, "data/towers/mage/1.png");
	addSprite(sdMap->TowerMage, "data/towers/mage/2.png");

	sdMap->Cursor = newSprite();
	addSprite(sdMap->Cursor, "data/interface/cursor.png");

	sdMap->Range = newSprite();
	addSprite(sdMap->Range, "data/interface/range.png");

	sdMap->InterfaceBackground = newSprite();
	addSprite(sdMap->InterfaceBackground, "data/interface/background/0.png");
	addSprite(sdMap->InterfaceBackground, "data/interface/background/1.png");

	//Init sdl_ttf
	if(TTF_Init() == -1)
	{
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	//Chargement des polices
	sdMap->policeMax = TTF_OpenFont("data/font.ttf", 70);
	sdMap->police = TTF_OpenFont("data/font.ttf", 20);
	sdMap->policeMin = TTF_OpenFont("data/font.ttf", 12);
	SDL_EnableKeyRepeat(100, 100);

	//Init de options
	setSdlMapSpeed(sdMap,0);
	setSdlMapMode(sdMap,0);
}

void sdlMapAff(const sdlMap *sdMap)
{
	sdlTerrainAff(sdMap);

	sdlEnemyAff(sdMap);

	sdlTowerAff(sdMap);

	sdlInterfaceAff(sdMap);
}

void sdlTerrainAff(const sdlMap *sdMap)
{
	int x,y,i;
	Map *map = getSdlMap(sdMap);
	Coord dim = getMapDim(map);
	//affichage terrain
	if (sdMap->infinityMode)
	{
		sdlApplySurface(sdMap->Terrain->sprites[1], getSdlMapEcran(sdMap), -1, -1);
		
		//Affichage du mode
		SDL_Color colorWhite = {255, 255, 255};
		SDL_Surface *surface;
		surface = textToSurface("INFINITY MODE", colorWhite, sdMap->policeMax);
		sdlApplySurface(surface, getSdlMapEcran(sdMap), 1, 15.5);
		SDL_FreeSurface(surface);
		
		for(i=0; i<13; i++){
			updateSprite(sdMap->TowerAura);
			sdlApplySurface(sdMap->TowerAura->sprites[sdMap->TowerAura->actual], getSdlMapEcran(sdMap), i, 17);
		}
		
	} else {
		sdlApplySurface(sdMap->Terrain->sprites[0], getSdlMapEcran(sdMap), -1, -1);
	}

	//Affichage chemin
	for(y=0;y<dim.y;++y)
	{
		for(x=0;x<dim.x;++x)
		{
			if (getCellPath(map->grid[y][x]))
			{
				sdlApplySurface(sdMap->Path->sprites[0], getSdlMapEcran(sdMap), x, y);
			}
		}
	}

	Coord end = getMapEnd(map);
	//Affichage chateau
	sdlApplySurface(sdMap->Castle->sprites[0], getSdlMapEcran(sdMap), end.y, (end.x-1));

	Coord start = getMapStart(map);
	//affichage arrive des monstres
	sdlApplySurface(sdMap->Grotte->sprites[0], getSdlMapEcran(sdMap), (start.y-1), (start.x-1));
}

void sdlEnemyAff(const sdlMap *sdMap)
{
	//affichage enemies
	int i,iSprite;
	double x,y;
	Map *map = getSdlMap(sdMap);
	for(i=getEnsEnemyNb(getMapEnemys(map)) - 1;i>=0;i--)
	{
		Enemy *e = getMapEnemys(map)->tab[i];
		//position
		Coord pos = getEnemyPosition(e);
		x = pos.x;
		y = pos.y;

		//affichage du sprite
		switch (getEnemyType(e)){
		case 'C':
			iSprite = getSpriteFromTimer(sdMap->EnemyClassic, getEnemyBaseMoveTimer(e), getEnemyMoveTimer(e));
			sdlApplySurface(sdMap->EnemyClassic->sprites[iSprite], getSdlMapEcran(sdMap), x, y);
			break;
		case 'F':
			iSprite = getSpriteFromTimer(sdMap->EnemyFly, getEnemyBaseMoveTimer(e), getEnemyMoveTimer(e));
			sdlApplySurface(sdMap->EnemyFly->sprites[iSprite], getSdlMapEcran(sdMap), x, y);
			break;
		case 'B':
			iSprite = getSpriteFromTimer(sdMap->EnemyBoss, getEnemyBaseMoveTimer(e), getEnemyMoveTimer(e));
			sdlApplySurface(sdMap->EnemyBoss->sprites[iSprite], getSdlMapEcran(sdMap), x, y);
			break;
		}

		//Barre de vie
		if (getEnemyHP(e) == getEnemyMaxHp(e)) 
		{
			sdlApplySurface(sdMap->Life->sprites[5], getSdlMapEcran(sdMap), x, y);
		} else if(getEnemyHP(e) >= getEnemyMaxHp(e)*0.8 && getEnemyHP(e) < getEnemyMaxHp(e)){
			sdlApplySurface(sdMap->Life->sprites[4], getSdlMapEcran(sdMap), x, y);
		} else if(getEnemyHP(e) >= getEnemyMaxHp(e)*0.6 && getEnemyHP(e) < getEnemyMaxHp(e)*0.8){
			sdlApplySurface(sdMap->Life->sprites[3], getSdlMapEcran(sdMap), x, y);
		} else if(getEnemyHP(e) >= getEnemyMaxHp(e)*0.4 && getEnemyHP(e) < getEnemyMaxHp(e)*0.6){
			sdlApplySurface(sdMap->Life->sprites[2], getSdlMapEcran(sdMap), x, y);
		} else if(getEnemyHP(e) >= getEnemyMaxHp(e)*0.2 && getEnemyHP(e) < getEnemyMaxHp(e)*0.4){
			sdlApplySurface(sdMap->Life->sprites[1], getSdlMapEcran(sdMap), x, y);
		} else if(getEnemyHP(e) >= 0 && getEnemyHP(e) < getEnemyHP(e)*0.2){
			sdlApplySurface(sdMap->Life->sprites[0], getSdlMapEcran(sdMap), x, y);
		}
	}
}

void sdlTowerAff(const sdlMap *sdMap)
{
	int i,iSprite;
	int x,y,px,py;
	//affichage des towers
	Map *map = getSdlMap(sdMap);
	for(i=0;i<getEnsTowerNb(getMapTowers(map));++i)
	{
		Tower *t = getMapTowers(map)->tab[i];//position
		Coord* pos = getTowerPosition(t);
		x = pos->x;
		y = pos->y;

		//Affichage de l'aura
		if (getTowerLvl(t) == 5) 
		{
			updateSprite(sdMap->TowerAura);
			sdlApplySurface(sdMap->TowerAura->sprites[sdMap->TowerAura->actual], getSdlMapEcran(sdMap), (x-1), (y-1));
		}

		Projectile *p = getTowerProjectile(t);
		pos = getTowerPosition(t);
		px = pos->x;
		py = pos->y;
		
		//Affichage de la tour
		switch (map->towers->tab[i]->type)
		{
		case 'A':
			//Affiche le projectile
			if(p != NULL)
				sdlApplySurface(sdMap->Projectile->sprites[1], getSdlMapEcran(sdMap), px, py);
			iSprite = getSpriteFromTimer(sdMap->TowerArcher, getTowerDefaultTimer(t), getTowerTimer(t));
			sdlApplySurface(sdMap->TowerArcher->sprites[iSprite], getSdlMapEcran(sdMap), x, y);
			break;
		case 'K':
			iSprite = getSpriteFromTimer(sdMap->TowerKnight, getTowerDefaultTimer(t), getTowerTimer(t));
			sdlApplySurface(sdMap->TowerKnight->sprites[iSprite], getSdlMapEcran(sdMap), x, y);
			break;
		case 'M':
			//Affiche le projectile
			if(p != NULL)
				sdlApplySurface(sdMap->Projectile->sprites[0], getSdlMapEcran(sdMap), px, py);
			iSprite = getSpriteFromTimer(sdMap->TowerMage, getTowerDefaultTimer(t), getTowerTimer(t));
			sdlApplySurface(sdMap->TowerMage->sprites[iSprite], getSdlMapEcran(sdMap), x, y);
			break;
		case 'C':
			//Affiche le projectile
			if(p != NULL)
				sdlApplySurface(sdMap->Projectile->sprites[2], getSdlMapEcran(sdMap), px, py);
			iSprite = getSpriteFromTimer(sdMap->TowerCannon, getTowerDefaultTimer(t), getTowerTimer(t));
			sdlApplySurface(sdMap->TowerCannon->sprites[iSprite], getSdlMapEcran(sdMap), x, y);
			break;
		}
	}
}

void sdlInterfaceAff(const sdlMap *sdMap)
{
	int baseX = 16;
	int baseY = 14;
	int cx,cy;
	//affichage cursor
	Map *map = getSdlMap(sdMap);
	Coord dim = getMapDim(map);

	Interface *interface = getSdlMapInterface(sdMap);

	Coord cpos = getCursorPosition(getInterfaceCursor(interface));
	cx = cpos.x;
	cy = cpos.y;
	//Affichage du curseur
	sdlApplySurface(sdMap->Cursor->sprites[0], getSdlMapEcran(sdMap), cx, cy);

	//Affichage background interface gauche
	sdlApplySurface(sdMap->InterfaceBackground->sprites[0], getSdlMapEcran(sdMap), (baseY+1), -0.6);

	char charBuffer[255];
	SDL_Surface *surface;

	//Init couleur sdl
	SDL_Color colorRed = {200, 0, 0};
	SDL_Color colorGreen = {0, 100, 0};
	SDL_Color colorYellow = {255, 255, 0};
	SDL_Color colorWhite = {255, 255, 255};
	SDL_Color colorBlack = {0, 0, 0};

	//affichage gold
	sprintf(charBuffer, "Or: %d", getMapGold(map));
	sdlApplyText(getSdlMapEcran(sdMap), baseX, 0, charBuffer, colorYellow, sdMap->police);

	//affichage life
	sprintf(charBuffer, "Vie: %d", getMapLife(map));
	sdlApplyText(getSdlMapEcran(sdMap), baseX, 1, charBuffer, colorRed, sdMap->police);

	//affichage vague
	sprintf(charBuffer, "Wave: %d", getMapWave(map));
	sdlApplyText(getSdlMapEcran(sdMap), baseX, 3, charBuffer, colorBlack, sdMap->police);

	//affichage aide pour nouvelle vague
	if (isWaveEnd(map)) 
	{
		sprintf(charBuffer, "\'W\' pour une nouvelle vague");
		sdlApplyText(getSdlMapEcran(sdMap), baseX, 3.6, charBuffer, colorBlack, sdMap->policeMin);
	}


	//affichage ennemies restant
	sprintf(charBuffer, "Ennemies restant:");
	sdlApplyText(getSdlMapEcran(sdMap), baseX, 5, charBuffer, colorBlack, sdMap->police);

	//affichage nb enemies restant
	sprintf(charBuffer, "%d", getEnsEnemyNb(getMapEnemys(map)));
	sdlApplyText(getSdlMapEcran(sdMap), baseX, 6, charBuffer, colorBlack, sdMap->policeMin);

	//Affichage de la vitesse
	if (getSdlMapSpeed(sdMap)) 
	{
		sprintf(charBuffer, "Vitesse: x2");
	} else {
		sprintf(charBuffer, "Vitesse: x1");
	}
	sdlApplyText(getSdlMapEcran(sdMap), baseX, 7, charBuffer, colorBlack, sdMap->police);

	sprintf(charBuffer, "\'S\' pour accelerer / ralentir");
	sdlApplyText(getSdlMapEcran(sdMap), baseX, 7.6, charBuffer, colorBlack, sdMap->policeMin);

	//affichage Tower sur le curseur
	if(interface->tower != NULL)
	{
		Tower *ti = interface->tower;
		//Affichage background interface tower
		sdlApplySurface(sdMap->InterfaceBackground->sprites[1], getSdlMapEcran(sdMap), baseY+0.8, (baseX-2.5));

		//Affichage du range de la tower
		int i,j;
		Coord* tPos = getTowerPosition(ti);
		double tRangeMin = getTowerRangeMin(ti);
		double tRangeMax = getTowerRangeMax(ti);
		double dist;

		for (i=0; i<dim.x; i++)
		{
			for (j=0; j<dim.y; j++) 
			{
				dist = getCoordsDistance(*tPos, map->grid[i][j]->position);
				if( (dist >= tRangeMin) && (dist <= tRangeMax) )
				{
					sdlApplySurface(sdMap->Range->sprites[0], getSdlMapEcran(sdMap), i, j);
				}
			}
		}

		//Affichage image tower
		switch (getTowerType(ti))
		{
		case 'A':
			surface = sdMap->TowerArcher->sprites[0];
			sprintf(charBuffer, "Archer Niv %d", getTowerLvl(ti));
			break;
		case 'K':
			surface = sdMap->TowerKnight->sprites[0];
			sprintf(charBuffer, "Chevalier Niv %d", getTowerLvl(ti));
			break;
		case 'M':
			surface = sdMap->TowerMage->sprites[0];
			sprintf(charBuffer, "Mage Niv %d", getTowerLvl(ti));
			break;
		case 'C':
			surface = sdMap->TowerCannon->sprites[0];
			sprintf(charBuffer, "Canon Niv %d", getTowerLvl(ti));
			break;
		default:
			surface = sdMap->Path->sprites[0];
			break;
		}
		sdlApplySurface(surface, getSdlMapEcran(sdMap), baseX, (baseY+1));

		sdlApplyText(getSdlMapEcran(sdMap), baseX, baseY, charBuffer, colorBlack, sdMap->police);

		//Affichage infos de la tower
		sprintf(charBuffer, "Dommages %.0f", getTowerDmg(ti));
		sdlApplyText(getSdlMapEcran(sdMap), baseX+3, baseY+1, charBuffer, colorBlack, sdMap->police);

		sprintf(charBuffer, "\'E\' pour evoluer (%d gold)", getTowerCost(ti));
		if(getTowerLvl(ti) < 5)
		{
			if(getTowerCost(ti) <= getMapGold(map))
			{
				sdlApplyText(getSdlMapEcran(sdMap), baseX+3, baseY+1.6, charBuffer, colorGreen, sdMap->policeMin);
			} else {
				sdlApplyText(getSdlMapEcran(sdMap), baseX+3, baseY+1.6, charBuffer, colorRed, sdMap->policeMin);
			}
		}
		
		sprintf(charBuffer, "\'V\' pour vendre");
		sdlApplyText(getSdlMapEcran(sdMap), baseX+3, baseY+2, charBuffer, colorBlack, sdMap->policeMin);

	}
}

void sdlMapBoucle(sdlMap *sdMap)
{
	int continuGame = 1;
	int resultMenu;
	int i;
	char c;
	Menu menu;
	sdlMenuInit(&menu, getSdlMapEcran(sdMap));
	//Lancement du menu
	resultMenu = sdlMenuBoucle(&menu);

	SDL_Event event;

	/* Horloges (en secondes) */
	float currentClock, prevClock;

	/* Intervalle de temps (en secondes) entre deux Èvolutions du jeu */
	float intervalClock = 0.1f;

	int rafraichissement;

	sdlMapAff(sdMap);
	assert(SDL_Flip(getSdlMapEcran(sdMap))!=-1);

	// RÈcupËre l'horloge actuelle et la convertit en secondes 
	// clock() retourne le nombre de tops horloge depuis le lancement du programme 
	prevClock = (float)clock()/(float)CLOCKS_PER_SEC;

	// Tant que ce n'est pas la fin ... 
	while (continuGame == 1)
	{
		switch (resultMenu) 
		{
		case 0:
			continuGame = 0;
			resultMenu = 1;
			break;
		case 2:
			setSdlMap(sdMap,newMap(15, 15));
			setSdlMapMode(sdMap, 0);
			setSdlMapSpeed(sdMap, 0);
			continuGame = 1;
			resultMenu = 1;
			break;
		default:
			break;
		}

		rafraichissement = 0;

		// RÈcupËre l'horloge actuelle et la convertit en secondes
		currentClock = (float)clock()/(float)CLOCKS_PER_SEC;
		//printf("\n %f \n %f \n %f \n %f \n", horloge_precedente, horloge_courante, (horloge_courante - horloge_precedente), intervalle_horloge);
		// Si suffisamment de temps s'est ÈcoulÈ depuis la derniËre prise d'horloge

		if ((currentClock - prevClock) >= intervalClock)
		{
			if (getSdlMapSpeed(sdMap)) 
			{
				for (i=0; i<10; i++) 
				{
					updateMap(getSdlMap(sdMap));
				}
			} else {
				for (i=0; i<5; i++) 
				{
					updateMap(sdMap->map);
				}
			}

			updateInterface(getSdlMapInterface(sdMap), getSdlMap(sdMap));
			rafraichissement = 1;
			prevClock = currentClock;

			if(getSdlMap(sdMap)->life <= 0)
			{
				resultMenu = sdlMenuBoucle(&menu);
			}

			if(getSdlMapMode(sdMap) && isWaveEnd(getSdlMap(sdMap)))
			{
				newWave(getSdlMap(sdMap));
			}

		}

		// tant qu'il y a des evenements ‡ traiter : cette boucle n'est pas bloquante 
		while (SDL_PollEvent(&event))
		{
			// Si l'utilisateur a cliquÈ sur la croix de fermeture 
			if ( event.type == SDL_QUIT )
				continuGame = 0;

			// Si l'utilisateur a appuyÈ sur une touche 
			if (event.type == SDL_KEYDOWN)
			{
				rafraichissement = 1;
				Map *map = getSdlMap(sdMap);
				Interface *interface = getSdlMapInterface(sdMap);
				Cursor *cursor = getInterfaceCursor(interface);
				switch (event.key.keysym.sym) 
				{
					//Quiter (esc)
				case SDLK_ESCAPE:
					resultMenu = sdlMenuBoucle(&menu);
					break;

					//Deplacement curseur droite (left)
				case SDLK_LEFT:
					moveCursorLeft(cursor);
					break;

					//Deplacement curseur gauche (right)
				case SDLK_RIGHT:
					moveCursorRight(cursor);
					break;

					//Deplacement curseur haut (up)
				case SDLK_UP:
					moveCursorUp(cursor);
					break;

					//Deplacement curseur bas (down)
				case SDLK_DOWN:
					moveCursorDown(cursor);
					break;

					//Nouvelle vague (w)
				case SDLK_w:
					if(isWaveEnd(map)){
						newWave(map);
					}
					break;

					//Nouvelle tours type archer (a)
				case SDLK_a:
					buyInterfaceTower('A', &(cursor->position), sdMap->map);

					break;

					//Nouvelle tours type knight (k)
				case SDLK_k:
					buyInterfaceTower('K', &(cursor->position), sdMap->map);
					break;

					//Nouvelle tours type mage (m)
				case SDLK_m:
					buyInterfaceTower('M', &(cursor->position), sdMap->map);
					break;

				case SDLK_c:
					buyInterfaceTower('C', &(cursor->position), sdMap->map);
					break;

				case SDLK_e:
					if(isCursorOnTower(cursor, getSdlMap(sdMap)))
					{
						evolveTower(interface->tower, &map->gold);
					}
					break;

				case SDLK_v:
					sellInterfaceTower(getSdlMap(sdMap), &(cursor->position), getInterfaceTower(interface));
					break;

				case SDLK_s:
					if (getSdlMapSpeed(sdMap))
					{
						setSdlMapSpeed(sdMap,0);
					} else 
					{
						setSdlMapSpeed(sdMap,1);
					}
					break;
				case SDLK_i:
					if(getSdlMapMode(sdMap)){
						setSdlMapMode(sdMap,0);
					} else {
						setSdlMapMode(sdMap,1);
					}
					break;
				default:
					break;
				}
			}
		}
		if (rafraichissement==1)
		{
			// on affiche le jeu sur le buffer caché
			sdlMapAff(sdMap);

			// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle)
			SDL_Flip( getSdlMapEcran(sdMap) );
		}

	}
	sdlMenuLibere(&menu);
}

void sdlMapLibere(sdlMap *sdMap)
{

	freeSprite(sdMap->Terrain);
	freeSprite(sdMap->Path);
	freeSprite(sdMap->Castle);
	freeSprite(sdMap->Grotte);

	SDL_FreeSurface(getSdlMapEcran(sdMap));

	freeSprite(sdMap->TowerAura);
	freeSprite(sdMap->TowerKnight);
	freeSprite(sdMap->TowerArcher);
	freeSprite(sdMap->TowerMage);
	freeSprite(sdMap->TowerCannon);

	freeSprite(sdMap->Life);
	freeSprite(sdMap->EnemyFly);
	freeSprite(sdMap->EnemyClassic);
	freeSprite(sdMap->EnemyBoss);

	freeSprite(sdMap->Cursor);
	freeSprite(sdMap->Range);
	freeSprite(sdMap->InterfaceBackground);

	freeMap(getSdlMap(sdMap));
	freeInterface(getSdlMapInterface(sdMap));

	TTF_CloseFont(sdMap->police);
	TTF_CloseFont(sdMap->policeMin);
	TTF_Quit();

	SDL_Quit();
}

int getSdlMapMode(const sdlMap *sdMap)
{
	return sdMap->infinityMode;
}

void setSdlMapMode(sdlMap *sdMap, int mode)
{
	sdMap->infinityMode = mode;
}

int getSdlMapSpeed(const sdlMap *sdMap)
{
	return sdMap->speed;
}

void setSdlMapSpeed(sdlMap *sdMap, int speed)
{
	sdMap->speed = speed;
}

Map* getSdlMap(const sdlMap *sdMap)
{
	return sdMap->map;
}

void setSdlMap(sdlMap *sdMap, Map *map)
{
	sdMap->map = map;
}

Interface* getSdlMapInterface(const sdlMap *sdMap)
{
	return sdMap->interface;
}

void setSdlMapInterface(sdlMap *sdMap, Interface *i)
{
	sdMap->interface = i;
}

SDL_Surface* getSdlMapEcran(const sdlMap *sdMap)
{
	return sdMap->surfaceEcran;
}

void setSdlMapEcran(sdlMap *sdMap, SDL_Surface* ecran)
{
	sdMap->surfaceEcran = ecran;
}
