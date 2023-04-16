#include "./tamagotchi.h"
#include <stdio.h>
#include <stdlib.h>

int UPDATE_INTERVAL = 10;

void display_main_menu() {
  printf("\nTamagotchi actions:\n");
  printf("1. Feed\n");
  printf("2. Play\n");
  printf("3. Sleep\n");
  printf("4. Save\n");
  printf("5. Load\n");
  printf("6. Quit\n");
}

void display_status(Tamagochi pet) {
  printf("\n%s's Status:\n", pet.name);
  printf("Age: %d\n", pet.age);
  printf("Hunger: %d\n", pet.hunger);
  printf("Happiness: %d\n", pet.happiness);
  printf("Health: %d\n", pet.health);
}

void feed(Tamagochi *pet) {
  pet->hunger -= 10;

  if (pet->hunger < 0) {
    pet->hunger = 0;
  }
}

void play(Tamagochi *pet) {
  pet->happiness += 10;

  if (pet->happiness > 100) {
    pet->happiness = 100;
  }
}

void sleep(Tamagochi *pet) {
  pet->health += 10;

  if (pet->health > 100) {
    pet->health = 100;
  }
}

void update_tamagotchi(Tamagochi *pet, int counter) {
  if (counter % UPDATE_INTERVAL == 0) {
    pet->age++;
    pet->hunger += 5;
    pet->happiness -= 5;
    pet->health -= (pet->hunger > 80 || pet->happiness < 20) ? 10 : 0;

    // Clamp values between 0 and 100
    pet->hunger = (pet->hunger > 100) ? 100 : pet->hunger;
    pet->happiness = (pet->happiness < 0) ? 0 : pet->happiness;
    pet->health = (pet->health < 0)     ? 0
                  : (pet->health > 100) ? 100
                                        : pet->health;
  }

  if (pet->health == 0) {
    printf("%s has passed away. :(\n", pet->name);
    exit(0);
  }
}

void save_tamagotchi(Tamagochi *pet, const char *filename) {
  FILE *file = fopen(filename, "wb");

  if (file == NULL) {
    printf("Error: Cannot save the file.\n");
    return;
  }

  fwrite(pet, sizeof(Tamagochi), 1, file);
  fclose(file);
}

void load_tamagotchi(Tamagochi *pet, const char *filename) {
  FILE *file = fopen(filename, "rb");

  if (file == NULL) {
    printf("Error: Cannot load the file.\n");
    return;
  }

  fread(pet, sizeof(Tamagochi), 1, file);
  fclose(file);
}
