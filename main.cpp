#include <iostream>
#include <cstring>

struct warrior
{
  char type[10];
  int strength;
};

void print_war_strength(struct warrior w)
{
  printf("the strencth of %s after battle is %i\n",w.type ,w.strength);
}

void print_winner(struct warrior the_winner, struct warrior the_loser)
{
  std::cout << "\033[32m" << the_winner.type << "\033[0m"  << " wins against " << "\033[31m" << the_loser.type << "\033[0m"  << std::endl;
}

// BUG: warrior strength ins't affected bc function works on cpy of data (w1,w2)
// FIX: change the parameters (w1,w2) to pointers 
void fight(struct warrior * w1, struct warrior * w2) {
  printf("FIGHT BETWEEN %s vs %s\n", w1->type, w2->type);
  if (w1->strength > w2->strength) {
    print_winner(*w1,*w2);        
  }  
  else if (w1->strength < w2->strength) {
    print_winner(*w2,*w1);        
  }
  else {
    std::cout << "\033[34m"  << w1->type << "\033[0m"  << " and " << "\033[34m"  << w2->type << "\033[0m"  << " draw" << std::endl;
  }
  w1->strength--;
  w2->strength-=2; 
  //print_war_strength(*w1);
  //print_war_strength(*w2);
  printf("\n\n");
}

int main() {
  struct warrior w1;
  struct warrior w2;
  struct warrior w3;

  strcpy(w1.type, "ninja");
  w1.strength = 10;
  
  strcpy(w2.type, "samurai");
  w2.strength = 9;

  strcpy(w3.type, "knight");
  w3.strength = 9;
  
  fight(&w1,&w2);
  fight(&w1,&w3);
  fight(&w2,&w3);
  fight(&w1,&w2);
  fight(&w1,&w2);
  fight(&w1,&w2);
  fight(&w1,&w2);
  fight(&w1,&w3);
  
}