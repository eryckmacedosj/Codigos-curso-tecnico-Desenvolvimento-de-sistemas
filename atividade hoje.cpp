#include <iostream>
#include <string>
using namespace std;


const int MAX_PRODUTOS = 5;

int main() {
    string nomes[MAX_PRODUTOS];
    float precos[MAX_PRODUTOS];
    int estoque[MAX_PRODUTOS];


    cout << "=== Cadastro de Produtos ===\n";
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        cout << "\nProduto " << i + 1 << ":\n";
        cout << "Nome: ";
        cin >> nomes[i];
        cout << "Preco: R$ ";
        cin >> precos[i];
        cout << "Quantidade em estoque: ";
        cin >> estoque[i];
    }

    int escolha;
    do {

        cout << "\n=== MENU DE COMPRAS ===\n";
        cout << "1. Visualizar produtos\n";
        cout << "2. Comprar produto\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                // Mostrar todos os produtos
                cout << "\n--- Lista de Produtos ---\n";
                for (int i = 0; i < MAX_PRODUTOS; i++) {
                    cout << i + 1 << ". " << nomes[i]
                         << " - R$ " << precos[i]
                         << " - Estoque: " << estoque[i] << endl;
                }
                break;

            case 2:
                // Compra de produto
                int codigo, quantidade;
                cout << "\nDigite o código do produto (1 a " << MAX_PRODUTOS << "): ";
                cin >> codigo;

                // Validação de código
                if (codigo < 1 || codigo > MAX_PRODUTOS) {
                    cout << "Código inválido!\n";
                    break;
                }

                cout << "Digite a quantidade desejada: ";
                cin >> quantidade;

                // Verificar estoque
                if (quantidade <= estoque[codigo - 1]) {
                    estoque[codigo - 1] -= quantidade;
                    float total = quantidade * precos[codigo - 1];
                    cout << "Compra realizada com sucesso!\n";
                    cout << "Total a pagar: R$ " << total << endl;
                } else {
                    cout << "Estoque insuficiente!\n";
                }
                break;

            case 3:
                cout << "Saindo do sistema...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
                break;
        }

    } while (escolha != 3);

}
