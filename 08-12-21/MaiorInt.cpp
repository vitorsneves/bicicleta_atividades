#include "MaiorInt.hpp"
#include "ValidaValor.hpp"

void MaiorInt::recebeValores() {

    for(int i = 0; i < 3; i++) {
        numeros[i] = ValidaValor::recebeInteiro();
    }

}

int MaiorInt::calculaMaior() {
    maior = (numeros[0] > numeros[1]) ? numeros[0] : numeros[1];
    maior = (maior > numeros[2]) ? maior : numeros[2];

    return maior;
}

