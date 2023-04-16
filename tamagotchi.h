typedef struct {
  char name[20];
  int age;
  int hunger;
  int happiness;
  int health;
} Tamagochi;

void display_main_menu();
void display_status(Tamagochi pet);
void feed(Tamagochi *pet);
void play(Tamagochi *pet);
void sleep(Tamagochi *pet);
void update_tamagotchi(Tamagochi *pet, int counter);
void save_tamagotchi(Tamagochi *pet, const char *filename);
void load_tamagotchi(Tamagochi *pet, const char *filename);
