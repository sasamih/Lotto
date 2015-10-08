#include "gui_sdl.h"

bool init()
{
  bool success = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("Failed to initialize!\nError: %s\n", SDL_GetError());
    success = false;
  }
  else
  {
    gWindow = SDL_CreateWindow("Lotto 7/39", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
              SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
      printf("Failed to create window!\nError: %s\n",SDL_GetError());
      success = false;
    }
    else
    {
      gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
  }

  return success;
}

bool loadMedia()
{
  bool success = true;

	int i;
	for (i = 1; i <= TOTAL_NUMBERS; i++)
	{
		char* tmp = (char*) calloc(3,sizeof(char));
		char* name = (char*) calloc(100,sizeof(char));

		strcat(name,"resources/res1/_");
		snprintf(tmp,3,"%d",i);
		strcat(strcat(name,tmp),".bmp");

		availableNumbers[i-1] = IMG_Load(name);
		free(name);
		free(tmp);
		if (availableNumbers[i-1] == NULL)
		{
			printf("Failed to load image!\n %s", SDL_GetError());
			success = false;
		}
	}

	for (i = 1; i <= TOTAL_NUMBERS; i++)
	{
		char* tmp = (char*) calloc(3,sizeof(char));
		char* name = (char*) calloc(100,sizeof(char));

		strcat(name,"resources/res1/x");
		snprintf(tmp,3,"%d",i);
		strcat(strcat(name,tmp),".bmp");

		pickedNumber[i-1] = IMG_Load(name);
		free(name);
		free(tmp);
		if (pickedNumber[i-1] == NULL)
		{
			printf("Failed to load image! %s\n", SDL_GetError());
			success = false;
		}
	}

	return success;
}

bool loadGenerateButton()
{
  bool success = true;

  generateButton = IMG_Load("resources/generate-button.bmp");
  if (generateButton == NULL)
  {
    printf("Failed to load button! %s\n", SDL_GetError());
    success = false;
  }

  return success;
}

void loadTicket(Ticket* ticket)
{
  int i;
  for(i = 0; i < MAX_NUMBER; i++)
  {
    ticketImage[i] = availableNumbers[ticket->numbers[i] - 1];
  }
}

void loadWinningTicket(Ticket* ticket)
{
  int i;
  for(i = 0; i < MAX_NUMBER; i++)
  {
    winningTicketImage[i] = pickedNumber[ticket->numbers[i] - 1];
  }
}

void printTicket()
{
  int i;
  for(i = 0; i < MAX_NUMBER; i++)
  {
    SDL_Rect number = {310 + i * NUMBER_WIDTH,130,NUMBER_WIDTH,NUMBER_HEIGHT};
    SDL_BlitSurface(ticketImage[i],NULL,gScreenSurface,&number);
  }
}

void printWinningTicket()
{
  int i;
  for(i = 0; i < MAX_NUMBER; i++)
  {
    SDL_Rect number = {310 + i * NUMBER_WIDTH,200,NUMBER_WIDTH,NUMBER_HEIGHT};
    SDL_BlitSurface(winningTicketImage[i],NULL,gScreenSurface,&number);
  }
}

void fillAvailableNumbers()
{
  int i,j;

  for (i = 0; i < 5; i++)
  {
    for (j = 0; j < 7; j++)
    {
      SDL_Rect number = {j * NUMBER_WIDTH, i * NUMBER_HEIGHT, NUMBER_WIDTH, NUMBER_HEIGHT};
      SDL_BlitSurface(availableNumbers[i*7+j],NULL,gScreenSurface,&number);
    }
  }
  for (j = 0; j < 4; j++)
  {
    SDL_Rect number = {j * NUMBER_WIDTH, i * NUMBER_HEIGHT, NUMBER_WIDTH, NUMBER_HEIGHT};
    SDL_BlitSurface(availableNumbers[i*7+j],NULL,gScreenSurface,&number);
  }

  for (i = 0; i < TOTAL_NUMBERS; i++)
  {
    currentGrid[i] = availableNumbers[i];
  }
}

void blitCurrentGrid()
{
  int i,j;

  for (i = 0; i < 5; i++)
  {
    for (j = 0; j < 7; j++)
    {
      SDL_Rect number = {j * NUMBER_WIDTH, i * NUMBER_HEIGHT, NUMBER_WIDTH, NUMBER_HEIGHT};
      SDL_BlitSurface(currentGrid[i*7+j],NULL,gScreenSurface,&number);
    }
  }
  for (j = 0; j < 4; j++)
  {
    SDL_Rect number = {j * NUMBER_WIDTH, i * NUMBER_HEIGHT, NUMBER_WIDTH, NUMBER_HEIGHT};
    SDL_BlitSurface(currentGrid[i*7+j],NULL,gScreenSurface,&number);
  }
}

void pickSelectedNumber(SDL_Rect* pickNumber,int columnNumber,int rowNumber)
{
  currentGrid[rowNumber * 7 + columnNumber] = pickedNumber[rowNumber * 7 + columnNumber];   // moguce refaktorisati

  SDL_BlitSurface(currentGrid[rowNumber*7+columnNumber],NULL,gScreenSurface,pickNumber);
}

void unpickSelectedNumber(SDL_Rect* unpickNumber,int columnNumber, int rowNumber)
{
  currentGrid[rowNumber * 7 + columnNumber] = availableNumbers[rowNumber * 7 + columnNumber];

  SDL_BlitSurface(currentGrid[rowNumber*7+columnNumber],NULL,gScreenSurface,unpickNumber);
}

void printResult(uint8_t match)
{
  char* score = (char*) malloc(2*sizeof(char));
  snprintf(score, 2, "%d", match);

  TTF_Init();
  SDL_Color textColor = {0, 0, 0};

  font = TTF_OpenFont("resources/open-sans/OpenSans-Light.ttf", 28);
  font2 = TTF_OpenFont("resources/open-sans/OpenSans-Light.ttf", 20);

  textCombination = TTF_RenderText_Solid(font2, "Your combination:", textColor);
  textWinCombination = TTF_RenderText_Solid(font2, "Winning combination:", textColor);
  youHave = TTF_RenderText_Solid(font, "You have ", textColor);
  numberOfMatches = TTF_RenderText_Solid(font, score, textColor);
  matches = TTF_RenderText_Solid(font, " matches!", textColor);

  SDL_Rect text1 = {310, 100, 100, 20};
  SDL_Rect text2 = {310, 170, 100, 20};
  SDL_Rect m1 = {320, 250, 120, 30};
  SDL_Rect m2 = {440, 250, 30, 30};
  SDL_Rect m3 = {460, 250, 50, 30};

  SDL_BlitSurface(textCombination,NULL,gScreenSurface,&text1);
  SDL_BlitSurface(textWinCombination,NULL,gScreenSurface,&text2);
  SDL_BlitSurface(youHave,NULL,gScreenSurface,&m1);
  SDL_BlitSurface(numberOfMatches,NULL,gScreenSurface,&m2);
  SDL_BlitSurface(matches,NULL,gScreenSurface,&m3);

  TTF_CloseFont(font);

  TTF_Quit();

}

void freeText()
{
  SDL_FreeSurface(textCombination);
  SDL_FreeSurface(textWinCombination);
  SDL_FreeSurface(youHave);
  SDL_FreeSurface(numberOfMatches);
  SDL_FreeSurface(matches);
}

void release()
{
  freeText();
  SDL_FreeSurface(gScreenSurface);
  SDL_DestroyWindow(gWindow);

  SDL_Quit();
}
