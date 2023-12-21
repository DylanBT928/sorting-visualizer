#include <vector>

class insertion_sort
{
public:
    void sort(int i, std::vector<int> &values)
    {
        i++;
        key = values[i];
        j = i - 1;
        while (j >= 0 && values[j] > key)
        {
            values[j+1] = values[j];
            j--;
        }
        values[j+1] = key;
    }
private:
    int key, j;
};
