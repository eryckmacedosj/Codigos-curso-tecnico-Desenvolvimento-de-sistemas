#include <iostream>

using namespace std;

int main(){
    double valorCompra, valorDesconto, valorApagar;    
    int tipoCliente;
   
    cout<<"Menu Principal"<<endl;
    cout<<"1 - Clientes Comuns"<<endl;
    cout<<"2 - Clientes VIP"<<endl;
    cout<<"Informe o tipo de cliente"<<endl;
    cin>>tipoCliente;
    cout<<"Informe o valor da compra"<<endl;
    cin>>valorCompra;
   
    switch(tipoCliente){
        case 1:
            
            if(valorCompra >= 100 && valorCompra < 500){
                
                valorDesconto = valorCompra * (5.0 / 100);                
            }else if(valorCompra >= 500 && valorCompra < 1000){
                valorDesconto = valorCompra * (10.0 / 100);                
            }else if(valorCompra >= 1000){
                valorDesconto = valorCompra * (15.0 / 100);
            }
           
            break;
        case 2:
           
            if(valorCompra >= 1 && valorCompra < 500){
                valorDesconto = valorCompra * (10.0 / 100);                
            }else if(valorCompra >= 500 && valorCompra < 1000){
                valorDesconto = valorCompra * (15.0 / 100);                
            }else if(valorCompra >= 1000){
                valorDesconto = valorCompra * (20.0 / 100);                
            }
           
            break;
    }
    valorApagar = valorCompra - valorDesconto;
    cout<<"Valor final da compra: "<<valorApagar<<endl;
}