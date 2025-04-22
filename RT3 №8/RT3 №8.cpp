#include <iostream>
#include <vector>
#include <array>

class Heap {
private:
    std::vector<int> heap;
public:
    Heap() {}

    template<typename K>
    Heap(K mas) {
        append(mas);
    }

    void append(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    template<typename T>
    void append(T mas) {
        for (int i = 0; i < mas.size(); i++) {
            heap.push_back(mas[i]);
            heapifyUp(heap.size() - 1);
        }
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = ((index - 1) / 2);
            if (heap[index] > heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int i = 0;
        while (i < index) {
            int last = 0;
            int left = (2 * i) + 1;
            int right = (2 * i) + 2;
            if (left < index && right < index) {
                if (left <= heap.size() - 1 && right <= heap.size() - 1) {
                    if (heap[left] > heap[right]) {
                        if (heap[i] < heap[left]) {
                            std::swap(heap[i], heap[left]);
                            last = left;
                        }
                        else {
                            break;
                        }
                    }
                    else {
                        if (heap[i] < heap[right]) {
                            std::swap(heap[i], heap[right]);
                            last = right;
                        }
                        else {
                            break;
                        }
                    }

                }
                else if (left <= heap.size() - 1) {
                    if (heap[i] < heap[left]) {
                        std::swap(heap[i], heap[left]);
                        last = left;
                    }
                    else {
                        break;
                    }
                }
                else if (right <= heap.size() - 1) {
                    if (heap[i] < heap[right]) {
                        std::swap(heap[i], heap[right]);
                        last = right;
                    }
                    else {
                        break;
                    }
                }
                i = last;
            }
            else {
                break;
            }
            
        }
    }

    int maxSearch() {
        if (!heap[0]) {
            std::cout << "Massive is empty";
        }
        else {
            return heap[0];
        }
    }

    void deleteMax() {
        auto begin = heap.cbegin();
        heap.erase(begin);
    }

    void print() {
        for (int i : heap) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    int size() {
        return heap.size();
    }

    void heapSort(int index) {
        if (index == 0) {
            return;
        }
        for (int i = 0; i != heap.size();  i++) {
            std::swap(heap[0], heap[index-i]);
            heapifyDown(index - i);
        }
    }
};



int main()
{
    setlocale(LC_ALL, "Russian");
    std::array<int, 9> mas{ 5,3,7,8,9,10,25,16,12 };
    Heap* heap = new Heap(mas);
    heap->print();
    heap->heapSort(heap->size()-1);
    heap->print();

    return 0;
}