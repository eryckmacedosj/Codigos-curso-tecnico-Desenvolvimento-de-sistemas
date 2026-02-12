#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

float calcularMedia(const vector<float>& notas) {
    float soma = 0.0;
    for (float nota : notas) {
        soma += nota;
    }
    return soma / notas.size();
}

int main() {
    int numAlunos, numAvaliacoes;

    cout << "Digite o número de alunos: ";
    cin >> numAlunos;

    cout << "Digite o número de avaliações: ";
    cin >> numAvaliacoes;

    vector<vector<float>> notas(numAlunos, vector<float>(numAvaliacoes));

    for (int i = 0; i < numAlunos; ++i) {
        cout << "\nAluno " << i + 1 << ":\n";
        for (int j = 0; j < numAvaliacoes; ++j) {
            cout << "  Nota " << j + 1 << ": ";
            cin >> notas[i][j];
        }
    }


    cout << "\nResultados Finais:\n";
    for (int i = 0; i < numAlunos; ++i) {
        float media = calcularMedia(notas[i]);
        string status = (media >= 6.0) ? "Aprovado" : "Reprovado";
        cout << fixed << setprecision(2);
        cout << "Aluno " << i + 1 << ": Média = " << media << " - " << status << "\n";
    }

    return 0;
}