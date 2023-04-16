#include "./tamagotchi.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  Tamagochi pet = {.age = 0, .hunger = 50, .happiness = 50, .health = 100};
  strcpy(pet.name, "Charlie");

  int choice;
  int counter = 0;
  while (1) {
    update_tamagotchi(&pet, counter);
    display_status(pet);
    display_main_menu();

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      // feed
      feed(&pet);
      break;
    case 2:
      // Playmain.c
      play(&pet);
      break;
    case 3:
      // Sleep
      sleep(&pet);
      break;
    case 4:
      // Save
      save_tamagotchi(&pet, "tamagotchi.dat");
      break;
    case 5:
      // load
      load_tamagotchi(&pet, "tamagotchi.dat");
      break;
    case 6:
      // Quit
      exit(0);
    default:
      printf("Invalid option. Please try again.\n");
    }
  }

  return 0;
}
