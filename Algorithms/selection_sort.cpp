#include <algorithm>
#include <vector>

class selection_sort
{
public:
    void sort(int i, std::vector<int> &values)
    {
        minIndex = i;
        for (j = i+1; j < values.size(); j++)
            if (values[minIndex] > values[j])
                minIndex = j;
        if (minIndex != i)
            std::swap(values[i], values[minIndex]);
    }
private:
    int minIndex, j;
};
