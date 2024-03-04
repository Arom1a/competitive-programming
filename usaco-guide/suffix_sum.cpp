#include <iostream>
#include <numeric>

template <typename T>
void print_vector(const std::vector<T> &my_vec)
{
    for (const T &i : my_vec)
        std::cout << i << ' ';
    std::cout << std::endl;
}

int main()
{
    std::vector<int> sample{1, 2, 3, 4, 5};
    std::vector<int> sum(sample.size() + 1);
    std::partial_sum(sample.rbegin(), sample.rend(), sum.rbegin() + 1);
    print_vector(sum);
    // sum [0,3): 1+2+3 = 6
    // sum [0,2]
    std::cout << sum[0] - sum[3] << '\n';
    // sum [1,4): 2+3+4 = 9
    // sum [1,3]
    std::cout << sum[1] - sum[4] << '\n';
}
