/**
 * Name: Bui Duc Thanh 
 * Matric number: A0243318J
 * Lab groupn number: B01
 * Lab group TA: Muhammad Ayaz Dzulfikar
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <list>
#include <cassert>
#include <unordered_map>

using namespace std; 
class Cat {
public:
    long order, infectionLevel;
    string catName;

    Cat(long ord, long iF, string name) {
        order = ord; 
        infectionLevel = iF;
        catName = name;
    }
}; 

class binary_heap {
private:
    vector<Cat> compact_vector; // the underlying data structure, we will ignore index 0
    int heap_size; // heap_size is not always the same as (int)compact_vector.size()
    unordered_map<string, long> mapNamewithIdx;
  // three helper navigation function, written in bit manipulation format to improve runtime speed, all three are fast O(1) functions
    int parent(int i) { 
        return i>>1; // i>>1 is the same as i/2
    } 
    int left(int i) { 
        return i<<1; // i<<1 is the same as i*2
    } 
    int right(int i) { 
        return (i<<1)+1; // (i<<1)+1 is the same as i*2+1
    } 

    void swapID(unordered_map<string, long> &mapNamewithIdx, string mainKey, string swapKey) {
        auto swapKeyID = mapNamewithIdx.find(swapKey);
        auto mainKeyID = mapNamewithIdx.find(mainKey);
        long temp = mainKeyID->second; 
        mainKeyID->second = swapKeyID->second;
        swapKeyID->second = temp;
    }

    void shift_up(int i) { // O(log n)
        if (i == 1) 
            return; // at root, do nothing
        if (compact_vector[i].infectionLevel > compact_vector[parent(i)].infectionLevel) { // violate property with parent
            swapID(mapNamewithIdx, compact_vector[i].catName, compact_vector[parent(i)].catName);
            swap(compact_vector[i], compact_vector[parent(i)]); // swap upwards
            shift_up(parent(i)); // recurse, at most O(log n) steps back to the root 
        } else if (compact_vector[i].infectionLevel == compact_vector[parent(i)].infectionLevel) {
            if (compact_vector[i].order < compact_vector[parent(i)].order) {
                swapID(mapNamewithIdx, compact_vector[i].catName, compact_vector[parent(i)].catName);
                swap(compact_vector[i], compact_vector[parent(i)]); // swap upwards
                shift_up(parent(i)); // recurse, at most O(log n) steps back to the root
            }
        }
    }

    void shift_down(int i) { // O(log n)
        if (i > heap_size) 
            return; // beyond last element, do nothing
        int swap_id = i;
        if ((left(i) <= heap_size) && ((compact_vector[i].infectionLevel < compact_vector[left(i)].infectionLevel) || (compact_vector[i].infectionLevel == compact_vector[left(i)].infectionLevel && compact_vector[i].order > compact_vector[left(i)].order))) // compare with left child, if exists
            swap_id = left(i);
        if ((right(i) <= heap_size) && ((compact_vector[swap_id].infectionLevel < compact_vector[right(i)].infectionLevel) || (compact_vector[swap_id].infectionLevel == compact_vector[right(i)].infectionLevel && compact_vector[swap_id].order > compact_vector[right(i)].order))) // compare with right child, if exists
            swap_id = right(i);
        if (swap_id != i) { // need to swap with the larger of the two children
            swapID(mapNamewithIdx, compact_vector[i].catName, compact_vector[swap_id].catName);
            swap(compact_vector[i], compact_vector[swap_id]); // swap downwards with the larger of the two children
            shift_down(swap_id); // recurse, at most O(log n) steps to one of the bottom-most leaf
        }
    }

public:
    binary_heap() { // O(1)
        compact_vector.push_back(Cat(0, 0, "")); // set index 0 to be 'dummy'
        heap_size = 0; // an empty Binary Heap
    }

    ~binary_heap() { // O(n)
        compact_vector.clear();
    }

    void push(Cat x) { // O(log n): done
        if (heap_size+1 >= (int)compact_vector.size()) // O(1)
            compact_vector.push_back(Cat(0, 0, "")); // enlarge the vector by one (internally, vector doubles its size) if needed, to avoid potential RCatE below, O(1)
        compact_vector[++heap_size] = x; // the only possible insertion point, O(1)
        mapNamewithIdx[x.catName] = heap_size;
        shift_up(heap_size); // shift upwards, O(log n) at worst
    }

    void pop() { // O(log n):done
        swapID(mapNamewithIdx, compact_vector[1].catName, compact_vector[heap_size].catName);
        mapNamewithIdx.erase(compact_vector[1].catName);
        swap(compact_vector[1], compact_vector[heap_size--]); // swap with the last existing leaf, O(1)
        shift_down(1); // fix heap property downwards, O(log n) at worst
    }

    void updateKey(string str, long delta) { //not done
        auto keyToUpdate = mapNamewithIdx.find(str);
        long id = keyToUpdate->second;
        compact_vector[id].infectionLevel += delta;
        shift_up(id);
    }

    void deleteKey(string str) {
        updateKey(str, 71);
        pop();
    }

    void printPQ() { //to check the binary_heap after each command
        cout << "PQ: "<< heap_size << " ";
        for (long i = 1; i <= heap_size; i++) {
            cout << compact_vector[i].catName << " " << compact_vector[i].infectionLevel << " " << compact_vector[i].order << " | ";
        }
        cout << endl;
    }

    void printMap() { //to check the map after each command 
        cout << "Hash: "; 
        for (auto i : mapNamewithIdx) {
            cout << i.first << " " << i.second << " | ";
        }
        cout << '\n';
    }

    string top() { // O(1)
        return compact_vector[1].catName; // this is the root
    }

    bool empty() { // O(1)
        return heap_size == 0; // the only condition for an empty compact_vector
    }

    int size() { // O(1)
        assert(heap_size <= (int)compact_vector.size()); // should be true at all times
        return heap_size;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    binary_heap patients;
    unordered_map<string, int> mapNamewithIdx;
    long n, command, infectionLevel, order = 0, increaseInfection;
    string catName; 

    cin >> n;
    for (long i = 0; i < n; i++) {
        cin >> command;
        if (command == 3) { //Query()
            if (!patients.empty()) {
                cout << patients.top() << '\n';
            } else {
                cout << "The clinic is empty\n";
            }
            // patients.printMap();
            // patients.printPQ();
        } else if (command == 1) { //UpdateInfectionLevel(catName, increaseInfection)
            cin >> catName >> increaseInfection;
            patients.updateKey(catName, increaseInfection);
            // patients.printMap();
            // patients.printPQ();
        } else if (command == 2) { //Treated(catName)
            cin >> catName;
            patients.deleteKey(catName);
            // patients.printMap();
            // patients.printPQ();
        } else if (command == 0) { //ArriveAtClinic(catName, infectionLevel)
            cin >> catName >> infectionLevel;
            Cat cat(order, infectionLevel, catName);
            order++;
            patients.push(cat);
            // patients.printMap();
            // patients.printPQ();
        }
    } 
    return 0;
}  