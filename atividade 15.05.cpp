#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Cliente {
    string cpf;
    string nome;
    int idade;
    string telefone;
};

struct Funcionario {
    int matricula;
    string nome;
    string telefone;
};

struct Produto {
    int id;
    string descricao;
    float valor;
    int quantidade;
};

struct Venda {
    string cpf_cliente;
    int matricula_funcionario;
    int id_produto;
    string data;
    int quantidade_comprada;
};

// Funções auxiliares para buscar clientes, produtos e funcionários
int buscarCliente(Cliente clientes[], int n, const string& cpf) {
    for (int i = 0; i < n; i++) {
        if (clientes[i].cpf == cpf) {
            return i; 
        }
    }
    return -1; 
}

int buscarProduto(Produto produtos[], int n, int id_produto) {
    for (int i = 0; i < n; i++) {
        if (produtos[i].id == id_produto) {
            return i;  
        }
    }
    return -1; 
}

int buscarFuncionario(Funcionario funcionarios[], int n, int matricula) {
    for (int i = 0; i < n; i++) {
        if (funcionarios[i].matricula == matricula) {
            return i;  // Funcionário encontrado
        }
    }
    return -1;  
}

// Funções para cadastro de Cliente, Funcionario e Produto
void cadastrarCliente(Cliente clientes[], int &n) {
    cout << "Digite o CPF: ";
    cin >> clientes[n].cpf;
    cout << "Digite o nome: ";
    cin.ignore(); 
    getline(cin, clientes[n].nome);
    cout << "Digite a idade: ";
    cin >> clientes[n].idade;
    cout << "Digite o telefone: ";
    cin >> clientes[n].telefone;
    n++;  
}

void cadastrarFuncionario(Funcionario funcionarios[], int &n) {
    cout << "Digite a matrícula: ";
    cin >> funcionarios[n].matricula;
    cout << "Digite o nome: ";
    cin.ignore();  
    getline(cin, funcionarios[n].nome);
    cout << "Digite o telefone: ";
    cin >> funcionarios[n].telefone;
    n++;  
}

void cadastrarProduto(Produto produtos[], int &n) {
    cout << "Digite o ID do produto: ";
    cin >> produtos[n].id;
    cout << "Digite a descrição do produto: ";
    cin.ignore();  // Limpa o buffer do teclado
    getline(cin, produtos[n].descricao);
    cout << "Digite o valor do produto: ";
    cin >> produtos[n].valor;
    cout << "Digite a quantidade do produto: ";
    cin >> produtos[n].quantidade;
    n++;  
}

void realizarVenda(Venda vendas[], int &nv, Cliente clientes[], int nc, Produto produtos[], int np, Funcionario funcionarios[], int nf) {
    string cpf;
    int matricula, id_produto, quantidade;
    
    cout << "Digite o CPF do cliente: ";
    cin >> cpf;

    // Verificar se o cliente existe
    int clienteIndex = buscarCliente(clientes, nc, cpf);
    if (clienteIndex == -1) {
        cout << "Cliente não encontrado!" << endl;
        return;
    }

    // Verificar se o funcionário existe
    cout << "Digite a matrícula do funcionário: ";
    cin >> matricula;
    int funcionarioIndex = buscarFuncionario(funcionarios, nf, matricula);
    if (funcionarioIndex == -1) {
        cout << "Funcionário não encontrado!" << endl;
        return;
    }

    // Verificar se o produto existe
    cout << "Digite o ID do produto: ";
    cin >> id_produto;
    int produtoIndex = buscarProduto(produtos, np, id_produto);
    if (produtoIndex == -1) {
        cout << "Produto não encontrado!" << endl;
        return;
    }

    cout << "Digite a quantidade comprada: ";
    cin >> quantidade;

    // Verificar se a quantidade disponível é suficiente
    if (quantidade > produtos[produtoIndex].quantidade) {
        cout << "Estoque insuficiente!" << endl;
        return;
    }

    // Registrar a venda
    vendas[nv].cpf_cliente = cpf;
    vendas[nv].matricula_funcionario = matricula;
    vendas[nv].id_produto = id_produto;
    cout << "Digite a data da venda (DD/MM/YYYY): ";
    cin >> vendas[nv].data;
    vendas[nv].quantidade_comprada = quantidade;

    produtos[produtoIndex].quantidade -= quantidade;
    nv++;  // 

    cout << "Venda realizada com sucesso!" << endl;
}

void totalVendas(Venda vendas[], int nv, Produto produtos[], int np) {
    float total = 0;
    for (int i = 0; i < nv; i++) {
        int id_produto = vendas[i].id_produto;
        for (int j = 0; j < np; j++) {
            if (produtos[j].id == id_produto) {
                total += produtos[j].valor * vendas[i].quantidade_comprada;
            }
        }
    }
    cout << "Total das vendas: R$ " << fixed << setprecision(2) << total << endl;
}

int main() {
    Cliente clientes[100];
    Funcionario funcionarios[50];
    Produto produtos[200];
    Venda vendas[500];
    
    int nc = 0, nf = 0, np = 0, nv = 0;
    int opcaoPrincipal, opcaoCadastro, opcaoRelatorio;

    do {
        cout << "\nMenu Principal\n";
        cout << "1 - Cadastros\n";
        cout << "2 - Venda\n";
        cout << "3 - Relatórios\n";
        cout << "4 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcaoPrincipal;

        switch(opcaoPrincipal) {
            case 1:
                do {
                    cout << "\nMenu Cadastro\n";
                    cout << "1 - Cadastrar Cliente\n";
                    cout << "2 - Cadastrar Funcionário\n";
                    cout << "3 - Cadastrar Produto\n";
                    cout << "4 - Voltar ao menu Principal\n";
                    cout << "Escolha uma opção: ";
                    cin >> opcaoCadastro;

                    switch(opcaoCadastro) {
                        case 1: cadastrarCliente(clientes, nc); break;
                        case 2: cadastrarFuncionario(funcionarios, nf); break;
                        case 3: cadastrarProduto(produtos, np); break;
                        case 4: break;
                        default: cout << "Opção inválida!" << endl; break;
                    }
                } while (opcaoCadastro != 4);
                break;

            case 2:
                realizarVenda(vendas, nv, clientes, nc, produtos, np, funcionarios, nf);
                break;

            case 3:
                do {
                    cout << "\nMenu Relatório\n";
                    cout << "1 - Total das Vendas\n";
                    cout << "2 - Voltar ao menu Principal\n";
                    cout << "Escolha uma opção: ";
                    cin >> opcaoRelatorio;

                    switch(opcaoRelatorio) {
                        case 1: totalVendas(vendas, nv, produtos, np); break;
                        case 2: break;
                        default: cout << "Opção inválida!" << endl; break;
                    }
                } while (opcaoRelatorio != 2);
                break;

            case 4: 
                cout << "Saindo..." << endl;
                break;

            default: 
                cout << "Opção inválida!" << endl; 
                break;
        }

    } while (opcaoPrincipal != 4);

    return 0;
}
