#ifndef SORT_H
#define SORT_H

#include "config.h"
#include "perf.h"
#include <vector>

namespace Sort 
{


    // Implementação do algoritmos de ordenação basicos O(n^2)
    // Escolha uns dos métodos abaixo para implementar
    //  - BubbleSort
    //  - SelectionSort
    //  - InsertionSort
    template<typename T, class Compare >
    void BasicSort(std::vector<T> &v, Compare cmp)
    {
        Perf::Performance perf;
        InsertionSort(v, cmp, perf);
#ifdef ENABLE_PERF
        std::cout << "BasicSort (InsertionSort): " << std::endl;
        std::cout << "   Tamanho    : " << v.size() << std::endl;
        std::cout << "   Comparacoes: " << perf.get_counter().get_comparisons() << std::endl;
        std::cout << "   Trocas     : " << perf.get_counter().get_swaps() << std::endl;
        std::cout << "   Tempo de execução : " << perf.get_timer().elapsed_time() << " segundos" << std::endl;    
#endif 
    }

    template<typename T, class Compare >
    void InsertionSort(std::vector<T> &v, Compare cmp, Performance& perf)
    {   
#ifdef ENABLE_PERF
        perf.get_timer().start();
#endif
        int i, j;
        T key;
        for (i = 1; i < v.size(); i++) {
            key = v[i];
            j = i - 1;
#ifdef ENABLE_PERF
            perf.get_counter().increment_comparisons();
#endif
            while (j >= 0 && cmp(key, v[j])) {
                v[j + 1] = v[j];
                j--;
#ifdef ENABLE_PERF
                perf.get_counter().increment_comparisons();
                perf.get_counter().increment_swaps();
#endif
            }
            v[j + 1] = key;
#ifdef ENABLE_PERF
            perf.get_counter().increment_swaps();
#endif
        }
        perf.get_timer().stop();
    }


    // TODO: Implemente algoritmo de ordenação MergeSort
    template<typename T, class Compare >
    void MergeSort(std::vector<T> &v, Compare cmp)
    {

    }

    // TODO: Implemente algoritmo de ordenação QuickSort
    template<typename T, class Compare >
    void QuickSort(std::vector<T> &v, Compare cmp)
    {

    }

    
    //  TODO: Implemente algoritmo de ordenação HeapSort
    template<typename T, class Compare >
    void HeapSort(std::vector<T> &v, Compare cmp)
    {
      
    }

    // TODO: Pesquise por algoritmos de ordenação eficientes não vistos em sala de aula.
    //       Implemente um deles.
    template<typename T, class Compare >
    void MySort(std::vector<T> &v, Compare cmp)
    {
   
    }

    //Observaçã0:
     // Compare cmp é uma função que recebe dois elementos do tipo T e retorna um bool.
     // Exemplo de como declarar uma função do tipo Compare:
     /*
       struct {
         bool operator() (T &a, T &b) const
            {
                return a < b;
            }
        } cmp;
    */
     // Se cmp(a, b) retorna true, então a é menor que b. 
     // veja nos arquivos de teste como usar essa função.

     // Funçoes auxiliares deve ser implementadas neste arquivo.
}

#endif /* SORT_H */
