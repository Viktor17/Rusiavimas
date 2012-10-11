#include <iostream>
#include <stdlib.h>
template <class T> void exch(T &, T &);
template <class T> void compexch(T &, T &, int &);
template <class T> void partition(T &, int &, int &, int &, int &, int &);
template <class T> void selection(T *, int, int, int &, int &);
template <class T> void insertion(T *, int, int, int &, int &);
template <class T> void bubble(T *, int, int, int &, int &);
template <class T> void quicksort(T *, int, int, int &, int &);
using namespace std;
int main(int argc, char *argv[])
{
    int i, N = 1000;
    int *a = new int[N], *b = new int[N], *c = new int[N];
    cout << "Sukureme tris masyvus:\nPirmas a masyvas random\nAntras b masyvas ";
    cout << "surusiuotas nuo 1 iki 1000\nTrecias c masyvas surusiuotas nuo 1000 iki 1\n\n";
    cout << "Isrinkimas (selection): ";
    //---------ISRINKIMAS---------
    int ai=0, aii=0, bi=0, bii=0, ci=0, cii=0, k=0;  //skaitliukai surast kiek atlikta veiksmu
    for (i = 0; i < N; i++) a[i] = 1000*(1.0*rand()/RAND_MAX);
    for (i = 0; i < N; i++) b[i] = i;
    for (i = N; i > 0; i--) { c[k] = i; k++; }
    selection(a, 0, N-1, ai, aii);
    selection(b, 0, N-1, bi, bii);
    selection(c, 0, N-1, ci, cii);
    cout <<"\n Pirmu atveju atlikoveiksmu: "<<ai<<" + "<<aii<<" = "<<ai+aii;
    cout <<"\n Antru atveju atlikoveiksmu: "<<bi<<" + "<<bii<<" = "<<bi+bii;
    cout <<"\n Treciu atveju atlikoveiksmu: "<<ci<<" + "<<cii<<" = "<<ci+aii;
    cout << endl;
    //---------ITERPIMAS---------
    ai=0, aii=0, bi=0, bii=0, ci=0, cii=0, k=0;  //skaitliukai surast kiek atlikta veiksmu
    for (i = 0; i < N; i++) a[i] = 1000*(1.0*rand()/RAND_MAX);
    for (i = 0; i < N; i++) b[i] = i;
    for (i = N; i > 0; i--) { c[k] = i; k++; }
    insertion(a, 0, N-1, ai, aii);
    insertion(b, 0, N-1, bi, bii);
    insertion(c, 0, N-1, ci, cii);
    cout <<"\n Pirmu atveju atlikoveiksmu: "<<ai<<" + "<<aii<<" = "<<ai+aii;
    cout <<"\n Antru atveju atlikoveiksmu: "<<bi<<" + "<<bii<<" = "<<bi+bii;
    cout <<"\n Treciu atveju atlikoveiksmu: "<<ci<<" + "<<cii<<" = "<<ci+aii;
    cout << endl;
    //---------BURBULAS---------
    ai=0, aii=0, bi=0, bii=0, ci=0, cii=0, k=0;  //skaitliukai surast kiek atlikta veiksmu
    for (i = 0; i < N; i++) a[i] = 1000*(1.0*rand()/RAND_MAX);
    for (i = 0; i < N; i++) b[i] = i;
    for (i = N; i > 0; i--) { c[k] = i; k++; }
    bubble(a, 0, N-1, ai, aii);
    bubble(b, 0, N-1, bi, bii);
    bubble(c, 0, N-1, ci, cii);
    cout <<"\n Pirmu atveju atlikoveiksmu: "<<ai<<" + "<<aii<<" = "<<ai+aii;
    cout <<"\n Antru atveju atlikoveiksmu: "<<bi<<" + "<<bii<<" = "<<bi+bii;
    cout <<"\n Treciu atveju atlikoveiksmu: "<<ci<<" + "<<cii<<" = "<<ci+aii;
    cout << endl;
    //---------QUICK SORT---------
    ai=0, aii=0, bi=0, bii=0, ci=0, cii=0, k=0;  //skaitliukai surast kiek atlikta veiksmu
    for (i = 0; i < N; i++) a[i] = 1000*(1.0*rand()/RAND_MAX);
    for (i = 0; i < N; i++) b[i] = i;
    for (i = N; i > 0; i--) { c[k] = i; k++; }
    quicksort(a, 0, N-1, ai, aii);
    quicksort(b, 0, N-1, bi, bii);
    quicksort(c, 0, N-1, ci, cii);
    cout <<"\n Pirmu atveju atlikoveiksmu: "<<ai<<" + "<<aii<<" = "<<ai+aii;
    cout <<"\n Antru atveju atlikoveiksmu: "<<bi<<" + "<<bii<<" = "<<bi+bii;
    cout <<"\n Treciu atveju atlikoveiksmu: "<<ci<<" + "<<cii<<" = "<<ci+aii;
    cout << endl;

}
// Sukeicia elementus vietomis
template <class T>
  void exch(T &A, T &B)
    { T t = A ; A = B; B = t;}
// Sukeicia elementus vietomis tik jei patenkinta salyga
template <class T>
  void compexch(T &A, T &B, int &su)
    { if (B < A){ exch(A, B); su++; } }
template <class T>
int partition(T a[], int left, int right, int pivotIndex, int &suk, int &lyg)
{
    int pivot = a[pivotIndex];
    do
    {
        while (a[left] < pivot) left++;
        while (a[right] > pivot) right--;
        if (left < right && a[left] != a[right])
        {
            swap(a[left], a[right]); suk++;
        }
        else
        {
            return right;
        }
    }
    while (left < right);
    return right;
}
// Isrinkimo algoritmo realizacija
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
// Iterpimo algoritmo realizacija
template <class T>
void insertion(T a[], int l, int r, int &sksuk, int &sklyg)
  {
    int i;
    for (i = r; i > l; i--)
    {
        compexch(a[i-1], a[i], sksuk);
        sklyg++;
    }

    for (i = l+2; i <= r; i++)
      { int j = i; T v = a[i];
        while (v < a[j-1])
          { a[j] = a[j-1]; j--; }
        a[j] = v;
      }
  }
// Burbulo algoritmas
template <class T>
void bubble(T a[], int l, int r, int &sksuk, int &sklyg)
  { for (int i = l; i < r; i++)
      for (int j = r; j > i; j--)
      {
          compexch(a[j-1], a[j],sksuk); sklyg++;
      }

  }
// quick sort realizacija
template <class T>
void quicksort(T a[], int left, int right, int &sksuk, int &sklyg)
{
    if (left < right)
    {
        int pivot = (left + right) / 2; // middle
        int pivotNew = partition(a, left, right, pivot,sksuk,sklyg);
        quicksort(a, left, pivotNew - 1, sksuk, sklyg);
        quicksort(a, pivotNew + 1, right, sksuk, sklyg);
        sklyg++;
    }
}

