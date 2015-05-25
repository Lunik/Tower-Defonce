#include "menu.h"

void sdlMenuInit(Menu *menu,SDL_Surface *surfaceEcran)
{
	menu->surfaceEcran = surfaceEcran;
	menu->cursor = newCursor();
	menu->cursor->position.x = 8;
	menu->cursor->position.y = 6;

	menu->helpAff =0;

	Coord c;
	c.x = 8;
	c.y = 12;
	menu->cursor->max = c;
	c.x = 8;
	c.y = 6;
	menu->cursor->min = c;

	menu->police = TTF_OpenFont("data/font.ttf", 20);
	menu->policeMin = TTF_OpenFont("data/font.ttf", 12);

	menu->Background = newSprite();
	addSprite(menu->Background, "data/menu/background/0.png");

	menu->Title = newSprite();
	addSprite(menu->Title, "data/menu/title/0.png");

	menu->Cursor = newSprite();
	addSprite(menu->Cursor, "data/menu/cursor/0.png");

	menu->Button = newSprite();
	addSprite(menu->Button, "data/menu/button/0.png");

	menu->cinematique = 1;
}

void sdlMenuAff(Menu *menu)
{
	char charBuffer[255];
	SDL_Color colorWhite = {255, 255, 255};
	SDL_Color colorRed = {200, 0, 0};

	// Remplir l'ecran de noir
	SDL_FillRect(menu->surfaceEcran, &menu->surfaceEcran->clip_rect, SDL_MapRGB(menu->surfaceEcran->format, 0x00, 0x00, 0x00));


	if (!menu->helpAff)
	{
		//Afficher le background
		sdlApplySurface(menu->Background->sprites[0], menu->surfaceEcran, -1, -1);
		//Afficher le titre
		sdlApplySurface(menu->Title->sprites[0], menu->surfaceEcran, 0, 1.5);

		//Afficher les cases menu
		//jouer
		sdlApplySurface(menu->Button->sprites[0], menu->surfaceEcran, 8U, 6);
		sprintf(charBuffer, "Jouer");
		sdlApplyText(menu->surfaceEcran, 10, 6.1, charBuffer, colorWhite, menu->police);

		//restart
		sdlApplySurface(menu->Button->sprites[0], menu->surfaceEcran, 8, 8);
		sprintf(charBuffer, "Recommencer");
		sdlApplyText(menu->surfaceEcran, 9, 8.1, charBuffer, colorWhite, menu->police);

		//Aide
		sdlApplySurface(menu->Button->sprites[0], menu->surfaceEcran, 8, 10);
		sprintf(charBuffer, "Aide");
		sdlApplyText(menu->surfaceEcran, 10.25, 10.1, charBuffer, colorWhite, menu->police);

		//quiter
		sdlApplySurface(menu->Button->sprites[0], menu->surfaceEcran, 8, 12);
		sprintf(charBuffer, "Quitter");
		sdlApplyText(menu->surfaceEcran, 10, 12.1, charBuffer, colorWhite, menu->police);

		sdlApplySurface(menu->Cursor->sprites[0], menu->surfaceEcran, menu->cursor->position.x, menu->cursor->position.y);
	} 
	else 
	{
		//Affiche l'aide
		//titre
		//Afficher le titre
		sdlApplySurface(menu->Title->sprites[0], menu->surfaceEcran, 0, -1);
		sprintf(charBuffer, "Aide");
		sdlApplyText(menu->surfaceEcran, 12, 3, charBuffer, colorWhite, menu->police);

		sprintf(charBuffer, "K: ");
		sdlApplyText(menu->surfaceEcran, 1, 4, charBuffer, colorRed, menu->police);
		sprintf(charBuffer, "Acheter un Chevalier");
		sdlApplyText(menu->surfaceEcran, 2, 4, charBuffer, colorWhite, menu->police);
		sprintf(charBuffer, "Rayon d'action: 1.2, Dommage: 150, Prix: 150, Tape les monstres au sol");
		sdlApplyText(menu->surfaceEcran, 2, 5, charBuffer, colorWhite, menu->policeMin);

		sprintf(charBuffer, "A: ");
		sdlApplyText(menu->surfaceEcran, 1, 6, charBuffer, colorRed, menu->police);
		sprintf(charBuffer, "Acheter un Archer");
		sdlApplyText(menu->surfaceEcran, 2, 6, charBuffer, colorWhite, menu->police);
		sprintf(charBuffer, "Rayon d'action: 3.6, Dommage: 80, Prix: 300, Tape les monstres au sol et volants");
		sdlApplyText(menu->surfaceEcran, 2, 7, charBuffer, colorWhite, menu->policeMin);

		sprintf(charBuffer, "M: ");
		sdlApplyText(menu->surfaceEcran, 1, 8, charBuffer, colorRed, menu->police);
		sprintf(charBuffer, "Acheter un Mage");
		sdlApplyText(menu->surfaceEcran, 2, 8, charBuffer, colorWhite, menu->police);
		sprintf(charBuffer, "Rayon d'action: 2.1, Dommage: 100, Prix: 500, Tape les monstres au sol et volants, Inflige un ralentissement des enemies");
		sdlApplyText(menu->surfaceEcran, 2, 9, charBuffer, colorWhite, menu->policeMin);

		sprintf(charBuffer,"C: ");
		sdlApplyText(menu->surfaceEcran, 1, 10, charBuffer, colorRed, menu->police);
		sprintf(charBuffer, "Acheter un Canon");
		sdlApplyText(menu->surfaceEcran, 2, 10, charBuffer, colorWhite, menu->police);
		sprintf(charBuffer, "Rayon d'action: 2, Dommage: 500, Prix: 1000, Tape les monstres au sol en degats de zone");
		sdlApplyText(menu->surfaceEcran, 2, 11, charBuffer, colorWhite, menu->policeMin);

		sprintf(charBuffer,"V: ");
		sdlApplyText(menu->surfaceEcran, 1, 12, charBuffer, colorRed, menu->police);
		sprintf(charBuffer, "Vendre une tour");
		sdlApplyText(menu->surfaceEcran, 2, 12, charBuffer, colorWhite, menu->police);

		sprintf(charBuffer,"W: ");
		sdlApplyText(menu->surfaceEcran, 1, 13, charBuffer, colorRed, menu->police);
		sprintf(charBuffer, "Lancer une vague d'ennemies");
		sdlApplyText(menu->surfaceEcran, 2, 13, charBuffer, colorWhite, menu->police);

		sprintf(charBuffer,"Echap: ");
		sdlApplyText(menu->surfaceEcran, 1, 14, charBuffer, colorRed, menu->police);
		sprintf(charBuffer, "Retour au menu");
		sdlApplyText(menu->surfaceEcran, 3, 14, charBuffer, colorWhite, menu->police);

		sprintf(charBuffer,"S: ");
		sdlApplyText(menu->surfaceEcran, 1, 15, charBuffer, colorRed, menu->police);
		sprintf(charBuffer, "Augmenter / Diminuer la vitesse du jeu");
		sdlApplyText(menu->surfaceEcran, 2, 15, charBuffer, colorWhite, menu->police);

		sprintf(charBuffer,"I: ");
		sdlApplyText(menu->surfaceEcran, 1, 16, charBuffer, colorRed, menu->police);
		sprintf(charBuffer, "Passer en mode Infinity");
		sdlApplyText(menu->surfaceEcran, 2, 16, charBuffer, colorWhite, menu->police);
	}
}

