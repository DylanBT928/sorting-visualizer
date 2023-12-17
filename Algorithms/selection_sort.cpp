#include <algorithm>
#include <vector>

class selection_sort
{
public:
    void sort(int i, std::vector<int> &values)
    {
        int temp;
        for (int j = i+1; j < values.size(); j++)
        {
            if (values[i] > values[j])
            {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
};