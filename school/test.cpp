#include <iostream>

int main() {
  int choice;

  do {
    std::cout << "Pick a number 1-3: ";
    std::cin >> choice;

    // Validate input (optional, but recommended):
    if (choice < 1 || choice > 3) {
      std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
      continue;
    }

    switch (choice) {
      case 1:
        std::cout << "Hello\n";
        break;
      case 2:
        std::cout << "World\n";
        break;
      case 3:
        std::cout << "beaver\n";
        break;
    }
  } while (true); // Loop indefinitely

  return 0;
}
