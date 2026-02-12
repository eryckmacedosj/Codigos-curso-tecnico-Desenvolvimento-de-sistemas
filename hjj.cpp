#include <iostream>
using namespace std;

// Variáveis globais
float resultados[5];
int indice = 0;

// Funções
float soma(float a, float b) {
    return a + b;
}

float subtrai(float a, float b) {
    return a - b;
}

void armazenar(float resultado) {
    if (indice < 5) {
        resultados[indice] = resultado;
        indice++;
    } else {
        cout << "Vetor cheio! Não é possível armazenar mais resultados.\n";
    }
}

void mostrarResultados() {
    cout << "\nResultados armazenados:\n";
    for (int i = 0; i < indice; i++) {
        cout << "Resultado " << i + 1 << ": " << resultados[i] << endl;
    }
}

int main() {
    int opcao;
    float num1, num2, resultado;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1 - Somar\n";
        cout << "2 - Subtrair\n";
        cout << "3 - Ver resultados\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        if (opcao == 1 || opcao == 2) {
            cout << "Digite dois números: ";
            cin >> num1 >> num2;

            if (opcao == 1) {
                resultado = soma(num1, num2);
            } else {
                resultado = subtrai(num1, num2);
            }

            armazenar(resultado);
            cout << "Resultado: " << resultado << endl;
        } else if (opcao == 3) {
            mostrarResultados();
        } else if (opcao != 0) {
            cout << "Opção inválida.\n";
        }

    } while (opcao != 0);

    return 0;
}