int sdlMenuBoucle(Menu *menu)
{
	SDL_Event event;
	int continuMenu = 1;
	int returnVal = 0;

	/* Horloges (en secondes) */
	float currentClock, prevClock;

	/* Intervalle de temps (en secondes) entre deux Èvolutions du jeu */
	float intervalClock = 0.1f;

	int rafraichissement;

	sdlMenuAff(menu);
	assert(SDL_Flip(menu->surfaceEcran)!=-1);

	// RÈcupËre l'horloge actuelle et la convertit en secondes
	// clock() retourne le nombre de tops horloge depuis le lancement du programme
	prevClock = (float)clock()/(float)CLOCKS_PER_SEC;

	// Tant que ce n'est pas la fin ...
	while ( continuMenu == 1 )
	{
		rafraichissement = 0;

		// RÈcupËre l'horloge actuelle et la convertit en secondes
		currentClock = (float)clock()/(float)CLOCKS_PER_SEC;
		//printf("\n %f \n %f \n %f \n %f \n", horloge_precedente, horloge_courante, (horloge_courante - horloge_precedente), intervalle_horloge);
		// Si suffisamment de temps s'est ÈcoulÈ depuis la derniËre prise d'horloge

		if ((currentClock - prevClock) >= intervalClock)
		{
			rafraichissement = 1;
			prevClock = currentClock;
		}

		// tant qu'il y a des evenements ‡ traiter : cette boucle n'est pas bloquante
		while (SDL_PollEvent(&event))
		{
			// Si l'utilisateur a cliquÈ sur la croix de fermeture
			if ( event.type == SDL_QUIT )
				continuMenu = 0;

			// Si l'utilisateur a appuyÈ sur une touche
			if (event.type == SDL_KEYDOWN)
			{
				rafraichissement = 1;

				switch (event.key.keysym.sym) 
				{
					//Deplacement curseur haut (up)
				case SDLK_UP:
					moveCursorUp(menu->cursor);
					moveCursorUp(menu->cursor);
					break;

					//Deplacement curseur bas (down)
				case SDLK_DOWN:
					moveCursorDown(menu->cursor);
					moveCursorDown(menu->cursor);
					break;

					//Sors de l'aide
				case SDLK_ESCAPE:
					menu->helpAff = 0;
					break;

				case SDLK_RETURN:
					switch ((int)menu->cursor->position.y)
					{
						//jouer
					case 6:
						returnVal = 1;
						continuMenu = 0;
						if(menu->cinematique)
							cinematique(menu->surfaceEcran);
						menu->cinematique = 0;
						break;
						//rejouer
					case 8:
						returnVal = 2;
						continuMenu = 0;
						break;

						//entre dans l'aide
					case 10:
						menu->helpAff = 1;
						break;
						//quitter
					case 12:
						returnVal = 0;
						continuMenu = 0;
					default:
						break;
					}
					break;
				}
			}
		}
		if (rafraichissement==1)
		{
			// on affiche le jeu sur le buffer caché
			sdlMenuAff(menu);

			// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle)
			SDL_Flip( menu->surfaceEcran );
		}

	}
	return returnVal;
}

