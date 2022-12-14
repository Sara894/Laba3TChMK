#include <iostream>
#include <math.h>
using namespace std;

bool is_prime(int x) {
  for (int d = 2; d * d < x; d++) {
    if (x % d == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  cout<<"Сколько линейных сравнений вы хотите проверить с помощью символа Лежандра: ";
  int l;
  cin>>l;
 while(l--){
    std::cout << "имеет ли решение сравнение  x^2 = a mod p.\n";
  std::cout<<"Введите числа a, p через пробел: ";
  int a, p;
  cin>>a>>p;
  if(a % p == 0 )
  {
     cout<<"Число x является квадратичным вычетом по модулю "<<p<<".\n";
    cout<<"По определению символ Лежандра "<< a <<"/"<< p<<" равен 0.\n";
  }
  else if(is_prime(p)){
    cout<<"Применим критерий Эйлера: \n";
    cout<<"Найдем значение символа Лежандра "<<a <<"/"<<p<<".\n";
    cout<<a<<"^("<<p<<"-1)/2 = "<<a <<"/"<<p<<" mod p \n";
    int temp = pow(a,(p-1)/2);
    cout<<a<<"^("<<p<<"-1)/2 = "<<temp<<".\n";
    int mod = temp % p;
    cout<<temp<<" по модулю "<<p<<" = "<<mod<<"\n";
    cout<<"По критерию Эйлера символ Лежандра равен "<<mod<<".\n";
    if(mod == 1)
      cout<<"Cледовательно, данное квадратичное сравнение имеет решение.\n";
    else if(mod == -1)
      cout<<"Значит, данное квадратичное сравнение решений не имеет.\n";
 }
   else if(!is_prime(p)){
     cout<<"Найдем значение символа Якоби "<<a <<"/"<<p<<".\n";
   }
  }



  
}