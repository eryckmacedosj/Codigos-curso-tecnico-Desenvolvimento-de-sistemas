#include <iostream>
#include <vector>
using namespace std;

vector<float> imcs; // Variável global para armazenar os IMCS

// Função para calcular IMC
float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

// Função para adicionar um IMC ao vetor
void adicionarIMC() {
    float peso, altura;
    cout << "Digite o peso (kg): ";
    cin >> peso;
    cout << "Digite a altura (m): ";
    cin >> altura;
    float imc = calcularIMC(peso, altura);
    imcs.push_back(imc);
    cout << "IMC adicionado: " << imc << endl;
}

// Função para exibir todas as classificações
void exibirClassificacoes() {
    for (float imc : imcs) {
        cout << "IMC: " << imc << " - ";
        if (imc < 18.5)
            cout << "Abaixo do peso";
        else if (imc < 24.9)
            cout << "Peso normal";
        else if (imc < 29.96)
            cout << "Sobrepeso";
        else
            cout << "Obesidade";
        cout << endl;
    }
}

// Funções para contar por categoria
int contarAbaixoPeso() {
    int count = 0;
    for (float imc : imcs)
        if (imc < 18.5) count++;
    return count;
}

int contarPesoNormal() {
    int count = 0;
    for (float imc : imcs)
        if (imc >= 18.5 && imc < 24.9) count++;
    return count;
}

int contarSobrepeso() {
    int count = 0;
    for (float imc : imcs)
        if (imc >= 25 && imc < 29.96) count++;
    return count;
}

int contarObesidade() {
    int count = 0;
    for (float imc : imcs)
        if (imc >= 30) count++;
    return count;
}

// Funções para maior, menor e média
float maiorIMC() {
    if (imcs.empty()) return 0;
    float maior = imcs[0];
    for (float imc : imcs)
        if (imc > maior) maior = imc;
    return maior;
}

float menorIMC() {
    if (imcs.empty()) return 0;
    float menor = imcs[0];
    for (float imc : imcs)
        if (imc < menor) menor = imc;
    return menor;
}

float mediaIMC() {
    if (imcs.empty()) return 0;
    float soma = 0;
    for (float imc : imcs) soma += imc;
    return soma / imcs.size();
}


int main() {
    int opcao;
    do {
        cout << "\nMenu Principal\n";
        cout << "1 - Add Imc\n";
        cout << "2 - Exibir todas as classificacoes\n";
        cout << "3 - Exibir a quantidade Abaixo do peso\n";
        cout << "4 - Exibir a quantidade Peso normal\n";
        cout << "5 - Exibir a quantidade Sobrepeso\n";
        cout << "6 - Exibir a quantidade Obesidade\n";
        cout << "7 - Exibir o maior IMC\n";
        cout << "8 - Exibir o menor IMC\n";
        cout << "9 - Exibir media dos IMCs\n";
        cout << "10 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: adicionarIMC(); break;
            case 2: exibirClassificacoes(); break;
            case 3: cout << "Quantidade abaixo do peso: " << contarAbaixoPeso() << endl; break;
            case 4: cout << "Quantidade peso normal: " << contarPesoNormal() << endl; break;
            case 5: cout << "Quantidade sobrepeso: " << contarSobrepeso() << endl; break;
            case 6: cout << "Quantidade obesidade: " << contarObesidade() << endl; break;
            case 7: cout << "Maior IMC: " << maiorIMC() << endl; break;
            case 8: cout << "Menor IMC: " << menorIMC() << endl; break;
            case 9: cout << "Media dos IMCs: " << mediaIMC() << endl; break;
            case 10: cout << "Saindo...\n"; break;
            default: cout << "Opcao invalida.\n"; break;
        }
    } while (opcao != 10);

    return 0;
}