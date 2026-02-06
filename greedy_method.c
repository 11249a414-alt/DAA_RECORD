#include <stdio.h>
struct Item {
    int weight;
    int value;
    float ratio;
};
void sortByRatio(struct Item items[], int n) {
    struct Item temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}
int main() {
    int n;
    float capacity, totalValue = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);
    sortByRatio(items, n);
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            // Take whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take fractional part
            totalValue += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);

    return 0;
}
