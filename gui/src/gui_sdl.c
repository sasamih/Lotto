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

void release()
{
  SDL_FreeSurface(gScreenSurface);
  SDL_DestroyWindow(gWindow);

  SDL_Quit();
}
