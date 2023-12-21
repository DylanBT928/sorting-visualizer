#include <algorithm>
#include <vector>

class selection_sort
{
public:
    void sort(int i, std::vector<int> &values)
    {
        int minIndex = i, temp;
        for (j = i+1; j < values.size(); j++)
            if (values[i] > values[j])
                minIndex = j;
        std::swap(values[i], values[minIndex]);
    }
private:
    int j;
};
