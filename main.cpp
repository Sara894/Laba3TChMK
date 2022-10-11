#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool is_prime(int x) {
  for (int d = 2; d * d < x; d++) {
    if (x % d == 0) {
      return false;
    }
  }
  return true;
}

vector<int> raz(int n) {
  vector<int> arr = {};
  for (int i = 2; i<=n && n > 1 ;)
    if (n % i == 0 && is_prime(i)) {
        arr.push_back(i);
        n /= i;
    }
  else if(n % i != 0){
    i++;
  }
  return arr;
}

int Lezhandr(int a, int p){
  if(a % p == 0 )
  {
     cout<<"Число "<<a<<" является квадратичным вычетом по модулю "<<p<<".\n";
    cout<<"По определению символ Лежандра "<< a <<"/"<< p<<" равен 0.\n";
    return 0;
  }
  else if(is_prime(p)){
    cout<<"Применим критерий Эйлера: \n";
    cout<<"Найдем значение символа Лежандра "<<a <<"/"<<p<<".\n";
    cout<<a<<"^("<<p<<"-1)/2 = "<<a <<"/"<<p<<" mod p \n";
    long long int temp = pow(a,(p-1)/2);
    cout<<a<<"^("<<p<<"-1)/2 = "<<temp<<".\n";
    long long int mod = temp % p;
    cout<<temp<<" по модулю "<<p<<" = "<<mod<<"\n";
    cout<<"По критерию Эйлера символ Лежандра равен "<<mod<<".\n";
    return mod;
 }
}


int Yakobi(int a, int p){
  int res = 1;
  if(!is_prime(a)){
    vector<int> v = raz(a);
    for(int i = 0; i < v.size();i++){
      if(v[i] % p != 0 && p % v[i] != 0)
      {
        int st = (p-1)/ 2 * (v[i] - 1)/2;
        res *= pow(-1,st);
      }
      else if(v[i] % p == 0 && p % v[i] == 0)
      {
        res*=0;
        return res;
      }
    }
  }else{
    if(p % a != 0 && a != p)
    {
      int st = (p-1)/ 2 * (a - 1)/2;
        res *= pow(-1,st);
    }else{
      res*=0;
      return res;
    }
  }
  return res;
}


int main() {
  cout<<"Сколько линейных сравнений вы хотите проверить: ";
  int l;
  cin>>l;
 while(l--){
    std::cout << "\nимеет ли решение сравнение  x^2 = a mod p.\n";
  std::cout<<"Введите числа a, p через пробел: ";
  int a, p;
  cin>>a>>p;
  if(a % p == 0 )
  {
     cout<<"Число а является квадратичным вычетом по модулю "<<p<<".\n";
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
     vector<int> v = raz(p);
     cout<<"По определению символа Якоби "<<a <<"/"<<p<<" = ";
     vector<int> lezs = {}; 
     for(int i = 0; i < v.size(); i++){
       cout<<a<<"/"<<v[i]<<" ";
       int tem = Yakobi(a,v[i]);
       lezs.push_back(tem);
       if(i != v.size()-1)
         cout<<"* ";
     }

     int res = 1;
     cout<<"Найдем значение каждого из сомножителей(являющихся символами Лежандра) и вычислим так символ Якоби:\n";
     for(int i = 0; i < lezs.size();i++){
       res*=lezs[i];
     }

      cout<<"Символ Якоби равен "<<res<<".\n";
    if(res == 1)
      cout<<"Cледовательно, данное квадратичное сравнение имеет решение.\n";
    else if(res == -1)
      cout<<"Значит, данное квадратичное сравнение решений не имеет.\n";
   }
  }



  
}