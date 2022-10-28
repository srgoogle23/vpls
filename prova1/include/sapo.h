#ifndef PDS2_SAPO_H
#define PDS2_SAPO_H

class Sapo {
  private:
    unsigned int _linha;
    unsigned int _coluna;
  public:
    Sapo(
      unsigned int linha, unsigned int coluna
    );
    
    void mover_cima();
    void mover_esq();
    void mover_direita();
    void mover_baixo();

    unsigned int get_linha();
    unsigned int get_coluna();
};

#endif