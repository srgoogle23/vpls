#include <ncurses.h>

#include "estrada.h"
#include "sapo.h"

int kbhit() {
  int ch = getch();

  if (ch != ERR) {
    ungetch(ch);
    return 1;
  } else {
    return 0;
  }
}

void desenha(Estrada &estrada, Sapo &sapo) {
  auto n_linhas = estrada.get_num_linhas();
  auto n_colunas = estrada.get_num_colunas();
  auto carros = estrada.get_carros();

  for (unsigned int linha = 0; linha < n_linhas; linha++) {
    for (unsigned int col = 0; col < n_colunas; col++) {
      if (sapo.get_linha() == linha && sapo.get_coluna() == col) {
        mvaddch(linha, col, 's');
        continue;
      }

      bool print_carro = false;
      for (Carro *carro_ptr : carros) {
        Carro carro = *carro_ptr;
        if (carro.get_linha() == linha && carro.get_coluna() == col) {
          mvaddch(linha, col, 'c');
        }
        print_carro = true;
      }

      if (print_carro) {
        continue;
      }

      mvaddch(linha, col, '-');
    }
    mvaddch(linha, n_colunas, '\n');
  }
}

int main() {
  initscr();
  cbreak();
  noecho();
  nodelay(stdscr, TRUE);

  Sapo sapo = Sapo(10, 6);
  Estrada estrada = Estrada(11, 14, 2, sapo);
  desenha(estrada, sapo);

  while (1) {
    MovimentoSapo mov = MovimentoSapo::NADA;
    if (kbhit()) {
      int ch = getch();
      // w, 119, a 97, s 115, d 100
      if (ch == 119) {
        mov = MovimentoSapo::CIMA;
      } else if (ch == 97) {
        mov = MovimentoSapo::ESQUERDA;
      } else if (ch == 115) {
        mov = MovimentoSapo::BAIXO;
      } else if (ch == 100) {
        mov = MovimentoSapo::DIREITA;
      }
    }
    bool acabou = estrada.atualiza(mov);
    desenha(estrada, sapo);
    if (acabou) {
      break;
    }
  }
  endwin();
  exit(0);
}