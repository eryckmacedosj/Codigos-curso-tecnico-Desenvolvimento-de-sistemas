#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void adicionarNota(vector<float>& notas) {
    float nota;
    cout << "Digite a nota: ";
    cin >> nota;
    notas.push_back(nota);
}

float somaNotas(const vector<float>& notas) {
    float soma = 0;
    for (float nota : notas) {
        soma += nota;
    }
    return soma;
}


float mediaNotas(const vector<float>& notas) {
    if (notas.empty()) return 0;
    return somaNotas(notas) / notas.size();
}


void exibirNotasMaiorOuIgual7(const vector<float>& notas) {
    cout << "Notas >= 7: ";
    for (float nota : notas) {
        if (nota >= 7) {
            cout << nota << " ";
        }
    }
    cout << endl;
}

void exibirNotasMenorQue7(const vector<float>& notas) {
    cout << "Notas < 7: ";
    for (float nota : notas) {
        if (nota < 7) {
            cout << nota << " ";
        }
    }
    cout << endl;
}


float menorNota(const vector<float>& notas) {
    if (notas.empty()) return numeric_limits<float>::infinity();
    float menor = notas[0];
    for (float nota : notas) {
        if (nota < menor) {
            menor = nota;
        }
    }
    return menor;
}

float maiorNota(const vector<float>& notas) {
    if (notas.empty()) return -numeric_limits<float>::infinity();
    float maior = notas[0];
    for (float nota : notas) {
        if (nota > maior) {
            maior = nota;
        }
    }
    return maior;
}

int main() {
    vector<float> notas;
    int opcao;

    do {
      
        cout << "\nMenu Principal\n";
        cout << "1 - Adicionar Notas\n";
        cout << "2 - Soma de todas as notas\n";
        cout << "3 - Média das notas\n";
        cout << "4 - Exibir as notas >= 7\n";
        cout << "5 - Exibir as notas < 7\n";
        cout << "6 - Exibir a média\n";
        cout << "7 - Exibir a menor nota\n";
        cout << "8 - Exibir a maior nota\n";
        cout << "9 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                adicionarNota(notas);
                break;
            case 2:
                cout << "Soma de todas as notas: " << somaNotas(notas) << endl;
                break;
            case 3:
                cout << "Média das notas: " << mediaNotas(notas) << endl;
                break;
            case 4:
                exibirNotasMaiorOuIgual7(notas);
                break;
            case 5:
                exibirNotasMenorQue7(notas);
                break;
            case 6:
                cout << "Média das notas: " << mediaNotas(notas) << endl;
                break;
            case 7:
                cout << "Menor nota: " << menorNota(notas) << endl;
                break;
            case 8:
                cout << "Maior nota: " << maiorNota(notas) << endl;
                break;
            case 9:
                cout << "Saindo do programa...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }

    } while(opcao != 9);

    return 0;
}