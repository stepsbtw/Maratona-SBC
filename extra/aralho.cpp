#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<vector<int>> custom_partition(const vector<int>& sequence, const vector<set<int>>& desired_partitions) {
    vector<vector<int>> partitions;

    map<int, int> partition_map;
    for (int i = 0; i < desired_partitions.size(); ++i) {
        for (int num : desired_partitions[i]) {
            partition_map[num] = i;
        }
    }

    for (int num : sequence) {
        if (partition_map.find(num) != partition_map.end()) {
            int part_idx = partition_map[num];
            if (partitions.size() <= part_idx) {
                partitions.resize(part_idx + 1);
            }
            partitions[part_idx].push_back(num);
        }
    }

    return partitions;
}

int main() {
    vector<int> sequence = {1, 6, 5, 2, 10, 3, 4, 8, 7, 9};

    vector<set<int>> desired_partitions = {
        {1, 2, 3, 4, 7, 9},
        {6, 8},
        {5, 10}
        // Ou alternativa
        // {1, 2, 3, 4},
        // {6, 8},
        // {5, 10},
        // {7, 9}
    };

    vector<vector<int>> partitions = custom_partition(sequence, desired_partitions);

    // Imprime as partições
    for (const auto& partition : partitions) {
        cout << "{ ";
        for (int num : partition) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
