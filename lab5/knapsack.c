#include <stdio.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

// Function to sort items by value/weight ratio in descending order
void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(struct Item items[], int n, int capacity) {
    sortItems(items, n);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take only a fraction of the item
            totalValue += items[i].ratio * capacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    float maxValue = fractionalKnapsack(items, n, capacity);

    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}