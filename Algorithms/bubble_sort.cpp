#include <algorithm>
#include <vector>

class bubble_sort
{
public:
    void sort(int i, std::vector<int> &values)
    {
        swapped = false;
        for (j = 0; j < values.size()-i-1; j++)
        {
            if (values[j] > values[j+1])
            {
                std::swap(values[j], values[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            return;
    }
private:
    int j;
    bool swapped;
};
