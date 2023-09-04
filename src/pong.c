#include <stdio.h>

void draw(int yroc1, int yroc2, int ballXpos, int ballYpos, int score1,
          int score2) {
  int maxx = 81;
  int maxy = 26;
  int xroc1 = 2;
  int xroc2 = 79;
  for (int y = 0; y <= maxy; y++) {
    for (int x = 0; x <= maxx; x++) {
      if ((x == 0) || (y == 0) || (x == maxx) || (y == maxy)) {
        printf("+");
      } else if (x == 40) {
        printf("|");
      } else if ((x == xroc1 && y == yroc1) ||
                 (x == xroc1 && y >= yroc1 - 1 && y <= yroc1 + 1)) {
        printf("|");
      } else if ((x == xroc2 && y == yroc2) ||
                 (x == xroc2 && y >= yroc2 - 1 && y <= yroc2 + 1)) {
        printf("|");
      } else if (x == ballXpos && y == ballYpos) {
        printf("o");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  printf("SCORE 1: %d                                                          "
         "   SCORE 2: %d\n",
         score1, score2);
}

int main() {
  int maxx = 81;
  int maxy = 26;

  int score1 = 0;
  int score2 = 0;

  int yroc1 = maxy / 2;
  int yroc2 = maxy / 2;

  int dvx = 1;
  int dvy = 1;
  int ballXpos = maxx / 2;
  int ballYpos = maxy / 2;

  while (score1 < 21 && score2 < 21) {
    draw(yroc1, yroc2, ballXpos, ballYpos, score1, score2);

    ballXpos += dvx;
    ballYpos += dvy;

    char hod;
    hod = getchar();
    if (hod == 'A') {
      if ((yroc1) >= 3) {
        yroc1 -= 1;
      }
    } else if (hod == 'Z') {
      if ((yroc1) <= 23) {
        yroc1 += 1;
      }
    } else if (hod == 'K') {
      if ((yroc2) >= 3) {
        yroc2 -= 1;
      }
    } else if (hod == 'M') {
      if ((yroc2) <= 23) {
        yroc2 += 1;
      }
    }

    if (ballYpos == 1) {
      dvy = 1;
    }
    if (ballYpos == maxy - 1) {
      dvy = -1;
    }

    if (ballXpos == maxx - 3) {
      if (ballYpos == yroc2 || ballYpos == yroc2 - 1 || ballYpos == yroc2 + 1) {
        dvx = -1;
      } else {
        score1 += 1;
        ballXpos = maxx / 2;
        ballYpos = maxy / 2;
        yroc1 = maxy / 2;
        yroc2 = maxy / 2;
      }
    }
    if (ballXpos == 3) {
      if (ballYpos == yroc1 || ballYpos == yroc1 - 1 || ballYpos == yroc1 + 1) {
        dvx = 1;
      } else {
        score2 += 1;
        ballXpos = maxx / 2;
        ballYpos = maxy / 2;
        yroc1 = maxy / 2;
        yroc2 = maxy / 2;
      }
    }
    printf("\033[H\033[J");
  }
  draw(yroc1, yroc2, ballXpos, ballYpos, score1, score2);
  if (score1 > score2) {
    printf("                                  WIN PLAYER 1\n");
  } else {
    printf("                                  WIN PLAYER 2\n");
  }
  return 0;
}