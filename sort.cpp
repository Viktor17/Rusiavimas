#include <iostream>
#include <stdlib.h>
template <class T> void exch(T &, T &);
template <class T> void compexch(T &, T &);
template <class T> void selection(T *, int, int, int &, int &);
template <class T> void insertion(T *, int, int, int &);
template <class T> void bubble(T *, int, int);
using namespace std;
int main(int argc, char *argv[])
{
    int i, N = 1000, k=0;
    int ai=0,aii=0, bi=0,bii=0, ci=0,cii=0;  //skaitliukai surast kiek atlikta veiksmu
    int *a = new int[N],*b = new int[N],*c = new int[N];
    for (i = 0; i < N; i++) a[i] = 1000*(1.0*rand()/RAND_MAX);
    for (i = 0; i < N; i++) b[i] = i;
    for (i = N; i > N; i++) { c[k] = i; k++; }
    cout << "Sukureme tris masyvus:\nPirmas a masyvas random\nAntras b masyvas surusiuotas nuo 1 iki 1000\nTrecias c masyvas surusiuotas nuo 1000 iki 1\n\n";
    selection(a, 0, N-1, ai, aii);
    selection(b, 0, N-1, bi, bii);
    selection(c, 0, N-1, ci, cii);

    //cout << "Surusiuotas skaiciu masyvas yra:" << endl;
    //for (i = 0; i < N; i++) cout << a[i] << " ";
    cout <<"\n Pirmu atveju atlikoveiksmu: "<<ai<<" + "<<aii<<" = "<<ai+aii;
    cout <<"\n Antru atveju atlikoveiksmu: "<<bi<<" + "<<bii<<" = "<<bi+bii;
    cout <<"\n Treciu atveju atlikoveiksmu: "<<ci<<" + "<<cii<<" = "<<ci+aii;
    cout << endl;

}
// Sukeičia elementus vietomis
template <class T>
  void exch(T &A, T &B)
    { T t = A ; A = B; B = t;}
// Sukeičia elementus vietomis tik jei patenkinta sąlyga
template <class T>
  void compexch(T &A, T &B)
    { if (B < A) exch(A, B); }
// Išrinkimo algoritmo realizacija
template <class T>
void selection(T a[], int l, int r, int &skaitliukassukeitimo, int &skaitliukaslyginimo)
  {

      for (int i = l; i < r; i++)
      { int min = i;
        for (int j = i+1; j <= r; j++)
            if (a[j] < a[min]) { min = j; skaitliukaslyginimo++;}
        exch(a[i], a[min]); skaitliukassukeitimo++;
      }
  }
// Įterpimo algoritmo realizacija
template <class T>
void insertion(T a[], int l, int r, int &skaitliukassukeitimo, int &skaitliukaslyginimo)
  { int i;
    for (i = r; i > l; i--) compexch(a[i-1], a[i]);
    for (i = l+2; i <= r; i++)
      { int j = i; T v = a[i];
        while (v < a[j-1])
          { a[j] = a[j-1]; j--; }
        a[j] = v;
      }
  }
// Burbulo algoritmas
template <class T>
void bubble(T a[], int l, int r)
  { for (int i = l; i < r; i++)
      for (int j = r; j > i; j--)
        compexch(a[j-1], a[j]);
  }
// quick sort realizacija


