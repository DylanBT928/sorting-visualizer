#include <algorithm>
#include <vector>

class selection_sort
{
public:
    void sort(int i, std::vector<int> &values)
    {
        int minIndex = i, temp;
        for (int j = i+1; j < values.size(); j++)
            if (values[i] > values[j])
                minIndex = j;
        temp = values[i];
        values[i] = values[minIndex];
        values[minIndex] = temp;
    }
};