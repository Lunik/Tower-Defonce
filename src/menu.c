#include "menu.h"

void sdlMenuInit(Menu *menu,SDL_Surface *surfaceEcran)
{
	menu->surfaceEcran = surfaceEcran;
	menu->cursor = newCursor();
	menu->cursor->position.x = 8;
	menu->cursor->position.y = 5;

	menu->helpAff =0;

	Coord c;
	c.x = 8;
	c.y = 11;
	menu->cursor->max = c;
	c.x = 8;
	c.y = 5;
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
}

void sdlMenuAff(Menu *menu)
{
	char charBuffer[255];
	SDL_Color colorWhite = {255, 255, 255};
	SDL_Color colorRed = {200, 0, 0};

	// Remplir l'ecran de noir
	SDL_FillRect(menu->surfaceEcran, &menu->surfaceEcran->clip_rect, SDL_MapRGB(menu->surfaceEcran->format, 0x00, 0x00, 0x00));

	//Afficher le background
	//sdlApplySurface(menu->surfaceBackground, menu->surfaceEcran, 1*TAILLE_MENU, 1*TAILLE_MENU);

	//Afficher le titre
	sdlApplySurface(menu->Title->sprites[0], menu->surfaceEcran, 5, 1);


	if (!menu->helpAff)
	{
		//Afficher les cases menu
		//jouer
		sdlApplySurface(menu->Button->sprites[0], menu->surfaceEcran, 8U, 5);
		sprintf(charBuffer, "Jouer");
		sdlApplyText(menu->surfaceEcran, 10, 5.1, charBuffer, colorWhite, menu->police);

		//restart
		sdlApplySurface(menu->Button->sprites[0], menu->surfaceEcran, 8, 7);
		sprintf(charBuffer, "Recommencer");
		sdlApplyText(menu->surfaceEcran, 9, 7.1, charBuffer, colorWhite, menu->police);

		//Aide
		sdlApplySurface(menu->Button->sprites[0], menu->surfaceEcran, 8, 9);
		sprintf(charBuffer, "Aide");
		sdlApplyText(menu->surfaceEcran, 10.25, 9.1, charBuffer, colorWhite, menu->police);

		//quiter
		sdlApplySurface(menu->Button->sprites[0], menu->surfaceEcran, 8, 11);
		sprintf(charBuffer, "Quitter");
		sdlApplyText(menu->surfaceEcran, 10, 11.1, charBuffer, colorWhite, menu->police);

		sdlApplySurface(menu->Cursor->sprites[0], menu->surfaceEcran, menu->cursor->position.x, menu->cursor->position.y);
	} 
	else 
	{
		//Affiche l'aide
		//titre
		SDL_Surface *quitBut = textToSurface("Aide", colorWhite, menu->police);
		sdlApplySurface(quitBut, menu->surfaceEcran, 9, 3);
		SDL_FreeSurface(quitBut);

		SDL_Surface *helpLine;
		SDL_Surface *underHelpLine;

		helpLine = textToSurface("K: ", colorRed, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 1, 4);
		SDL_FreeSurface(helpLine);
		helpLine = textToSurface("Acheter un Chevalier", colorWhite, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 2, 4);
		SDL_FreeSurface(helpLine);
		underHelpLine = textToSurface("Rayon d'action: 1.2, Dommage: 150, Prix: 150, Tape les monstres au sol", colorWhite, menu->policeMin);
		sdlApplySurface(underHelpLine, menu->surfaceEcran, 2, 5);
		SDL_FreeSurface(underHelpLine);

		helpLine = textToSurface("A: ", colorRed, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 1, 6);
		SDL_FreeSurface(helpLine);
		helpLine = textToSurface("Acheter un Archer", colorWhite, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 2, 6);
		SDL_FreeSurface(helpLine);
		underHelpLine = textToSurface("Rayon d'action: 3.6, Dommage: 80, Prix: 300, Tape les monstres au sol et volants", colorWhite, menu->policeMin);
		sdlApplySurface(underHelpLine, menu->surfaceEcran, 2, 7);
		SDL_FreeSurface(underHelpLine);

		helpLine = textToSurface("M: ", colorRed, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 1, 8);
		SDL_FreeSurface(helpLine);
		helpLine = textToSurface("Acheter un Mage", colorWhite, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 2, 8);
		SDL_FreeSurface(helpLine);
		underHelpLine = textToSurface("Rayon d'action: 2.1, Dommage: 100, Prix: 500, Tape les monstres au sol et volants, Inflige un ralentissement des enemies", colorWhite, menu->policeMin);
		sdlApplySurface(underHelpLine, menu->surfaceEcran, 2, 9);
		SDL_FreeSurface(underHelpLine);

		helpLine = textToSurface("K: ", colorRed, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 1, 10);
		SDL_FreeSurface(helpLine);
		helpLine = textToSurface("Acheter un Canon", colorWhite, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 2, 10);
		SDL_FreeSurface(helpLine);
		underHelpLine = textToSurface("Rayon d'action: 2, Dommage: 500, Prix: 1000, Tape les monstres au sol en dégats de zone", colorWhite, menu->policeMin);
		sdlApplySurface(underHelpLine, menu->surfaceEcran, 2, 11);
		SDL_FreeSurface(underHelpLine);

		helpLine = textToSurface("V: ", colorRed, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 1, 12);
		SDL_FreeSurface(helpLine);
		helpLine = textToSurface("Vendre une tour", colorWhite, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 2, 12);
		SDL_FreeSurface(helpLine);

		helpLine = textToSurface("W: ", colorRed, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 1, 13);
		SDL_FreeSurface(helpLine);
		helpLine = textToSurface("Lancer une vague d'ennemies", colorWhite, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 2, 13);
		SDL_FreeSurface(helpLine);

		helpLine = textToSurface("Echap: ", colorRed, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 1, 14);
		SDL_FreeSurface(helpLine);
		helpLine = textToSurface("Retour au menu", colorWhite, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 3, 14);
		SDL_FreeSurface(helpLine);

		helpLine = textToSurface("S: ", colorRed, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 1, 15);
		SDL_FreeSurface(helpLine);
		helpLine = textToSurface("Augmenter / Diminuer la vitesse du jeu", colorWhite, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 2, 15);
		SDL_FreeSurface(helpLine);

		helpLine = textToSurface("I: ", colorRed, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 1, 16);
		SDL_FreeSurface(helpLine);
		helpLine = textToSurface("Passer en mode Infinity", colorWhite, menu->police);
		sdlApplySurface(helpLine, menu->surfaceEcran, 2, 16);
		SDL_FreeSurface(helpLine);
	}
}

int sdlMenuBoucle(Menu *menu)
{
	printf("Menu\n");
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
					case 5:
						returnVal = 1;
						continuMenu = 0;
						break;
						//rejouer
					case 7:
						returnVal = 2;
						continuMenu = 0;
						break;

						//entre dans l'aide
					case 9:
						menu->helpAff = 1;
						break;
						//quitter
					case 11:
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
