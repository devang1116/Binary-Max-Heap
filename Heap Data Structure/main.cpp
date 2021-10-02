//
//  main.cpp
//  Heap Data Structure
//
//  Created by Devang Papinwar on 02/10/21.
//

#include <iostream>
#include <vector>
using namespace std;

class BinaryHeap
{
    public :
    vector<int> heap;
    
    void insertEle(int element)
    {
        int size = heap.size();
        if(size == 0)
        {
            heap.push_back(element);
        }
        else
        {
            heap.push_back(element);
            for(int i = size / 2 - 1 ; i >= 0 ; i--)
            {
                heapify(i);
            }
        }
    }
    
    void deleteEle(int index)
    {
        int i;
        for(i = 0 ; i < heap.size() ; i++)
        {
            if(heap[i] == heap[index])
            {
                break;
            }
        }
        
        swap(&heap[index] , &heap[heap.size()-1]);
        heap.pop_back();
        
        for(int i = heap.size() / 2 - 1 ; i >= 0 ; i--)
        {
            heapify(i);
        }
    }

    void heapify(int index)
    {
      int size = heap.size();
      int largest = index;
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      if(left < size && heap[left] > heap[largest])
      {
        largest = left;
      }
      if(right < size && heap[right] > heap[largest])
      {
        largest = right;
      }

      if(largest != index)
      {
        swap(&heap[index], &heap[largest]);
        heapify(largest);
      }
    }
    
    void swap(int *a, int *b)
    {
      int temp = *b;
      *b = *a;
      *a = temp;
    }

    void printHeap()
    {
        for( int i = 0 ; i < heap.size() ; i++ )
            cout << " " << heap[i];
        cout << endl;
    }
};


int main(int argc, const char * argv[])
{
    
    BinaryHeap binaryHeap;
    
    binaryHeap.insertEle(43);
    binaryHeap.insertEle(64);
    binaryHeap.insertEle(23);
    binaryHeap.insertEle(98);
    binaryHeap.insertEle(34);
    binaryHeap.insertEle(4);
    
    binaryHeap.printHeap();
    
    binaryHeap.deleteEle(3);
    binaryHeap.printHeap();
    
    return 0;
}