void sdlMenuLibere(Menu *menu)
{
	free(menu->cursor);

	freeSprite(menu->Background);
	freeSprite(menu->Title);

	freeSprite(menu->Cursor);
	freeSprite(menu->Button);

	TTF_CloseFont(menu->police);
	TTF_CloseFont(menu->policeMin);
}

void cinematique(SDL_Surface *ecran){
	Sprite *ville = newSprite();
	addSprite(ville, "data/menu/cinematique/ville.png");
	addSprite(ville, "data/menu/cinematique/ville2.png");
	addSprite(ville, "data/menu/cinematique/remember.png");

	Sprite *dialogue = newSprite();
	addSprite(dialogue, "data/menu/cinematique/dialogue/0.png");
	addSprite(dialogue, "data/menu/cinematique/dialogue/1.png");
	addSprite(dialogue, "data/menu/cinematique/dialogue/2.png");
	addSprite(dialogue, "data/menu/cinematique/dialogue/3.png");
	addSprite(dialogue, "data/menu/cinematique/dialogue/4.png");

	Sprite *fire = newSprite();
	addSprite(fire, "data/menu/cinematique/fire/0.png");
	addSprite(fire, "data/menu/cinematique/fire/1.png");
	addSprite(fire, "data/menu/cinematique/fire/2.png");
	addSprite(fire, "data/menu/cinematique/fire/3.png");

	Sprite *pers = newSprite();
	addSprite(pers, "data/menu/cinematique/personnage/0.png");
	addSprite(pers, "data/menu/cinematique/personnage/1.png");
	addSprite(pers, "data/menu/cinematique/personnage/2.png");
	addSprite(pers, "data/menu/cinematique/personnage/3.png");

	sdlApplySurface(ville->sprites[0], ecran, -1, -1);
	sdlApplySurface(ville->sprites[2], ecran, -1, -1);
	SDL_Flip(ecran);

	//#
	//dialogue 1
	sdlApplySurface(ville->sprites[0], ecran, -1, -1);
	sdlApplySurface(ville->sprites[2], ecran, -1, -1);
	sdlApplySurface(dialogue->sprites[0], ecran, 12.5, 7.5);

	SDL_Delay(1500);
	SDL_Flip(ecran);

	//#
	//dialogue 2
	sdlApplySurface(ville->sprites[0], ecran, -1, -1);
	sdlApplySurface(ville->sprites[2], ecran, -1, -1);
	sdlApplySurface(dialogue->sprites[1], ecran, 13.5, 7.5);

	SDL_Delay(1500);
	SDL_Flip(ecran);

	//#
	//dialogue 3
	sdlApplySurface(ville->sprites[0], ecran, -1, -1);
	sdlApplySurface(ville->sprites[2], ecran, -1, -1);
	sdlApplySurface(dialogue->sprites[2], ecran, 13.5, 7.5);

	SDL_Delay(1500);
	SDL_Flip(ecran);

	//#
	//mise en feu de la ville
	sdlApplySurface(ville->sprites[0], ecran, -1, -1);
	sdlApplySurface(ville->sprites[2], ecran, -1, -1);
	sdlApplySurface(dialogue->sprites[2], ecran, 13.5, 7.5);

	//fire
	sdlApplySurface(fire->sprites[1], ecran, 4.6, 8.4);
	sdlApplySurface(fire->sprites[0], ecran, 11, 4.6);

	SDL_Delay(2000);
	SDL_Flip(ecran);

	//#
	//Arrivé du personnage
	sdlApplySurface(ville->sprites[1], ecran, -1, -1);
	sdlApplySurface(pers->sprites[0], ecran, 11, -1.5);

	//fire
	sdlApplySurface(fire->sprites[2], ecran, 5, 4.6);
	sdlApplySurface(fire->sprites[3], ecran, 7, 3);
	sdlApplySurface(fire->sprites[3], ecran, 13, 4.6);
	sdlApplySurface(fire->sprites[2], ecran, 15, 5.4);
	sdlApplySurface(fire->sprites[3], ecran, 13, 10);
	sdlApplySurface(fire->sprites[2], ecran, 15, 12);

	SDL_Delay(2000);
	SDL_Flip(ecran);

	//#
	sdlApplySurface(ville->sprites[1], ecran, -1, -1);
	sdlApplySurface(pers->sprites[1], ecran, 11, -1);

	//fire
	sdlApplySurface(fire->sprites[3], ecran, 5, 4.6);
	sdlApplySurface(fire->sprites[2], ecran, 7, 3);
	sdlApplySurface(fire->sprites[2], ecran, 13, 4.6);
	sdlApplySurface(fire->sprites[3], ecran, 15, 5.4);
	sdlApplySurface(fire->sprites[2], ecran, 13, 10);
	sdlApplySurface(fire->sprites[3], ecran, 15, 12);

	SDL_Delay(100);
	SDL_Flip(ecran);

	//#
	sdlApplySurface(ville->sprites[1], ecran, -1, -1);
	sdlApplySurface(pers->sprites[0], ecran, 11, -0.5);

	//fire
	sdlApplySurface(fire->sprites[2], ecran, 5, 4.6);
	sdlApplySurface(fire->sprites[3], ecran, 7, 3);
	sdlApplySurface(fire->sprites[3], ecran, 13, 4.6);
	sdlApplySurface(fire->sprites[2], ecran, 15, 5.4);
	sdlApplySurface(fire->sprites[3], ecran, 13, 10);
	sdlApplySurface(fire->sprites[2], ecran, 15, 12);

	SDL_Delay(100);
	SDL_Flip(ecran);

	//#
	sdlApplySurface(ville->sprites[1], ecran, -1, -1);
	sdlApplySurface(pers->sprites[2], ecran, 11, 0);

	//fire
	sdlApplySurface(fire->sprites[3], ecran, 5, 4.6);
	sdlApplySurface(fire->sprites[2], ecran, 7, 3);
	sdlApplySurface(fire->sprites[2], ecran, 13, 4.6);
	sdlApplySurface(fire->sprites[3], ecran, 15, 5.4);
	sdlApplySurface(fire->sprites[2], ecran, 13, 10);
	sdlApplySurface(fire->sprites[3], ecran, 15, 12);

	SDL_Delay(100);
	SDL_Flip(ecran);

	//#
	sdlApplySurface(ville->sprites[1], ecran, -1, -1);
	sdlApplySurface(pers->sprites[0], ecran, 11, 0);

	//fire
	sdlApplySurface(fire->sprites[2], ecran, 5, 4.6);
	sdlApplySurface(fire->sprites[3], ecran, 7, 3);
	sdlApplySurface(fire->sprites[3], ecran, 13, 4.6);
	sdlApplySurface(fire->sprites[2], ecran, 15, 5.4);
	sdlApplySurface(fire->sprites[3], ecran, 13, 10);
	sdlApplySurface(fire->sprites[2], ecran, 15, 12);

	SDL_Delay(100);
	SDL_Flip(ecran);

	//#
	sdlApplySurface(ville->sprites[1], ecran, -1, -1);
	sdlApplySurface(pers->sprites[0], ecran, 11, 0);
	sdlApplySurface(pers->sprites[3], ecran, 11.1, -1.2);

	//fire
	sdlApplySurface(fire->sprites[3], ecran, 5, 4.6);
	sdlApplySurface(fire->sprites[2], ecran, 7, 3);
	sdlApplySurface(fire->sprites[2], ecran, 13, 4.6);
	sdlApplySurface(fire->sprites[3], ecran, 15, 5.4);
	sdlApplySurface(fire->sprites[2], ecran, 13, 10);
	sdlApplySurface(fire->sprites[3], ecran, 15, 12);

	SDL_Delay(500);
	SDL_Flip(ecran);

	//#
	//fin personnage
	//Message du personnage
	sdlApplySurface(dialogue->sprites[3], ecran, -1, -1);

	SDL_Delay(1500);
	SDL_Flip(ecran);

	//#
	//fin personnage
	//Message de debut
	SDL_FillRect(ecran, &ecran->clip_rect, SDL_MapRGB(ecran->format, 0x00, 0x00, 0x00));
	sdlApplySurface(dialogue->sprites[4], ecran, -1, -1);

	SDL_Delay(2000);
	SDL_Flip(ecran);

	SDL_Delay(2000);

	freeSprite(ville);
	freeSprite(dialogue);
	freeSprite(fire);
	freeSprite(pers);
}





